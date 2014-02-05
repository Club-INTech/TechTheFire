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
 * @author pf
 *
 */

public class ScriptFunnyAction extends Script {

	public ScriptFunnyAction(Pathfinding pathfinding,
			HookGenerator hookgenerator, Read_Ini config, Log log,
			RobotVrai robotvrai) {
		super(pathfinding, hookgenerator, config, log, robotvrai);
		// TODO Auto-generated constructor stub
	}

	@Override
	public ArrayList<Integer> version(Robot robot, Table table) {
		// TODO
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		return versionList;
	}

	@Override
	protected Vec2 point_entree(int id) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int score(int id_version, Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table)
			throws MouvementImpossibleException, SerialException {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// TODO Auto-generated method stub
		
	}

}
