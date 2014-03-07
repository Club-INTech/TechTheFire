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
 * Script de dépose de feu
 * @author pf, krissprolls
 *
 */
public class ScriptDeposerFeu extends Script {

	public ScriptDeposerFeu(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(0);
		versionList.add(1);
		versionList.add(2);
		versionList.add(3);
		versionList.add(4);
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		if (id==0)
		{
			return new Vec2(-1150,233);			
		}
		if(id == 1)
		{
			return new Vec2(1150,233);
		}
		if(id == 2)
		{
			return new Vec2(0, 1470);
		}
		if(id == 3)
		{
			return new Vec2(-391, 739);
		}
		if(id == 4)
		{
			return new Vec2(391, 739);
		}
		return null;
	}

	@Override
	public int score(int id_version, Robot robot, Table table) 
	{
		//En effet, quand on pose un feu 
		try{
		if(robot.isThereFireGauche() && robot.isThereFireDroite())
		{
			return 4;
		}
		else if(robot.isThereFireGauche() && robot.isThereFireDroite())
		{
			return 2;
		}
		else
		{
			return 0;
		}
		}
		catch(SerialException e) {
			e.printStackTrace();
			return 0;
		}
		
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException, SerialException
	{
		//Suivant là où onva poser, on doit se positionner différemment
		if (id_version == 0)
		{
			robot.tourner((float)(Math.PI+Math.atan(2/3)));
		}
		if(id_version == 1)
		{
			robot.tourner((float)(-Math.atan(2/3)));
		}
		if(id_version == 2)
		{
			robot.tourner((float)(-Math.PI));
		}
		if(id_version == 3)
		{
			robot.tourner((float)(Math.atan(2/3)));
		}
		if(id_version == 4)
		{
			robot.tourner((float)(Math.PI-Math.atan(2/3)));
		}
		if((couleur.equals("rouge") && robot.isFireRedGauche())|| couleur.equals("jaune")&& ! robot.isFireRedGauche())
		{
			robot.poserFeuBonCoteGauche();
		}
		else
		{
			robot.poserFeuEnRetournantGauche();
		}
		//On s'occupe de retourner ou non les pinces gauche et droite, de poser le feu et de remonter
		if((couleur.equals("rouge") && robot.isFireRedDroite()) || (couleur.equals("jaune")&& ! robot.isFireRedDroite()))
		{
			robot.poserFeuBonCoteDroit();
		}
		else
		{
			robot.poserFeuEnRetournantDroit();
		}
		robot.avancer(-50);
		
	}

	@Override
	protected void termine(Robot robot, Table table)
	{
		try
		{
			robot.lever_pince_droite();
			robot.fermer_pince_droite();
			robot.lever_pince_gauche();
			robot.fermer_pince_gauche();
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
