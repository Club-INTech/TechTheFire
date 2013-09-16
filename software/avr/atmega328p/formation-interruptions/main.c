#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <libintech/gpio.hpp>
#include <libintech/serial/serial_0_interrupt.hpp>
#include <libintech/serial/serial_0.hpp>

int main(){
	//initialisation led
	B5::output();

	//port serie
	Serial<0>::init();
	Serial<0>::change_baudrate(9600);
	Serial<0>::print("initialisation de la serie");

	//passage d'un pin en ouput
	D6::output();
	D6::low(); //éteint

	//activation des interruptions
	sei();
	//Configuration sur front montant des INT0 et 1
	int0::mode(int0::RISING_EDGE);
	int1::mode(int1::RISING_EDGE);
	//Activation des interruptions
	int0::enable();
	int1::enable();
	while(1){
		Serial<0>::print("tout vas bien.");
		D6::toggle();
		_delay_ms(1000);
	}
	return 0;
}

ISR(INT0_vect){
	Serial<0>::print("0");
}
ISR(INT1_vect){
	Serial<0>::print("1");
}
