
public class Feu extends Elements_de_jeu {
	protected enum Colour {RED, YELLOW, UNDETERMINED} ;	
	protected enum Orientation {GROUND, XPLUS, YPLUS, UNDETERMINED}; //XPLUS = orienté de couleur couleur vers les X croissants, suppose d'être debout
																	//De même pour YPLUS. GROUND signifie que le feu est à l'horizontal
	public Feu()
	{
	}
	
	int id ;
	int height=0 ; //0=sol, chaque unité supplémentaire représente un feu en-dessous	
	Orientation orientation = Orientation.UNDETERMINED ;
	Colour colour = Colour.UNDETERMINED ;
	boolean onFireplace = false ;
	boolean stored  = false ;
	Vector position ;
	
	public void define_id(int a)	//Cette méthode appelée pour chaque feu fixe ses paramètres initiaux
	{
		this.id = a;
		if ( a==4 || a==5 || a==6 )
		{
			this.orientation = Orientation.GROUND ;
			this.height = (a-3);
			this.position.set_x(1100);
			this.position.set_y(2100);
		}
		
		if ( a==11 || a==12 || a==13)
		{
			this.orientation = Orientation.GROUND ;
			this.height = (a-10);
			this.position.set_x(1100);
			this.position.set_y(900);
		}
		
		if (a==1 || a==2 || a==15 ||a==16)
		{
			this.orientation = Orientation.YPLUS ;
			this.colour = Colour.YELLOW ;
		}
		
		switch (a)
		{
		case (1) :
			{
			this.position.set_x(600);
			this.position.set_y(2100);
			}
		case (2) :
			{
			this.position.set_x(800);
			this.position.set_y(3000);
			}
		case(3) :
			{
			this.orientation = Orientation.XPLUS;
			this.colour = Colour.RED ;
			this.position.set_x(1100);
			this.position.set_y(2600);
			}
		case(4) :
			{
			this.colour = Colour.YELLOW;
			}
		case(5) :
			{
			this.colour = Colour.RED ;
			}
		case(6) :
			{
			this.colour = Colour.YELLOW;
			}
		case(7) :
			{
			this.orientation = Orientation.YPLUS;
			this.colour = Colour.RED;
			this.position.set_x(1600);
			this.position.set_y(2100);
			}
		case(8) :
			{
			this.orientation = Orientation.XPLUS;
			this.colour = Colour.RED;
			this.position.set_x(2000);
			this.position.set_y(1700);
			}
		case(9) :
			{
			this.orientation= Orientation.XPLUS;
			this.colour= Colour.YELLOW;
			this.position.set_x(2000);
			this.position.set_y(1300);
			}
		case(10) :
			{
			this.orientation=Orientation.YPLUS;
			this.colour= Colour.RED;
			this.position.set_x(1600);
			this.position.set_y(900);
			}
		case(11) :
			{
			this.colour=Colour.RED;
			}
		case(12) :
			{
			this.colour=Colour.YELLOW;
			}
		case(13) :
			{
			this.colour = Colour.RED;
			}
		case(14) :
			{
			this.orientation = Orientation.XPLUS;
			this.colour = Colour.YELLOW;
			this.position.set_x(1100);
			this.position.set_y(400);
			}
		case(15) :
			{
			this.position.set_x(800);
			this.position.set_y(0);
			}
		case(16) :
			{
			this.position.set_x(600);
			this.position.set_y(900);
			}
		}
	}	
	
}
