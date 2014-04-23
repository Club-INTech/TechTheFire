package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import exception.SerialException;
import hook.HookGenerator;
import robot.Cote;
import smartMath.Vec2;
import strategie.GameState;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de récupération des feux debouts
 * Pour ceux qui préfèrent séparer les feux dans les torches 
 * @author  krissprolls
 *
 */
public class ScriptFeuDebout extends Script{
	
	
	public ScriptFeuDebout(HookGenerator hookgenerator, Read_Ini config, Log log)
	{
		super(hookgenerator, config, log);
	}
	@Override 
	public  ArrayList<Integer> meta_version(final GameState<?> state)
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
	public ArrayList<Integer> version(GameState<?> state) {
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

	@Override
	public int score(int id_version, GameState<?> state) {
		return 0;
	}


	public int poids(GameState<?> state) {
		// TODO Auto-generated method stub
		return 0;
	}


	protected void execute(int id_version, GameState<?> state)
			throws MouvementImpossibleException {
		if(id_version == 0)
			//Vec2(-1100, 900);
		{
		    state.robot.tourner((float)Math.PI/2);
		}	
		else if(id_version == 1)
			// Vec2(1100,900);
		{
		    state.robot.tourner((float)Math.PI/2);
		}	
		else if(id_version == 2)
			// Vec2(-600, 400);
		{
		    state.robot.tourner((float)Math.PI);
		}	
		else if(id_version == 3)
			// Vec2(600,400);
		{
		    state.robot.tourner((float)Math.PI);
		}	
		else if(id_version == 4)
			// Vec2(-600, 1400);
		{
		    state.robot.tourner((float)Math.PI);
		}	
		else if(id_version == 5)
			// Vec2(600, 1400);
		{
		    state.robot.tourner((float)0);			
		}
		if(!state.robot.isTient_feu(Cote.GAUCHE))
		{
			if(id_version == 2  && id_version == 3 && id_version == 4 && id_version == 5 && id_version == 10 && id_version == 11)
			{
				//Pour les feux à pousser
				
				try {
				    state.robot.milieu_pince(Cote.GAUCHE);
				    state.robot.avancer(10);
				    state.robot.avancer(-10);
				    state.robot.baisser_pince(Cote.GAUCHE);
				    state.robot.ouvrir_pince(Cote.GAUCHE);
				    state.robot.avancer(10);
				    state.robot.fermer_pince(Cote.GAUCHE);
				    state.robot.avancer(-10);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
			
			
			}
		
		else if(state.robot.isFeu_tenu_rouge(Cote.DROIT))
		{
			
		    // TODO: cette condition est impossible à réaliser. Clément le sait-il?
			if(id_version == 2  && id_version == 3 && id_version == 4 && id_version == 5 && id_version == 10 && id_version == 11)
			{
				try {
				
				    state.robot.milieu_pince(Cote.DROIT);
				    state.robot.avancer(10);
				    state.robot.avancer(-10);
				    state.robot.baisser_pince(Cote.DROIT);
				    state.robot.ouvrir_pince(Cote.DROIT);
				    state.robot.avancer(10);
				    state.robot.fermer_pince(Cote.DROIT);
				    state.robot.avancer(-10);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
			}
			}
		}
	}

	protected void termine(GameState<?> state) {
		try
		{
		    state.robot.lever_pince(Cote.DROIT);
		    state.robot.fermer_pince(Cote.DROIT);
		    state.robot.lever_pince(Cote.GAUCHE);
		    state.robot.fermer_pince(Cote.GAUCHE);
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
