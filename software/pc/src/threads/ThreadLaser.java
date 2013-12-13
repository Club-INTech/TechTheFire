package threads;

import robot.cartes.Laser;
import table.Table;
import utils.Log;
import utils.Read_Ini;
import container.Service;

/**
 * Thread de gestion de la balise laser
 * @author pf
 *
 */

class ThreadLaser extends AbstractThread {

	private Laser laser;
	private Table table;
	private ThreadTimer threadtimer;
	
	public ThreadLaser(Read_Ini config, Log log, Laser laser, Table table, ThreadTimer threadtimer)
	{
		super(config, log);
		this.laser = laser;
		this.table = table;
		this.threadtimer = threadtimer;
	}

}
