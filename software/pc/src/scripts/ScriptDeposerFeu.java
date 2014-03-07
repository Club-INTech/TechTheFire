package scripts;

import java.util.ArrayList;

import exception.MouvementImpossibleException;
import hook.HookGenerator;
import pathfinding.Pathfinding;
import robot.Robot;
import robot.RobotVrai;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;

/**
 * Script de d��pose de feu
 * @author pf
 *
 */

// Il me reste à savoir la séquence exacte des actions à faire... (-Raspbeguy)
public class ScriptDeposerFeu extends Script {

	public ScriptDeposerFeu(Pathfinding pathfinding, HookGenerator hookgenerator, Read_Ini config, Log log, RobotVrai robotvrai)
	{
		super(pathfinding, hookgenerator, config, log, robotvrai);
	}

	@Override
	public ArrayList<Integer> version(final Robot robot, final Table table) {
		// TODO
		ArrayList<Integer> versionList = new ArrayList<Integer>();
		versionList.add(0); // Simple retournement de feu sur place
		versionList.add(1); // Dépose de feu sur le foyer gauche
		versionList.add(2); // Dépose de feu sur le foyer droit
		versionList.add(3); // Dépose de feu sur le foyer central
		// Note pour Krissprolls : Ici, on fait la différence gauche/droite car ça ne dépend pas de la couleur du robot.
		return versionList;
	}

	@Override
	public Vec2 point_entree(int id) {
		// TODO Auto-generated method stub
		Vec2 pos = null;
		switch (id) {
		case 0 :
			pos = null; // Mettre ici une valeur à la place de null, j'aimerai renvoyer la position du robot actuelle en utilisant robot.getPosition, mais j'y ai pas accès...
			break;
		case 1 :
			pos = new Vec2(0,0); // Valeur à débattre et à mesurer
			break;
		case 2 :
			pos = new Vec2(0,0); // Idem, sachant qu'il suffira d'opposer le x
			break;
		case 3 :
			pos = new Vec2(0,0); // Idem, et je suis en train de me demander s'il ne faudrait pas créer des versions supplémentaires pour distinguer les côtés vers lesquels on arrive.
			break;
		}
		return pos;
	}

	@Override
	public int score(int id_version, Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 2; // Là c'est pareil, j'aurais besoin de mettre en parallèle le numéro de version.
	}

	@Override
	public int poids(Robot robot, Table table) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	protected void execute(int id_version, Robot robot, Table table) throws MouvementImpossibleException
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void termine(Robot robot, Table table) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public float proba_reussite()
	{
		// TODO
		return 1;
	}
	
	public String toString()
	{
		return "ScriptDeposerFeu";
	}

}
