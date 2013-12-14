package scripts;

import hook.HookGenerator;

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
	 * Le script lance 4 balles sur le côté droit
	 * Le script donne un point d'entrée
	 */
	

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		/*
		 * De 0 à 2 versions possibles
		 */
		return null;
	}

	@Override
	public Vec2 point_entree(int id, final Robot robot, final Table table) {
		// A modifier, la position devant le mammouth
		return new Vec2(0,0);
	}

	@Override
	public int score(int id_version, final Robot robot, final Table table) {
		// combien on gagne? demander à la table
		return 0;
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
		// à réfléchir (côté droit ou gauche)
		robot.tirerBalles(true);
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// vide
	}
	
}
