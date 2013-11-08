#ifndef _INT_4_HPP
#define _INT_4_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<4>
{
public:
    enum InterruptMode
    {
        LOW_LEVEL,
        ANY_LEVEL,
        FALLING_EDGE,
        RISING_EDGE
    };

public:
    static inline void enable()
    {
        EIMSK |= (1 << INT4);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT4);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRB &= ~(1 < ISC40) & ~(1 << ISC41);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRB = (EICRB & ~(1 < ISC41)) | (1 << ISC40);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRB = (EICRB & ~(1 < ISC40)) | (1 << ISC41);
        }
        else if (mode == RISING_EDGE)
        {
            EICRB |= (1 < ISC40) | (1 << ISC41);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT4_vect_num, user_function);
    }
};

typedef Int<4> int4;

#endif // INT0_HPP
