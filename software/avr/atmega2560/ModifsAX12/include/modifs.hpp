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
  Ax12 ax12_0;
  Ax12 ax12_1;
  Ax12 ax12_2;
  Ax12 ax12_3;
  Ax12 ax12_4;
  Ax12 ax12_5;
  Ax12 ax12_6;
  Ax12 ax12_7;
  Ax12 ax12_8;
  Ax12 ax12_9;
  Ax12 ax12_10;
  Ax12 ax12_11;
  Ax12 ax12_12;
  Ax12 ax12_13;

	public:

	Communication():
	  ax12_0(0,0,1023),
	  ax12_1(1,0,1023),
	  ax12_2(2,0,1023),
	  ax12_3(3,0,1023),
	  ax12_4(4,0,1023),
	  ax12_5(5,0,1023),
	  ax12_6(6,0,1023),
	  ax12_7(7,0,1023),
	  ax12_8(8,0,1023),
	  ax12_9(9,0,1023),
	  ax12_10(10,0,1023),
	  ax12_11(11,0,1023),
	  ax12_12(12,0,1023),
	  ax12_13(13,0,1023)

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
		    ax12_1.reanimationMode(9600);
		    serial_pc::printfln("Reanim finie");
		  }
		else if(strcmp(ordre,"test")==0)
		  {
		    serial_pc::printfln("test");
		    ax12_1.goToB(90);
		    _delay_ms(500);
		    ax12_1.goToB(200);
		    _delay_ms(500);
		  }
		else if (strcmp(ordre,"changer")==0)
		  {
		    int nouveau=0;
		    serial_pc::printfln("nouvel id?");
		    serial_pc::read(nouveau);
		    ax12_1.initIDB(nouveau);
		  }		
		else if (strcmp(ordre,"couple")==0)
		  {
		    int couple =1023;
		    serial_pc::printfln("nouveau couple entre 0 et 1023");
		    serial_pc::read(couple);
		    ax12_1.changeCouple(couple);
      		  }
		else if (strcmp(ordre,"anglemin")==0)
		  {
		    int anglemin =0;
		    serial_pc::printfln("angle minimum entre 0 et 1023");
		    serial_pc::read(anglemin);
		    ax12_1.changeAngleMIN(anglemin);
		  }
		else if (strcmp(ordre,"anglemax")==0)
		  {
		    int anglemax = 1023;
		    serial_pc::printfln("angle maximum entre 0 et 1023");
		    serial_pc::read(anglemax);
		    ax12_1.changeAngleMAX(anglemax);
		  }
		else if (strcmp(ordre,"angle")==0)
		  {
		    int angle = 150;
		    serial_pc::printfln("angle voulu ?");
		    serial_pc::read(angle);
		    ax12_1.goToB(angle);
		  }
		else if(strcmp(ordre,"id")==0)
		  {
		    serial_pc::printfln("Début du test \n");
serial_pc::printfln("0\n");
		    ax12_0.goTo(200);
		    _delay_ms(1000);
		    ax12_0.goTo(0);
		    _delay_ms(1000);


 serial_pc::printfln("1\n");
		    ax12_1.goTo(200);
		    _delay_ms(1000);
		    ax12_1.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("2\n");
		    ax12_2.goTo(200);
		    _delay_ms(1000);
		    ax12_2.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("3\n");
		    ax12_3.goTo(200);
		    _delay_ms(1000);
		    ax12_3.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("4\n");
		    ax12_4.goTo(200);
		    _delay_ms(1000);
		    ax12_4.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("5\n");
		    ax12_5.goTo(200);
		    _delay_ms(1000);
		    ax12_5.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("6\n");
		    ax12_6.goTo(200);
		    _delay_ms(1000);
		    ax12_6.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("7\n");
		    ax12_7.goTo(200);
		    _delay_ms(1000);
		    ax12_7.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("8\n");
		    ax12_8.goTo(200);
		    _delay_ms(1000);
		    ax12_8.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("9\n");
		    ax12_9.goTo(200);
		    _delay_ms(1000);
		    ax12_9.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("10\n");
		    ax12_10.goTo(200);
		    _delay_ms(1000);
		    ax12_10.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("11\n");
		    ax12_11.goTo(200);
		    _delay_ms(1000);
		    ax12_11.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("12\n");
		    ax12_12.goTo(200);
		    _delay_ms(1000);
		    ax12_12.goTo(0);
		    _delay_ms(1000);

 serial_pc::printfln("13\n");
		    ax12_13.goTo(200);
		    _delay_ms(1000);
		    ax12_13.goTo(0);
		    _delay_ms(1000);
 serial_pc::printfln("Fin du test");

		  }
	  }
};
 
#endif

