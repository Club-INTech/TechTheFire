package hook.methodes;

import robot.Robot;
import hook.Executable;

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
