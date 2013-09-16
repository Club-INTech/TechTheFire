#include <stdint.h>
#include <libintech/gpio.hpp>
#include <util/delay.h>
#include <avr/io.h>

int main(){
	//mode output pour la led
	D5::output();
	while(1){
		//mettre du jus
		D5::high();
		_delay_ms(25);
		//...ou pas
		D5::low();
		_delay_ms(50);
	}
	return 0;
}
