#ifndef _UART_1_HPP_
#define _UART_1_HPP_

#include <stdint.h>
#include <avr/interrupt.h>

#define INIT_BAUDRATE_1 9600

template<>
inline void Uart<1>::init() {
    acquittement = false;
    sei();
    uint16_t UBRR = (F_CPU / 8 / INIT_BAUDRATE_1 - 1) / 2;
    UBRR1H = (unsigned char) (UBRR >> 8);
    UBRR1L = (unsigned char) UBRR;
    UCSR1C = (1 << USBS1) | (3 << UCSZ10);
    UCSR1B |= (1 << RXCIE1); //Activation de l'interruption de réception
    UCSR1B |= (1 << RXEN1); //Activation de la réception
    UCSR1B |= (1 << TXEN1); //Activation de l'emission
}

template<>
inline void Uart<1>::send_char(unsigned char byte) {
    while (!(UCSR1A & (1 << UDRE1)));
    UDR1 = byte;
}

template<>
inline void Uart<1>::change_baudrate(uint32_t new_baudrate) {
    uint16_t UBRR = (F_CPU / 8 / new_baudrate - 1) / 2;
    UBRR1H = (unsigned char) (UBRR >> 8);
    UBRR1L = (unsigned char) UBRR;
    UCSR1C = (1 << USBS1) | (3 << UCSZ10);
}

template<>
inline void Uart<1>::enable_rx() {
	UCSR1B |= (1 << RXCIE1);
	UCSR1B |= (1 << RXEN1);
}

template<>
inline void Uart<1>::disable_rx() {
	UCSR1B &= ~(1 << RXCIE1);
	UCSR1B &= ~(1 << RXEN1);
}

template<>
inline void Uart<1>::enable_tx() {
	UCSR1B |= (1 << TXEN1);
}

template<>
inline void Uart<1>::disable_tx() {
	UCSR1B &= ~(1 << TXEN1);
}

typedef Uart<1> uart1;

#endif // UART_1_HPP
