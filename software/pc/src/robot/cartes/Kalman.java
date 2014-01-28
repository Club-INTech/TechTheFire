package robot.cartes;

import smartMath.Matrn;

/**
 * Filtrage mathématique. Classe en visibilité "friendly"
 * @author pf
 *
 */

class Kalman {

	public Kalman(Matrn x, Matrn p, Matrn f, Matrn h, Matrn r, Matrn q) {
		// TODO Auto-generated constructor stub
		void prediction(Matrn u)
		{
			if (u)
			{
				
			}
			F.multiplier(x).addition(u)
		}
		void prediction()
		{
			prediction(null);
		}
		
		
	}



}
