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

// TODO Guy

public class ScriptLances extends Script {
	

	public ScriptLances(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	/*
	 * Le script lance 4 balles sur le côté droit
	 * Le script donne un point d'entrée
	 */
	

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		// En fait, si j'ai bien compris, les versions repr�sentent en fait
		// le nombre de lances pouvant �tre lanc�es, dans la limite de 4.
		// J'ai bon ?
		if (robot.getNbrLances() > 0) {
			versionList.add(0);
			versionList.add(1);
		}
		return versionList;
	}

	@Override
	protected Vec2 point_entree(int id, final Robot robot, final Table table) {
		// A modifier, la position devant le mammouth
		// Note � moi-m�me : demander � Ngon� ou Alexandre pour la distance
		return new Vec2(1000,1300);
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
		robot.va_au_point(point_entree(id_version, robot, table));
		// ajuster l'orientation du robot (objet robot)
		robot.tourner(0);
		// tirer (objet robot)
		ArrayList<Hook> hooks = new ArrayList<Hook>();
		Executable tirerballes = new TirerBalles(robot);
		Hook hook = hookgenerator.hook_abscisse(0); // modifier abscisse
		hook.ajouter_callback(new Callback(tirerballes, true));
		hooks.add(hook);
		
		robot.set_vitesse_translation("vitesse_mammouth");
		robot.avancer(50, hooks); // modifier distance
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
