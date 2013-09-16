#ifndef _PORT_K_HPP
#define _PORT_K_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'K'>
{
public:
    static inline void input()
    {
        DDRK = 0x00;
        PORTK = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRK = 0x00;
        PORTK = 0xFF;
    }

    static inline void output()
    {
        DDRK = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTK = port;
    }

    static inline uint8_t read()
    {
        return PORTK;
    }
};

template<uint8_t bit>
class PinPortK
{
public:
    static inline void input()
    {
        DDRK &= ~(1 << bit);
        PORTK &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRK &= ~(1 << bit);
        PORTK |= (1 << bit);
    }

    static inline void output()
    {
        DDRK |= (1 << bit);
    }

    static inline void high()
    {
        PORTK |= (1 << bit);
    }

    static inline void low()
    {
        PORTK &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINK = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINK & (1 << bit)) >> bit);
    }
};

typedef Port<'K'> PortK;

#ifdef PORTK0
typedef PinPortK<0> K0;
#endif
#ifdef PORTK1
typedef PinPortK<1> K1;
#endif
#ifdef PORTK2
typedef PinPortK<2> K2;
#endif
#ifdef PORTK3
typedef PinPortK<3> K3;
#endif
#ifdef PORTK4
typedef PinPortK<4> K4;
#endif
#ifdef PORTK5
typedef PinPortK<5> K5;
#endif
#ifdef PORTK6
typedef PinPortK<6> K6;
#endif
#ifdef PORTK7
typedef PinPortK<7> K7;
#endif

#endif // PORT_K_HPP
