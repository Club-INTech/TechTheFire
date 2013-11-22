#ifndef _UART_3_HPP_
#define _UART_3_HPP_

#include <stdint.h>
#include <avr/interrupt.h>

#define INIT_BAUDRATE_3 9600

template<>
void Uart<3>::init() {
    acquittement = false;
    uint16_t UBRR = (F_CPU / 8 / INIT_BAUDRATE_3 - 1) / 2;
    UBRR3H = (unsigned char) (UBRR >> 8);
    UBRR3L = (unsigned char) UBRR;
    UCSR3C = (1 << USBS3) | (3 << UCSZ30);
    UCSR3B |= (1 << RXCIE3); //Activation de l'interruption de réception
    UCSR3B |= (1 << RXEN3); //Activation de la réception
    UCSR3B |= (1 << TXEN3); //Activation de l'emission
}

template<>
void Uart<3>::send_char(unsigned char byte) {
    init();
    while (!(UCSR3A & (1 << UDRE3)));
    UDR3 = byte;
}

template<>
void Uart<3>::change_baudrate(uint32_t new_baudrate) {
    init();
    uint16_t UBRR = (F_CPU / 8 / new_baudrate - 1) / 2;
    UBRR3H = (unsigned char) (UBRR >> 8);
    UBRR3L = (unsigned char) UBRR;
    UCSR3C = (1 << USBS3) | (3 << UCSZ30);
}

template<>
inline void Uart<3>::enable_rx() {
	UCSR3B |= (1 << RXCIE3);
	UCSR3B |= (1 << RXEN3);
}

template<>
inline void Uart<3>::disable_rx() {
	UCSR3B &= ~(1 << RXCIE3);
	UCSR3B &= ~(1 << RXEN3);
}

template<>
inline void Uart<3>::enable_tx() {
	UCSR3B |= (1 << TXEN3);
}

template<>
inline void Uart<3>::disable_tx() {
	UCSR3B &= ~(1 << TXEN3);
}

typedef Uart<3> uart3;

#endif // UART_3_HPP_
