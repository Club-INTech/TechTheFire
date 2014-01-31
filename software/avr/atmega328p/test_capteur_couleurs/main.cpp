#include <stdint.h>
#include <avr/io.h>
#include <libintech/gpio.hpp>
#include <libintech/uart.hpp>
#include <libintech/timer.hpp>
#include <libintech/isr.hpp>
#include <libintech/capteur_srf05.hpp>
#include <libintech/algorithm.hpp>

typedef ring_buffer<uint16_t, 4> ringBufferC; 

INITIALISE_INTERRUPT_MANAGER();

ringBufferC ringBufferValeursR, ringBufferValeursB, ringBufferValeursG;
int flag = 0;
uint16_t counter = 0, countR = 0, countG = 0, countB = 0, medR, medG, medB;
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

  D3::low();
  D4::high();
  D5::high();
  D6::low();

  timer0::mode(timer0::MODE_COUNTER);
  timer0::set_prescaler(timer0::prescaler::PRESCALER_1024);

  timer0::counter::overflow_interrupt::attach(interruption_timer);
  timer0::counter::overflow_interrupt::enable();

  int0::mode(int0::LOW_LEVEL);
  int0::attach(interruption_int0);
  int0::enable();

  char buffer[17];  

  while(1){
    uart0::read(buffer);
    if(!strcmp(buffer,"?")){
      
      ringBufferValeursR.append(countR);
      medR = mediane(ringBufferValeursR);

      ringBufferValeursB.append(countB);
      medB = mediane(ringBufferValeursB);

      ringBufferValeursG.append(countG);
      medG = mediane(ringBufferValeursG);

      if(medR/medG == 0)
	uart0::printfln("ROUGE g=%d b=%d r=%d",medG,medB,medR);
      else{
      if(medR/medG == 1)
	uart0::printfln("JAUNE g=%d b=%d r=%d",medG,medB,medR);
      else
	uart0::printfln("? g=%d %d r=%d",medG,medB,medR);
      }
//uart0::printfln("red = %d, blue = %d, green = %d", medR/100, medB/100, medG/100);
    }
  }
}

void interruption_timer()
{

	flag++;
	if(flag == 1)
	{
		countR = counter;
		D4::high(); //DD5
		D3::high(); //D6

	}
	else if(flag == 2)
	{

		countG = counter;
		D4::low();
		D3::high();

	}
	else if(flag == 3)
	{

		countB = counter;
		D4::low();
		D3::low();
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

/*Cablage: s0 = D6
           s1 = D5
           s2 = D4
           s3 = D3
           out = D2

Valeurs: RIEN: r=14 b=11/12 g=13
         JAUNE: r=13/17 b=12 g=11
         ROUGE: r=15 b=14/7 g=17
*/ 
