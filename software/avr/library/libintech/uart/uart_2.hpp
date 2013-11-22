#ifndef _UART_2_HPP_
#define _UART_2_HPP_

#include <stdint.h>
#include <avr/interrupt.h>

#define INIT_BAUDRATE_2 9600

template<>
void Uart<2>::init() {
    acquittement = false;
    uint16_t UBRR = (F_CPU / 8 / INIT_BAUDRATE_2 - 1) / 2;
    UBRR2H = (unsigned char) (UBRR >> 8);
    UBRR2L = (unsigned char) UBRR;
    UCSR2C = (1 << USBS2) | (3 << UCSZ20);
    UCSR2B |= (1 << RXCIE2); //Activation de l'interruption de réception
    UCSR2B |= (1 << RXEN2); //Activation de la réception
    UCSR2B |= (1 << TXEN2); //Activation de l'emission
}

template<>
void Uart<2>::send_char(unsigned char byte) {
    init();
    while (!(UCSR2A & (1 << UDRE2)));
    UDR2 = byte;
}

template<>
void Uart<2>::change_baudrate(uint32_t new_baudrate) {
    init();
    uint16_t UBRR = (F_CPU / 8 / new_baudrate - 1) / 2;
    UBRR2H = (unsigned char) (UBRR >> 8);
    UBRR2L = (unsigned char) UBRR;
    UCSR2C = (1 << USBS2) | (3 << UCSZ20);
}

template<>
inline void Uart<2>::enable_rx() {
	UCSR2B |= (1 << RXCIE2);
	UCSR2B |= (1 << RXEN2);
}

template<>
inline void Uart<2>::disable_rx() {
	UCSR2B &= ~(1 << RXCIE2);
	UCSR2B &= ~(1 << RXEN2);
}

template<>
inline void Uart<2>::enable_tx() {
	UCSR2B |= (1 << TXEN2);
}

template<>
inline void Uart<2>::disable_tx() {
	UCSR2B &= ~(1 << TXEN2);
}

typedef Uart<2> uart2;

#endif // UART_2_HPP_
