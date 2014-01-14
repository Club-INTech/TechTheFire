package hook.methodes;

import robot.Robot;
import hook.Executable;

/**
 * Classe implémentant la méthode de récupération de feu dès qu'on en détecte un
 * @author pf
 *
 */

public class TakeFire implements Executable {

	private Robot robot;
	
	public TakeFire(Robot robot)
	{
		this.robot = robot;
	}

	public void execute() {
		robot.takefire();
	}

	
}
