package table;

public class Fruit {

	private int fruit_id; // face à l'arbre, le fruit 0 est celui juste à droite, et on tourne dans le sens trigonométrique
	private boolean taken = false;
	private boolean good = true;
	
	/**
	 * Constructeur public
	 * @param ID
	 */
	public Fruit (int ID)
	{
		this.fruit_id=ID;
	}
	
	/**
	 * Constructeur appelé par clone()
	 * @param ID
	 * @param taken
	 * @param good
	 */
	private Fruit(int ID, boolean taken, boolean good)
	{
		this(ID);
		this.taken = taken;
		this.good = good;
	}

	public Fruit clone()
	{
		return new Fruit(fruit_id, taken, good);
	}
	
}
