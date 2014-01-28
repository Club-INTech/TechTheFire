package robot.cartes;

import smartMath.Vec2;
import utils.Log;
import utils.Read_Ini;
import container.Service;
import smartMath.Matrn;
public class FiltrageLaser implements Service {


	private Log log;
	private double dt;
	private Matrn x;
	private Matrn P;
	private Matrn F;
	public FiltrageLaser(Read_Ini config, Log log)
	{
		this.log = log;
		dt = (double)0.2;
		double[][] tab_x = {{1400., 100.,0.,0.}};
		Matrn x = new Matrn(tab_x);
		double[][] tab_p = {{30,0,0,0},{0,30,0,0},{0,0,10,0},{0,0,0,10}};
		Matrn P = new Matrn(tab_p);
		double[][] tab_f = {{1,0,dt,0},{0,1,0,dt},{0,0,1,0},{0,0,0,1}};
		Matrn F = new Matrn(tab_f);
		double[][] tab_h = {{1,0,0,0},{0,1,0,0}};
		Matrn H = new Matrn(tab_h);
		double[][] tab_r = {{900,0},{0,900}};
		Matrn R = new Matrn(tab_r);
		double[][] tab_q = {{Math.pow(dt, 3)/3., 0, Math.pow(dt, 2.)/2., 0},{0, Math.pow(dt, 3.)/3., 0, Math.pow(dt, 2.)/2},{Math.pow(dt, 2.)/2., 0, 4*dt, 0},{0, Math.pow(dt, 2.)/2, 0, 4*dt}};
		Matrn Q = new Matrn(tab_q);
		Kalman filtre_kalman = new Kalman(x, P, F, H, R, Q) /* à remplir*/
		Vec2[] historique = collections.deque(maxlen=3) //à faire
		int valeurs_rejetees = 0;
		acceleration = null;
		
		
	}
	

	// TODO
	public Vec2 etat_robot_adverse()
	{
		return filtre_kalman.x;
	}
	
	// TODO
	public void update_dt(float new_dt)
	{
		dt = new_dt;
		filtre_kalman.F.matrice[0][2] = new_dt;
		filtre_kalman.F.matrice[1][3] = new_dt;
	}

	// TODO
	public Vec2 position()
	{
		return last_point;
	}
	// TODO
	public Vec2 vitesse()
	{
		Kalman state = filtre_kalman;
		return Vitesse((int)(state[2], (int)state[3])) ;
	}

	// TODO
	public void update(Vec2 point)
	{
		if(this.filtrage_acceleration(point))
		{
			last_point = point;
		}
	}
	
	// TODO
	private boolean filtrage_acceleration(Vec2 pointm0)
	{
		if(historique.length != 3)
		{
			return true;
		}
		Vec2 pointm1 = historique[2];
		Vec2 pointm2 = historique[1];
		Vec2 pointm3 = historique[0];
		Vec2 vitesse_actuelle = pointm0.MinusNewVector(pointm1);
		Vec2 vitesse_m1 = pointm1.MinusNewVector(pointm2);
		Vec2 vitesse_m2 = pointm2.MinusNewVector(pointm3);
		Vec2 acceleration_actuelle = vitesse_actuelle.MinusNewVector(vitessem1);
		Vec2 acceleration_precedente = vitesse_m1.MinusNewVector(vitesse_m2);
		Vec2 jerk = acceleration_actuelle.MinusNewVector(acceleration_precedente);
		float produit = acceleration_actuelle.dot(vitesse_m1);
		if(acceleration_actuelle.SquaredLength()/this.dt**2 >50000 & this.valeurs_rejetees < 3 )
		{
			valeurs_rejetees +=1;
			return false;
		}
		else
		{
			valeurs_rejetees = 0;
		    return true;
		}
	}

	
	
}
