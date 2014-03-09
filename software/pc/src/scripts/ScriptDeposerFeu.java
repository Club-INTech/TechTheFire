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
		if(robot.isTient_feu_droite() || robot.isTient_feu_gauche())
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
		if(robot.isTient_feu_droite() && robot.isTient_feu_gauche())
			return 4;
		else if(robot.isTient_feu_droite() || robot.isTient_feu_gauche())
			return 2;
		return 0;		
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException, SerialException
	{
		//Suivant là où on va poser, on doit se positionner différemment
		if (id_version == 0)
			robot.tourner((float)(Math.PI+Math.atan(2/3)));
		else if(id_version == 1)
			robot.tourner((float)(-Math.atan(2/3)));
		else if(id_version == 2)
			robot.tourner((float)(-Math.PI));
		else if(id_version == 3)
			robot.tourner((float)(Math.atan(2/3)));
		else if(id_version == 4)
			robot.tourner((float)(Math.PI-Math.atan(2/3)));

		if(robot.isTient_feu_gauche())
		{
			if(robot.isFeu_tenu_gauche_rouge() ^ couleur == "rouge")
				robot.poserFeuEnRetournantGauche();
			else
				robot.poserFeuBonCoteGauche();
		}
		
		if(robot.isTient_feu_droite())
		{
			if(robot.isFeu_tenu_gauche_rouge() ^ couleur == "rouge")
				robot.poserFeuEnRetournantDroit();
			else
				robot.poserFeuBonCoteDroit();
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
