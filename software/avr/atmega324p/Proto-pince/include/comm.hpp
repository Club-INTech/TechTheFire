#ifndef COMM_HPP
#define COMM_HPP

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
	Ax12 positionGauche;
	Ax12 orientationGauche;
	Ax12 pinceDroite; //ax12 de la pince droite
	Ax12 positionDroite; 
	Ax12 orientationDroite;
	
	public:

//constructeur

	Communication():
		pinceGauche (0,1,1023),
		positionGauche (2,1,1023),
		orientationGauche (1,1,1023),
		pinceDroite (3,1,1023),
		positionDroite (5,1,1023),
		orientationDroite (4,1,1023)
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
			serial_pc::printfln ( "pince" );
		}
		else if ( strcmp ( ordre , "og" ) == 0 )			//o = ouvrir
		{
			this->ouvrirGauche ();
		}
		else if ( strcmp ( ordre , "od" ) == 0 )		       
		{
			this->ouvrirDroite ();
		}
		else if ( strcmp ( ordre , "fg" ) == 0 )			//f = fermer
		{
			this->fermerGauche ();
		}
		else if ( strcmp ( ordre , "fd" ) == 0 )			
		{
			this->fermerDroite ();
		}
 		else if ( strcmp ( ordre , "ag" ) == 0 )			//a = angle
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
		else if ( strcmp ( ordre , "bg" ) == 0)
// b = position basse
		{
			this -> basGauche ();
		}
		else if ( strcmp ( ordre , "bd" ) == 0)
		{
			this -> basDroite ();
		}
		else if ( strcmp (ordre , "mg" ) == 0)
// m = milieu 
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

		else if (strcmp (ordre , "angleg") == 0)
// angle de l'ax 12 de position
		{
			serial_pc::printfln ( "angle?" );			
			uint16_t p,o;
			serial_pc::read (p);
			positionGauche.goTo (p);
			  if ((p-150) < 0)
			    {
			      o = 330-p ;
			    }
			  else
			    {
			      o = p-150 ;
			    }
			orientationGauche.goTo (o);
			}
		else if (strcmp (ordre , "angled") == 0)
		{
			serial_pc::printfln ( "angle?" );			
			int p,o;
			serial_pc::read (p);
			positionDroite.goTo (p);
			  if ((p-150) < 0)
			    {
			      o = 330-p ;
			    }
			  else
			    {
			      o = p-150 ;
			    }
			orientationDroite.goTo (o);
			}
	}

//actions de la pince		
	
	void ouvrirGauche ()
	{
		pinceGauche.goTo (60);
	}
	void fermerGauche ()
	{
	  uint16_t positionPrecedente = (pinceGauche.getPosition_0_1023());
	  uint16_t positionActuelle = positionPrecedente ;
	  pinceGauche.goTo(155);
	  for(int i=0; i<7;i++)
	      {
		_delay_ms(100);
		positionActuelle = (pinceGauche.getPosition_0_1023());
		if (positionActuelle == positionPrecedente) // vu qu'on a attendu 0,1 s, si on est toujours à la meme position, c'est que ça bloque
		  pinceGauche.goTo(positionActuelle);//Dans ce cas on bloque l'ax12 là où il est
	      }
	}
	void basGauche ()
	{
		orientationGauche.goTo(270);
		positionGauche.goTo(60);
	}
	void milieuGauche ()
	{
		orientationGauche.goTo(185);
		positionGauche.goTo(150);
	}
	void hautGauche ()
	{
	  	positionGauche.goTo(240);
		_delay_ms(600);
		orientationGauche.goTo(100);
	}
	void ouvrirDroite ()
	{
		pinceDroite.goTo (180);
	}
	void fermerDroite ()
	{
	  uint16_t positionPrecedente = (pinceDroite.getPosition_0_1023());
	  uint16_t positionActuelle = positionPrecedente ;
	  pinceDroite.goTo(90);
	  for(int i=0; i<7; i++)
	      {
		_delay_ms(100);
		positionActuelle = (pinceDroite.getPosition_0_1023());
		if (positionActuelle == positionPrecedente) // vu qu'on a attendu 0,1 s, si on est toujours à la meme position, c'est que ça bloque
		  pinceDroite.goTo(positionActuelle);//Dans ce cas on bloque l'ax12 là où il est
		else // on est encore en mouvement, donc on actualise la position
		 positionPrecedente = positionActuelle ;
	      }
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
  void test ()
  {
    positionDroite.goToB(200);
  }	
};

#endif
