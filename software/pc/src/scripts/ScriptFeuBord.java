
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
 * Script de récupération de feux sur les torches mobiles et les feux debout
 * @author krissprolls
 *
 */


public class ScriptFeuBord extends Script {

	public ScriptFeuBord(HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
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
		return metaversionList;
	}
	@Override
	public  ArrayList<Integer> version_asso(int id_meta)
	{
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(id_meta);
		return versionList;
	}
	@Override
	public ArrayList<Integer> version(Robot robot, Table table, Pathfinding pathfinding) {
		// TODO
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		//Les feux dans les torches
		//Ajouter une condition sur la présence de feux dans les torches
		//Ca va nécessiter de créer d'autres versions encore
		versionList.add(0);
		versionList.add(1);
		//Les feux verticaux
		//Ajouter une condition pour chaque feu pour savoir s'il est toujours là ?
		versionList.add(2);
		versionList.add(3);
		return versionList;
	}
	
	@Override
	public Vec2 point_entree(int id) {
		//Les coordonnées ont été prises à partir du réglement
		if(id ==0)
			return new Vec2(-1200,1000);
		else if(id ==1)
			return new Vec2(1200, 1000);
		
		else if(id ==2)
			return new Vec2(-200, 200);
		else if(id ==3)
			return new Vec2(200, 200);
		else
			return null;		
	}
	@Override
	public int score(int id_version, Robot robot, Table table) {
		return 0;
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table, Pathfinding pathfinding)
			throws MouvementImpossibleException, SerialException {
		if(id_version ==0)
			// Vec2(-1500,1200);
		{
			robot.tourner((float)Math.PI);
		}	
		else if(id_version ==1)
			// Vec2(1500, 1200);
		{
			robot.tourner(0);
		}	
		else if(id_version ==2||id_version ==3)
			// Vec2(-200, 0);
			// Vec2(200, 0);
		{
			robot.tourner((float)(-Math.PI/2));
		}	
		
		if(!robot.isTient_feu(Cote.GAUCHE))
		{
			
			
			
				//Pour les feux à tirer
				try {
				robot.milieu_pince(Cote.GAUCHE);
				robot.ouvrir_pince(Cote.GAUCHE);
				robot.avancer(10);
				robot.fermer_pince(Cote.GAUCHE);
				robot.avancer(-10);
				robot.ouvrir_pince(Cote.GAUCHE);
				robot.baisser_pince(Cote.GAUCHE);
				robot.avancer(5);
				robot.fermer_pince(Cote.GAUCHE);
				robot.lever_pince(Cote.GAUCHE);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			
		}
		else if(robot.isFeu_tenu_rouge(Cote.DROIT))
		{
				try {
				robot.milieu_pince(Cote.DROIT);
				robot.ouvrir_pince(Cote.DROIT);
				robot.avancer(10);
				robot.fermer_pince(Cote.DROIT);
				robot.avancer(-10);
				robot.ouvrir_pince(Cote.DROIT);
				robot.baisser_pince(Cote.DROIT);
				robot.avancer(5);
				robot.fermer_pince(Cote.DROIT);
				robot.lever_pince(Cote.DROIT);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			
		}
	}

	@Override
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

	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}

	public String toString()
	{
		return "ScriptFeuBord";
	}
	
	public void maj_config()
	{
	}
}
