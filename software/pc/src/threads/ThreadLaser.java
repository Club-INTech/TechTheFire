package threads;

import robot.cartes.Laser;
import table.Table;
import container.Service;

/**
 * Thread de gestion de la balise laser
 * @author pf
 *
 */

public class ThreadLaser extends AbstractThread {

	private Laser laser;
	private Table table;
	private ThreadTimer threadtimer;
	
	public ThreadLaser(Service config, Service log, Service laser, Service table, Service threadtimer)
	{
		super(config, log);
		this.laser = (Laser) laser;
		this.table = (Table) table;
		this.threadtimer = (ThreadTimer) threadtimer;
	}

}
