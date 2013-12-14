package table;

class Fruit {

	private boolean good = true;
	
	public void clone(Fruit fruit)
	{
		fruit.good = good;
	}
	
	public boolean isGood() {
		return good;
	}
}
