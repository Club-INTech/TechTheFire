package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import exception.SerialException;
import hook.HookGenerator;
import pathfinding.Pathfinding;
import robot.Cote;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de dépose de feu
 * @author pf, krissprolls
 *
 */
public class ScriptDeposerFeu extends Script {

	public ScriptDeposerFeu(HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(hookgenerator, config, log, robotvrai);
	}
	@Override 
	public  ArrayList<Integer> meta_version(final Robot robot, final Table table, Pathfinding pathfinding)
	{
		ArrayList<Integer> metaversionList = new ArrayList<Integer>();
		if(robot.isTient_feu(Cote.DROIT) || robot.isTient_feu(Cote.GAUCHE))
		{
			metaversionList.add(0);
			metaversionList.add(1);
			metaversionList.add(2);
		}
		return metaversionList;
	}
	
	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table, Pathfinding pathfinding) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		if(robot.isTient_feu(Cote.DROIT) || robot.isTient_feu(Cote.GAUCHE))
		{
			versionList.add(0);
			versionList.add(1);
			versionList.add(2);
			versionList.add(3);
			versionList.add(4);
		}
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		if(id == 0)
		{
			return new Vec2(-1150,233);			
		}
		else if(id == 1)
		{
			return new Vec2(1150,233);
		}
		else if(id == 2)
		{
			return new Vec2(0, 1270);
		}
		else if(id == 3)
		{
			return new Vec2(-391, 739);
		}
		else if(id == 4)
		{
			return new Vec2(391, 739);
		}
		return null;
	}

	@Override
	public int score(int id_version, Robot robot, Table table) 
	{
		if(robot.isTient_feu(Cote.DROIT) && robot.isTient_feu(Cote.GAUCHE))
			return 4;
		else if(robot.isTient_feu(Cote.DROIT) || robot.isTient_feu(Cote.GAUCHE))
			return 2;
		return 0;		
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table, Pathfinding pathfinding) throws MouvementImpossibleException, SerialException
	{
		//Suivant là où on va poser, on doit se positionner différemment
		if (id_version == 0)
			robot.tourner((float)(Math.PI+Math.atan(2/3)));
		else if(id_version == 1)
			robot.tourner((float)(-Math.atan(2/3)));
		else if(id_version == 2)
			robot.tourner((float)(-Math.PI/2));
		else if(id_version == 3)
			robot.tourner((float)(Math.atan(2/3)));
		else if(id_version == 4)
			robot.tourner((float)(Math.PI-Math.atan(2/3)));

		if(robot.isTient_feu(Cote.GAUCHE))
		{
			if(robot.isFeu_tenu_rouge(Cote.GAUCHE) ^ couleur == "rouge")
				robot.poserFeuEnRetournant(Cote.GAUCHE);
			else
				robot.poserFeuBonCote(Cote.GAUCHE);
		}
		
		if(robot.isTient_feu(Cote.DROIT))
		{
			if(robot.isFeu_tenu_rouge(Cote.DROIT) ^ couleur == "rouge")
				robot.poserFeuEnRetournant(Cote.DROIT);
			else
				robot.poserFeuBonCote(Cote.DROIT);
		}
		
		robot.avancer(-50);
		
	}

	@Override
	protected void termine(Robot robot, Table table, Pathfinding pathfinding)
	{
		try
		{
			robot.lever_pince(Cote.DROIT);
			robot.fermer_pince(Cote.DROIT);
			robot.lever_pince(Cote.GAUCHE);
			robot.fermer_pince(Cote.GAUCHE);
		}
		catch(SerialException e) {
			e.printStackTrace();
		}
	}
	
	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}
	
	public String toString()
	{
		return "ScriptDeposerFeu";
	}

}
