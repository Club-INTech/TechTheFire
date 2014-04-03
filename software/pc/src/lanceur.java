import hook.HookGenerator;

import org.junit.Assert;
import org.junit.runner.JUnitCore;

import container.Container;
import exception.ContainerException;
import robot.RobotChrono;
import robot.RobotVrai;
import scripts.Script;
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
		config.set("couleur", "jaune");
		robotchrono.majRobotChrono(robotvrai);
		Table table = (Table)container.getService("Table");
		HookGenerator hookgenerator = (HookGenerator)container.getService("HookGenerator");
		robotvrai.setPosition(new Vec2(1300, 1200));
		robotvrai.setOrientation((float)(Math.PI));
		robotvrai.set_vitesse_rotation("entre_scripts");
		robotvrai.set_vitesse_translation("entre_scripts");
		container.getService("threadPosition");
		container.demarreThreads();
		//robotvrai.set_vitesse_translation("30");
		

		while(!threadtimer.match_demarre)
		{
			Thread.sleep(100);
		}
		
			
		//Le dégager
		robotvrai.avancer(100);
		//robotvrai.tourner((float)(-Math.PI/2-Math.PI/6));
		//robotvrai.avancer(100);
		while (true)
		{
			try{
				//On va lancer des balles sur le mammouth
				Script s_lances0 = (Script)scriptmanager.getScript("ScriptLances");
				//robotvrai.va_au_point(s_lances0.point_entree(0), true);
				//robotvrai.setOrientation((float)(Math.PI));
				s_lances0.agit(0, robotvrai, table, false);
			}
			
			finally{}
			try{
				//On va déposer la fresque
				
				Script s_fresque = (Script)scriptmanager.getScript("ScriptFresque");
				//robotvrai.va_au_point(s_fresque.point_entree(2), true);
				//robotvrai.setOrientation((float)(Math.PI/2));
				s_fresque.agit(2, robotvrai, table, false);
			}
			finally{}
			try
			{
				//On dépose un feu si ça a été pris
				Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
				s.agit(0, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On va prendre des fruits dans l'arbre 0
				Script s_arbre0 = (Script)scriptmanager.getScript("ScriptTree");
				//robotvrai.va_au_point(s_arbre0.point_entree(0), true);
				//robotvrai.setOrientation((float)0);
				s_arbre0.agit(0, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On va prendre des fruits dans l'arbre 1
				Script s_arbre1 = (Script)scriptmanager.getScript("ScriptTree");
				//robotvrai.va_au_point(s_arbre1.point_entree(1), true);
				//robotvrai.setOrientation((float)(-Math.PI));
				s_arbre1.agit(1, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On dépose un feu si ça a été pris
				Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
				s.agit(1, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On va lancer des balles sur l'autre mammouth
				Script s_lances1 = (Script)scriptmanager.getScript("ScriptLances");
				//robotvrai.va_au_point(s_lances1.point_entree(1), true);
				//robotvrai.setOrientation((float)(Math.PI));
				s_lances1.agit(1, robotvrai, table, false);
			}
			finally{}
			try
			{
				//On dépose les fruits
				Script s_depot0 = (Script)scriptmanager.getScript("ScriptDeposerFruits");
				//robotvrai.va_au_point(s_depot0.point_entree(1), true);
				//robotvrai.setOrientation((float)(Math.PI/2));
				s_depot0.agit(1, robotvrai, table, false);
			}
			finally{}
			try
			{
				//On dépose un feu si ça a été pris
				Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
				s.agit(1, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On prend des fruits sur l'arbre 3
				Script s_arbre3 = (Script)scriptmanager.getScript("ScriptTree");
				//robotvrai.va_au_point(s_arbre3.point_entree(3), true);
				//robotvrai.setOrientation((float)(Math.PI));
				s_arbre3.agit(3, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On prend des fruits sur l'arbre 2
				Script s_arbre2 = (Script)scriptmanager.getScript("ScriptTree");
				//robotvrai.va_au_point(s_arbre2.point_entree(2), true);
				//robotvrai.setOrientation((float)(-Math.PI));
				s_arbre2.agit(2, robotvrai, table, true);
			}
			finally {}
			try
			{
				//On dépose un feu si ça a été pris
				Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
				s.agit(2, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On dépose encore des fruits
				Script s_depot1 = (Script)scriptmanager.getScript("ScriptDeposerFruits");
				//robotvrai.va_au_point(s_depot1.point_entree(1), true);
				//robotvrai.setOrientation((float)(Math.PI/2));
				s_depot1.agit(1, robotvrai, table, false);
			}
			finally{}
			
			try
			{
				//On prend sur une torche
				Script s = (Script)scriptmanager.getScript("ScriptTorche");
				s.agit(0, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On dépose un feu si ça a été pris
				Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
				s.agit(3, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On prend sur une torche
				Script s = (Script)scriptmanager.getScript("ScriptTorche");
				s.agit(1, robotvrai, table, true);
			}
			finally{}
			try
			{
				//On dépose un feu si ça a été pris
				Script s = (Script)scriptmanager.getScript("ScriptDeposerFeu");
				s.agit(4, robotvrai, table, true);
			}
			finally{}
			
		//Enchaîner le scripts à faire en boucle: fait
		//Entourer chaque script d'un try catch sans rien catcher : fait
		}
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}

}
