package table;

import smartMath.Vec2;

public class Fruit extends Game_Element {

	private int fruit_id; // face à l'arbre, le fruit 0 est celui juste à droite, et on tourne dans le sens trigonométrique
	private boolean taken = false;
	private boolean good = true;
	
	public Fruit (Vec2 position, int ID)
	{
		super(position);
		this.fruit_id=ID;
		
	}

}
