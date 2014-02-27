#include <stdint.h>
#include <libintech/gpio.hpp>
#include <util/delay.h>

int main()
{
	B5::output();
	B4::output();
	B3::output();
	B2::output();
	while (1)
	{
		B5::toggle();
		if ((B5::read())) 
		{ B4::toggle() ;
		if ((B4::read()))
		{B3::toggle() ;
		if ((B3::read()))
		{B2::toggle() ;}
		}
		}
		_delay_ms(500);
	}
	return 0 ;
}
