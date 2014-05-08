#ifndef TOT_HPP
#define TOT_HPP

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>
#include "capteurs.hpp"



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
        Ax12 filet; //ax12 du lance-filet
	Capteurs capteurs;
 


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
		bac (10,1,1023),
		chargeur (11,1,1023),
		filet (12,1,1023)

	{
		serial_pc::init();
		serial_pc::change_baudrate (57600);
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

	//Actions pince gauche
		else if ( strcmp ( ordre , "og" ) == 0 )  //o = ouvrir
		{
			this->ouvrirGauche ();
		}
		else if ( strcmp ( ordre , "od" ) == 0 )		       
		{
			this->ouvrirDroite ();
		}
        else if ( strcmp ( ordre , "obd" ) == 0 )		       
		{
			this->ouvrirBasDroite ();
		}
		else if ( strcmp ( ordre , "fg" ) == 0 )  //f = fermer
		{
			this->fermerGauche ();
		}
		else if ( strcmp ( ordre , "fd" ) == 0 )			
		{
			this->fermerDroite ();
		}
		else if ( strcmp ( ordre , "pfd" ) == 0 )			
		{
			this->presqueFermerDroite ();
		}
 		else if ( strcmp ( ordre , "ag" ) == 0 )  //a = angle
		{
			serial_pc::printfln ( "angle?" );			
			uint16_t i;
			serial_pc::read (i);
			pinceGauche.goTo (i);
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
		else if ( strcmp (ordre , "mg" ) == 0)  // m = milieu
		{
			this -> milieuGauche ();
		}
		else if (strcmp (ordre , "hg") ==0)
		{
       	       		this -> hautGauche ();
		}
		else if (strcmp (ordre, "torcheg")==0)
		  {
		    this -> torcheGauche();
		  }
	//Actions pinces droite
		else if ( strcmp ( ordre , "od" ) == 0 )
		{
			this->ouvrirDroite ();
		}
		else if ( strcmp ( ordre , "fd" ) == 0 )
		{
			this->fermerDroite ();
		}
		else if ( strcmp ( ordre , "ad" ) == 0 )
		{
			serial_pc::printfln ( "angle?" );
			uint16_t i;
			serial_pc::read (i);
			pinceDroite.goTo (i);
		}
		else if ( strcmp ( ordre , "td" ) == 0)  // retourner un feu à droite
		{
			this -> retournerDroite ();
		}
		else if ( strcmp ( ordre , "rd" ) == 0)  // remettre en position initiale niveau rotation à droite
		{
			this -> retablirDroite ();
		}
		else if ( strcmp ( ordre , "bd" ) == 0)
		{
			this -> basDroite ();
		}
		else if ( strcmp (ordre , "md" ) == 0)
		{
			this -> milieuDroite ();
		}
		else if (strcmp (ordre , "hd") ==0)
		{
       	       		this -> hautDroite ();
		}
		else if (strcmp (ordre, "torched")==0)
		  {
		    this -> torcheDroite ();
		  }
		else if (strcmp (ordre , "pg") ==0)
		{
       	       		this -> posGauche ();
		}
		else if (strcmp (ordre , "pd") ==0)
		{
       	       		this -> posDroite ();
		}
		else if (strcmp (ordre , "tombeg") ==0)
		{
       	       		this -> tombeGauche();
		}
		else if (strcmp (ordre , "tombed") ==0)
		{
       	       		this -> tombeDroite ();
		}
		/*
		  else if (strcmp (ordre, "hrd") ==0)
		  {
		    this -> remonterEtRetablirDroite ();
		  }
		else if (strcmp (ordre, "hrg") ==0)
		  {
		    this -> remonterEtRetablirGauche ();
		  }
		*/
		else if (strcmp (ordre, "test")==0)
		  {
		    this -> test ();
		  }

	//Actions bac
		else if ( strcmp ( ordre , "bb" ) == 0 )  //bb = bac bas
		{
			this->bacBas ();
		}
		else if ( strcmp ( ordre , "bh" ) == 0 )  //bh = bacHaut
		{
			this->bacHaut ();
		}

	//Actions rateau droit
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

	//Actions rateau gauche
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

	//Actions chargeur
		else if ( strcmp ( ordre , "tourne" ) == 0 )  
		{
			this->tourner();
		}
		else if ( strcmp ( ordre , "reload" ) == 0 )  
		{
			this->reload();
		}
		//Actions lance-filet
		else if ( strcmp ( ordre , "tf" ) == 0 )  
		{
			this->tirerFilet();
		}
		else if ( strcmp ( ordre , "rf" ) == 0 )  
		{
			this->rembobinerFilet();
		}
	//Actions ventilo
        else if (strcmp(ordre, "von") == 0)
        {
        	D4::high();
	// c'est plus D4, c'est la pin connectée au PWM
        }
        else if (strcmp(ordre, "voff") ==0)
        {
        	D4::low();
        }

	// infrarouge
        else if (strcmp(ordre, "ir_g")==0)
        {
            serial_pc::print(capteurs.inf1.value());
        }
        else if (strcmp(ordre, "ir_d")==0)
        {
	  //TODO dans capteurs.hpp    serial_pc::print(capteurs.inf1.value());
        }
		
	// Ultrasons SRF05
        else if (strcmp(ordre, "us_av")==0)
        {
            serial_pc::print(capteurs.us1.value());
        }
	        
	// JUMPER DE DÉBUT DE MATCH
       	else if (strcmp(ordre, "j") == 0)
       	{
       	    serial_pc::print(C2::read());
       	}
	
	// CAPTEURS CONTACT
       	else if (strcmp(ordre, "cg") == 0)
       	{
       	    serial_pc::print(capteurs.contactGauche());
       	}
       	else if (strcmp(ordre, "cm") == 0)
       	{
       	    serial_pc::print(capteurs.contactMilieu());
       	}
        else if (strcmp(ordre, "cd") == 0)
       	{
       	    serial_pc::print(capteurs.contactDroit());
       	}
	}


//actions de la pince gauche		
	
	void ouvrirGauche ()
	{
		pinceGauche.goTo (60);
	}
	void fermerGauche ()
	{
//	  uint16_t positionPrecedente = (pinceGauche.getPosition_0_1023());
//	  uint16_t positionActuelle = positionPrecedente ;
	  pinceGauche.goTo(153);
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
		positionGauche.goTo(210);
		orientationGauche.goTo(82);
	}
	void milieuGauche ()
	{
		positionGauche.goTo(140);
		orientationGauche.goTo(155);
	}
	void hautGauche ()
	{
	  retablirGauche();
	  	positionGauche.goTo(60);
		_delay_ms(300);
		orientationGauche.goTo(110);
		_delay_ms(200);
		orientationGauche.goTo(125); //cet ajout a pour but de mettre la pince verticale, qu'elle prenne moins de place.
	}
void retournerGauche ()
  {
    retourneurGauche.goTo (240);
  }
  void retablirGauche ()
  {
    retourneurGauche.goTo (60);
  }

void posGauche ()
  {
    	serial_pc::printfln ( "angle?" );			
        uint16_t i;
	serial_pc::read (i);
	positionGauche.goTo(i);
	orientationGauche.goTo(300-i);
  }

 void tombeGauche ()
  {
    pinceGauche.goTo(0);
  }

 void torcheGauche ()
	{

	  pinceGauche.goTo (60);
	  orientationGauche.goTo(175);
	  positionGauche.goTo(115);
	}


  /*
  void remonterEtRetablirGauche ()
  {
    orientationGauche.goTo(120);
	positionGauche.goTo(120);
	_delay_ms(500);
	retourneurGauche.goTo (60);
	hautGauche();
  }
  inutile pour l'instant
  */
//actions de la pince droite

	void ouvrirDroite ()
	{
		pinceDroite.goTo (200);
	}
	void fermerDroite ()
	{
//	  uint16_t positionPrecedente = (pinceDroite.getPosition_0_1023());
//	  uint16_t positionActuelle = positionPrecedente ;
	  pinceDroite.goTo(130);
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
		positionDroite.goTo(215);
		orientationDroite.goTo(220);
	}
    void ouvrirBasDroite ()
	{
		positionDroite.goTo(215);
		orientationDroite.goTo(220);
        _delay_ms(250);
        ouvrirDroite();
	}
		
    void milieuDroite ()
	{
		positionDroite.goTo(150);
		orientationDroite.goTo(155);
	}
 
	void hautDroite ()
	{
	  retablirDroite();
	  	positionDroite.goTo(70);
		_delay_ms(450);
		orientationDroite.goTo(200);
		_delay_ms(200);
		orientationDroite.goTo(175);
	}
  void posDroite ()
  {
    	serial_pc::printfln ( "angle?" );			
        uint16_t i;
	serial_pc::read (i);
	positionDroite.goTo(i);
	orientationDroite.goTo(290-i);
  }
void torcheDroite ()
	{
	  pinceDroite.goTo (213);
	  positionDroite.goTo(120);
	  orientationDroite.goTo(170);
	}
  void tombeDroite ()
  {
    pinceDroite.goTo(300);
  }

 void retournerDroite ()
  {
    retourneurDroite.goTo (60);
  }
  void retablirDroite ()
  {
    retourneurDroite.goTo (240);
  }
	void presqueFermerDroite ()
	{
	  pinceDroite.goTo(160);
	}
  /* void remonterEtRetablirDroite ()
  {
    	orientationDroite.goTo(145);
	positionDroite.goTo(180);
	_delay_ms(500);
	retourneurDroite.goTo (240);
	hautDroite();
  }
  inutile pour le moment
  */
  // test généralisé
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
		rateauD.goTo (105);
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
		rateauG.goTo (195);
	}	


//actions du chargeur

	void tourner ()
	{
		static int a=50;
		if (a>=300)
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

  //Actions du lance-filet

	void tirerFilet ()
	{
		filet.goTo (300);
	}
	void rembobinerFilet ()
	{
		filet.goTo (0);
	}



};

#endif
