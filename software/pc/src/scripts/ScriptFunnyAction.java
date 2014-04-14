package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import exception.SerialException;
import hook.HookGenerator;
import pathfinding.Pathfinding;
import robot.Cote;
import robot.PositionRateau;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import threads.ThreadTimer;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de la funny action (se met juste en position)
 * @author pf, krissprolls, rasbeguy
 *
 */

public class ScriptFunnyAction extends Script {

	private ThreadTimer threadtimer;
	
	public ScriptFunnyAction(HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai, ThreadTimer threadtimer) {
		super(hookgenerator, config, log, robotvrai);
		this.threadtimer = threadtimer;
	}
	@Override 
	public  ArrayList<Integer> meta_version(final Robot robot, final Table table, Pathfinding pathfinding)
	{
		ArrayList<Integer> metaversionList = new ArrayList<Integer>();
		metaversionList.add(0);
		return metaversionList;
	}
	@Override
	public  ArrayList<Integer> version_asso(int id_meta)
	{
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		if(id_meta == 0)
			versionList.add(0);
		return versionList;
	}
	@Override
	public ArrayList<Integer> version(Robot robot, Table table, Pathfinding pathfinding) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(0);
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		return new Vec2(800,1300); 
	}

	@Override
	public int score(int id_version, Robot robot, Table table) {
		// Point si ça marche
		return 6;
	}

	@Override
	public int poids(Robot robot, Table table) {
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table, Pathfinding pathfinding)
			throws MouvementImpossibleException, SerialException {
		robot.tourner_sans_symetrie((float)(-1 * Math.PI/2));	// pas de symétrie
		robot.rateau(PositionRateau.BAS, Cote.DROIT);
		robot.sleep(threadtimer.temps_restant());
		robot.sleep(1500);
		robot.lancerFilet();
	}

	@Override
	public float proba_reussite()
	{
		return 1;
	}

	@Override
	protected void termine(Robot robot, Table table, Pathfinding pathfinding) {
		// rien à faire, la partie est finie et rien n'est dérangé.
		
	}

}
