//import hook.sortes.HookGenerator;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.junit.runner.JUnitCore;

//import robot.RobotChrono;
import robot.RobotVrai;
import robot.cartes.Capteurs;
import robot.cartes.Deplacements;
import robot.hautniveau.DeplacementsHautNiveau;
import scripts.Script;
import scripts.ScriptManager;
import smartMath.Vec2;
import strategie.GameState;
import strategie.Strategie;
import tests.JUnit_StrategieThreadTest;
//import sun.rmi.runtime.Log;
import threads.ThreadTimer;
import utils.Read_Ini;
import utils.Sleep;
import container.Container;
import enums.Vitesse;


		
public class lanceur
{
	static Container container;
	static Read_Ini config;
	static GameState<RobotVrai> real_state;
	static Strategie strategie;
	static ScriptManager scriptmanager;
	static DeplacementsHautNiveau deplacements;
	static Deplacements dep;
	static Capteurs capteurs;
	static boolean doitFaireDepartRapide;
	
	
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception
	{
		
        // si on veut exécuter un test unitaire sur la rapbe, recopier test.nomDeLaClasseDeTest
		//JUnitCore.main(		"tests.JUnit_DeplacementsTest");  
		
		
		container = new Container();
		config = (Read_Ini) container.getService("Read_Ini");
	
		
		//Début des paramétrages
		configCouleur();
	
		
		// initialise les singletons
		real_state = (GameState<RobotVrai>) container.getService("RealGameState");
		strategie = (Strategie) container.getService("Strategie");
	    scriptmanager = (ScriptManager) container.getService("ScriptManager");
	    deplacements = (DeplacementsHautNiveau)container.getService("DeplacementsHautNiveau");
	    dep = (Deplacements)container.getService("Deplacements");
	    capteurs = (Capteurs) container.getService("Capteur");
	    
		real_state.robot.initialiser_actionneurs_deplacements();
		

		// Threads
		container.demarreTousThreads();

		recalerRobot();
		setFruitNoirPositions();
		configDepartRapide() ;
		
		// met le ronot en position finale avant le debut du match
		if(doitFaireDepartRapide)
			initialiserDepartRapide();
		else
			initialiserDepartStandard();

		// attends que le jumper soit retiré
		attendreDebutMatch();
		
		// fais un depart rapide si besoin
		if(doitFaireDepartRapide)
			faireDepartRapide();
		else
			faireDepartStandard();
		
		
		System.out.println("Le robot commence le match");
		 
		
		// fais le match avec l'IA
		strategie.boucle_strategie();
		
		//Le match s'arrête
		container.destructeur();
	}
	
	
	
	/** setFruitNoirPositions : demande la position des fruits noirs
	 * 
	 * On a 2 inputs 
	 * Le deuxième pour les arbres 0 et 3 (on donne pour 0 et pour le 3 ça sera calculé facilement)
	 * Le troisième pour les arbres 1 et 2 (one donne pour 1 et pour les 2 ça sera calculé facilement) 
	 * La position des fruits dans un arbre est expliqué dans la classe Tree
	 * 
	 * @throws Exception
	 */
	static void setFruitNoirPositions()  throws Exception
	{

		/*
		 * On a 2 inputs 
		 * Le deuxième pour les arbres 0 et 3 (on donne pour 0 et pour le 3 ça sera calculé facilement)
		 * Le troisième pour les arbres 1 et 2 (one donne pour 1 et pour les 2 ça sera calculé facilement) 
		 * La position des fruits dans un arbre est expliqué dans la classe Tree
		*/		
		//Pour les fruits noirs
		String pos_noir1 = "";
		String pos_noir2 = "";
		
		while(!(pos_noir1.contains("0")|| pos_noir1.contains("1")|| pos_noir1.contains("2")||pos_noir1.contains("3")||pos_noir1.contains("4")||pos_noir1.contains("5")))
		{
			System.out.println("Donnez la position des fruits noirs pour les arbres 0 et 3 : ");
			BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
			pos_noir1 = keyboard.readLine(); 
			if(pos_noir1.contains("0"))
			{
				real_state.table.setFruitNoir(0, 0);
				real_state.table.setFruitNoir(3, 3);
			}
			else if(pos_noir1.contains("1"))
			{
				real_state.table.setFruitNoir(0, 1);
				real_state.table.setFruitNoir(3, 4);
			}
			else if (pos_noir1.contains("2"))
			{
				real_state.table.setFruitNoir(0, 2);
				real_state.table.setFruitNoir(3, 5);
			}
			else if (pos_noir1.contains("3"))
			{
				real_state.table.setFruitNoir(0, 3);
				real_state.table.setFruitNoir(3, 0);
			}
			else if (pos_noir1.contains("4"))
			{
				real_state.table.setFruitNoir(0, 4);
				real_state.table.setFruitNoir(3, 1);
			}
			else if (pos_noir1.contains("5"))
			{
				real_state.table.setFruitNoir(0, 5);
				real_state.table.setFruitNoir(3, 2);
			}
		}		
		while(!(pos_noir2.contains("0")|| pos_noir2.contains("1")|| pos_noir2.contains("2")||pos_noir2.contains("3")||pos_noir2.contains("4")||pos_noir2.contains("5")))
		{
			System.out.println("Donnez la position des fruits noirs pour les arbres 1 et 2 : ");
			BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
			pos_noir2 = keyboard.readLine(); 
			if(pos_noir2.contains("0"))
			{
				real_state.table.setFruitNoir(1, 0);
				real_state.table.setFruitNoir(2, 3);
			}
			else if(pos_noir2.contains("1"))
			{
				real_state.table.setFruitNoir(1, 1);
				real_state.table.setFruitNoir(2, 4);
			}
			else if (pos_noir2.contains("2"))
			{
				real_state.table.setFruitNoir(1, 2);
				real_state.table.setFruitNoir(2, 5);
			}
			else if (pos_noir2.contains("3"))
			{
				real_state.table.setFruitNoir(1, 3);
				real_state.table.setFruitNoir(2, 0);
			}
			else if (pos_noir2.contains("4"))
			{
				real_state.table.setFruitNoir(1, 4);
				real_state.table.setFruitNoir(2, 1);
			}
			else if (pos_noir2.contains("5"))
			{
				real_state.table.setFruitNoir(1, 5);
				real_state.table.setFruitNoir(2, 2);
			}
				
		}
	}
	
	

	/**
	 * Demande si il faut faire un depart rapide ou un depart standard
	 * @throws Exception
	 */
	static void configDepartRapide()  throws Exception
	{

		String departRapideInput = "";
		doitFaireDepartRapide = false;
		while(!(departRapideInput.contains("oui") ||departRapideInput.contains("non")))
		{
			System.out.println("Activer le départ rapide ? (oui/non) ");
			BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
			departRapideInput = keyboard.readLine(); 
			if(departRapideInput.contains("oui"))
			{
				doitFaireDepartRapide = true;
			}
			else if(departRapideInput.contains("non"))
			{
				doitFaireDepartRapide = false;
			}
		}
		
		if(doitFaireDepartRapide)
		{

			String departRapideVistesseInput = "";
			int departRapideVitesseRotation = 25;	// valeur négatif pour ne pas faire le démarrage rapide
			while(!(departRapideVistesseInput.contains("oui") ||departRapideVistesseInput.contains("non")))
			{
				System.out.println("Quelle doit être la vitesse de rotation du démarrage rapide ? (par default " + departRapideVitesseRotation + ")");
				BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
				departRapideVistesseInput = keyboard.readLine(); 
				
				try
				{
					departRapideVitesseRotation = Integer.parseInt(departRapideVistesseInput);
				}
				catch(NumberFormatException e)
				{
					continue;
				}
				// si on arrive ici c'est que departRapideVitesseRotation a été affecté, donc on sors de boucle
				break;
			}
		}

	}

	
	

	/**
	 * Demande si la couleur est rouge au jaune
	 * @throws Exception
	 */
	static void configCouleur()  throws Exception
	{

		String couleur = "";
		while(!couleur.contains("rouge") && !couleur.contains("jaune"))
		{
			System.out.println("Rentrez \"jaune\" ou \"rouge\" : ");
			BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
			 
			couleur = keyboard.readLine(); 
			if(couleur.contains("rouge"))
				config.set("couleur","rouge");
			else if(couleur.contains("jaune"))
				config.set("couleur", "jaune");
			
		}
		
	}
	
	

	/**
	 * Recale le robot
	 * @throws Exception
	 */
	static void recalerRobot()  throws Exception
	{

		System.out.println("Pret au recalage, appuyez sur entrée pour continuer");
		config.set("capteurs_on", false);	// pas de capteurs durant le recalage
		capteurs.maj_config();
		
		// attends la pression sur entrée
		new BufferedReader(new InputStreamReader(System.in)).readLine();
		
		//recale
		real_state.robot.recaler();
		
	}	
	

	/**
	 * Attends que le match soit lancé
	 * @throws Exception
	 */
	static void attendreDebutMatch()  throws Exception
	{

		System.out.println("Robot pret pour le match, attente du retrait du jumper");
		
		// hack si le jumper est inopérant
		//ThreadTimer.match_demarre = true;

		while(!capteurs.demarrage_match())
				Sleep.sleep(100);
	}
	


	/**
	 * initialise le départ non Rapide
	 * @throws Exception
	 */
	static void initialiserDepartStandard()  throws Exception
	{
		real_state.robot.avancer(300);
	}

	

	/**
	 * effectue le départ non Rapide
	 * @throws Exception
	 */
	static void faireDepartStandard()  throws Exception
	{

	}
	
	
	/**
	 * initialise le départ Rapide
	 * @throws Exception
	 */
	static void initialiserDepartRapide()  throws Exception
	{
		real_state.robot.set_vitesse(Vitesse.DEBUT);
		real_state.robot.tourner(-1.6*Math.PI/3);
	    System.out.println("Position de départ :" + real_state.robot.getPosition());
	}
	
	
	/**
	 * Effectue le départ rapide
	 * @throws Exception
	 */
	static void faireDepartRapide()  throws Exception
	{

	    deplacements.setConsigne(new Vec2(-1300, 1200));
	    
	    /*  Hook hook = hookgenerator.hook_abscisse_gauche(-900);   
	    ArrayList<Hook> hooks = new ArrayList<Hook>();
	    Executable arret = new Arret(dep);
	    hook.ajouter_callback(new Callback(arret, true));
	    hooks.add(hook);*/
	    
	    deplacements.va_au_point_gestion_exception(null, true, false, false);
	    Script s = (Script)scriptmanager.getScript("ScriptTree");
	    s.agit(2, real_state, true);
	}
	
}