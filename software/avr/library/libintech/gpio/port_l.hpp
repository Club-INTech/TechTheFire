#ifndef _PORT_L_HPP
#define _PORT_L_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'L'>
{
public:
    static inline void input()
    {
        DDRL = 0x00;
        PORTL = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRL = 0x00;
        PORTL = 0xFF;
    }

    static inline void output()
    {
        DDRL = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTL = port;
    }

    static inline uint8_t read()
    {
        return PORTL;
    }
};

template<uint8_t bit>
class PinPortL
{
public:
    static inline void input()
    {
        DDRL &= ~(1 << bit);
        PORTL &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRL &= ~(1 << bit);
        PORTL |= (1 << bit);
    }

    static inline void output()
    {
        DDRL |= (1 << bit);
    }

    static inline void high()
    {
        PORTL |= (1 << bit);
    }

    static inline void low()
    {
        PORTL &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINL = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINL & (1 << bit)) >> bit);
    }
};

typedef Port<'L'> PortL;

#ifdef PORTL0
typedef PinPortL<0> L0;
#endif
#ifdef PORTL1
typedef PinPortL<1> L1;
#endif
#ifdef PORTL2
typedef PinPortL<2> L2;
#endif
#ifdef PORTL3
typedef PinPortL<3> L3;
#endif
#ifdef PORTL4
typedef PinPortL<4> L4;
#endif
#ifdef PORTL5
typedef PinPortL<5> L5;
#endif
#ifdef PORTL6
typedef PinPortL<6> L6;
#endif
#ifdef PORTL7
typedef PinPortL<7> L7;
#endif

#endif // PORT_L_HPP
