package table;

import smartMath.Vec2;

public class Tree extends Game_Element {

	private float radius = 150 ;
	Fruit arrayFruit[] = new Fruit[6];
	
	public Tree (Vec2 position, float rad)
	{
		super(position);
		this.radius = rad;
	}
	
}
