package table;

import smartMath.Vec2;

public class Tree extends Game_Element implements Cloneable
{

	// Indice dans arrayTree:
	//depuis le haut vers le bas, de 0 à 3;
	// 0 et 1 : côté droit
	// 2 et 3 : côté gauche
	private boolean taken = false;
	private final Fruit arrayFruit[] = new Fruit[6];

	/**
	 * Constructeur public
	 * @param position
	 */
	public Tree(Vec2 position, int indice_noir)
	{
		super(position);
		for(int i = 0; i < 6; i++)
	        this.arrayFruit[i] = new Fruit(i != indice_noir);

		// Convention par Guy (spammez moi si je me trompe) :
		// 0-2 : partie gauche de l'arbre
		// 3-5 : partie droite de l'arbre
		// De plus, 0 et 3 sont les fruits les plus proches du robot.
	}

	public void clone(Tree ct)
	{
	    ct.taken = taken;
	}
	public Fruit[] getArrayFruit()
	{
		return arrayFruit;
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
	
}
