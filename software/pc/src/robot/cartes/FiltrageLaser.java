package robot.cartes;

import smartMath.Mat2;
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
		Mat2 x = new Mat2(1400, 100, 0, 0);	// vecteur d'état au départ
		//Mat2[] P = new 
		
	}
	
	
	
}
