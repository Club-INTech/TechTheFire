#ifndef _PORT_H_HPP
#define _PORT_H_HPP

#include <stdint.h>
#include <avr/io.h>

template<>
class Port<'H'>
{
public:
    static inline void input()
    {
        DDRH = 0x00;
        PORTH = 0x00;
    }

    static inline void input_pull_up()
    {
        DDRH = 0x00;
        PORTH = 0xFF;
    }

    static inline void output()
    {
        DDRH = 0xFF;
    }

    static inline void write(uint8_t port)
    {
        PORTH = port;
    }

    static inline uint8_t read()
    {
        return PORTH;
    }
};

template<uint8_t bit>
class PinPortH
{
public:
    static inline void input()
    {
        DDRH &= ~(1 << bit);
        PORTH &= ~(1 << bit);
    }

    static inline void input_pull_up()
    {
        DDRH &= ~(1 << bit);
        PORTH |= (1 << bit);
    }

    static inline void output()
    {
        DDRH |= (1 << bit);
    }

    static inline void high()
    {
        PORTH |= (1 << bit);
    }

    static inline void low()
    {
        PORTH &= ~(1 << bit);
    }

    static inline void toggle()
    {
        PINH = (1 << bit);
    }

    static inline uint8_t read()
    {
        return ( (PINH & (1 << bit)) >> bit);
    }
};

typedef Port<'H'> PortH;

#ifdef PORTH0
typedef PinPortH<0> H0;
#endif
#ifdef PORTH1
typedef PinPortH<1> H1;
#endif
#ifdef PORTH2
typedef PinPortH<2> H2;
#endif
#ifdef PORTH3
typedef PinPortH<3> H3;
#endif
#ifdef PORTH4
typedef PinPortH<4> H4;
#endif
#ifdef PORTH5
typedef PinPortH<5> H5;
#endif
#ifdef PORTH6
typedef PinPortH<6> H6;
#endif
#ifdef PORTH7
typedef PinPortH<7> H7;
#endif

#endif // PORT_H_HPP
