#include <stdint.h>
#include "communication.hpp"
#include <libintech/interrupt_manager.hpp>
#include <libintech/isr.hpp>

INITIALISE_INTERRUPT_MANAGER();

int main ()
{
	Communication communication;
	Communication::serial_pc::activer_acquittement(true);

	char tab[20];
	while (1)
	{
		Communication::serial_pc::read(tab);
		communication.execute(tab);
	}
}
