
public class Feu extends Elements_de_jeu {
	public Feu(int id, int height, Orientation orientation, Colour colour, Position position)
	{
		this.id = id;
		this.height = height;
		this.orientation = orientation;
		this.colour = colour;
		this.position = position;
	}
	
	int id ;
	int height=0 ; //0=sol, chaque unité supplémentaire représente un feu en-dessous	
	Orientation orientation = Orientation.UNDETERMINED ;
	Colour colour = Colour.UNDETERMINED ;
	boolean onFireplace = false ;	// what is ?
	boolean taken  = false ;	// IDEM
	

	public void pickFire()
	{
		this.taken = true;
	}
	
	public void ejectFire()
	{
		this.onFireplace = true;
	}
}
