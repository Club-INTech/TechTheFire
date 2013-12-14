package robot.cartes;

import utils.Log;
import utils.Read_Ini;
import container.Service;

public class FiltrageLaser implements Service {

	private Log log;
	private Read_Ini config;

	private float dt = (float)0.2;
	
	public FiltrageLaser(Read_Ini config, Log log)
	{
		this.log = log;
		this.config = config;
		
	}
	
	
	
}
