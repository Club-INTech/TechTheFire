package table;

public class Fruit {

	private int fruit_id;
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
	
	public boolean isTaken() {
		return this.taken;
	}
	
	public boolean isGood() {
		return this.good;
	}
	
	public void getTaken() {
		this.taken = true;
	}
}
