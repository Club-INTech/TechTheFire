#ifndef MODIFS_H
#define MODIFS_H

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>


class Communication
{
	public:

	typedef uart0 serial_pc;
	typedef uart1 serial_ax12;
	typedef AX<serial_ax12> Ax12;
	Ax12 ax12;
	
	public:

	Communication():
		ax12(3,1,1023)
	{
		serial_pc::init();
		serial_pc::change_baudrate(9600);
		serial_ax12::init();
		serial_ax12::change_baudrate(9600);
	}
	void execute(char ordre[])
	{
		if (strcmp(ordre,"?") == 0)
		{
			serial_pc::printfln("modifsAX12");
		}
		else if(strcmp(ordre,"reanim")==0)
		  {
		    serial_pc::printfln("Réanim en cours");
		    ax12.reanimationMode(9600);
		    serial_pc::printfln("Reanim finie");
		  }
		else if(strcmp(ordre,"test")==0)
		  {
		    serial_pc::printfln("test");
		    ax12.goToB(90);
		    _delay_ms(500);
		    ax12.goToB(200);
		    _delay_ms(500);
		  }
		else if (strcmp(ordre,"changer")==0)
		  {
		    int nouveau=0;
		    serial_pc::printfln("nouvel id?");
		    serial_pc::read(nouveau);
		    ax12.initIDB(nouveau);
		  }		
	}

};

#endif

