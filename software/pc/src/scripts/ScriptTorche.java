package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import hook.HookGenerator;
import pathfinding.Pathfinding;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de récupération de feux sur les torches mobiles et les feux debout
 * @author pf
 *
 */
public class ScriptTorche extends Script {

	public ScriptTorche(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	protected Vec2 point_entree(int id, Robot robot, Table table) {
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
			throws MouvementImpossibleException {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// TODO Auto-generated method stub
		
	}

	public String toString()
	{
		return "ScriptTorche";
	}
	
}
