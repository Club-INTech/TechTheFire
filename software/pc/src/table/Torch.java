package table;

import smartMath.Vec2;

/**
 * Torche mobile
 * @author pf
 *
 */
class Torch extends Game_Element {
	
	private final int torch_id; // 0 et 1 sont les mobiles, les autres sont numérotées de haut en bas
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

	public void clone(Torch torch)
	{
		 fires[0].clone(torch.fires[0]);
		 fires[1].clone(torch.fires[1]);
		 fires[2].clone(torch.fires[2]);
	}
	
}
