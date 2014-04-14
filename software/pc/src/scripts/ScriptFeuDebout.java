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
 * Script de récupération des feux debouts
 * Pour ceux qui préfèrent séparer les feux dans les torches 
 * @author  krissprolls
 *
 */
public class ScriptFeuDebout extends Script{
	
	
	public ScriptFeuDebout(HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(hookgenerator, config, log, robotvrai);
	}
	@Override 
	public  ArrayList<Integer> meta_version(final Robot robot, final Table table, Pathfinding pathfinding)
	{
		ArrayList<Integer> metaversionList = new ArrayList<Integer>();
		metaversionList.add(0);
		metaversionList.add(1);
		metaversionList.add(2);
		metaversionList.add(3);
		metaversionList.add(4);
		metaversionList.add(5);
		return metaversionList;
	}
	@Override
	public  ArrayList<Integer> version_asso(int id_meta)
	{
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(id_meta);
		return versionList;
	}
	public ArrayList<Integer> version(Robot robot, Table table, Pathfinding pathfinding) {
		// TODO
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		//Les feux verticaux
		//Ajouter une condition pour chaque feu pour savoir s'il est toujours là ?
		versionList.add(0);
		versionList.add(1);
		versionList.add(2);
		versionList.add(3);
		versionList.add(4);
		versionList.add(5);
		return versionList;
	}
	
	public Vec2 point_entree(int id) {
		//Les coordonnées ont été prises à partir du réglement
		
		if(id ==0)
			return new Vec2(-1100, 700);
		else if(id ==1)
			return new Vec2(1100,700);
		else if(id ==2)
			return new Vec2(-400, 400);
		else if(id ==3)
			return new Vec2(400,400);
		else if(id ==4)
			return new Vec2(-400, 1400);
		else if(id ==5)
			return new Vec2(400, 1400);
		else
			return null;		
	}


	public int score(int id_version, Robot robot, Table table) {
		return 0;
	}


	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}


	protected void execute(int id_version, Robot robot, Table table, Pathfinding pathfinding)
			throws MouvementImpossibleException {
		if(id_version == 0)
			//Vec2(-1100, 900);
		{
			robot.tourner((float)Math.PI/2);
		}	
		else if(id_version == 1)
			// Vec2(1100,900);
		{
			robot.tourner((float)Math.PI/2);
		}	
		else if(id_version == 2)
			// Vec2(-600, 400);
		{
			robot.tourner((float)Math.PI);
		}	
		else if(id_version == 3)
			// Vec2(600,400);
		{
			robot.tourner((float)Math.PI);
		}	
		else if(id_version == 4)
			// Vec2(-600, 1400);
		{
			robot.tourner((float)Math.PI);
		}	
		else if(id_version == 5)
			// Vec2(600, 1400);
		{
			robot.tourner((float)0);			
		}
		if(!robot.isTient_feu(Cote.GAUCHE))
		{
			if(id_version == 2  && id_version == 3 && id_version == 4 && id_version == 5 && id_version == 10 && id_version == 11)
			{
				//Pour les feux à pousser
				
				try {
				robot.milieu_pince(Cote.GAUCHE);
				robot.avancer(10);
				robot.avancer(-10);
				robot.baisser_pince(Cote.GAUCHE);
				robot.ouvrir_pince(Cote.GAUCHE);
				robot.avancer(10);
				robot.fermer_pince(Cote.GAUCHE);
				robot.avancer(-10);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
			
			
			}
		
		else if(robot.isFeu_tenu_rouge(Cote.DROIT))
		{
			
			if(id_version == 2  && id_version == 3 && id_version == 4 && id_version == 5 && id_version == 10 && id_version == 11)
			{
				try {
				
				robot.milieu_pince(Cote.DROIT);
				robot.avancer(10);
				robot.avancer(-10);
				robot.baisser_pince(Cote.DROIT);
				robot.ouvrir_pince(Cote.DROIT);
				robot.avancer(10);
				robot.fermer_pince(Cote.DROIT);
				robot.avancer(-10);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
			}
			}
		}
	}

	protected void termine(Robot robot, Table table, Pathfinding pathfinding) {
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

	public float proba_reussite()
	{
		// TODO
		return 1;
	}

	public String toString()
	{
		return "ScriptFeuDebout";
	}
	
	public void maj_config()
	{
	}

}
