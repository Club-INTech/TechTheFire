#ifndef FINDER_HPP
#define FINDER_HPP

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>

class Communication
{
	public:
	
	typedef uart0 serial_pc;
	typedef uart1 serial_ax12;
	typedef AX<serial_ax12> Ax12;
  Ax12 ax12_0 ;
  Ax12 ax12_1 ;
  Ax12 ax12_2 ;
  Ax12 ax12_3 ;
  Ax12 ax12_4 ;
  Ax12 ax12_5 ;				
	
	public:

//constructeur

	Communication():
	  ax12_0 (0,1,1023),
	  ax12_1 (1,1,1023),
	  ax12_2 (2,1,1023),
	  ax12_3 (3,1,1023),
	  ax12_4 (4,1,1023),
	  ax12_5 (5,1,1023)
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
	      serial_pc::printfln ( "ID" );
	    }
	  else if (strcmp(ordre,"t")==0)
	    {
	       	serial_pc::printfln ( "0" );
		this->ouvrir0();
		_delay_ms(2000);
		this->fermer0();
		_delay_ms(2000);
serial_pc::printfln ( "1" );
		this->ouvrir1();
		_delay_ms(2000);
		this->fermer1();
		_delay_ms(2000);
serial_pc::printfln ( "2" );
		this->ouvrir2();
		_delay_ms(2000);
		this->fermer2();
		_delay_ms(2000);
serial_pc::printfln ( "3" );
		this->ouvrir3();
		_delay_ms(2000);
		this->fermer3();
		_delay_ms(2000);
serial_pc::printfln ( "4" );
		this->ouvrir4();
		_delay_ms(2000);
		this->fermer4();
		_delay_ms(2000);
serial_pc::printfln ( "5" );
		this->ouvrir5();
		_delay_ms(2000);
		this->fermer5();
		_delay_ms(2000);
	    }
	  else if (strcmp(ordre, "test") ==0)
	    {
	      ax12_0.goToB(200);
	      serial_pc::printfln ("ceci est un test");
	    }
	  else if (strcmp(ordre,"c")==0)
	    {
	      int nouveau=0;
	      serial_pc::printfln ("nouvel id?");
	      serial_pc::read (nouveau);
	      ax12_0.initIDB (nouveau);
	    }
}

//actions des ax12	
	
	void ouvrir0 ()
	{
		ax12_0.goTo (60);
	}
	void fermer0 ()
	{
		ax12_0.goTo (240);
	}
	void ouvrir1 ()
	{
		ax12_1.goTo (60);
	}
	void fermer1 ()
	{
		ax12_1.goTo (240);
	}	
        void ouvrir2 ()
	{
		ax12_2.goTo (60);
	}
	void fermer2 ()
	{
		ax12_2.goTo (240);
	}
	void ouvrir3 ()
	{
		ax12_3.goTo (60);
	}
	void fermer3 ()
	{
		ax12_3.goTo (240);
	}
	void ouvrir4 ()
	{
		ax12_4.goTo (60);
	}
	void fermer4 ()
	{
		ax12_4.goTo (240);
	}
 	void ouvrir5 ()
	{
		ax12_5.goTo (60);
	}
	void fermer5 ()
	{
		ax12_5.goTo (240);
	}
};

#endif
