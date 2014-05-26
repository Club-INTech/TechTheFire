//import hook.sortes.HookGenerator;

import java.io.BufferedReader;
import java.io.InputStreamReader;

//import robot.RobotChrono;
import robot.RobotVrai;
import robot.cartes.Capteurs;
import strategie.GameState;
import strategie.Strategie;
//import sun.rmi.runtime.Log;
//import threads.ThreadTimer;
import utils.Read_Ini;
import container.Container;


/*
 * TODO pour le lanceur final:
 * - ne pas oublier container.destructeur();
 *
 */
		
public class lanceur
{
	public static void main(String[] args) throws Exception
	{
		
		Container container = new Container();
		Read_Ini config = (Read_Ini) container.getService("Read_Ini");

		@SuppressWarnings("unchecked")
		GameState<RobotVrai> real_state = (GameState<RobotVrai>) container.getService("RealGameState");
		Strategie strategie = (Strategie) container.getService("Strategie");
		
		real_state.robot.initialiser_actionneurs_deplacements();
		real_state.robot.recaler();
      
		//DeplacementsHautNiveau deplacements = (DeplacementsHautNiveau)container.getService("DeplacementsHautNiveau");
		
		//Normalement fait par boucle_strategie()
		// Pas de capteurs avant le recalage
		Capteurs capteurs = (Capteurs) container.getService("Capteur");
		config.set("capteurs_on", false);
		capteurs.maj_config();
			
			/*On aura 3 inputs 
			Le premier pour la couleur du robot avec 0 pour jaune et 1 pour rouge
			Le deuxième pour les arbres 0 et 3 (on donne pour 0 et pour le 3 ça sera calculé facilement)
			Le troisième pour les arbres 1 et 2 (one donne pour 1 et pour les 2 ça sera calculé facilement) 
			La position des fruits dans un arbre est expliqué dans la classe Tree
			*/			
			
			//--------------------------------------------------------------
			//Début des paramétrages
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
			real_state.robot.maj_config();
									
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
			
			 /*while(!capteurs.demarrage_match())
					 Sleep.sleep(100);*/
			container.demarreTousThreads();
			strategie.boucle_strategie();
			//Le match s'arrête
			container.destructeur();
	}
}