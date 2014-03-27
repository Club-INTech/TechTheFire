import hook.HookGenerator;

import org.junit.Assert;
import org.junit.runner.JUnitCore;

import container.Container;
import exception.ContainerException;
import robot.RobotChrono;
import robot.RobotVrai;
import scripts.ScriptManager;
import smartMath.Vec2;
import table.Table;
import threads.ThreadTimer;
import utils.Log;
import utils.Read_Ini;

		
public class lanceur
{
	
	private static Test test = new Test();
	
	public static void main(String[] args)
	{
		Container container;
		try {
			container = new Container();
			Read_Ini config = (Read_Ini) container.getService("Read_Ini");
			Log log = (Log) container.getService("Log");

		ThreadTimer threadtimer = (ThreadTimer) container.getService("threadTimer");
		// compléter avec: vitesse, position, ...
		ScriptManager scriptmanager = (ScriptManager)container.getService("ScriptManager");
		RobotVrai robotvrai = (RobotVrai)container.getService("RobotVrai");
		RobotChrono robotchrono = new RobotChrono(config, log);
		robotchrono.majRobotChrono(robotvrai);
		Table table = (Table)container.getService("Table");
		HookGenerator hookgenerator = (HookGenerator)container.getService("HookGenerator");
		robotvrai.setPosition(new Vec2(1300, 1200));
		robotvrai.setOrientation((float)Math.PI);
		robotvrai.set_vitesse_rotation("entre_scripts");
		robotvrai.set_vitesse_translation("entre_scripts");
		container.getService("threadPosition");
		container.demarreThreads();
		robotvrai.set_vitesse_translation("30");
		

		while(!threadtimer.match_demarre)
			Thread.sleep(100);
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		//Le dégager
		//Enchaîner le scripts à faire en boucle
		//Entourer chaque script d'un try catch sans rien catcher
		
		
	}

}
