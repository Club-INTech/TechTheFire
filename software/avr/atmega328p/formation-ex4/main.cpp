#include <stdint.h>
#include <util/delay.h>
#include <libintech/timer.hpp>
#include <libintech/gpio.hpp>


int main(){
	timer0::mode(timer0::MODE_PWM);
	timer0::set_prescaler(timer0::prescaler::PRESCALER_8);

	timer0::pwm::waveform_mode(timer0::pwm::PWM_FAST);
	timer0::pwm::output_mode_b(timer0::pwm::OUTPUT_NON_INVERTING);
	timer0::pwm::pwm_b(20);

	D5::output();

	while(1);
	return 0;
}
