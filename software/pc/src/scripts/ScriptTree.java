package scripts;

import robot.Cote;
import robot.PositionRateau;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;
import hook.Callback;
import hook.Executable;
import hook.Hook;
import hook.HookGenerator;
import hook.methodes.LeverRateau;

import java.util.ArrayList;

import pathfinding.Pathfinding;
import exception.MouvementImpossibleException;
import exception.SerialException;
/**
 * Script de prise de fruits
 * @author pf, krissprolls
 *
 */
public class ScriptTree extends Script{

	public ScriptTree(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		ArrayList<Integer> versionsList = new ArrayList<Integer>();
		for (int i = 0; i < 4; i++)
			if (!table.isTreeTaken(i))
				versionsList.add(i);
		return versionsList;
	}

	@Override
	public Vec2 point_entree(int id_version) {
		Vec2 entree = null;

		if (id_version == 0)
			entree = new Vec2(1000, 740);
		else if (id_version == 1)
			entree = new Vec2(870, 500);
		else if (id_version == 2)
			entree = new Vec2(-870, 500);
		else if (id_version == 3)
			entree = new Vec2(-1000, 610);
		return entree;
	}

	@Override
	public int score(int id_version, final Robot robot, final Table table) {
		int res = 0;

		if (id_version <= 1)
			res = table.nbrTotalTree(0) + table.nbrTotalTree(1);

		else
			res = table.nbrTotalTree(2) + table.nbrTotalTree(3);

		return res;
	}

	@Override
	public int poids(final Robot robot, final Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException, SerialException
	{
		// Orientation du robot, le rateau étant à l'arrière
//		log.debug("I", this);
		int recul = 0;
		if (id_version == 0)
			robot.tourner((float)Math.PI);
		else if (id_version == 1 || id_version == 2)
			robot.tourner((float) (Math.PI / 2));
		else if (id_version ==3)
			robot.tourner(0) ;
		if(id_version == 0 ||id_version == 3)
			recul = 50;
		else
			recul = 50;
//		log.debug("II", this);

		// on déploie les bras 
		robot.rateau(PositionRateau.BAS, Cote.DROIT);
		robot.rateau(PositionRateau.BAS, Cote.GAUCHE);
		
		// on avance et on rebaisse les rateaux au min
		robot.set_vitesse_translation("arbre_arriere");
		robot.avancer(-318+recul);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.DROIT);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.GAUCHE);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.DROIT);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.GAUCHE);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.DROIT);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.GAUCHE);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.DROIT);
		robot.rateau(PositionRateau.SUPER_BAS, Cote.GAUCHE);
		robot.sleep(500);
		//pour être sûr
		//On remonte juste un peu pour éviter que les rateaux cognent sur le rebord de la table
		robot.rateau(PositionRateau.BAS, Cote.DROIT);
		robot.rateau(PositionRateau.BAS, Cote.GAUCHE);
		// on remonte les bras à mi-hauteur en fonction de la position du fruit pourri, tout en reculant
		
		ArrayList<Hook> hooks = new ArrayList<Hook>();
		
		Cote cote = Cote.GAUCHE;
		do {
			int nbFruits = table.nbrTree(id_version, cote) ;
			Executable remonte = new LeverRateau(robot, cote);
			double distance = 0;
			if(nbFruits == 3)
				distance = 0;
			else if(nbFruits == 2)
				distance = 75;
			else if(nbFruits == 1)
				distance = 200;
			else if(nbFruits == 0)
				distance = 310;
			Vec2 diff = new Vec2((float)(distance*Math.cos((double)robot.getOrientation())),(float)(distance*Math.sin((double)robot.getOrientation())));
			Hook hook = hookgenerator.hook_position(robot.getPosition().PlusNewVector(diff));
			hook.ajouter_callback(new Callback(remonte, true));
			hooks.add(hook);

			if(cote == Cote.GAUCHE)
				cote = Cote.DROIT;
			else
				cote = Cote.GAUCHE;
		} while(cote == Cote.DROIT);
		robot.set_vitesse_translation("arbre_avant");
		robot.avancer(350, hooks);
	}

	@Override
	protected void termine(Robot robot, Table table) {
		try {
			robot.rateau(PositionRateau.RANGER, Cote.DROIT);
			robot.rateau(PositionRateau.RANGER, Cote.GAUCHE);
		} catch (SerialException e) {
			e.printStackTrace();
		}
	}

	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}

	public String toString()
	{
		return "ScriptTree";
	}
	
	public void maj_config()
	{
		// TODO
	}
}
