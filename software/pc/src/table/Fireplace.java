package table;

import smartMath.Vec2;

public class Fireplace extends Game_Element {
	private float radius;
	private int placed_fires;
	
	public Fireplace (Vec2 position, float rad)
	{
		super(position);
		this.radius = rad;
		placed_fires = 0;
	}
	
}
