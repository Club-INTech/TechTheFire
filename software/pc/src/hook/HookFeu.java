package hook;

import robot.cartes.Capteur;
import smartMath.Vec2;
import utils.Log;
import utils.Read_Ini;

/**
 * Classe des hook de capteur de feu, qui hérite de la classe hook
 * @author pf
 *
 */

class HookFeu extends Hook {

	private Capteur capteur;
	
	public HookFeu(Read_Ini config, Log log, Capteur capteur)
	{
		super(config, log);
		this.capteur = capteur;
	}
	
	public void evaluate(Vec2 positionRobot)
	{
		if(capteur.isThereFire())
			declencher();
	}
	
}
