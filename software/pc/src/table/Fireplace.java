package table;

import smartMath.Vec2;

public class Fireplace extends Game_Element {
	private float radius;
	private int placed_fires;
	
	/**
	 * Constructeur public
	 * @param position
	 * @param rad
	 */
	public Fireplace (Vec2 position, float rad)
	{
		super(position);
		this.radius = rad;
		placed_fires = 0;
	}

	/**
	 * Constructeur appelé par clone()
	 * @param position
	 * @param rad
	 * @param placed_fires
	 */
	private Fireplace (Vec2 position, float rad, int placed_fires)
	{
		this(position, rad);
		this.placed_fires = placed_fires;
	}

	public Fireplace clone()
	{
		return new Fireplace(position.clone(), radius, placed_fires);
	}
	
	public int getPlaced_fires()
	{
		return placed_fires;
	}
	
}
