#include <stdint.h>
#include <avr/io.h>
#include <libintech/gpio.hpp>
#include <libintech/uart.hpp>
#include <libintech/timer.hpp>
#include <libintech/isr.hpp>
#include <libintech/algorithm.hpp>

typedef ring_buffer<uint16_t, NB_VALEURS_MEDIANE_SRF> ringBufferSRF;

INITIALISE_INTERRUPT_MANAGER();

int flag = 0;
uint16_t counter = 0, countR = 0, countG = 0, countB = 0;
void interruption_timer();
void interruption_int0();

int main() {

  D6::output();
  D5::output();
  D4::output();
  D3::output();
  D2::input();

  uart0::init();
  uart0::change_baudrate(9600); // vitesse de connection: 9600

  D3::high();
  D4::high();
  D5::high();
  D6::low();

  timer0::mode(timer0::MODE_COUNTER);
  timer0::prescaler(timer0::PRESCALER_1);

  timer0::counter::overflow_interrupt::attach(interruption_timer);
  timer0::counter::overflow_interrupt::enable();

  int0::mode(int0::LOW_LEVEL);
  int0::attach(interruption_int0);
  int0::enable();

  char buffer[17];  

  while(1){
    uart0::read(buffer);
    if(!strcmp(buffer,"?")){

      uart0::printfln("red = %d, blue = %d, green = %d", countR, countB, countG);
    }
  }
}

void interruption_timer()
{

	flag++;
	if(flag == 1)
	{
		countR = counter;
		D5::high();
		D6::high();

	}
	else if(flag == 2)
	{

		countG = counter;
		D5::low();
		D6::high();

	}
	else if(flag == 3)
	{

		countB = counter;
		D5::low();
		D6::low();
	}
	else if(flag == 4)
	{

		flag = 0;
	}
	counter = 0;
}

void interruption_int0()
{
	counter++;
}
