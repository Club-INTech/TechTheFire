#include <libintech/gpio.hpp>
#include <libintech/timer.hpp>
#include <libintech/uart.hpp>
#include <libintech/isr.hpp>
#include <libintech/interrupt_manager.hpp>

INITIALISE_INTERRUPT_MANAGER();

int main ()
{
	typedef D4 dir;
	typedef D6 pwm;

	dir::output();
	dir::high();//définit à l'état haut
	pwm::output();
	timer0::mode(timer0::MODE_PWM);
	timer0::set_prescaler(timer0::prescaler::PRESCALER_1); // comptage à 20Mhz
	timer0::pwm::output_mode_a(timer0::pwm::OUTPUT_NON_INVERTING);
	uart0::init();
	uart0::activer_acquittement(true);
	uart0::change_baudrate(9600);

	char order[8];

	while(1){
		uart0::read(order);
		if(!strcmp(order, "?")){
			uart0::printfln("3"); //ping pour identifier la carte
		}
		else if(!strcmp(order,"l_on")){
			timer0::pwm::pwm_a(255);//correspond à la moitié des états hauts
		}
		else if (!strcmp(order,"l_off")){
			timer0::pwm::pwm_a(0); // iil n'y aura que des états bas
		}

	}
}
