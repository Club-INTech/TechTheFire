#include <stdint.h>
#include <libintech/gpio.hpp>
#include <libintech/uart.hpp>
#include <libintech/isr.hpp>

INITIALISE_INTERRUPT_MANAGER();

int main()
{	
	uart0::init();
	uart0::change_baudrate(9600);
			
	while (1)
	{
		char a[8] ;
		uart0::read(a);
		if (strcmp(a, "?") == 0)
		{
			uart0::printfln("Hello world !");

		}


	}
	return 0 ;
}
