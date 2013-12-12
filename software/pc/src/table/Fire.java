package table;

import robot.Orientation;
import smartMath.Vec2;

public class Fire extends Game_Element {

	private int fire_id ;//numérotation : par x décroissants et à x égaux par y décroissants (en gros de haut en bas, de gauche à droite dans le règlement)
	private int height ; //0=sol, chaque unité supplémentaire représente un feu en-dessous	
	private Orientation orientation;
	private Colour colour;
	private boolean onFireplace = false ;	// Booléen qui dit si le feu est sur un foyer ou non
	private boolean taken  = false ;	// Booléen indiquant si le feu a été pris
	
	/**
	 * Constructeur utilisé par clone()
	 * @param position
	 * @param fire_id
	 * @param height
	 * @param orientation
	 * @param colour
	 * @param onFireplace
	 * @param taken
	 */
	private Fire(Vec2 position, int fire_id, int height,
			Orientation orientation, Colour colour, boolean onFireplace,
			boolean taken) {
		super(position);
		this.fire_id = fire_id;
		this.height = height;
		this.orientation = orientation;
		this.colour = colour;
		this.onFireplace = onFireplace;
		this.taken = taken;
	}

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
	
	public void ejectFire()
	{
		this.onFireplace = true;
	}
	
	public Fire clone()
	{
		return new Fire(position.clone(), fire_id, height, orientation, colour, onFireplace, taken);
	}
	
}
