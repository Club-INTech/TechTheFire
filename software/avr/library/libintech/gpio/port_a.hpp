#ifndef _PORT_A_HPP
#define _PORT_A_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'A'>
{
public:
    static inline void input()
    {
        DDRA = 0x00;
        PORTA = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRA = 0x00;
        PORTA = 0xFF;
    }

    static inline void output()
    {
        DDRA = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTA = port;
    }

    static inline uint8_t read()
    {
        return PORTA;
    }
};

template<uint8_t bit>
class PinPortA
{
public:
    static inline void input()
    {
        DDRA &= ~(1 << bit);
        PORTA &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRA &= ~(1 << bit);
        PORTA |= (1 << bit);
    }

    static inline void output()
    {
        DDRA |= (1 << bit);
    }

    static inline void high()
    {
        PORTA |= (1 << bit);
    }

    static inline void low()
    {
        PORTA &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINA = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINA & (1 << bit)) >> bit);
    }
};

typedef Port<'A'> PortA;

#ifdef PORTA0
typedef PinPortA<0> A0;
#endif
#ifdef PORTA1
typedef PinPortA<1> A1;
#endif
#ifdef PORTA2
typedef PinPortA<2> A2;
#endif
#ifdef PORTA3
typedef PinPortA<3> A3;
#endif
#ifdef PORTA4
typedef PinPortA<4> A4;
#endif
#ifdef PORTA5
typedef PinPortA<5> A5;
#endif
#ifdef PORTA6
typedef PinPortA<6> A6;
#endif
#ifdef PORTA7
typedef PinPortA<7> A7;
#endif

#endif // PORT_A_HPP
