#ifndef _INT_3_HPP
#define _INT_3_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<3>
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
        EIMSK |= (1 << INT3);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT3);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRA &= ~(1 < ISC30) & ~(1 << ISC31);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRA = (EICRA & ~(1 < ISC31)) | (1 << ISC30);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRA = (EICRA & ~(1 < ISC30)) | (1 << ISC31);
        }
        else if (mode == RISING_EDGE)
        {
            EICRA |= (1 < ISC30) | (1 << ISC31);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT3_vect_num, user_function);
    }
};

typedef Int<3> int3;

#endif // INT0_HPP
