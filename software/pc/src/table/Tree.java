package table;

import smartMath.Vec2;

class Tree extends Game_Element {

	// Indice dans arrayTree:
	//depuis le haut vers le bas, de 0 à 3;
	// 0 et 1 : côté droit
	// 2 et 3 : côté gauche
	private boolean taken = false;
	private final Fruit arrayFruit[] = new Fruit[6];

	// combien gauche()
	// combien droit()

	/**
	 * Constructeur public
	 * @param position
	 */
	public Tree(Vec2 position)
	{
		super(position);
		this.arrayFruit[0] = new Fruit(true);
		this.arrayFruit[1] = new Fruit(true);
		this.arrayFruit[2] = new Fruit(true);
		this.arrayFruit[3] = new Fruit(true);
		this.arrayFruit[4] = new Fruit(true);
		this.arrayFruit[5] = new Fruit(true);
		// Convention par Guy (spammez moi si je me trompe) :
		// 0-2 : partie gauche de l'arbre
		// 3-5 : partie droite de l'arbre
		// De plus, 0 et 3 sont les fruits les plus proches du robot.
	}

	public void clone(Tree tree)
	{
		// Si l'arbre est pris, on ne prend même pas la peine de copier ses fruits
		tree.taken = taken;
	}
	
	public int nbrLeft ()
	{
		int var = 0;
		int i = 0;
		if (!(this.taken))
		{
			while (i < 3 && this.arrayFruit[i].isGood()) 
			{
				var++;
				i++;
			}
		}
		return var;
	}
	
	public int nbrRight ()
	{
		int var = 0;
		int i = 3;
		if (!(this.taken))
		{
			while (i < 6 && this.arrayFruit[i].isGood()) 
			{
				var++;
				i++;
			}
		}
		return var;
	}
	
	public int nbrTotal ()
	{
		return (nbrLeft()+nbrRight());
	}
		
	public boolean isTaken()
	{
		return this.taken;
	}
	
	public void setTaken()
	{
		this.taken = true;
	}
	
	public Vec2 getPosition()
	{
		return position;
	}
}
