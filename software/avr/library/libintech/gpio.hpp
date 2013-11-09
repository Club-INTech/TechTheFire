#ifndef _GPIO_HPP
#define _GPIO_HPP

#include <avr/io.h>
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

#endif // GPIO_HPP
