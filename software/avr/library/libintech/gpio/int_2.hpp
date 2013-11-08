#ifndef _INT_2_HPP
#define _INT_2_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<2>
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
        EIMSK |= (1 << INT2);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT2);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRA &= ~(1 < ISC20) & ~(1 << ISC21);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRA = (EICRA & ~(1 < ISC21)) | (1 << ISC20);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRA = (EICRA & ~(1 < ISC20)) | (1 << ISC21);
        }
        else if (mode == RISING_EDGE)
        {
            EICRA |= (1 < ISC20) | (1 << ISC21);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT2_vect_num, user_function);
    }
};

typedef Int<2> int2;

#endif // INT0_HPP
