package hook;

import robot.Robot;
import robot.cartes.Capteur;
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
	
	public void evaluate(final Robot robot)
	{
		if(capteur.isThereFire())
			declencher();
	}
	
}
