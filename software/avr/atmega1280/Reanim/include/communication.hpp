#ifndef COMMUNICATION_H
#define COMMUNICATION_H

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
		ax12(1,1,1023)
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
			serial_pc::printfln("reanim");
		}
		else if(strcmp(ordre,"reanim")==0)
		  {
		    serial_pc::printfln("Réanim en cours");
		    ax12.reanimationMode(9600);
		    serial_pc::printfln("Reanim finie");
		  }
		else if(strcmp(ordre,"test")==0)
		  {
		    ax12.goTo(90);
		    _delay_ms(750);
		    ax12.goTo(180);
		    _delay_ms(750);
		  }
	}

};

#endif

