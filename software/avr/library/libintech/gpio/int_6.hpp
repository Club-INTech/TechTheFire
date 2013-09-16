#ifndef _INT_6_HPP
#define _INT_6_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class Int<6>
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
        EIMSK |= (1 << INT6);
    }

    static inline void disable()
    {
        EIMSK &= ~(1 << INT6);
    }

    static inline void mode(const InterruptMode mode)
    {
        if (mode == LOW_LEVEL)
        {
            EICRB &= ~(1 < ISC60) & ~(1 << ISC61);
        }
        else if (mode == ANY_LEVEL)
        {
            EICRB = (EICRB & ~(1 < ISC61)) | (1 << ISC60);
        }
        else if (mode == FALLING_EDGE)
        {
            EICRB = (EICRB & ~(1 < ISC60)) | (1 << ISC61);
        }
        else if (mode == RISING_EDGE)
        {
            EICRB |= (1 < ISC60) | (1 << ISC61);
        }
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(INT6_vect_num, user_function);
    }
};

typedef Int<6> int6;

#endif // INT0_HPP
