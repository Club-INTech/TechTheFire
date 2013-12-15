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
  Ax12 pince0 ;
  Ax12 pince1 ;
  Ax12 pince2 ;
  Ax12 pince3 ;
  Ax12 pince4 ;
  Ax12 pince5 ;				
	
	public:

//constructeur

	Communication():
	  pince0 (0,1,1023),
	  pince1 (1,1,1023),
	  pince2 (2,1,1023),
	  pince3 (3,1,1023),
	  pince4 (4,1,1023),
	  pince5 (5,1,1023)
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
	      serial_pc::printfln ( "2" );
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
}

//actions des ax12	
	
	void ouvrir0 ()
	{
		pince0.goTo (60);
	}
	void fermer0 ()
	{
		pince0.goTo (240);
	}
	void ouvrir1 ()
	{
		pince1.goTo (60);
	}
	void fermer1 ()
	{
		pince1.goTo (240);
	}	
        void ouvrir2 ()
	{
		pince2.goTo (60);
	}
	void fermer2 ()
	{
		pince2.goTo (240);
	}
	void ouvrir3 ()
	{
		pince3.goTo (60);
	}
	void fermer3 ()
	{
		pince3.goTo (240);
	}
	void ouvrir4 ()
	{
		pince4.goTo (60);
	}
	void fermer4 ()
	{
		pince4.goTo (240);
	}
 	void ouvrir5 ()
	{
		pince5.goTo (60);
	}
	void fermer5 ()
	{
		pince5.goTo (240);
	}
};

#endif
