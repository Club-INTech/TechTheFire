#ifndef _INTERRUPTMANAGER_HPP
#define _INTERRUPTMANAGER_HPP

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define INITIALISE_INTERRUPT_MANAGER() 	\
	void do_nothing() {}				\
	InterruptManager::voidFunctionPointer InterruptManager::interrupts[]

void do_nothing();
//TODO Trouver une solution pour initialiser le tableau interrupts[] sinon seg fault dans les ISR
class InterruptManager
{
public:
    typedef void (*voidFunctionPointer)(void);

public:
    static voidFunctionPointer interrupts[_VECTORS_SIZE];

public:
    static inline void attach(uint8_t vector, void (*user_function)(void))
    {
        interrupts[vector] = user_function;
    }

    static inline void dettach(uint8_t vector)
    {
        interrupts[vector] = &do_nothing;
    }

    static inline void enable()
    {
        sei();
    }

    static inline void disable()
    {
        cli();
    }
};

#endif // INTERRUPTMANAGER_HPP
