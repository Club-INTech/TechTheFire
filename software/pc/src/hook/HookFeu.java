package hook;

import robot.Cote;
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
	Cote cote;
	
	public HookFeu(Read_Ini config, Log log, Capteurs capteur, Cote cote)
	{
		super(config, log);
		this.capteur = capteur;
		this.cote = cote;
	}
	
	public boolean evaluate(final Robot robot)
	{
		// si on tient déjà un feu de ce côté...
		if(robot.isTient_feu(cote))
			return false;
		
		// on regarde à gauche ou à droite selon la valeur de "gauche"
		if(cote == Cote.GAUCHE && capteur.isThereFireGauche() || cote == Cote.DROIT && capteur.isThereFireDroit())
		{
			if(cote == Cote.GAUCHE)
				log.warning("Un feu a été détecté à gauche! Il est pris.", this);
			else
				log.warning("Un feu a été détecté à droite! Il est pris.", this);
			return declencher();
		}
		return false;
	}
	
}
