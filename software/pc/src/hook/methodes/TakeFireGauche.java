package hook.methodes;

import exception.SerialException;
import robot.Robot;
import hook.Executable;

/**
 * Classe implémentant la méthode de récupération de feu dès qu'on en détecte un
 * @author pf
 *
 */

public class TakeFireGauche implements Executable {

	private Robot robot;
	
	public TakeFireGauche(Robot robot)
	{
		this.robot = robot;
	}

	public void execute() {
		try {
			robot.takefiregauche();
		} catch (SerialException e) {
			e.printStackTrace();
		}
	}

	@Override
	public boolean bougeRobot() {
		return true;
	}	

	
}
