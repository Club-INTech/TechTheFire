#include <stdint.h>
#include <libintech/interrupt_manager.hpp>
#include "tot.hpp"
#define IGNORE_TIMER1_OVF_vect
#define IGNORE_TIMER2_OVF_vect
#define IGNORE_TIMER0_OVF_vect
#define IGNORE_PCINT0_vect
#define IGNORE_PCINT1_vect
#define IGNORE_PCINT2_vect
#define IGNORE_PCINT3_vect
#include <libintech/isr.hpp>

INITIALISE_INTERRUPT_MANAGER();
Communication communication;
int main ()
{

	char ordre[20];
	
	while (1)
	{
		Communication::serial_pc::read (ordre);
		communication.execute (ordre);
	}	
	
}



// /!\ Interruption a debuguer !!!


ISR (TIMER1_OVF_vect)
{
}

ISR(TIMER2_OVF_vect)
{
}

ISR(TIMER0_OVF_vect) //overflow du timer 2, qui appelle le refresh d'un ou des capteur(s) SRF05 (autant de refresh que de capteurs)
{
    static uint8_t overflow=0;  //on appelle la fonction refresh qu'une fois sur 5 overflow (sinon les réponses des capteurs se superposent)
    if(overflow==0)
    {
        communication.capteurs.us1.refresh();
	//       communication.capteurs.us2.refresh();
    }
    overflow++;
    overflow%=5;

    communication.capteurs.maj();
}

ISR(PCINT0_vect)
{
  //  communication.capteurs.us2.interruption();
}

ISR(PCINT1_vect)
{
}


ISR(PCINT2_vect)
{
}

ISR(PCINT3_vect)
{
    communication.capteurs.us1.interruption();
}
