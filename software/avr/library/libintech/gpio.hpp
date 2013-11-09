#ifndef _GPIO_HPP
#define _GPIO_HPP

#include <avr/io.h>
#include "interrupt_manager.hpp"
//TODO Define du mode debug pour toute la lib (mise à jour des registres userfriendly)
/*
 *-vérification du pointeur de fonction dans les ISR
 *-activation des interruptions pour les INT et les PCINT
 *-mise en output des pins de timer
 *-mise en output des pins dans les méthodes low() et high()
 *...
 */
template<char>
class Port;

template<uint8_t>
class PinChangeInterrupt;

template<uint8_t>
class Int;

/*
 *PORT
 */

#ifdef PORTA
#include "gpio/port_a.hpp"
#endif

#ifdef PORTB
#include "gpio/port_b.hpp"
#endif

#ifdef PORTC
#include "gpio/port_c.hpp"
#endif

#ifdef PORTD
#include "gpio/port_d.hpp"
#endif

#ifdef PORTE
#include "gpio/port_e.hpp"
#endif

#ifdef PORTF
#include "gpio/port_f.hpp"
#endif

#ifdef PORTG
#include "gpio/port_g.hpp"
#endif

#ifdef PORTH
#include "gpio/port_h.hpp"
#endif

#ifdef PORTI
#include "gpio/port_i.hpp"
#endif

#ifdef PORTJ
#include "gpio/port_j.hpp"
#endif

#ifdef PORTK
#include "gpio/port_k.hpp"
#endif

#ifdef PORTL
#include "gpio/port_l.hpp"
#endif

/*
 *PCINT
 */

#ifdef PCMSK0
#include "gpio/pci_0.hpp"
#endif

#ifdef PCMSK1
#include "gpio/pci_1.hpp"
#endif

#ifdef PCMSK2
#include "gpio/pci_2.hpp"
#endif

#ifdef PCMSK3
#include "gpio/pci_3.hpp"
#endif

/*
 *INT
 */

#ifdef INT0
#include "gpio/int_0.hpp"
#endif

#ifdef INT1
#include "gpio/int_1.hpp"
#endif

#ifdef INT2
#include "gpio/int_2.hpp"
#endif

#ifdef INT3
#include "gpio/int_3.hpp"
#endif

#ifdef INT4
#include "gpio/int_4.hpp"
#endif

#ifdef INT5
#include "gpio/int_5.hpp"
#endif

#ifdef INT6
#include "gpio/int_6.hpp"
#endif

#ifdef INT7
#include "gpio/int_7.hpp"
#endif

/*
 *ISR
 */

#if defined(EXT_INT0_vect) && !defined(IGNORE_EXT_INT0_vect)
ISR(EXT_INT0_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[EXT_INT0_vect_num]();
}
#endif

#if defined(INT0_vect) && !defined(IGNORE_INT0_vect)
ISR(INT0_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT0_vect_num]();
}
#endif

#if defined(INT1_vect) && !defined(IGNORE_INT1_vect)
ISR(INT1_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT1_vect_num]();
}
#endif

#if defined(INT2_vect) && !defined(IGNORE_INT2_vect)
ISR(INT2_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT2_vect_num]();
}
#endif

#if defined(INT3_vect) && !defined(IGNORE_INT3_vect)
ISR(INT3_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT3_vect_num]();
}
#endif

#if defined(INT4_vect) && !defined(IGNORE_INT4_vect)
ISR(INT4_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT4_vect_num]();
}
#endif

#if defined(INT5_vect) && !defined(IGNORE_INT5_vect)
ISR(INT5_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT5_vect_num]();
}
#endif

#if defined(INT6_vect) && !defined(IGNORE_INT6_vect)
ISR(INT6_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT6_vect_num]();
}
#endif

#if defined(INT7_vect) && !defined(IGNORE_INT7_vect)
ISR(INT7_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[INT7_vect_num]();
}
#endif

#if defined(IO_PINS_vect) && !defined(IGNORE_IO_PINS_vect)
ISR(IO_PINS_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[IO_PINS_vect_num]();
}
#endif

#if defined(LOWLEVEL_IO_PINS_vect) && !defined(IGNORE_LOWLEVEL_IO_PINS_vect)
ISR(LOWLEVEL_IO_PINS_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[LOWLEVEL_IO_PINS_vect_num]();
}
#endif

#if defined(PCINT0_vect) && !defined(IGNORE_PCINT0_vect)
ISR(PCINT0_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[PCINT0_vect_num]();
}
#endif

#if defined(PCINT1_vect) && !defined(IGNORE_PCINT1_vect)
ISR(PCINT1_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[PCINT1_vect_num]();
}
#endif

#if defined(PCINT2_vect) && !defined(IGNORE_PCINT2_vect)
ISR(PCINT2_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[PCINT2_vect_num]();
}
#endif

#if defined(PCINT3_vect) && !defined(IGNORE_PCINT3_vect)
ISR(PCINT3_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[PCINT3_vect_num]();
}
#endif

#if defined(PCINT_vect) && !defined(IGNORE_PCINT_vect)
ISR(PCINT_vect, __attribute__((weak)))
{
        InterruptManager::interrupts[PCINT_vect_num]();
}
#endif

#endif // GPIO_HPP
