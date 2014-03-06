#include <stdint.h>
#include <libintech/interrupt_manager.hpp>
#include <libintech/isr.hpp>
#include "tot.hpp"

INITIALISE_INTERRUPT_MANAGER();

int main ()
{
	Communication communication;
	char ordre[20];
	
	while (1)
	{
		Communication::serial_pc::read (ordre);
		communication.execute (ordre);
	}	
	
}

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
        communications.capteurs.us1.refresh();
        communications.capteurs.us2.refresh();
        communications.capteurs.inf1.refresh();
        communications.capteurs.inf2.refresh();
    }
    overflow++;
    overflow%=5;

    communications.capteurs.maj();
}

ISR(PCINT0_vect)
{
}

ISR(PCINT1_vect)
{
}

ISR(PCINT2_vect)
{
}

ISR(PCINT3_vect)
{
    communications.capteurs.us1.interruption();
    communications.capteurs.us2.interruption();
}
