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
		if(robot.isFresquesPosees())
			return versionList;
		versionList.add(0);
		versionList.add(1);
		versionList.add(2);
		return versionList;
	}

	@Override
	protected Vec2 point_entree(int id) {
		return new Vec2(-150+id*150, 1700);
	}

	@Override
	public int score(int id_version, final Robot robot, final Table table) {
		return 6;
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
		robot.tourner((float)-Math.PI/2);
		robot.avancer(-300, false, true);
		robot.deposer_fresques();
		robot.avancer(300);
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
