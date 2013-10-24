#include <stdint.h>
#include <libintech/gpio.hpp>
#include <util/delay.h>
#include <libintech/serial/serial_0_interrupt.hpp>
#include <libintech/serial/serial_0.hpp>

int main()
{	
	Serial<0>::init();
	Serial<0>::change_baudrate(9600);
			
	while (1)
	{
		char a[8] ;
		Serial<0>::read(a);
		if (strcmp(a, "?") == 0)
		{
			Serial<0>::print("Hello world !");

		}


	}
	return 0 ;
}
