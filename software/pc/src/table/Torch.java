package table;

import smartMath.Vec2;

public class Torch extends Game_Element {
	private int torch_id; // 0 et 1 sont les mobiles, les autres sont numérotées de haut en bas
	private float radius; 
	private boolean mobile ;
	
	public Torch (Vec2 position, int id, boolean mobile, float rad)
	{
		super(position);
		this.torch_id = id;
		this.mobile = mobile;
		this.radius = rad;
	}
	
	public Torch clone()
	{
		return new Torch(position, torch_id, mobile, radius);
	}
}
