package table;

import smartMath.Vec2;

public class Tree extends Game_Element {

	private int tree_id; //depuis le haut vers le bas, de 0 à 3
	private float radius = 150 ;
	Fruit arrayFruit[] = new Fruit[6];

	// combien gauche()
	// combien droit()

	public Tree (Vec2 position, int id, Vec2 pos0, Vec2 pos1, Vec2 pos2, Vec2 pos3, Vec2 pos4, Vec2 pos5)
	{
		super(position);
		this.tree_id = id;
		this.arrayFruit[0] = new Fruit(pos0, 0);
		this.arrayFruit[1] = new Fruit(pos1, 1);
		this.arrayFruit[2] = new Fruit(pos2, 2);
		this.arrayFruit[3] = new Fruit(pos3, 3);
		this.arrayFruit[4] = new Fruit(pos4, 4);
		this.arrayFruit[5] = new Fruit(pos5, 5);	
	}
	
	public Tree(Vec2 position, int tree_id, float radius, Fruit[] arrayFruit) {
		super(position);
		this.tree_id = tree_id;
		this.radius = radius;
		this.arrayFruit = arrayFruit;
	}

	// TODO cloner l'array
	public Tree clone()
	{
		return new Tree(position, tree_id, radius, arrayFruit);
	}
	
}
