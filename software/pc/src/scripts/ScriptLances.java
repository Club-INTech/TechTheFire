package scripts;

import robot.RobotChrono;
import smartMath.Vec2;
import table.Table;
import container.Service;

/**
 * Script pour les lances
 * @author pf
 *
 */

// TODO Guy

public class ScriptLances extends Script {
	

	/*
	 * Le script lance 4 balles sur le côté droit
	 * Le script donne un point d'entrée
	 */
	
	public ScriptLances(Service pathfinding, Service threadtimer,
			Service robotvrai, Service robotchrono, Service hookgenerator,
			Service table, Service config, Service log) {
		super(pathfinding, threadtimer, robotvrai, robotchrono, hookgenerator, table,
				config, log);
		// TODO Auto-generated constructor stub
	}

	@Override
	public int[] version() {
		/*
		 * De 0 à 2 versions possibles
		 */
		return null;
	}

	@Override
	public Vec2 point_entree(int id) {
		// A modifier, la position devant le mammouth
		return new Vec2(0,0);
	}

	@Override
	public int score() {
		// combien on gagne? demander à la table
		return 0;
	}

	@Override
	public int poids() {
		// On s'en fout pour le moment
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version) {
		// ajuster l'orientation du robot (objet robot)
		robot.tourner(0);
		// tirer (objet robot)
		// à réfléchir (côté droit ou gauche)
		robot.tirerBalles(true);
	}

	@Override
	protected void termine() {
		// vide
	}
	
	/*
	 * On verra celles-là plus tard
	 */

	@Override
	public Table futureTable(Table table) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public RobotChrono futurRobotChrono(RobotChrono robotchrono) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public float getDuree() {
		// TODO Auto-generated method stub
		return 0;
	}


	
	
}
