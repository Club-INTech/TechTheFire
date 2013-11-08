#ifndef _PCI_1_HPP
#define _PCI_1_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class PinChangeInterrupt<1>
{
public:
    static inline void enable()
    {
        PCICR |= (1 << PCIE1);
    }

    static inline void disable()
    {
        PCICR &= ~(1 << PCIE1);
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(PCINT1_vect_num, user_function);
    }
};

template <uint8_t bit>
class PinChangeInterrupt1
{
public:
    static inline void enable()
    {
        PCMSK1 |= (1 << bit);
        PinChangeInterrupt<1>::enable();
    }

    static inline void disable()
    {
        PCMSK1 &= ~(1 << bit);
    }
};

typedef PinChangeInterrupt<1> pci1;

#ifdef PCINT8
typedef PinChangeInterrupt1<PCINT8> pcint8;
#endif
#ifdef PCINT9
typedef PinChangeInterrupt1<PCINT9> pcint9;
#endif
#ifdef PCINT10
typedef PinChangeInterrupt1<PCINT10> pcint10;
#endif
#ifdef PCINT11
typedef PinChangeInterrupt1<PCINT11> pcint11;
#endif
#ifdef PCINT12
typedef PinChangeInterrupt1<PCINT12> pcint12;
#endif
#ifdef PCINT13
typedef PinChangeInterrupt1<PCINT13> pcint13;
#endif
#ifdef PCINT14
typedef PinChangeInterrupt1<PCINT14> pcint14;
#endif
#ifdef PCINT15
typedef PinChangeInterrupt1<PCINT15> pcint15;
#endif

#endif // PCI_1_HPP
