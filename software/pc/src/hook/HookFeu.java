package hook;

import robot.Robot;
import robot.cartes.Capteurs;
import utils.Log;
import utils.Read_Ini;

/**
 * Classe des hook de capteur de feu, qui hérite de la classe hook
 * @author pf
 *
 */

class HookFeu extends Hook {

	private Capteurs capteur;
	
	public HookFeu(Read_Ini config, Log log, Capteurs capteur)
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
