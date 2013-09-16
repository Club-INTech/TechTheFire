#ifndef _INT_7_HPP
#define _INT_7_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<7>
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
        EIMSK |= (1 << INT7);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT7);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRB &= ~(1 < ISC70) & ~(1 << ISC71);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRB = (EICRB & ~(1 < ISC71)) | (1 << ISC70);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRB = (EICRB & ~(1 < ISC70)) | (1 << ISC71);
        }
        else if (mode == RISING_EDGE)
        {
            EICRB |= (1 < ISC70) | (1 << ISC71);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT7_vect_num, user_function);
    }
};

typedef Int<7> int7;

#endif // INT0_HPP
