#ifndef _PORT_C_HPP
#define _PORT_C_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'C'>
{
public:
    static inline void input()
    {
        DDRC = 0x00;
        PORTC = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRC = 0x00;
        PORTC = 0xFF;
    }

    static inline void output()
    {
        DDRC = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTC = port;
    }

    static inline uint8_t read()
    {
        return PORTC;
    }
};

template<uint8_t bit>
class PinPortC
{
public:
    static inline void input()
    {
        DDRC &= ~(1 << bit);
        PORTC &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRC &= ~(1 << bit);
        PORTC |= (1 << bit);
    }

    static inline void output()
    {
        DDRC |= (1 << bit);
    }

    static inline void high()
    {
        PORTC |= (1 << bit);
    }

    static inline void low()
    {
        PORTC &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINC = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINC & (1 << bit)) >> bit);
    }
};

typedef Port<'C'> PortC;

#ifdef PORTC0
typedef PinPortC<0> C0;
#endif
#ifdef PORTC1
typedef PinPortC<1> C1;
#endif
#ifdef PORTC2
typedef PinPortC<2> C2;
#endif
#ifdef PORTC3
typedef PinPortC<3> C3;
#endif
#ifdef PORTC4
typedef PinPortC<4> C4;
#endif
#ifdef PORTC5
typedef PinPortC<5> C5;
#endif
#ifdef PORTC6
typedef PinPortC<6> C6;
#endif
#ifdef PORTC7
typedef PinPortC<7> C7;
#endif

#endif // PORT_C_HPP
