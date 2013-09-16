#ifndef _PORT_F_HPP
#define _PORT_F_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'F'>
{
public:
    static inline void input()
    {
        DDRF = 0x00;
        PORTF = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRF = 0x00;
        PORTF = 0xFF;
    }

    static inline void output()
    {
        DDRF = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTF = port;
    }

    static inline uint8_t read()
    {
        return PORTF;
    }
};

template<uint8_t bit>
class PinPortF
{
public:
    static inline void input()
    {
        DDRF &= ~(1 << bit);
        PORTF &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRF &= ~(1 << bit);
        PORTF |= (1 << bit);
    }

    static inline void output()
    {
        DDRF |= (1 << bit);
    }

    static inline void high()
    {
        PORTF |= (1 << bit);
    }

    static inline void low()
    {
        PORTF &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINF = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINF & (1 << bit)) >> bit);
    }
};

typedef Port<'F'> PortF;

#ifdef PORTF0
typedef PinPortF<0> F0;
#endif
#ifdef PORTF1
typedef PinPortF<1> F1;
#endif
#ifdef PORTF2
typedef PinPortF<2> F2;
#endif
#ifdef PORTF3
typedef PinPortF<3> F3;
#endif
#ifdef PORTF4
typedef PinPortF<4> F4;
#endif
#ifdef PORTF5
typedef PinPortF<5> F5;
#endif
#ifdef PORTF6
typedef PinPortF<6> F6;
#endif
#ifdef PORTF7
typedef PinPortF<7> F7;
#endif

#endif // PORT_F_HPP
