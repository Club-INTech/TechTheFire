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
 * Script de dépose de fruits
 * @author pf, raspbeguy, krissprolls 
 *
 */

public class ScriptDeposerFruits extends Script {

	public ScriptDeposerFruits(Pathfinding pathfinding,
			HookGenerator hookgenerator, Read_Ini config, Log log,
			RobotVrai robotvrai) {
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(Robot robot, Table table) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		if (robot.get_nombre_fruits_bac() >0)
		{
			versionList.add(0);
			versionList.add(1);
		}		
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		return new Vec2(-600-300*id, 1300);
	}

	@Override
	public int score(int id_version, Robot robot, Table table) {
		return robot.get_nombre_fruits_bac();
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	protected void execute(int id_version, Robot robot, Table table)
			throws MouvementImpossibleException, SerialException {
		robot.tourner((float)-Math.PI/2);
		robot.avancer(-160);
		robot.bac_haut();	// histoire d'être sûr qu'il y arrive bien
		robot.bac_haut();
		robot.bac_haut();
		robot.sleep(500);
		robot.avancer(50);
		robot.bac_bas();
	}
	@Override
	protected void termine(Robot robot, Table table) {
		try {
			robot.bac_bas();
		} catch (SerialException e) {
			e.printStackTrace();
		}
	}
	@Override
	public float proba_reussite()
	{
		return 1;
	}

	public String toString()
	{
		return "ScriptDeposerFruits";
	}
}
