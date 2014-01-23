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

/**
 * Script de dépose des fresques
 * @author pf
 *
 */

public class ScriptFresque extends Script {
	

	public ScriptFresque(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		// TODO
		return versionList;
	}

	@Override
	protected Vec2 point_entree(int id, final Robot robot, final Table table) {
		// TODO
		return null;
	}

	@Override
	public int score(int id_version, final Robot robot, final Table table) {
		// TODO
		return 0;
	}

	@Override
	public int poids(final Robot robot, final Table table) {
		// TODO
		// On s'en fout pour le moment
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException
	{
		// TODO
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// vide
	}
	
	public String toString()
	{
		return "ScriptFresque";
	}

}
