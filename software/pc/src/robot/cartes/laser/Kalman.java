package robot.cartes.laser;

import exceptions.MatriceException;
import smartMath.Matrn;

/**
 * Filtrage mathématique. Classe en visibilité "friendly"
 * @author pf
 * @auteur clément
 */
//Les erreurs sont dues à la mauvaise gestion des excptions, PF? Au secours !!!

class Kalman {
	//les attributs qui ont été mises en public sont utilisées dans FiltrageLaser.java
	public Matrn x;
	private Matrn p;
	public Matrn f;
	private Matrn h;
	private Matrn r;
	private Matrn q;
	private Matrn ident;
	public Kalman(Matrn x, Matrn p, Matrn f, Matrn h, Matrn r, Matrn q) 
		{
			
			this.x = x;
			this.p = p;
			this.f = f;
			this.h = h;
			this.r = r;
			this.q = q;
			this.ident = Matrn.identiter(this.x.taille[0]);
			
		}
	
		void prediction(Matrn u)
		{
			if (u == null)
			{
				u = new Matrn(this.x.taille[0], this.x.taille[1], 0);
			}
			try {
				this.x = this.f.multiplier(this.x).additionner(u);
				this.p = this.f.multiplier(this.p).multiplier(this.f.transpose()).additionner(this.q);
			} catch (MatriceException e) {
				e.printStackTrace();
			}
			//self.x = (self.F * self.x) + u
			
			/*self.P = self.F * self.P * self.F.transpose() + self.Q*/
			/*
			 * Il y a une histoire d'exception et j'ai la flemme de gérer ça. PF?
			 */
		}
		void prediction()
		{
			prediction(null);
		}
		void measurement(Matrn z)
		{
			Matrn y;
			try {
				y = z.soustraire(this.h.multiplier(this.x));
				Matrn s = this.h.multiplier(this.p).multiplier(this.h.transpose()).additionner(this.r);
				Matrn k = this.p.multiplier(this.h.transpose()).multiplier(s.inverser());
				this.x.additionner_egal(k.multiplier(y));
				this.p = (this.ident.soustraire(k.multiplier(this.h))).multiplier(this.p);
			} catch (MatriceException e) {
				e.printStackTrace();
			}
		}
		void filtrer(Matrn z,Matrn u)
		{
			prediction(u);
			measurement(z);			
		}		
}
