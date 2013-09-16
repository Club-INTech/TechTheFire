#ifndef _PORT_B_HPP
#define _PORT_B_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'B'>
{
public:
    static inline void input()
    {
        DDRB = 0x00;
        PORTB = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRB = 0x00;
        PORTB = 0xFF;
    }

    static inline void output()
    {
        DDRB = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTB = port;
    }

    static inline uint8_t read()
    {
        return PORTB;
    }
};

template<uint8_t bit>
class PinPortB
{
public:
    static inline void input()
    {
        DDRB &= ~(1 << bit);
        PORTB &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRB &= ~(1 << bit);
        PORTB |= (1 << bit);
    }

    static inline void output()
    {
        DDRB |= (1 << bit);
    }

    static inline void high()
    {
        PORTB |= (1 << bit);
    }

    static inline void low()
    {
        PORTB &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINB = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINB & (1 << bit)) >> bit);
    }
};

typedef Port<'B'> PortB;

#ifdef PORTB0
typedef PinPortB<0> B0;
#endif
#ifdef PORTB1
typedef PinPortB<1> B1;
#endif
#ifdef PORTB2
typedef PinPortB<2> B2;
#endif
#ifdef PORTB3
typedef PinPortB<3> B3;
#endif
#ifdef PORTB4
typedef PinPortB<4> B4;
#endif
#ifdef PORTB5
typedef PinPortB<5> B5;
#endif
#ifdef PORTB6
typedef PinPortB<6> B6;
#endif
#ifdef PORTB7
typedef PinPortB<7> B7;
#endif

#endif // PORT_B_HPP
