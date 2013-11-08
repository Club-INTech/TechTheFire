#ifndef _PCI_0_HPP
#define _PCI_0_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class PinChangeInterrupt<0>
{
public:
    static inline void enable()
    {
        PCICR |= (1 << PCIE0);
    }

    static inline void disable()
    {
        PCICR &= ~(1 << PCIE0);
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(PCINT0_vect_num, user_function);
    }
};

template <uint8_t bit>
class PinChangeInterrupt0
{
public:
    static inline void enable()
    {
        PCMSK0 |= (1 << bit);
        PinChangeInterrupt<0>::enable();
    }

    static inline void disable()
    {
        PCMSK0 &= ~(1 << bit);
    }
};

typedef PinChangeInterrupt<0> pci0;

#ifdef PCINT0
typedef PinChangeInterrupt0<PCINT0> pcint0;
#endif
#ifdef PCINT1
typedef PinChangeInterrupt0<PCINT1> pcint1;
#endif
#ifdef PCINT2
typedef PinChangeInterrupt0<PCINT2> pcint2;
#endif
#ifdef PCINT3
typedef PinChangeInterrupt0<PCINT3> pcint3;
#endif
#ifdef PCINT4
typedef PinChangeInterrupt0<PCINT4> pcint4;
#endif
#ifdef PCINT5
typedef PinChangeInterrupt0<PCINT5> pcint5;
#endif
#ifdef PCINT6
typedef PinChangeInterrupt0<PCINT6> pcint6;
#endif
#ifdef PCINT7
typedef PinChangeInterrupt0<PCINT7> pcint7;
#endif

#endif // PCI_0_HPP
