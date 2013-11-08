#ifndef _PORT_J_HPP
#define _PORT_J_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'J'>
{
public:
    static inline void input()
    {
        DDRJ = 0x00;
        PORTJ = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRJ = 0x00;
        PORTJ = 0xFF;
    }

    static inline void output()
    {
        DDRJ = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTJ = port;
    }

    static inline uint8_t read()
    {
        return PORTJ;
    }
};

template<uint8_t bit>
class PinPortJ
{
public:
    static inline void input()
    {
        DDRJ &= ~(1 << bit);
        PORTJ &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRJ &= ~(1 << bit);
        PORTJ |= (1 << bit);
    }

    static inline void output()
    {
        DDRJ |= (1 << bit);
    }

    static inline void high()
    {
        PORTJ |= (1 << bit);
    }

    static inline void low()
    {
        PORTJ &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINJ = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINJ & (1 << bit)) >> bit);
    }
};

typedef Port<'J'> PortJ;

#ifdef PORTJ0
typedef PinPortJ<0> J0;
#endif
#ifdef PORTJ1
typedef PinPortJ<1> J1;
#endif
#ifdef PORTJ2
typedef PinPortJ<2> J2;
#endif
#ifdef PORTJ3
typedef PinPortJ<3> J3;
#endif
#ifdef PORTJ4
typedef PinPortJ<4> J4;
#endif
#ifdef PORTJ5
typedef PinPortJ<5> J5;
#endif
#ifdef PORTJ6
typedef PinPortJ<6> J6;
#endif
#ifdef PORTJ7
typedef PinPortJ<7> J7;
#endif

#endif // PORT_J_HPP
