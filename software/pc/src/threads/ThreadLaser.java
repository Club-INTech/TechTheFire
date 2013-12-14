package threads;

import java.util.ArrayList;

import robot.cartes.Balise;
import robot.cartes.FiltrageLaser;
import robot.cartes.Laser;
import smartMath.Vec2;
import table.Table;
import utils.Log;
import utils.Read_Ini;
import container.Service;

/**
 * Thread de gestion de la balise laser
 * @author pf
 *
 */

class ThreadLaser extends AbstractThread {

	private FiltrageLaser filtragelaser;
	private Laser laser;
	private Table table;
	private ThreadTimer threadtimer;
	
	private int table_x;
	private int table_y;
	private float lasers_frequence;
	
	public ThreadLaser(Laser laser, Table table, ThreadTimer threadtimer, FiltrageLaser filtragelaser)
	{
		this.filtragelaser = filtragelaser;
		this.laser = laser;
		this.table = table;
		this.threadtimer = threadtimer;
		try {
		table_x = Integer.parseInt(config.get("table_x"));
		table_y = Integer.parseInt(config.get("table_y"));
		lasers_frequence = Float.parseFloat(config.get("lasers_frequence"));
		}
		catch(Exception e)
		{
			log.critical(e, this);
		}
	}
	
	public void run()
	{
		// On attends le démarrage du match et qu'au moins une balise réponde
		while(!threadtimer.match_demarre || laser.verifier_balises_connectes() == 0)
		{
			if(stop_threads)
			{
				log.debug("Stoppage du thread laser", this);
				return;
			}
			sleep(100);
		}

		// Allumage des lasers
		laser.allumer();

		// Attente de la vitesse stable
		sleep(3000);
		
		for(Balise balise: laser.balises_ignorees())
		{
            log.warning("balise n°" + Integer.toString(balise.id) + " ignorée pendant le match, pas de réponses aux ping", this);
		}

        // Vérification de la cohérence des données des balises
        laser.verifier_coherence_balise();

        // Liste des balises prises en compte
        ArrayList<Balise> balises = laser.balises_actives();

        while(!threadtimer.fin_match)
        {
        	long start = System.currentTimeMillis();
			if(stop_threads)
			{
				log.debug("Stoppage du thread laser", this);
				return;
			}

			for(Balise balise: balises)
			{
                // Récupération de la position brute
				Vec2 p_bruit = laser.position_balise(balise.id); 

                // Aucune réponse valable
                if(p_bruit == null)
					continue;
                
                // Mise à jour du modèle de filtrage
                filtragelaser.update(p_bruit);

                // Récupération des valeurs filtrées
                Vec2 p_filtre = filtragelaser.position();

                // Vérification si l'obstacle est sur la table 
                if(p_filtre.x > -table_x/2 && p_filtre.y > 0 && p_filtre.x < table_x/2 && p_filtre.y < table_y)
                    table.deplacer_robot_adverse(balise.id, p_filtre);
                
                sleep((long)(1./lasers_frequence));
                long end = System.currentTimeMillis();
                filtragelaser.update_dt((int)(end-start));
			}

			laser.eteindre();
	        log.debug("Fin du thread des lasers", this);
        }
	}

}
