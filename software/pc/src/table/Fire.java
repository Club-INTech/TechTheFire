package table;

import robot.Orientation;
import smartMath.Vec2;

public class Fire extends Game_Element {

	private int fire_id ;//numérotation : par x décroissants et à x égaux par y décroissants (en gros de haut en bas, de gauche à droite dans le règlement)
	private int height=0 ; //0=sol, chaque unité supplémentaire représente un feu en-dessous	
	private Orientation orientation = Orientation.UNDETERMINED ;
	private Colour colour = Colour.UNDETERMINED ;
	private boolean onFireplace = false ;	// Booléen qui dit si le feu est sur un foyer ou non
	private boolean taken  = false ;	// Booléen indiquant si le feu a été pris
	
	public Fire(Vec2 position, int id, int height, Orientation orientation, Colour couleur)
	{
		super(position);
		this.fire_id = id;
		this.height = height;
		this.orientation = orientation;
		this.colour = couleur;		
	}

	public void pickFire()
	{
		this.taken = true;
	}
	
	public void ejectFire()
	{
		this.onFireplace = true;
	}
}
