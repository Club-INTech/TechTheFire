package table;

import smartMath.Vec2;

/**
 * Torche mobile
 * @author pf
 *
 */
class Torch extends Game_Element {
	
	private Fire[] fires;

	public Torch(Vec2 position, Fire fire0, Fire fire1, Fire fire2)
	{
		super(position);
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
