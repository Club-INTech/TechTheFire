package table;

class Fruit {

	private final int fruit_id;
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
	
	public void clone(Fruit fruit)
	{
		fruit.taken = taken;
		fruit.good = good;
	}
	
	public boolean isTaken() {
		return taken;
	}
	
	public boolean isGood() {
		return good;
	}
	
	public void setTaken() {
		taken = true;
	}
	
	public int getID()
	{
		return fruit_id;
	}
}
