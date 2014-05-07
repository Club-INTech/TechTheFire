import java.io.BufferedReader;
import java.io.InputStreamReader;

import pathfinding.Pathfinding;
import container.Container;
import exceptions.strategie.ScriptException;
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
			

			//Table
			Table table = (Table)container.getService("Table");
//			Pathfinding pathfinding = new Pathfinding(table, config, log);
//			pathfinding.setPrecision(2);
			
			// Etat intial du robot
			robotvrai.setPosition(new Vec2(1100, 1500));
			//robotvrai.setPosition(new Vec2(1251, 1695));
			robotvrai.setOrientation((float)(Math.PI));
			robotvrai.set_vitesse_rotation("entre_scripts");
			robotvrai.set_vitesse_translation("entre_scripts");
			
			// DEmare les threads
			container.demarreTousThreads();
//			robotvrai.avancer(2000);
		}
		catch(Exception e)
		{
		    e.printStackTrace();
		}
	}
	
}