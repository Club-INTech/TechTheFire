package scripts;

import hook.Callback;
import hook.Executable;
import hook.Hook;
import hook.HookGenerator;
import hook.methodes.LeverRateau;
import hook.methodes.TirerBalles;

import java.util.ArrayList;

import pathfinding.Pathfinding;
import robot.Robot;
import smartMath.Vec2;
import table.Table;
import threads.ThreadTimer;
import utils.Log;
import utils.Read_Ini;
import exception.MouvementImpossibleException;

/**
 * Script pour les lances
 * @author pf
 *
 */

// TODO Guy

class ScriptLances extends Script {
	

	public ScriptLances(Pathfinding pathfinding, ThreadTimer threadtimer, HookGenerator hookgenerator, Read_Ini config, Log log)
	{
		super(pathfinding, threadtimer, hookgenerator, config, log);
	}

	/*
	 * Le script lance 4 balles sur le c√¥t√© droit
	 * Le script donne un point d'entr√©e
	 */
	

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		// En fait, si j'ai bien compris, les versions représentent en fait
		// le nombre de lances pouvant être lancées, dans la limite de 4.
		// J'ai bon ?
		if (robot.getNbrLances() > 0) {
			versionList.add(0);
			versionList.add(1);
		}
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id, final Robot robot, final Table table) {
		// A modifier, la position devant le mammouth
		// Note à moi-même : demander à Ngoné ou Alexandre pour la distance
		return new Vec2(0,0);
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
	
}
