#include <libintech/gpio.hpp>
#include <util/delay.h>

int main(){
	//mode output pour la led
	B5::output();
	while(1)
	{
		B5::toggle();
		_delay_ms(500);
	}
	return 0;
}
