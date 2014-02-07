#ifndef CHANGER_HPP
#define CHANGER_HPP

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>

class Communication
{
	public:
	
	typedef uart0 serial_pc;
	typedef uart1 serial_ax12;
	typedef AX<serial_ax12> Ax12;
  	Ax12 aChanger;
	
	public:

//constructeur

	Communication():
		aChanger(1,1,1023)
	{
		serial_pc::init();
		serial_pc::change_baudrate(9600);
		serial_pc::activer_acquittement(true);
		serial_ax12::init();
		serial_ax12::change_baudrate(9600);
	}

//fonction d'execution des ordres
	
	void execute (char ordre[])
	{
	  if ( strcmp ( ordre , "?") == 0 )
	    {
	      serial_pc::printfln( "IDchanger" );
	    }
	  else if (strcmp(ordre,"c")==0)
	    {
	      int nouveau=0;
	      serial_pc::printfln("nouvel id?");
	      serial_pc::read(nouveau);
	      aChanger.initIDB(nouveau);
	    }
	}
};

#endif
