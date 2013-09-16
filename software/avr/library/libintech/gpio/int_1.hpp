#ifndef _INT_1_HPP
#define _INT_1_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<1>
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
        EIMSK |= (1 << INT1);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT1);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRA &= ~(1 < ISC10) & ~(1 << ISC11);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRA = (EICRA & ~(1 < ISC11)) | (1 << ISC10);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRA = (EICRA & ~(1 < ISC10)) | (1 << ISC11);
        }
        else if (mode == RISING_EDGE)
        {
            EICRA |= (1 < ISC10) | (1 << ISC11);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT1_vect_num, user_function);
    }
};

typedef Int<1> int1;

#endif // INT0_HPP
