#ifndef _PORT_E_HPP
#define _PORT_E_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'E'>
{
public:
    static inline void input()
    {
        DDRE = 0x00;
        PORTE = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRE = 0x00;
        PORTE = 0xFF;
    }

    static inline void output()
    {
        DDRE = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTE = port;
    }

    static inline uint8_t read()
    {
        return PORTE;
    }
};

template<uint8_t bit>
class PinPortE
{
public:
    static inline void input()
    {
        DDRE &= ~(1 << bit);
        PORTE &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRE &= ~(1 << bit);
        PORTE |= (1 << bit);
    }

    static inline void output()
    {
        DDRE |= (1 << bit);
    }

    static inline void high()
    {
        PORTE |= (1 << bit);
    }

    static inline void low()
    {
        PORTE &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINE = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINE & (1 << bit)) >> bit);
    }
};

typedef Port<'E'> PortE;

#ifdef PORTE0
typedef PinPortE<0> E0;
#endif
#ifdef PORTE1
typedef PinPortE<1> E1;
#endif
#ifdef PORTE2
typedef PinPortE<2> E2;
#endif
#ifdef PORTE3
typedef PinPortE<3> E3;
#endif
#ifdef PORTE4
typedef PinPortE<4> E4;
#endif
#ifdef PORTE5
typedef PinPortE<5> E5;
#endif
#ifdef PORTE6
typedef PinPortE<6> E6;
#endif
#ifdef PORTE7
typedef PinPortE<7> E7;
#endif

#endif // PORT_E_HPP
