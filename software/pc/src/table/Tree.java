package table;

import smartMath.Vec2;

public class Tree extends Game_Element {

	private int tree_id; //depuis le haut vers le bas, de 0 à 3
	private float radius = 150 ;
	Fruit arrayFruit[] = new Fruit[6];

	// combien gauche()
	// combien droit()

	/**
	 * Constructeur public
	 * @param position
	 * @param id
	 */
	public Tree (Vec2 position, int id)
	{
		super(position);
		this.tree_id = id;
		this.arrayFruit[0] = new Fruit(0);
		this.arrayFruit[1] = new Fruit(1);
		this.arrayFruit[2] = new Fruit(2);
		this.arrayFruit[3] = new Fruit(3);
		this.arrayFruit[4] = new Fruit(4);
		this.arrayFruit[5] = new Fruit(5);	
	}
	
	/**
	 * Constructeur utilisé par clone()
	 * @param position
	 * @param tree_id
	 * @param radius
	 * @param arrayFruit
	 */
	private Tree(Vec2 position, int tree_id, float radius, Fruit[] arrayFruit) {
		super(position);
		this.tree_id = tree_id;
		this.radius = radius;
		this.arrayFruit = arrayFruit;
	}

	public Tree clone()
	{
		Fruit[] cloned_arrayFruit = new Fruit[6];
		for(int i = 0; i < 6; i++)		
			cloned_arrayFruit[i] = arrayFruit[i].clone();
		return new Tree(position.clone(), tree_id, radius, cloned_arrayFruit);
	}
	
}
