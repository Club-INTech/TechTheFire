#ifndef _PCI_3_HPP
#define _PCI_3_HPP

#include <stdint.h>
#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<>
class PinChangeInterrupt<3>
{
public:
    static inline void enable()
    {
        PCICR |= (1 << PCIE3);
    }

    static inline void disable()
    {
        PCICR &= ~(1 << PCIE3);
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(PCINT3_vect_num, user_function);
    }
};

template <uint8_t bit>
class PinChangeInterrupt3
{
public:
    static inline void enable()
    {
        PCMSK3 |= (1 << bit);
        PinChangeInterrupt<3>::enable();
    }

    static inline void disable()
    {
        PCMSK3 &= ~(1 << bit);
    }
};

typedef PinChangeInterrupt<3> pci3;

#ifdef PCINT24
typedef PinChangeInterrupt3<PCINT24> pcint24;
#endif
#ifdef PCINT25
typedef PinChangeInterrupt3<PCINT25> pcint25;
#endif
#ifdef PCINT26
typedef PinChangeInterrupt3<PCINT26> pcint26;
#endif
#ifdef PCINT27
typedef PinChangeInterrupt3<PCINT27> pcint27;
#endif
#ifdef PCINT28
typedef PinChangeInterrupt3<PCINT28> pcint28;
#endif
#ifdef PCINT29
typedef PinChangeInterrupt3<PCINT29> pcint29;
#endif
#ifdef PCINT30
typedef PinChangeInterrupt3<PCINT30> pcint30;
#endif
#ifdef PCINT31
typedef PinChangeInterrupt3<PCINT31> pcint31;
#endif

#endif // PCI_3_HPP
