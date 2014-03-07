package scripts;

import hook.Callback;
import hook.Executable;
import hook.Hook;
import hook.HookGenerator;
import hook.methodes.TirerBalles;

import java.util.ArrayList;

import pathfinding.Pathfinding;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;
import exception.MouvementImpossibleException;

/**
 * Script pour les lances
 * @author pf
 *
 */

public class ScriptLances extends Script {
	

	public ScriptLances(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	/*
	 * Le script lance 4 balles sur le c��t�� droit
	 * Le script donne un point d'entr��e
	 */
	

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		// En fait, si j'ai bien compris, les versions repr���sentent en fait
		// le nombre de lances pouvant ���tre lanc���es, dans la limite de 4.
		// J'ai bon ?
		// EDIT : Bon ben en fait non, j'ai l'impression qu'ici les versions ne servent à rien.
		if (robot.getNbrLances() > 0) {
			versionList.add(0);
			versionList.add(1);
		}
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		// Les points d'entr��es ne sont pas sym��triques car le lanceur n'est que d'un seul c��t��
		if(couleur == "jaune")
			return new Vec2(-400,1400);
		else
			return new Vec2(-1200,1400);
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
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException
	{
		// TODO: tester!
		
		robot.tourner((float)Math.PI, true);

		ArrayList<Hook> hooks = new ArrayList<Hook>();
		Executable tirerballes = new TirerBalles(robot);
		
		// Hook pour la 1ere balle
		Hook hook1 = hookgenerator.hook_abscisse(950);
		hook1.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook1);
		
		// Hook pour la 2e balle
		Hook hook2 = hookgenerator.hook_abscisse(850);
		hook2.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook2);
		
		// Hook pour la 3e balle
		Hook hook3 = hookgenerator.hook_abscisse(750);
		hook3.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook3);
		
		robot.set_vitesse_translation("vitesse_mammouth");
		robot.avancer(800, hooks);
	}

	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// vide
	}
	
	public String toString()
	{
		return "ScriptLances";
	}

}
