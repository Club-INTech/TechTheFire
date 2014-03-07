package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import exception.SerialException;
import hook.HookGenerator;
import pathfinding.Pathfinding;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de la funny action (se met juste en position)
 * @author pf, krissprolls, rasbeguy
 *
 */

public class ScriptFunnyAction extends Script {

	public ScriptFunnyAction(Pathfinding pathfinding,
			HookGenerator hookgenerator, Read_Ini config, Log log,
			RobotVrai robotvrai) {
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(Robot robot, Table table) {
		// TODO
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(0);
		//0 c'est devant le mammouth de droitz
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		return new Vec2(700,1300 );
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
	protected void execute(int id_version, Robot robot, Table table)
			throws MouvementImpossibleException, SerialException {
		robot.tourner((float)(Math.PI));
		robot.lancerFilet();
	}

	@Override
	public float proba_reussite()
	{
		return 1;
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// rien à faire, la partie est finie et rien n'est dérangé.
		
	}

}
