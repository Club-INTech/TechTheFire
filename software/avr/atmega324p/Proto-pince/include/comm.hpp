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
	
	public:

//constructeur

	Communication():
		pince (0,1,1023)
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
			serial_pc::printfln ( "0" );
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
		
	}

//actions de la pince		
	
	void ouvrir ()
	{
		pince.goTo (60);
	}
	void fermer ()
	{
		pince.goTo (240);
	}
	 
	
};

#endif
