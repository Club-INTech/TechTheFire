package table;

class Fruit {

	private boolean good;
	
	public Fruit(boolean good)
	{
		this.good = good;
	}
	
	public void clone(Fruit fruit)
	{
		fruit.good = good;
	}
	
	public boolean isGood() {
		return good;
	}
}
