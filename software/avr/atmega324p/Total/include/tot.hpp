#ifndef TOT_HPP
#define TOT_HPP

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>

class Communication
{
	public:
	
	typedef uart0 serial_pc;
	typedef uart1 serial_ax12;
	typedef AX<serial_ax12> Ax12;
	Ax12 pinceGauche; //ax12 de la pince gauche
	Ax12 orientationGauche;
	Ax12 positionGauche;
 	Ax12 retourneurGauche;
 	Ax12 pinceDroite; //ax12 de la pince droite
	Ax12 orientationDroite;
	Ax12 positionDroite; 
	Ax12 retourneurDroite ;
  	Ax12 rateauG; //ax12 du rateau gauche	
  	Ax12 rateauD; //ax12 du rateau droit
	Ax12 bac; //ax12 du bac
	Ax12 chargeur; //ax12 du chargeur
	
	public:

//constructeur

	Communication():
		pinceGauche (0,1,1023),
		orientationGauche (1,1,1023),
		positionGauche (2,1,1023),
		retourneurGauche (3,1,1023),
		pinceDroite (4,1,1023),
		orientationDroite (5,1,1023),
		positionDroite (6,1,1023),
		retourneurDroite (7,1,1023),
		rateauG (8,1,1023),
		rateauD (9,1,1023),
		bac (10,1,1023)

	{
		serial_pc::init();
		serial_pc::change_baudrate (9600);
		serial_pc::activer_acquittement(true);
		serial_ax12::init();
		serial_ax12::change_baudrate (9600);
	}

//fonction d'execution des ordres
	
	void execute ( char ordre[] )
	{
		if ( strcmp ( ordre , "?") == 0 )
		{
			serial_pc::printfln ( "3" );
		}
		else if ( strcmp ( ordre , "og" ) == 0 )  //o = ouvrir
		{
			this->ouvrirGauche ();
		}
		else if ( strcmp ( ordre , "od" ) == 0 )		       
		{
			this->ouvrirDroite ();
		}
		else if ( strcmp ( ordre , "fg" ) == 0 )  //f = fermer
		{
			this->fermerGauche ();
		}
		else if ( strcmp ( ordre , "fd" ) == 0 )			
		{
			this->fermerDroite ();
		}
 		else if ( strcmp ( ordre , "ag" ) == 0 )  //a = angle
		{
			serial_pc::printfln ( "angle?" );			
			uint16_t i;
			serial_pc::read (i);
			pinceGauche.goTo (i);
		}
		else if ( strcmp ( ordre , "ad" ) == 0 )		       
		{
			serial_pc::printfln ( "angle?" );			
			uint16_t i;
			serial_pc::read (i);
			pinceDroite.goTo (i);
		}
		else if ( strcmp ( ordre , "bg" ) == 0)  // b = position basse
		{
			this -> basGauche ();
		}
		else if ( strcmp ( ordre , "tg" ) == 0)  // retourner un feu
		{
			this -> retournerGauche ();
		}
		else if ( strcmp ( ordre , "rg" ) == 0)  // remettre en position initiale niveau rotation
		{
			this -> retablirGauche ();
		}
		else if ( strcmp ( ordre , "bd" ) == 0)
		{
			this -> basDroite ();
		}
		else if ( strcmp (ordre , "mg" ) == 0)  // m = milieu 
		{
			this -> milieuGauche ();
		}
		else if ( strcmp (ordre , "md" ) == 0)
		{
			this -> milieuDroite ();
		}
		else if (strcmp (ordre , "hg") ==0)
		{
       	       		this -> hautGauche ();
		}
		else if (strcmp (ordre , "hd") ==0)
		{
       	       		this -> hautDroite ();
		}

		else if (strcmp (ordre, "test")==0)
		  {
		    this -> test ();
		  }
		else if ( strcmp ( ordre , "bb" ) == 0 )  //bb = bac bas
		{
			this->bacBas ();
		}
		else if ( strcmp ( ordre , "bh" ) == 0 )  //bh = bacHaut
		{
			this->bacHaut ();
		}
 		else if ( strcmp ( ordre , "rrd" ) == 0 )  //rrd = rangerRateaud
		{
			this->rangerRateaud ();
		}
		else if ( strcmp ( ordre , "rbd" ) == 0 )  //rbd = rateauBasd
		{
			this->rateauBasd ();
		}
		else if ( strcmp ( ordre , "rhd" ) == 0 )  //rhd = rateauHautd
		{
			this->rateauHautd ();
		}
		else if ( strcmp ( ordre , "rbbd" ) == 0 )  //rbbd = rateauBasBasd
		{
			this->rateauBasBasd ();
		}
		else if ( strcmp ( ordre , "rrg" ) == 0 )  //rrg = rangerRateaug
		{
			this->rangerRateaug ();
		}
		else if ( strcmp ( ordre , "rbg" ) == 0 )  //rbg = rateauBasg
		{
			this->rateauBasg ();
		}
		else if ( strcmp ( ordre , "rhg" ) == 0 )  //rhg = rateauHautg
		{
			this->rateauHautg ();
		}
		else if ( strcmp ( ordre , "rbbg" ) == 0 )  //rbbg = rateauBasBasg
		{
			this->rateauBasBasg ();
		}
		else if ( strcmp ( ordre , "tourne" ) == 0 )  
		{
			this->tourner (a);
		}
		else if ( strcmp ( ordre , "reload" ) == 0 )  
		{
			this->reload ();
		}
	}


//actions de la pince gauche		
	
	void ouvrirGauche ()
	{
		pinceGauche.goTo (0);
	}
	void fermerGauche ()
	{
//	  uint16_t positionPrecedente = (pinceGauche.getPosition_0_1023());
//	  uint16_t positionActuelle = positionPrecedente ;
	  pinceGauche.goTo(65);
/*	  for(int i=0; i<7;i++)
	      {
		_delay_ms(100);
		positionActuelle = (pinceGauche.getPosition_0_1023());
		if (positionActuelle == positionPrecedente) // vu qu'on a attendu 0,1 s, si on est toujours à la meme position, c'est que ça bloque
		  pinceGauche.goTo(positionActuelle);//Dans ce cas on bloque l'ax12 là où il est
	      }*/
	}
	void basGauche ()
	{
		positionGauche.goTo(60);
		orientationGauche.goTo(210);
	}
	void milieuGauche ()
	{
		positionGauche.goTo(150);
		orientationGauche.goTo(120);

	}
	void hautGauche ()
	{
	  	positionGauche.goTo(240);
		_delay_ms(300);
		orientationGauche.goTo(30);
		_delay_ms(200);
		orientationGauche.goTo(120); //cet ajout a pour but de mettre la pince verticale, qu'elle prenne moins de place.
	}
void retournerGauche ()
  {
    retourneurGauche.goTo (60);
  }
  void retablirGauche ()
  {
    retourneurGauche.goTo (240);
  }


//actions de la pince droite

	void ouvrirDroite ()
	{
		pinceDroite.goTo (180);
	}
	void fermerDroite ()
	{
//	  uint16_t positionPrecedente = (pinceDroite.getPosition_0_1023());
//	  uint16_t positionActuelle = positionPrecedente ;
	  pinceDroite.goTo(90);
/*	  for(int i=0; i<7; i++)
	      {
		_delay_ms(100);
		positionActuelle = (pinceDroite.getPosition_0_1023());
		if (positionActuelle == positionPrecedente) // vu qu'on a attendu 0,1 s, si on est toujours à la meme position, c'est que ça bloque
		  pinceDroite.goTo(positionActuelle);//Dans ce cas on bloque l'ax12 là où il est
		else // on est encore en mouvement, donc on actualise la position
		 positionPrecedente = positionActuelle ;
	      }*/
	}
	void basDroite ()
	{
		orientationDroite.goTo(270);
		positionDroite.goTo(60);
	}
	void milieuDroite ()
	{
		orientationDroite.goTo(185);
		positionDroite.goTo(150);
	}
	void hautDroite ()
	{
	  	positionDroite.goTo(240);
		_delay_ms(600);
		orientationDroite.goTo(100);
	}
 void retournerDroite ()
  {
    retourneurDroite.goTo (60);
  }
  void retablirDroite ()
  {
    retourneurDroite.goTo (240);
  }
  void test ()
  {
    positionDroite.goToB(200);
  }


//action du bac

	void bacBas ()
	{
		bac.goTo (60);
	}
	void bacHaut ()
	{
		bac.goTo (110);
	}


//actions du rateau droit

	void rangerRateaud ()
	{
		rateauD.goTo (60);
	}
	void rateauBasd ()
	{
		rateauD.goTo (150);
	}
	void rateauBasBasd ()
	{
		bac.goTo (50);
		rateauD.goTo (170);		
	}	
	void rateauHautd ()
	{
		rateauD.goTo (95);
	}


//actions du rateau gauche

	void rangerRateaug ()
	{
		rateauG.goTo (240);
	}
	void rateauBasg ()
	{
		rateauG.goTo (150);
	}
	void rateauBasBasg ()
	{
		bac.goTo (50);	
		rateauG.goTo (130);		
	}	
	void rateauHautg ()
	{
		rateauG.goTo (205);
	}	
};

//actions du chargeur

	void tourner ()
	{
		static int a=0;
		if (a=300)
		{
			a=0;
		}
		else
		{
			a+=60;
		}
		chargeur.goTo (a);	
	}
	void reload ()
	{
		chargeur.goTo (0);
	}
	
	


#endif
