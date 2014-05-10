package table;

class Fruit {

	private boolean good;
	
	public Fruit(boolean good)
	{
		this.good = good;
	}
	
	public void setNoir()
	{
	    this.good = false;
	}

	public boolean isGood() {
		return good;
	}
}
