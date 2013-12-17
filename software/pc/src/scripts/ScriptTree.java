package scripts;

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

class ScriptTree extends Script{

	public ScriptTree(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
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
	protected Vec2 point_entree(int id_version, final Robot robot, final Table table) {
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
	public int score(int id_version, final Robot robot, final Table table) {
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
	public int poids(final Robot robot, final Table table) {
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
		
		ArrayList<Hook> hooks = new ArrayList<Hook>();
		Executable remonteDroit = new LeverRateau(robot, true);
		Hook hook = hookgenerator.hook_position(new Vec2(0,0));
		hook.ajouter_callback(new Callback(remonteDroit, true));		
		hooks.add(hook);

		Executable remonteGauche = new LeverRateau(robot, false);
		hook = hookgenerator.hook_position(new Vec2(0,0));
		hook.ajouter_callback(new Callback(remonteGauche, true));
		hooks.add(hook);
		
		robot.avancer(60, hooks);
	}

	@Override
	protected void termine(Robot robot, Table table) {
		robot.remonter_rateaux();	
	}

}
