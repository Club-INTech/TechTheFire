package table;

import smartMath.Vec2;

/**
 * Torche mobile
 * @author pf
 *
 */
public class Torch extends Game_Element {
	
	private int torch_id; // 0 et 1 sont les mobiles, les autres sont numérotées de haut en bas
	private Fire[] fires;

	public Torch(Vec2 position, int id, Fire fire0, Fire fire1, Fire fire2)
	{
		super(position);
		this.torch_id = id;
		fires = new Fire[3];
		fires[0] = fire0;
		fires[1] = fire1;
		fires[2] = fire2;
	}

	public Torch clone()
	{
		return new Torch(position.clone(), torch_id, fires[0].clone(), fires[1].clone(), fires[2].clone());
	}
	
}
