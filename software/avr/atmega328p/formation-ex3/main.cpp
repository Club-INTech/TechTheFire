#include <libintech/uart.hpp>
#include <libintech/isr.hpp>
#include <libintech/timer.hpp>
#include <libintech/gpio.hpp>
#include <stdint.h>

INITIALISE_INTERRUPT_MANAGER();

void f()
{
	B5::toggle();
}

int main() 
{
	B5::output();
	timer1::mode(timer1::MODE_COUNTER);
	timer1::set_prescaler(timer1::prescaler::PRESCALER_64);
	timer1::counter::overflow_interrupt::attach(f);
	timer1::counter::overflow_interrupt::enable();
	uart0::init();
	uart0::change_baudrate(9600);

	while(1)
	{
		char string[8];
		uart0::read(string);
		if (strcmp(string, "v") == 0)
		{
			uart0::printfln("%u",timer1::counter::value());
		}
	}
}
