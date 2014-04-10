package pathfinding;

import java.util.ArrayList;

import pathfinding.SearchSpace.Grid2DSpace;
import pathfinding.cache.CacheHolder;
import smartMath.IntPair;
import smartMath.Vec2;
import table.ObstacleCirculaire;
import table.Table;
import utils.Log;
import utils.Read_Ini;
import container.Service;
import exception.ConfigException;
import exception.PathfindingException;


/**
 * Service de recherche de chemin
 * @author Marsu, pf
 * 
 * 
 * Permet de traiter les problèmes de chemins : longueur d'un parcourt d'un point à un autre de la map,
 * 												 trajet d'un point a un autre de la map
 * 	Le tout indépendamment de l'algorithme (pour l'instant que weithed A*)
 *
 */

public class Pathfinding implements Service
{
	// Dépendances
	private final Table table;	// Final: protection contre le changement de référence.
								// Si la référence change, tout le memorymanager foire.
	private int hashTableSaved = -1;	// Permet, à l'update, de ne recalculer map que si la table a effectivement changé.
	private static Read_Ini config;
	private static Log log;
	private boolean resultUpToDate;
	private int rayon_robot = 200;
	private int table_x = 3000;
	private int table_y = 2000;
	private int code_torches_actuel = -1;

	
	public Grid2DSpace map;

	/* Quatre Grid2DSpace qui sont la base, avec les obstacles fixes. On applique des pochoirs dessus.
	 * Quatre parce qu'il y a la table initiale, la table à laquelle il manque une torche fixe et la table sans torche fixe.
	 * Ces quatre cas permettront de n'ajouter au final que les obstacles mobiles.
	 */
	private static Grid2DSpace[] map_obstacles_fixes;
	
	/* Les caches des distances, un pour chaque map_obstacles_fixes
	 */
	private static CacheHolder[] distance_caches;

	/*
	 * Ce code, en static, n'est exécuté qu'une seule fois
	 */
	static {
		distance_caches = new CacheHolder[4];
		try {
			for(int i = 0; i < 4; i++)
				distance_caches[i] = CacheHolder.load(i);
		} catch (Exception e) {
//			e.printStackTrace();
		}
	}
	
	private int millimetresParCases;

	private AStar solver;
	private ArrayList<IntPair> result;
	private ArrayList<Vec2> output;
	
	public Pathfinding(Table requestedtable, Read_Ini requestedConfig, Log requestedLog, int requestedMillimetresParCases)
	{
		table = requestedtable;
		config = requestedConfig;
		log = requestedLog;
		maj_config();
		millimetresParCases = requestedMillimetresParCases;
		map = new Grid2DSpace(new IntPair(table_x/millimetresParCases, table_y/millimetresParCases), table, rayon_robot, log, config);
		solver = new AStar(map, new IntPair(0,0), new IntPair(0,0));
		output = new ArrayList<Vec2>();
		result = new ArrayList<IntPair>();
		resultUpToDate = false;
		update(); 	// initialisation de la map
	}
	
	public boolean isResultUpToDate() 
	{
		return resultUpToDate;
	}

	public void maj_config()
	{
		try {
			rayon_robot = Integer.parseInt(config.get("rayon_robot"));
		} catch (NumberFormatException | ConfigException e) {
			e.printStackTrace();
		}
		try {
			table_x = Integer.parseInt(config.get("table_x"));
		} catch (NumberFormatException | ConfigException e) {
			e.printStackTrace();
		}
		try {
			table_y = Integer.parseInt(config.get("table_y"));
		} catch (NumberFormatException | ConfigException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Méthode appelée par le thread de capteur. Met à jour les obstacles de la recherche de chemin en les demandant à table
	 * On consulte pour cela l'attribut table qui a été modifié de l'extérieur.
	 */
	public void update()
	{
		synchronized(table) // Mutex sur la table, afin qu'elle ne change pas pendant qu'on met à jour le pathfinding
		{
			// Si le hash actuel est égal au hash du dernier update, on annule la copie car la map n'a pas changé.
			if(table.hashTable() == hashTableSaved)
				return;

			// On recharge les map_fixes quand le code des torches changent. Deux raisons:
			// 1) Ces codes changent rarement
			// 2) Mieux vaut économiser la mémoire
			if(table.codeTorches() != code_torches_actuel)
			{
				code_torches_actuel = table.codeTorches();
				try {
					for(int millimetresParCases = 1; millimetresParCases <= 16; millimetresParCases++)
						map_obstacles_fixes[millimetresParCases] = Grid2DSpace.load(millimetresParCases, table.codeTorches());
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
			}

			hashTableSaved = table.hashTable();
			
			// On recopie les obstacles fixes
			map_obstacles_fixes[millimetresParCases].clone(map);

			// Puis les obstacles temporaires
			ArrayList<ObstacleCirculaire> obs = table.getListObstacles();
			for(ObstacleCirculaire o: obs)
				map.appendObstacleTemporaire(o);
			// les chemins sont périmés puisque la map est différente
			resultUpToDate = true;
		}
	}

	/**
	 * Retourne l'itinéraire pour aller d'un point de départ à un point d'arrivée
	 * @param depart, exprimé en milimètres, avec comme origine le point en face du centre des mamouths
	 * @param arrivee système de coords IDEM
	 * @return l'itinéraire, exprimé comme des vecteurs de déplacement, et non des positions absolues, et en millimètres
	 * 			Si l'itinéraire est non trouvable, une exception est est retournée.
	 * @throws PathfindingException 
	 */
	
	// TODO : deal with precision issue (divide by millimetresParCases)
	public ArrayList<Vec2> chemin(Vec2 depart, Vec2 arrivee) throws PathfindingException
	{
		solver.setDepart(new IntPair((int)((float)(depart.x + table_x/2) / millimetresParCases), (int)((float)(depart.y) / millimetresParCases)));
		solver.setArrivee(new IntPair((int)((float)(arrivee.x + table_x/2) / millimetresParCases), (int)((float)(arrivee.y) / millimetresParCases)));
/*		// Change de système de coordonnées
		solver.setDepart(new IntPair((int)Math.round(depart.x + 1500)/millimetresParCases, (int)Math.round(depart.y)/millimetresParCases));
		solver.setArrivee(new IntPair((int)Math.round(arrivee.x + 1500)/millimetresParCases, (int)Math.round(arrivee.y)/millimetresParCases));

		System.out.println("solver.depart : " + solver.getDepart().x + "   " + solver.getDepart().y);
		System.out.println("solver.arrivee : " + solver.getArrivee().x + "   " + solver.getArrivee().y);
		System.out.println("solver.espace.size : " + solver.getEspace().getSizeX() + "   " + solver.getEspace().getSizeY());
		*/
		// calcule le chemin
		solver.process();
		if (!solver.isValid())	// null si A* dit que pas possib'
			throw new PathfindingException();
		result = lissage(solver.getChemin(), map);
		
		
		// affiche la liste des positions
		output.clear();
		for (int i = 0; i < result.size()-1; ++i)
			output.add(new Vec2((float)(result.get(i).x)* millimetresParCases -table_x/2, (float)(result.get(i).y)* millimetresParCases));
		output.add(arrivee);
		System.out.println("Chemin : " + output);
		
		resultUpToDate = true;
		return output;
		
		// convertit la sortie de l'AStar en suite de Vec2 dans le système de coords d'entrée.
		/*
		output.clear();
		for (int i = 1; i < result.size(); ++i)
			output.add(new Vec2((float)(result.get(i).x - result.get(i-1).x)* millimetresParCases, (float)(result.get(i).y - result.get(i-1).y)* millimetresParCases));
		
		
		
		return output;*/
		
	}

	/**
	 * Renvoie la distance entre départ et arrivée, en utilisant le cache ou non.
	 * @param depart
	 * @param arrivee
	 * @param use_cache :  si le chemin doit être précisément calculé, ou si on peut utiliser un calcul préfait.
	 * @return la longeur du parsours, exprimée en milimèrtes. Le parsours calculé est diponible via getResult. -1 est retourné quand le chemin est pas trouvable
	 * @throws PathfindingException 
	 */
	public int distance(Vec2 depart, Vec2 arrivee, boolean use_cache) throws PathfindingException
	{
		if(!use_cache || distance_caches == null)
		{
			// Change de système de coordonnées
			solver.setDepart(new IntPair((int)Math.round(depart.x + table_x/2)/millimetresParCases, (int)Math.round(depart.y)/millimetresParCases));
			solver.setArrivee(new IntPair((int)Math.round(arrivee.x + table_x/2)/millimetresParCases, (int)Math.round(arrivee.y)/millimetresParCases));
			
			// calcule le chemin
			solver.process();
			if (!solver.isValid())	// lève une exception si A* dit que pas possible
				throw new PathfindingException();
			result = lissage(solver.getChemin(), map);
			
			// convertit la sortie de l'AStar en suite de Vec2
			int out = 0;
			for (int i = 1; i < result.size(); ++i)
				out +=  Math.sqrt(	(result.get(i).x - result.get(i-1).x) * (result.get(i).x - result.get(i-1).x) +
									(result.get(i).y - result.get(i-1).y) * (result.get(i).y - result.get(i-1).y));

			resultUpToDate = true;
			return out*millimetresParCases;
		}
		else
		{
			resultUpToDate = true;
			return distance_caches[table.codeTorches()].data[(int)depart.x+table_x/2][(int)depart.y][(int)arrivee.x+table_x/2][(int)arrivee.y];
		}
	}
	
	


	/**
	 * Transforme un chemin ou chaque pas est spécifié en un chemin lissé ou il ne reste que très peu de sommets
	 * ch
			// calcule le chemin
			solver.setDepart(new IntPair((int)Math.round(depart.x),(int)Math.round(depart.y)));
			solver.setArrivee(new IntPair((int)Math.round(arrivee.x),(int)Math.round(arrivee.y)));
			solver.process();
			result = lissage(solver.getChemin(), map);acun de ses sommets est séparé par une ligne droite sans obstacle
	 * @param le chemin non lissé (avec tout les pas)
	 * @return le chemin liss (avec typiquement une disaine de sommets grand maximum)
	 */
	public ArrayList<IntPair> lissage(ArrayList<IntPair> cheminFull, Grid2DSpace map)
	{
		if (cheminFull.size() < 2)
			return cheminFull;
		// Nettoie le chemin
		ArrayList<IntPair> chemin = new ArrayList<IntPair>();
		int 	lastXDelta = 0,
				lastYDelta = 0,
				xDelta = 0,
				yDelta = 0;
		
		// On doit rentrer les 2 premiers points du parcours
		//chemin.add(cheminFull.get(cheminFull.size()-1)); // ajoute la fin
		chemin.add(cheminFull.get(0));
		chemin.add(cheminFull.get(1));
		
		xDelta = (int)(cheminFull.get(1).x - cheminFull.get(0).x);
		yDelta = (int)(cheminFull.get(1).y - cheminFull.get(0).y);
		for (int i = 2; i < cheminFull.size(); ++i)	
		{
			lastXDelta = xDelta;
			lastYDelta = yDelta;
			xDelta = (int)(cheminFull.get(i).x - cheminFull.get(i-1).x);
			yDelta = (int)(cheminFull.get(i).y - cheminFull.get(i-1).y);
			
			if (xDelta != lastXDelta && yDelta != lastYDelta)	// Si virage, on garde le point, sinon non.
				chemin.add(cheminFull.get(i-1));
		}
		chemin.remove(1); // retire l'intermédiare de calcul
		chemin.add(cheminFull.get(cheminFull.size()-1)); // ajoute la fin
		
		
		// supprimes les points non nécéssaire.
		ArrayList<IntPair> out = new ArrayList<IntPair>();
		
		// saute les 2 derniers points, comme on ne pourra rien simplifier entre.
		for (int i = 0; i < chemin.size(); ++i)	
		{
			// regardes si un point plus loin peut �tre rejoint en ligne droite
			for (int j = chemin.size()-1; j > i; --j)
			{
				if (map.canCrossLine(chemin.get(i).x, chemin.get(i).y, chemin.get(j).x, chemin.get(j).y))
				{
					//System.out.println("Lissage loops parameters :  i = " + i + ";  j = " + j);
					//map.drawLine(chemin.get(i).x, chemin.get(i).y, chemin.get(j).x, chemin.get(j).y);
					// on a trouvé le point le plus loin que l'on peut rejoindre en ligne droite
					out.add(chemin.get(i));
					i = j-1;	// on continuras la recherche a partir de ce point.
					break;
				}
			}
		}
		// 	on ajoute le point d'arrivée au chemin final
		out.add(chemin.get(chemin.size()-1));
		
		return out;
	}
	

	public ArrayList<IntPair> getResult() 
	{
		return result;
	}
	public IntPair getDepart() 
	{
		return solver.getDepart();
	}
	public IntPair getArrivee() 
	{
		return solver.getArrivee();
	}
	/**
	 * @return the map
	 */
	public Grid2DSpace getMap()
	{
		return map;
	}
	
	/**
	 * @return the millimetresParCases
	 */
	public int getMillimetresParCases() 
	{
		return millimetresParCases;
	}

	/**
	 * @param millimetresParCases the millimetresParCases to set
	 */
	public void setMillimetresParCases(int millimetresParCases) 
	{
		this.millimetresParCases = millimetresParCases;
	}
	
	/**
	 * Le pathfinding en argument deviendra la copie de this (this reste inchangé)
	 * @param cp (cloned_pathfinding)
	 */
	public void clone(Pathfinding cp)
	{
		table.clone(cp.table);  // clone de la table
		cp.update();		    // et update
	}

}
