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
	Ax12 pince;						//ax12 de la pince
	Ax12 position;
	Ax12 orientation;
	
	public:

//constructeur

	Communication():
		pince (0,1,1023),
		orientation (1,1,1023),
		position (2,1,1023)
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
		else if ( strcmp ( ordre , "o" ) == 0 )			//o = ouvrir
		{
			this->ouvrir ();
		}
		else if ( strcmp ( ordre , "f" ) == 0 )			//f = fermer
		{
			this->fermer ();
		}
 		else if ( strcmp ( ordre , "a" ) == 0 )			//a = angle
		{
			serial_pc::printfln ( "angle?" );			
			int i;
			serial_pc::read (i);
			pince.goTo (i);
		}
		else if ( strcmp ( ordre , "b" ) == 0)
		{
			this -> bas ();
		}
		else if ( strcmp (ordre , "m" ) == 0)
		{
			this -> milieu ();
		}
		else if (strcmp (ordre , "h") ==0)
		{
       	       		this -> haut ();
		}
		else if (strcmp (ordre , "angle") == 0)
		{
			serial_pc::printfln ( "angle?" );			
			int p,o;
			serial_pc::read (p);
			position.goTo (p);
			  if ((p-150) < 0)
			    {
			      o = 330-p ;
			    }
			  else
			    {
			      o = p-150 ;
			    }
			orientation.goTo (o);
			}
	}

//actions de la pince		
	
	void ouvrir ()
	{
		pince.goTo (60);
	}
	void fermer ()
	{
		pince.goTo (150);
	}
	void bas ()
	{
		orientation.goTo(270);
		position.goTo(60);
	}
	void milieu ()
	{
		orientation.goTo(185);
		position.goTo(150);
	}
	void haut ()
	{
	  	position.goTo(240);
		_delay_ms(600);
		orientation.goTo(100);
	}
	
	
};

#endif
