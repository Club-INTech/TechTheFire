import java.io.BufferedReader;
import java.io.InputStreamReader;
import pathfinding.Pathfinding;
import container.Container;
import exception.ScriptException;
import robot.RobotChrono;
import robot.RobotVrai;
import robot.cartes.Capteurs;
import scripts.Script;
import scripts.ScriptManager;
import smartMath.Vec2;
import table.Table;
import threads.ThreadTimer;
import utils.Log;
import utils.Read_Ini;

/*
 * TODO pour le lanceur final:
 * - ne pas oublier container.destructeur();
 *
 */
		
public class lanceur
{
	
	private static Test test = new Test();
	
	public static void main(String[] args)
	{
		test.test();
		Container container;
		try 
		{
			
			// Config & Logs
			container = new Container();
			Read_Ini config = (Read_Ini) container.getService("Read_Ini");
			Log log = (Log) container.getService("Log");
			
			// Pas de capteurs avant le racalage
			Capteurs capteurs = (Capteurs) container.getService("Capteur");
			config.set("capteurs_on", false);
			capteurs.maj_config();
			
			// Timer
			ThreadTimer threadtimer = (ThreadTimer) container.getService("threadTimer");
			
			// Declaration robot
			// compléter avec: vitesse, position, ...
			ScriptManager scriptmanager = (ScriptManager)container.getService("ScriptManager");
			RobotVrai robotvrai = (RobotVrai)container.getService("RobotVrai");
			RobotChrono robotchrono = new RobotChrono(config, log);
			//config.set("couleur", "jaune");
			robotchrono.majRobotChrono(robotvrai);
			

			//Talbe
			Table table = (Table)container.getService("Table");
			Pathfinding pathfinding = new Pathfinding(table, config, log, 1);
			
			// Etat intial du robot
			robotvrai.setPosition(new Vec2(1300, 1350));
			//robotvrai.setPosition(new Vec2(1251, 1695));
			robotvrai.setOrientation((float)(-Math.PI/2));
			robotvrai.set_vitesse_rotation("entre_scripts");
			robotvrai.set_vitesse_translation("entre_scripts");
			
			// DEmare les threads
			container.demarreTousThreads();
			
			
			/*On aura 3 inputs 
			Le premier pour la couleur du robot avec 0 pour jaune et 1 pour rouge
			Le deuxième pour les arbres 0 et 3 (on donne pour 0 et pour le 3 ça sera calculé facilement)
			Le troisième pour les arbres 1 et 2 (one donne pour 1 et pour les 2 ça sera calculé facilement) 
			La position des fruits dans un arbre est expliqué dans la classe Tree
			*/
			//--------------------------------------------------------------
			//Début des paramétrages
			String couleur = "";
			while(!couleur.contains("0") && !couleur.contains("1"))
			{
				System.out.println("Rentrez 0 pour jaune et 1 pour rouge : ");
				BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
				 
				couleur = keyboard.readLine(); 
				
				
				if(couleur.contains("0"))
					config.set("couleur","jaune");
				else if(couleur.contains("1"))
					config.set("couleur", "rouge");
				robotvrai.maj_config();
			}
			
			
			// On initialise des trucs
			
			
			
			
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
					table.setFruitNoir(0, 0);
					table.setFruitNoir(3, 3);
				}
				else if(pos_noir1.contains("1"))
				{
					table.setFruitNoir(0, 1);
					table.setFruitNoir(3, 4);
				}
				else if (pos_noir1.contains("2"))
				{
					table.setFruitNoir(0, 2);
					table.setFruitNoir(3, 5);
				}
				else if (pos_noir1.contains("3"))
				{
					table.setFruitNoir(0, 3);
					table.setFruitNoir(3, 0);
				}
				else if (pos_noir1.contains("4"))
				{
					table.setFruitNoir(0, 4);
					table.setFruitNoir(3, 1);
				}
				else if (pos_noir1.contains("5"))
				{
					table.setFruitNoir(0, 5);
					table.setFruitNoir(3, 2);
				}
			}		
			while(!(pos_noir2.contains("0")|| pos_noir2.contains("1")|| pos_noir2.contains("2")||pos_noir2.contains("3")||pos_noir2.contains("4")||pos_noir2.contains("5")))
			{
				System.out.println("Donnez la position des fruits noirs pour les arbres 1 et 2 : ");
				BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in)); 
				pos_noir2 = keyboard.readLine(); 
				if(pos_noir2.contains("0"))
				{
					table.setFruitNoir(1, 0);
					table.setFruitNoir(2, 3);
				}
				else if(pos_noir2.contains("1"))
				{
					table.setFruitNoir(1, 1);
					table.setFruitNoir(2, 4);
				}
				else if (pos_noir2.contains("2"))
				{
					table.setFruitNoir(1, 2);
					table.setFruitNoir(2, 5);
				}
				else if (pos_noir2.contains("3"))
				{
					table.setFruitNoir(1, 3);
					table.setFruitNoir(2, 0);
				}
				else if (pos_noir2.contains("4"))
				{
					table.setFruitNoir(1, 4);
					table.setFruitNoir(2, 1);
				}
				else if (pos_noir2.contains("5"))
				{
					table.setFruitNoir(1, 5);
					table.setFruitNoir(2, 2);
				}
					
			}
			//Fin paramétrage terrain
			//------------------------------------------------------
	

			// Attente du top départ par le thread timer
			while(!threadtimer.match_demarre)
			{
				Thread.sleep(100);
			}
			
			
			// Debut du match
			robotvrai.initialiser_actionneurs_deplacements();
			robotvrai.recaler();
			
			config.set("capteurs_on", true);
			capteurs.maj_config();
			
			
			// vitesse de translation
			robotvrai.set_vitesse_translation("entre_scripts");
			
			
			// Entrée sur le terrain
			robotvrai.avancer(200);
			robotvrai.tourner((float)(-Math.PI/2-Math.PI/6));
			robotvrai.avancer(500);
			threadtimer.match_demarre = true;
			//Thread.sleep(1000);	// ?
			
			
			// 2 séquences d'action en boucles selon couleur
			if(couleur.contains("0"))
				//C'est jaune
			{
				while (true)
				{

					
					try
					{
						//On prend des fruits sur l'arbre 3
						Script s_arbre3 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre3.agit(3, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try{
						//On va lancer des balles sur le mammouth
						Script s_lances0 = (Script)scriptmanager.getScript("ScriptLances");
						s_lances0.agit(0, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try{
						//On va déposer la fresque
						
						Script s_fresque = (Script)scriptmanager.getScript("ScriptFresque");
						s_fresque.agit(2, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
						//On va prendre des fruits dans l'arbre 0
						Script s_arbre0 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre0.agit(0, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
						
						//dans l'arbre 1
						Script s_arbre1 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre1.agit(1, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
						//On va lancer des balles sur l'autre mammouth
						Script s_lances1 = (Script)scriptmanager.getScript("ScriptLances");
						s_lances1.agit(1, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
						//On dépose les fruits
						Script s_depot0 = (Script)scriptmanager.getScript("ScriptDeposerFruits");
						s_depot0.agit(1, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
						//On prend des fruits sur l'arbre 3
						Script s_arbre3 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre3.agit(3, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
						//On prend des fruits sur l'arbre 2
						Script s_arbre2 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre2.agit(2, robotvrai, table, pathfinding, true);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}		
					try
					{
						//On dépose encore des fruits
						Script s_depot1 = (Script)scriptmanager.getScript("ScriptDeposerFruits");
						s_depot1.agit(1, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					/*
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					*/
				}
			}
			else
			{
				//Si la couleur est rouge
				while (true)
				{
					/*
					try{
						//On va lancer des balles sur le mammouth
						Script s_lances1 = (Script)scriptmanager.getScript("ScriptLances");
						s_lances1.agit(0, robotvrai, table, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					*/
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try{
						//On va déposer la fresque
						
						Script s_fresque = (Script)scriptmanager.getScript("ScriptFresque");
						s_fresque.agit(2, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
						//On va prendre des fruits dans l'arbre 0
						Script s_arbre3 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre3.agit(0, robotvrai, table, pathfinding, true);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
						//On va prendre des fruits dans l'arbre 1
						Script s_arbre2 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre2.agit(1, robotvrai, table, pathfinding, true);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					/*
					try
					{
						//On va lancer des balles sur l'autre mammouth
						Script s_lances0 = (Script)scriptmanager.getScript("ScriptLances");
						s_lances0.agit(1, robotvrai, table, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					*/
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
						//On dépose les fruits
						Script s_depot0 = (Script)scriptmanager.getScript("ScriptDeposerFruits");
						s_depot0.agit(1, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					try
					{
						//On prend des fruits sur l'arbre 3
						Script s_arbre3 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre3.agit(3, robotvrai, table, pathfinding, true);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
						//On prend des fruits sur l'arbre 2
						Script s_arbre2 = (Script)scriptmanager.getScript("ScriptTree");
						s_arbre2.agit(2, robotvrai, table, pathfinding, true);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					
					
					
					try
					{
						//On dépose encore des fruits
						Script s_depot1 = (Script)scriptmanager.getScript("ScriptDeposerFruits");
						s_depot1.agit(1, robotvrai, table, pathfinding, false);
					} catch (ScriptException e) {
						e.printStackTrace();
					}
					try
					{
					if(System.currentTimeMillis() - threadtimer.date_debut > threadtimer.duree_match-15000)
					{
						Script s = (Script)scriptmanager.getScript("ScriptFunnyAction");
						s.agit(0, robotvrai, table, pathfinding, false);
					}
					} catch (ScriptException e) {
						e.printStackTrace();
					}
				}
			}
			} catch (Exception e1) {
				e1.printStackTrace();
			}
			
	
	}

}




/*Package prise feu sur torche et dépôt feu
 * 
 * try
 			{
 				//On prend sur une torche
 				Script s = (Script)scriptmanager.getScript("ScriptTorche");
 				s.agit(1, robotvrai, table, true);
			} catch (ScriptException e) {
				e.printStackTrace();
 			}
 * 
 	try
 	{
 		//On dépose un feu si ça a été pris
 		Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
 		s.agit(0, robotvrai, table, true);
	} catch (ScriptException e) {
		e.printStackTrace();
 	}
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */
 