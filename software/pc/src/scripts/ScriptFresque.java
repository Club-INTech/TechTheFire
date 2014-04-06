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
import exception.SerialException;

/**
 * Script de dépose des fresques
 * @author pf
 *
 */

public class ScriptFresque extends Script {
	

	public ScriptFresque(HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table, Pathfinding pathfinding) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		if(robot.isFresquesPosees())
			return versionList;
		versionList.add(0);
		versionList.add(1);
		versionList.add(2);
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
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
	protected void execute(int id_version, Robot robot, Table table, Pathfinding pathfinding) throws MouvementImpossibleException, SerialException
	{
		robot.tourner((float)-Math.PI/2);
		robot.bac_bas();
		robot.avancer_dans_mur(-150);
		robot.deposer_fresques();
		robot.avancer(300);
	}

	@Override
	protected void termine(Robot robot, Table table, Pathfinding pathfinding) {
		// vide
	}
	
	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}
	
	public String toString()
	{
		return "ScriptFresque";
	}

	public void maj_config()
	{
		// TODO
	}
}
