package table;

import robot.Orientation;
import smartMath.Vec2;

class Fire extends Game_Element {

	private final int fire_id ;//numérotation : par x décroissants et à x égaux par y décroissants (en gros de haut en bas, de gauche à droite dans le règlement)
	private int height ; //0=sol, chaque unité supplémentaire représente un feu en-dessous	
	private final Orientation orientation;
	private final Colour colour;
	private boolean onFireplace = false ;	// Booléen qui dit si le feu est sur un foyer ou non
	private boolean taken  = false ;	// Booléen indiquant si le feu a été pris

	/**
	 * Constructeur public
	 * @param position
	 * @param id
	 * @param height
	 * @param orientation
	 * @param couleur
	 */
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
	
	public boolean isTaken()
	{
		return taken;
	}
	
	public void ejectFire()
	{
		this.onFireplace = true;
	}
	
	public int getId()
	{
		return fire_id;
	}
	
	public void clone(Fire fire)
	{
		fire.height = height;
		fire.onFireplace = onFireplace;
		fire.taken = taken;
	}
	
}
