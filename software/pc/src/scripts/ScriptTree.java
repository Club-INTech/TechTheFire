package scripts;

import robot.Robot;
import robot.RobotChrono;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import threads.ThreadTimer;
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

class ScriptTree extends Script{

	public ScriptTree(Pathfinding pathfinding, ThreadTimer threadtimer, HookGenerator hookgenerator, Read_Ini config, Log log)
	{
		super(pathfinding, threadtimer, hookgenerator, config, log);
	}

	@Override
	public ArrayList<Integer> version(Robot robot, Table table) {
		int i;
		ArrayList<Integer> versionsList = new ArrayList<Integer>();
		for (i=0; i<=3; i++)
		{
			if (table.isTreeTaken(i) == false)
				{
					versionsList.add(i);
				}
		}
		return versionsList;
	}

	@Override

	public Vec2 point_entree(int id_version, Robot robot, Table table) {
		Vec2 entree = new Vec2();

		if (id_version == 0)
		{
			entree.x = 1165 ; // à modifier en fonction de la taille du robot
			entree.y = 700 ;
		}
		if (id_version == 1)
		{
			entree.x = 800;
			entree.y = 435;		//idem
		}
		if (id_version == 2)
		{
			entree.x = -800;
			entree.y = 435 ;	//idem
		}
		if (id_version == 3)
		{
			entree.x = -1165 ;	//idem
			entree.y = 700 ;
		}
		return entree;
	}

	@Override
	public int score(int id_version, Robot robot, Table table) {
		int res = 0;
		if (id_version <= 1)
		{
			res = table.nbrTotalTree(0) + table.nbrTotalTree(1);
		}
		else
		{
			res = table.nbrTotalTree(2) + table.nbrTotalTree(3);
		}
		return res;
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException
	{
		int Fruitsgauche = table.nbrLeftTree(id_version) ;
		int Fruitsdroite = table.nbrRightTree(id_version);
		
		// Orientation du robot, le rateau étant à l'arrière
		if (id_version == 0)
		{
			robot.tourner((float)(Math.PI));
		}
		if (id_version ==1 || id_version ==2)
		{
			robot.tourner((float) (Math.PI / 2));
		}
		if (id_version ==3)
		{
			robot.tourner(0) ;
		}
		
		// on déploie les bras 
		robot.baisser_rateaux();
		// on avance et on rebaisse les rateaux au min
		robot.avancer(-200);
		robot.baisser_rateaux_bas();
		// on remonte les bras à mi-hauteur en fonction de la position du fruit pourri, tout en reculant
		
		Hook[] hooks = new Hook[2];
		Executable remonteDroit = new LeverRateau(robot, true);
		hooks[0] = hookgenerator.hook_position(new Vec2(0,0));
		hooks[0].ajouter_callback(new Callback(remonteDroit, true));

		Executable remonteGauche = new LeverRateau(robot, false);
		hooks[1] = hookgenerator.hook_position(new Vec2(0,0));
		hooks[1].ajouter_callback(new Callback(remonteGauche, true));
		
		robot.avancer(60, hooks);
	}

	@Override
	protected void termine(Robot robot, Table table) {
		robot.remonter_rateaux();	
	}

}
