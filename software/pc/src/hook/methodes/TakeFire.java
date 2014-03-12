package hook.methodes;

import robot.Cote;
import robot.Robot;
import hook.Executable;

/**
 * Classe implémentant la méthode de récupération de feu dès qu'on en détecte un
 * @author pf
 *
 */

public class TakeFire implements Executable {

	private Robot robot;
	private Cote cote;
	
	public TakeFire(Robot robot, Cote cote)
	{
		this.robot = robot;
		this.cote = cote;
	}

	public void execute() {
		try {
			robot.takefire(cote);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@Override
	public boolean bougeRobot() {
		return true;
	}	

	
}
