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
	Ax12 rateauD;						//ax12 du rateau
	Ax12 bac;
	Ax12 rateauG;							//ax12 du bac
	
	public:

//constructeur

	Communication():
		rateauD (2,1,1023),
		bac (1,1,1023),
		rateauG (3,1,1023)
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
		else if ( strcmp ( ordre , "bb" ) == 0 )			//bb = bac bas
		{
			this->bacBas ();
		}
		else if ( strcmp ( ordre , "bh" ) == 0 )			//bh = bacHaut
		{
			this->bacHaut ();
		}
 		else if ( strcmp ( ordre , "rrd" ) == 0 )			//rrd = rangerRateaud
		{
			this->rangerRateaud ();
		}
		else if ( strcmp ( ordre , "rbd" ) == 0 )			//rbd = rateauBasd
		{
			this->rateauBasd ();
		}
		else if ( strcmp ( ordre , "rhd" ) == 0 )			//rhd = rateauHautd
		{
			this->rateauHautd ();
		}
		else if ( strcmp ( ordre , "rbbd" ) == 0 )			//rbbd = rateauBasBasd
		{
			this->rateauBasBasd ();
		}
		else if ( strcmp ( ordre , "rrg" ) == 0 )			//rrg = rangerRateaug
		{
			this->rangerRateaug ();
		}
		else if ( strcmp ( ordre , "rbg" ) == 0 )			//rbg = rateauBasg
		{
			this->rateauBasg ();
		}
		else if ( strcmp ( ordre , "rhg" ) == 0 )			//rhg = rateauHautg
		{
			this->rateauHautg ();
		}
		else if ( strcmp ( ordre , "rbbg" ) == 0 )			//rbbg = rateauBasBasg
		{
			this->rateauBasBasg ();
		}
	}

//actions du bac		
	
	void bacBas ()
	{
		bac.goTo (70);
	}
	void bacHaut ()
	{
		bac.goTo (120);
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
		rateauD.goTo (170);		
	}	
	void rateauHautd ()
	{
		rateauD.goTo (110);
	}

//actions du rateau gauche

	void rangerRateaug ()
	{
		rateauG.goTo (60);
	}
	void rateauBasg ()
	{
		rateauG.goTo (150);
	}
	void rateauBasBasg ()
	{
		rateauG.goTo (170);		
	}	
	void rateauHautg ()
	{
		rateauG.goTo (110);
	}
	 
	
};

#endif
