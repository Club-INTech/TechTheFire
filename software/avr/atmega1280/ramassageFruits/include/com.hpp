#ifndef COM_HPP
#define COM_HPP

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>

class Communication
{
	public:
	
	typedef uart0 serial_pc;
	typedef uart1 serial_ax12;
	typedef AX<serial_ax12> Ax12;
	Ax12 rateau;						//ax12 du rateau
	Ax12 bac;							//ax12 du bac
	
	public:

//constructeur

	Communication():
		rateau (2,1,1023),
		bac (1,1,1023)
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
			serial_pc::printfln ( "5" );
		}
		else if ( strcmp ( ordre , "bb" ) == 0 )			//bb = bac bas
		{
			this->bacBas ();
		}
		else if ( strcmp ( ordre , "bh" ) == 0 )			//bh = bacHaut
		{
			this->bacHaut ();
		}
 		else if ( strcmp ( ordre , "rr" ) == 0 )			//rr = rangerRateau
		{
			this->rangerRateau ();
		}
		else if ( strcmp ( ordre , "rb" ) == 0 )			//rb = rateauBas
		{
			this->rateauBas ();
		}
		else if ( strcmp ( ordre , "rh" ) == 0 )			//rh = rateauHaut
		{
			this->rateauHaut ();
		}
		
	}

//actions du bac		
	
	void bacBas ()
	{
		bac.goTo (70);
	}
	void bacHaut ()
	{
		bac.goTo (100);
	}

//actions du rateau

	void rangerRateau ()
	{
		rateau.goTo (60);
	}
	void rateauBas ()
	{
		rateau.goTo (150);
	}
	void rateauHaut ()
	{
		rateau.goTo (90);
	}
	 
	
};

#endif
