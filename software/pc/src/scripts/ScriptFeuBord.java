
package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import exception.SerialException;
import hook.HookGenerator;
import robot.Cote;
import smartMath.Vec2;
import strategie.GameState;
import table.Colour;
import table.Fire;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de récupération de feux sur les torches mobiles et les feux debout
 * @author krissprolls
 *
 */


public class ScriptFeuBord extends Script {

	public ScriptFeuBord(HookGenerator hookgenerator, Read_Ini config, Log log)
	{
		super(hookgenerator, config, log);
	}
	@Override 
	public  ArrayList<Integer> meta_version(final GameState<?> state)
	{
		ArrayList<Integer> metaversionList = new ArrayList<Integer>();
		// TODO
		if(!(state.robot.isTient_feu(Cote.DROIT)||state.robot.isTient_feu(Cote.GAUCHE)))
		{
			if (state.table.isTakenFixedFire(0))
				metaversionList.add(0);
			if (state.table.isTakenFixedFire(3))
				metaversionList.add(1);
			if (state.table.isTakenFixedFire(2))
				metaversionList.add(2);
			if (state.table.isTakenFixedFire(1))
				metaversionList.add(3);
		}
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
	public ArrayList<Integer> version(GameState<?> state) {
		// TODO
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		/*
		 * arrayFixedFire[0] = new Fire(new Vec2(1485,1200), 0, 0, Colour.YELLOW);
		arrayFixedFire[1] = new Fire(new Vec2(200,15), 7, 0, Colour.YELLOW);
		arrayFixedFire[2] = new Fire(new Vec2(-200,15), 8, 0, Colour.RED);
		arrayFixedFire[3] = new Fire(new Vec2(-1485,1200), 15, 0, Colour.YELLOW);
		
		 */
		if(!(state.robot.isTient_feu(Cote.DROIT)||state.robot.isTient_feu(Cote.GAUCHE)))
		{
			if (state.table.isTakenFixedFire(0))
				versionList.add(0);
			if (state.table.isTakenFixedFire(3))
				versionList.add(1);
			//Les feux verticaux
			//Ajouter une condition pour chaque feu pour savoir s'il est toujours là ?
			if (state.table.isTakenFixedFire(2))
				versionList.add(2);
			if (state.table.isTakenFixedFire(1))
				versionList.add(3);
		}
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
	public int score(int id_version, GameState<?> state) {
		return 0;
	}

	@Override
	public int poids(GameState<?> state) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, GameState<?> state)
			throws MouvementImpossibleException, SerialException {
		if(id_version ==0)
			// Vec2(-1500,1200);
		    state.robot.tourner((float)Math.PI);

		else if(id_version ==1)
			// Vec2(1500, 1200);
		    state.robot.tourner(0);

		else if(id_version ==2||id_version ==3)
			// Vec2(-200, 0);
			// Vec2(200, 0);
		    state.robot.tourner((float)(-Math.PI/2));

		
		if(!state.robot.isTient_feu(Cote.GAUCHE))
		{
				//Pour les feux à tirer
				try {
				state.robot.milieu_pince(Cote.GAUCHE);
				state.robot.ouvrir_pince(Cote.GAUCHE);
				state.robot.avancer(10);
				state.robot.fermer_pince(Cote.GAUCHE);
				state.robot.avancer(-10);
				state.robot.ouvrir_pince(Cote.GAUCHE);
				state.robot.baisser_pince(Cote.GAUCHE);
				state.robot.avancer(5);
				state.robot.fermer_pince(Cote.GAUCHE);
				state.robot.lever_pince(Cote.GAUCHE);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			
		}
		else if(state.robot.isTient_feu(Cote.DROIT))
		{
				try {
				    state.robot.milieu_pince(Cote.DROIT);
				    state.robot.ouvrir_pince(Cote.DROIT);
				    state.robot.avancer(10);
				    state.robot.fermer_pince(Cote.DROIT);
				    state.robot.avancer(-10);
				    state.robot.ouvrir_pince(Cote.DROIT);
				    state.robot.baisser_pince(Cote.DROIT);
				    state.robot.avancer(5);
				    state.robot.fermer_pince(Cote.DROIT);
				    state.robot.lever_pince(Cote.DROIT);
				} catch (SerialException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			
		}
		//Et oui, il faut parler à la stratégie !!! GNNNNN
		state.table.pickFixedFire(id_version);
	}

	@Override
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
