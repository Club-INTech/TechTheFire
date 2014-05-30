#include <stdint.h>
#include "Robot2.hpp"
#include <libintech/interrupt_manager.hpp>
#include <libintech/isr.hpp>
#include <libintech/gpio.hpp>

INITIALISE_INTERRUPT_MANAGER();

int main ()
{
    Robot2 robot2;
    B5::output();
    _delay_ms(10000);
    //_delay_ms(91000);
    B5::toggle();
    robot2.tirerFilet();
    while (1)
    {
    }
}
