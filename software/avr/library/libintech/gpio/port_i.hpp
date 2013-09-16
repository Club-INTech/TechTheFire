#ifndef _PORT_I_HPP
#define _PORT_I_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'I'>
{
public:
    static inline void input()
    {
        DDRI = 0x00;
        PORTI = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRI = 0x00;
        PORTI = 0xFF;
    }

    static inline void output()
    {
        DDRI = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTI = port;
    }

    static inline uint8_t read()
    {
        return PORTI;
    }
};

template<uint8_t bit>
class PinPortI
{
public:
    static inline void input()
    {
        DDRI &= ~(1 << bit);
        PORTI &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRI &= ~(1 << bit);
        PORTI |= (1 << bit);
    }

    static inline void output()
    {
        DDRI |= (1 << bit);
    }

    static inline void high()
    {
        PORTI |= (1 << bit);
    }

    static inline void low()
    {
        PORTI &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINI = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINI & (1 << bit)) >> bit);
    }
};

typedef Port<'I'> PortI;

#ifdef PORTI0
typedef PinPortI<0> I0;
#endif
#ifdef PORTI1
typedef PinPortI<1> I1;
#endif
#ifdef PORTI2
typedef PinPortI<2> I2;
#endif
#ifdef PORTI3
typedef PinPortI<3> I3;
#endif
#ifdef PORTI4
typedef PinPortI<4> I4;
#endif
#ifdef PORTI5
typedef PinPortI<5> I5;
#endif
#ifdef PORTI6
typedef PinPortI<6> I6;
#endif
#ifdef PORTI7
typedef PinPortI<7> I7;
#endif

#endif // PORT_I_HPP
