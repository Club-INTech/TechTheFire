package hook.methodes;

import enums.Cote;
import robot.RobotVrai;
import hook.Executable;

/**
 * Classe implémentant la méthode de récupération de feu dès qu'on en détecte un
 * @author pf
 *
 */

public class TakeFire implements Executable {

	private RobotVrai robot;
	private Cote coteReel, cotePrise;
	
	public TakeFire(RobotVrai robot)
	{
		this.robot = robot;
	}

	@Override
	public boolean execute() {
		try {
			robot.takefire(cotePrise, coteReel);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return true; // le robot doit repartir
	}

	public void setColour(Cote cotePrise, Cote coteReel)
	{
        this.cotePrise = cotePrise;
        this.coteReel = coteReel;
	}
	
}
