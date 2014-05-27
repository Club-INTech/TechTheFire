#ifndef MODIFS324_H
#define MODIFS324_H

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
  Ax12 axSansLimites;
	
	public:

	Communication():
	  ax12(10,1,1023),
		axSansLimites(11)
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
		else if (strcmp(ordre,"couple")==0)
		  {
		    int couple =1023;
		    serial_pc::printfln("nouveau couple entre 0 et 1023");
		    serial_pc::read(couple);
		    ax12.changeCouple(couple);
      		  }
		else if (strcmp(ordre,"anglemin")==0)
		  {
		    int anglemin =0;
		    serial_pc::printfln("angle minimum entre 0 et 1023");
		    serial_pc::read(anglemin);
		    ax12.changeAngleMIN(anglemin);
		  }
		else if (strcmp(ordre,"anglemax")==0)
		  {
		    int anglemax = 1023;
		    serial_pc::printfln("angle maximum entre 0 et 1023");
		    serial_pc::read(anglemax);
		    ax12.changeAngleMAX(anglemax);
		  }
		else if (strcmp(ordre,"angle")==0)
		  {
		    int angle = 150;
		    serial_pc::printfln("angle voulu ?");
		    serial_pc::read(angle);
		    ax12.goTo(angle);
		  }
		else if(strcmp(ordre,"nolim")==0)
		  {
		    int angle = 150;
		    serial_pc::printfln(" angle du sans lim ?");
		    serial_pc::read(angle);
		    axSansLimites.goTo(angle);
		  }
		else if (strcmp(ordre,"mov")==0)
		  {
		    if(ax12.isMoving())
		      {
			serial_pc::printfln("IL BOUUUUGE !");
		      }
		    else
		      {
			serial_pc::printfln("bouge pas");
		      }
		  }
		else if (strcmp(ordre,"pos")==0)
		  {
		    uint16_t position=0;
		    position = ax12.getPositionDegres();
		    serial_pc::printfln("position:%d", position);
		  }
	}

};
 
#endif

