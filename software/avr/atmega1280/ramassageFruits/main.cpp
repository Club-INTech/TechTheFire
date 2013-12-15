#include <stdint.h>
#include <libintech/interrupt_manager.hpp>
#include <libintech/isr.hpp>
#include "com.hpp"

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
