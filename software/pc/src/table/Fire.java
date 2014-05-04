package table;

import enums.Colour;
import smartMath.Vec2;

public class Fire extends Game_Element {

	private int height ; //0=sol, chaque unité supplémentaire représente un feu en-dessous	
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
	public Fire(Vec2 position, int id, int height, Colour couleur)
	{
		super(position);
		this.height = height;
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
	
	public Colour getColour()
	{
		return colour;
	}
	
	public void clone(Fire fire)
	{
		fire.height = height;
		fire.onFireplace = onFireplace;
		fire.taken = taken;
		// pas de copie de colour, qui est constant
	}
	
}
