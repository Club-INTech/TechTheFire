#ifndef _INT_5_HPP
#define _INT_5_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<5>
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
        EIMSK |= (1 << INT5);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT5);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRB &= ~(1 < ISC50) & ~(1 << ISC51);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRB = (EICRB & ~(1 < ISC51)) | (1 << ISC50);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRB = (EICRB & ~(1 < ISC50)) | (1 << ISC51);
        }
        else if (mode == RISING_EDGE)
        {
            EICRB |= (1 < ISC50) | (1 << ISC51);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT5_vect_num, user_function);
    }
};

typedef Int<5> int5;

#endif // INT0_HPP
