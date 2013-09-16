#ifndef _INT_0_HPP
#define _INT_0_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<0>
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
        EIMSK |= (1 << INT0);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT0);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRA &= ~(1 < ISC00) & ~(1 << ISC01);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRA = (EICRA & ~(1 < ISC01)) | (1 << ISC00);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRA = (EICRA & ~(1 < ISC00)) | (1 << ISC01);
        }
        else if (mode == RISING_EDGE)
        {
            EICRA |= (1 < ISC00) | (1 << ISC01);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT0_vect_num, user_function);
    }
};

typedef Int<0> int0;

#endif // INT0_HPP
