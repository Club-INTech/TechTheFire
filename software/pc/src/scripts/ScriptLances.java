package scripts;

import hook.HookGenerator;

import java.util.ArrayList;

import pathfinding.Pathfinding;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;
import exception.MouvementImpossibleException;
import exception.SerialException;

/**
 * Script pour les lances
 * @author pf
 *
 */

public class ScriptLances extends Script {
	

	public ScriptLances(HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(hookgenerator, config, log, robotvrai);
	}
	@Override 
	public  ArrayList<Integer> meta_version(final Robot robot, final Table table, Pathfinding pathfinding)
	{
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		if(robot.getNbrLances() > 0)
		{
			versionList.add(0);
			versionList.add(1);
		}
		return versionList;
	}

	/*
	 * Le script lance 3 balles sur le c��t�� droit
	 * Le script donne un point d'entr��e
	 */
	@Override
	public  ArrayList<Integer> version_asso(int id_meta)
	{
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(id_meta);
		return versionList;
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table, Pathfinding pathfinding) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		if  (robot.getNbrLances() > 0){
			versionList.add(0);
			versionList.add(1);
		}
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		// Les points d'entrée ne sont pas symétriques car le lanceur n'est que d'un seul c��t��
		//if(couleur == "jaune")
		if(id == 0)
			//return new Vec2(400,1400);
			return new Vec2(750,1400);
		else
			//return new Vec2(-1200,1400);
			return new Vec2(-750,1400);
	}

	@Override
	public int score(int id_version, final Robot robot, final Table table) {
		return robot.getNbrLances()*2;
	}

	@Override
	public int poids(final Robot robot, final Table table) {
		// On s'en fout pour le moment
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table, Pathfinding pathfinding) throws MouvementImpossibleException
	{
		// TODO: tester!
		/*
		int a1,a2,a3;
		
		
		//robot.tourner(0, true);
		robot.tourner((float)(Math.PI), true);
		ArrayList<Hook> hooks = new ArrayList<Hook>();
		Executable tirerballes = new TirerBalles(robot);
		if(id_version ==  0)
		{
			//Il faut toujours que a1<a2<a3 car sinon, on recule et on risque de ne pas voir le robot adverse
			//a1 = 950;
			a1 = 650;
			a2 = 750;
			// a3 = 750;
			a3 = 850;
		}
		else
		{
			// a1 = -650;
			a1 = -850;
			a2 = -750;
			// a3 = -850;
			a3 = -650;
		}
		// Hook pour la 1ere balle
		Hook hook1 = hookgenerator.hook_abscisse(a1);
		hook1.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook1);
		
		// Hook pour la 2e balle
		Hook hook2 = hookgenerator.hook_abscisse(a2);
		hook2.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook2);
		
		// Hook pour la 3e balle
		Hook hook3 = hookgenerator.hook_abscisse(a3);
		hook3.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook3);
		*/
		robot.tourner_sans_symetrie((float)(Math.PI));
			try {
				//Abadon des hooks, on fait donc tout à la main
				robot.tirerBalle();
				robot.sleep(800);
				robot.tirerBalle();
				robot.sleep(800);
				robot.tirerBalle();
				robot.sleep(1500);
			} catch (SerialException e) {
				e.printStackTrace();
			}
		//robot.set_vitesse_translation("vitesse_mammouth");
		//robot.avancer(600, hooks);
		
	}

	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}

	@Override
	protected void termine(Robot robot, Table table, Pathfinding pathfinding) {
		// vide car rien qui gène
	}
	
	public String toString()
	{
		return "ScriptLances";
	}

}
