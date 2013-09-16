#ifndef _PORT_D_HPP
#define _PORT_D_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'D'>
{
public:
    static inline void input()
    {
        DDRD = 0x00;
        PORTD = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRD = 0x00;
        PORTD = 0xFF;
    }

    static inline void output()
    {
        DDRD = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTD = port;
    }

    static inline uint8_t read()
    {
        return PORTD;
    }
};

template<uint8_t bit>
class PinPortD
{
public:
    static inline void input()
    {
        DDRD &= ~(1 << bit);
        PORTD &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRD &= ~(1 << bit);
        PORTD |= (1 << bit);
    }

    static inline void output()
    {
        DDRD |= (1 << bit);
    }

    static inline void high()
    {
        PORTD |= (1 << bit);
    }

    static inline void low()
    {
        PORTD &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PIND = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PIND & (1 << bit)) >> bit);
    }
};

typedef Port<'D'> PortD;

#ifdef PORTD0
typedef PinPortD<0> D0;
#endif
#ifdef PORTD1
typedef PinPortD<1> D1;
#endif
#ifdef PORTD2
typedef PinPortD<2> D2;
#endif
#ifdef PORTD3
typedef PinPortD<3> D3;
#endif
#ifdef PORTD4
typedef PinPortD<4> D4;
#endif
#ifdef PORTD5
typedef PinPortD<5> D5;
#endif
#ifdef PORTD6
typedef PinPortD<6> D6;
#endif
#ifdef PORTD7
typedef PinPortD<7> D7;
#endif

#endif // PORT_D_HPP
