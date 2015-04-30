#ifndef ROBOT2_H_
#define ROBOT2_H_

#include <libintech/ax12.hpp>
#include <libintech/uart.hpp>
#include <util/delay.h>

class Robot2
{
private:
    typedef uart0 serial_ax12;
    typedef AX<serial_ax12> Ax12;
    Ax12 filet; //ax12 du lance-filet

public:
    Robot2() :
            filet(12, 1, 1023)
    {
        serial_ax12::init();
        serial_ax12::change_baudrate(9600);
    }

    void tirerFilet()
    {
        filet.goTo(300);
    }
    void rembobinerFilet()
    {
        filet.goTo(0);
    }
};

#endif /* ROBOT2_H_ */
