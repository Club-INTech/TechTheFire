package robot.cartes;

import robot.RobotVrai;
import robot.serial.Serial;
import smartMath.Vec2;
import utils.Log;
import utils.Read_Ini;
import container.Service;

public class Laser implements Service {

	// Dépendances
	private Read_Ini config;
	private Log log;
	private Serial serie;
	private RobotVrai robotvrai;

	private Balise[] balises;
	
	public Laser(Service config, Service log, Service serie, Service robotvrai)
	{
		this.config = (Read_Ini) config;
		this.log = (Log) log;
		this.serie = (Serial) serie;
		this.robotvrai = (RobotVrai) robotvrai;
		
		balises = new Balise[2];
		balises[0] = new Balise(0, false);
		balises[1] = new Balise(1, false);

	}
	
	// TODO
	public Balise[] balises_actives()
	{
		return null;
	}

	// TODO
	public Balise[] balises_ignorees()
	{
		return null;
	}
	
	// TODO
	public void allumer()
	{
		
	}
	
	// TODO
	public void eteindre()
	{
		
	}
	
	// TODO
	public int verifier_balises_connectes()
	{
		return 0;
	}
	
	// TODO
	public boolean ping_balise(int id)
	{
		return false;
	}

	// TODO
	public float frequence_moteur()
	{
		return 0;
	}
	
	// TODO
	public Vec2 position_balise(int id)
	{
		return null;
	}
	
	// TODO
	public void verifier_coherence_balise()
	{
		
	}
	
}
