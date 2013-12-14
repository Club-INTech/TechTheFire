package table;

import smartMath.Vec2;

class Fireplace extends Game_Element {
	private int placed_fires;
	
	/**
	 * Constructeur appelé par clone()
	 * @param position
	 * @param rad
	 * @param placed_fires
	 */
	private Fireplace (Vec2 position, int placed_fires)
	{
		super(position);
		this.placed_fires = placed_fires;
	}

	public void clone(Fireplace fireplace)
	{
		fireplace.placed_fires = placed_fires;
	}
	
	public int getPlaced_fires()
	{
		return placed_fires;
	}
	
}
