#ifndef TESTLEVAGE_HPP
#define TESTLEVAGE_HPP

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>

class Communication
{
	public:

		typedef uart0 serial_pc;
		typedef uart1 serial_ax12;
		typedef AX<serial_ax12> Ax12;
		Ax12 support;				

	public:

		//constructeur

		Communication():
			support (1,1,1023)
	{
		serial_pc::init();
		serial_pc::change_baudrate (9600);
		serial_pc::activer_acquittement(true);
		serial_ax12::init();
		serial_ax12::change_baudrate (9600);
	}

		//fonction d'execution des ordres

		void execute (char ordre[])
		{
			if ( strcmp ( ordre , "?") == 0 )
			{
				serial_pc::printfln ( "1" );
			}
			else if (strcmp(ordre,"up")==0)
			{
				serial_pc::printfln ( "ok" );
				up();
			}
			else if (strcmp(ordre,"mid")==0)
			{
				serial_pc::printfln ( "ok" );
				mid();
			}
			else if (strcmp(ordre,"down")==0)
			{
				serial_pc::printfln ("ok");
				down();
			}
		}

		//actions de l'ax12

		void up()
		{
			support.goTo (60);
		}

		void mid()
		{
			support.goTo (150);
		}

		void down()
		{
			support.goTo (240);
		}
};

#endif 
