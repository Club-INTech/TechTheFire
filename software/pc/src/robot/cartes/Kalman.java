package robot.cartes;

import smartMath.Matrn;

/**
 * Filtrage mathématique. Classe en visibilité "friendly"
 * @author pf
 *
 */

public class Kalman {
	Matrn x;
	Matrn p;
	Matrn f;
	Matrn h;
	Matrn r;
	Matrn q;
	public Kalman(Matrn x, Matrn p, Matrn f, Matrn h, Matrn r, Matrn q) 
		{
			
			this.x = x;
			this.p = p;
			this.f = f;
			this.h = h;
			this.r = r;
			this.q = q;
			
		}
		// TODO Auto-generated constructor stub
		void prediction(Matrn u)
		{
			if (u == null)
			{
				Matrn u = Matrn(x.taille[0], x.taille[1], 0);
			}
			Matrn tampon1 = this.f;
			tampon1.multiplier(this.x);
			tampon1.addition(u);
			this.x = tampon1;
			//self.x = (self.F * self.x) + u
			Matrn tampon2 = this.f;
			tampon2.multiplier(this.p);
			Matrn tampon3 = this.f;
			tampon3.transpose();
			tampon2.multiplier(tampon3);
			this.p = tampon2;
			this.p.addition(this.q);
			/*Tout ça , ça fait ça : self.P = self.F * self.P * self.F.transpose() + self.Q*/
			/*oui c'est lourd*/
		}
		void prediction()
		{
			prediction(null);
		}
		void measurement(Matrn z)
		{
			Matrn tampon1 = this.h;
			tampon1.multiplier(x);
			Matrn tampon2 = z;
			tampon2.soustraire(tampon1);
			Matrn y = tampon2;
		}
		void filtrer(Matrn z,Matrn u)
		{
			prediction(u);
			measurement(z);			
		}
		
}
