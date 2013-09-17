#include <libintech/codeuse.hpp>
#include <avr/interrupt.h>
#include <libintech/serial/serial_0_interrupt.hpp>
#include <libintech/serial/serial_0.hpp>
#include <libintech/gpio.hpp>


typedef Codeuse< D2, pcint18, D3, pcint19, false > codeuse;
typedef Serial<0> serialPC;
codeuse c;


int main()
{
	sei();
	serialPC::init();
	
	while(1)
	{
		serialPC::print(c.compteur());
	}
	return 0;
}

ISR (PCINT2_vect)
{
		c.interruption();
}
