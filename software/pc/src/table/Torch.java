package table;

import smartMath.Vec2;

/**
 * Torche mobile
 * @author pf
 *
 */
public class Torch extends Game_Element {
	
//	private Fire[] fires;
	private boolean disparue = false; // True si elle est dégommée
	public int rayon = 80;
    private boolean taken  = false ;    // Booléen indiquant si le feu a été pris

/*	public Torch(Vec2 position, Fire fire0, Fire fire1, Fire fire2)
	{
		super(position);
		fires = new Fire[3];
		fires[0] = fire0;
		fires[1] = fire1;
		fires[2] = fire2;
	}*/

	public Torch(Vec2 position)
	{
		super(position);
	}
	
	public void setDisparue()
	{
		disparue = true;
	}
	
	public boolean isDisparue()
	{
		return disparue;
	}
	
	public void pickTorch()
	{
	    taken = true;
	}

    public boolean isTaken()
    {
        return taken;
    }

   public void clone(Torch other)
	{
		other.disparue = disparue;
		other.taken = taken;
	}
	
/*
	public void clone(Torch torch)
	{
		 fires[0].clone(torch.fires[0]);
		 fires[1].clone(torch.fires[1]);
		 fires[2].clone(torch.fires[2]);
	}
	*/
}
