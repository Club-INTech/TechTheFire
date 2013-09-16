#ifndef _PORT_G_HPP
#define _PORT_G_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'G'>
{
public:
    static inline void input()
    {
        DDRG = 0x00;
        PORTG = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRG = 0x00;
        PORTG = 0xFF;
    }

    static inline void output()
    {
        DDRG = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTG = port;
    }

    static inline uint8_t read()
    {
        return PORTG;
    }
};

template<uint8_t bit>
class PinPortG
{
public:
    static inline void input()
    {
        DDRG &= ~(1 << bit);
        PORTG &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRG &= ~(1 << bit);
        PORTG |= (1 << bit);
    }

    static inline void output()
    {
        DDRG |= (1 << bit);
    }

    static inline void high()
    {
        PORTG |= (1 << bit);
    }

    static inline void low()
    {
        PORTG &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PING = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PING & (1 << bit)) >> bit);
    }
};

typedef Port<'G'> PortG;

#ifdef PORTG0
typedef PinPortG<0> G0;
#endif
#ifdef PORTG1
typedef PinPortG<1> G1;
#endif
#ifdef PORTG2
typedef PinPortG<2> G2;
#endif
#ifdef PORTG3
typedef PinPortG<3> G3;
#endif
#ifdef PORTG4
typedef PinPortG<4> G4;
#endif
#ifdef PORTG5
typedef PinPortG<5> G5;
#endif
#ifdef PORTG6
typedef PinPortG<6> G6;
#endif
#ifdef PORTG7
typedef PinPortG<7> G7;
#endif

#endif // PORT_G_HPP
