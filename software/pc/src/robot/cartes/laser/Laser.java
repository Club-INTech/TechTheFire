package robot.cartes.laser;

import java.util.ArrayList;

import robot.RobotVrai;
import robot.serial.Serial;
import smartMath.Vec2;
import utils.Log;
import utils.Read_Ini;
import container.Service;
import exceptions.serial.SerialException;

/**
 * Classe qui gère la balise laser
 * @author pf
 *
 */

public class Laser implements Service {

	// Dépendances
	private Log log;
	private Serial serie;
	private RobotVrai robotvrai;

	private Balise[] balises;

	public Laser(Read_Ini config, Log log, Serial serie, RobotVrai robotvrai)
	{
		this.log = log;
		this.serie = serie;
		this.robotvrai = robotvrai;

		balises = new Balise[2];
		balises[0] = new Balise(0, false);
		balises[1] = new Balise(1, false);

	}

	/**
	 * Indique les balises considérées comme opérationnelle pour le match
	 * @return
	 */
	public ArrayList<Balise> balises_actives()
	{
		ArrayList<Balise> out = new ArrayList<Balise>();
		for(Balise b: balises)
			if(b.active)
				out.add(b);
		return out;
	}

	/**
	 * Indique les balises considérées comme non opérationnelle pour le match
	 * @return
	 */
	public ArrayList<Balise> balises_ignorees()
	{
		ArrayList<Balise> out = new ArrayList<Balise>();
		for(Balise b: balises)
			if(!b.active)
				out.add(b);
		return out;
	}

	/**
	 * Allumer le moteur et les lasers
	 */
	public void allumer()
	{
		try {
			serie.communiquer("motor_on", 0);
			serie.communiquer("laser_on", 0);
		} catch (SerialException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Eteindre le moteur et les lasers
	 */
	public void eteindre()
	{
		try {
			serie.communiquer("motor_off", 0);
			serie.communiquer("laser_off", 0);
		} catch (SerialException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Ping chaque balise et vérifie celles qui sont connectées
	 * @return
	 */
	public int verifier_balises_connectes()
	{
		int balises_ok = 0;
		for(Balise b: balises)
			try {
				if(ping_balise(b.id))
				{
					if(!b.active)
					{
						b.active = true;
						log.debug("balise n°" + Integer.toString(b.id) + " répondant au ping", this);
					}
					balises_ok++;
				}
				else
				{
					//log.warning("balise n°"+b.id+" ne répond pas.", this);
				}
			} catch (SerialException e) {
				e.printStackTrace();
			}
		return balises_ok;
	}

	/**
	 * Ping une balise
	 * @param id
	 * @return
	 * @throws SerialException 
	 */
	private boolean ping_balise(int id) throws SerialException
	{
		// TODO (de PF) vérifier la méthode, mais on faisait comme ça l'année dernière
		String[] ping = serie.communiquer("ping_all", balises.length);	    
		return !ping[id].equals("aucune réponse");
	}

	/**
	 * Récupère la fréquence actuelle du moteur
	 * @return
	 */
	private float frequence_moteur()
	{
		try {
			String[] reponse = serie.communiquer("freq", 1);
			//System.out.println(reponse[0]);
			return Float.parseFloat(reponse[0]);
		}
		catch(Exception e)
		{
			e.printStackTrace();
			return 18; // TODO valeur normale
		}

	}
	/**
	 * Récupère la valeur (rayon, angle) d'une balise
	 * Et renvoie la position relative de la balise dans le système de coordonnées du laser.
	 * @param id
	 * @return point
	 * @throws SerialException 
	 */
	public Vec2 position_balise_relative(int id) throws SerialException
	{
		String chaines[] = {"value", Integer.toString(id)};
		String[] reponse = serie.communiquer(chaines, 3);

		if(reponse[0].equals("NO_RESPONSE") || reponse[1].equals("NO_RESPONSE")
				|| reponse[0].equals("OLD_VALUE") || reponse[1].equals("OLD_VALUE")
				|| reponse[0].equals("UNVISIBLE") || reponse[1].equals("UNVISIBLE"))
			return null;

		// Fréquence actuelle du moteur
		float freq = frequence_moteur();

		// Valeur de la distance, sur l'échelle du timer 8 bit
		float timer = Float.parseFloat(reponse[0]);

		// Délai du passage des deux lasers, en seconde
		float delai = 128 * timer / 20000000;

		// Calcul de la distance (en mm)
		float ecart_laser = 35;
		float theta = (float) (delai * freq * 2 * Math.PI);

		if(theta == 0)
		{
			log.warning("Division par zéro dans le calcul d'angle : freq = "+Float.toString(freq)+", delai = "+Float.toString(delai), this);
			return null;
		}

		int distance = (int) (ecart_laser / Math.sin(theta / 2));

		// Angle
		float angle = Float.parseFloat(reponse[1]);

		// Changement dans le repère de la table
		Vec2 point = new Vec2((int)(distance * Math.cos(angle)), (int)(distance * Math.sin(angle)));
		return point;
	}

	/**
	 * Récupère la valeur (rayon, angle) d'une balise
	 * @param id
	 * @return
	 * @throws SerialException 
	 */
	public Vec2 position_balise(int id) throws SerialException
	{
		String chaines[] = {"value", Integer.toString(id)};
		String[] reponse = serie.communiquer(chaines, 3);

		if(reponse[0].equals("NO_RESPONSE") || reponse[1].equals("NO_RESPONSE")
				|| reponse[0].equals("OLD_VALUE") || reponse[1].equals("OLD_VALUE")
				|| reponse[0].equals("UNVISIBLE") || reponse[1].equals("UNVISIBLE"))
			return null;

		// Fréquence actuelle du moteur
		float freq = frequence_moteur();

		// Valeur de la distance, sur l'échelle du timer 8 bit
		float timer = Float.parseFloat(reponse[0]);

        // Délai du passage des deux lasers, en seconde
        float delai = 128 * timer / 20000000;
        
        // Calcul de la distance (en mm)
        float ecart_laser = 35;
        float theta = (float) (delai * freq * 2 * Math.PI);

        if(theta == 0)
        {
            log.warning("Division par zéro dans le calcul d'angle : freq = "+Float.toString(freq)+", delai = "+Float.toString(delai), this);
            return null;
        }

        int distance = (int) (ecart_laser / Math.sin(theta / 2));
        // Angle
        float angle = Float.parseFloat(reponse[1]);

        // Changement dans le repère de la table
        Vec2 point = robotvrai.getPosition();
        double orientation = robotvrai.getOrientation();
        
        point.Plus(new Vec2((int)(distance * Math.cos(angle + orientation)), (int)(distance * Math.sin(angle + orientation))));
        return point;
	}

	/**
	 * Vérifie si les données des balises actives sont cohérentes en début de match
	 */
	public void verifier_coherence_balise()
	{
		// Nombre d'essais pour les calculs
		int essais = 10;

		ArrayList<Balise> balises_actives = balises_actives();
		for(Balise b : balises_actives)
		{
			float moyenne = 0;
			ArrayList<Float> valeurs = new ArrayList<Float>();
			float ecart_type = 0;
			int n = 0;

			for(int i = 0; i < essais; i++)
			{
				try {
					String chaines[] = {"value", Integer.toString(b.id)};
					String[] reponse = serie.communiquer(chaines, 3);
					//System.out.println(reponse[0]/* + " " + reponse[1] + " " + reponse[2]*/);
					if(!(reponse[0].equals("NO_RESPONSE") || reponse[1].equals("NO_RESPONSE")
							|| reponse[0].equals("OLD_VALUE") || reponse[1].equals("OLD_VALUE")
							|| reponse[0].equals("UNVISIBLE") || reponse[1].equals("UNVISIBLE")))
					{
						float angle = Float.parseFloat(reponse[1]);
						n++;
						moyenne += angle;
						valeurs.add(angle);
					}
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
			}

			// Calcul de la moyenne
			if(n > 0)
			{
				moyenne /= (float) n;

				// Calcul de l'écart type
				for(Float v: valeurs)
					ecart_type += (v - moyenne) * (v - moyenne);
				ecart_type /= (float) n;

			}

			// Vérification de la cohérence
			if(n < essais / 2 || ecart_type > 1)
			{
				log.critical("balise n°"+Integer.toString(b.id)+" ignorée pendant le match, valeurs renvoyées incohérentes (valeurs reçues = "+Integer.toString(n)+" / "+Integer.toString(essais)+", angle moyen = "+Float.toString(moyenne)+", écart-type = "+Float.toString(ecart_type)+")", this);
				b.active = false;
			}
			else
				log.debug("balise n°"+Integer.toString(b.id)+" renvoie des valeurs cohérentes (valeurs reçues = "+Integer.toString(n)+" / "+Integer.toString(essais)+", angle moyen = "+Float.toString(moyenne)+", écart-type = "+Float.toString(ecart_type)+")", this);				
		}


	}

	public void maj_config()
	{
	}
}
