#include <stdint.h>
#include <util/delay.h>
#include <libintech/gpio.hpp>
#include <libintech/serial/serial_0_interrupt.hpp>
#include <libintech/serial/serial_0.hpp>

int main(){
	//initialisation led
	B5::output();

	//port serie
	char reception[10];
	Serial<0>::init();
	Serial<0>::change_baudrate(9600);
	Serial<0>::print("initialisation de la serie");

	B0::input();

	while(1){
		if(B0::read()){
			Serial<0>::print("pas contact\n");
		}else{
			Serial<0>::print("contact\n");
		}
		_delay_ms(1000);
	}
	return 0;
}
