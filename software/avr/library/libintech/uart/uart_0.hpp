#ifndef _UART_0_HPP_
#define _UART_0_HPP_

#include <stdint.h>
#include <avr/interrupt.h>

#define INIT_BAUDRATE_0 9600

template<>
inline void Uart<0>::init()
{
    acquittement = false;
    sei();
    uint16_t UBRR = (F_CPU / 8 / INIT_BAUDRATE_0 - 1) / 2;
    UBRR0H = (unsigned char) (UBRR >> 8);
    UBRR0L = (unsigned char) UBRR;
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
    UCSR0B |= (1 << RXCIE0); //Activation de l'interruption de réception
    UCSR0B |= (1 << RXEN0); //Activation de la réception
    UCSR0B |= (1 << TXEN0); //Activation de l'emission
}

template<>
inline void Uart<0>::send_char(unsigned char byte)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = byte;
}

template<>
inline void Uart<0>::change_baudrate(uint32_t new_baudrate)
{
    uint16_t UBRR = (F_CPU / 8 / new_baudrate - 1) / 2;
    UBRR0H = (unsigned char) (UBRR >> 8);
    UBRR0L = (unsigned char) UBRR;
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

template<>
inline void Uart<0>::enable_rx()
{
    UCSR0B |= (1 << RXCIE0);
    UCSR0B |= (1 << RXEN0);
}

template<>
inline void Uart<0>::disable_rx()
{
    UCSR0B &= ~(1 << RXCIE0);
    UCSR0B &= ~(1 << RXEN0);
}

template<>
inline void Uart<0>::enable_tx()
{
    UCSR0B |= (1 << TXEN0);
}

template<>
inline void Uart<0>::disable_tx()
{
    UCSR0B &= ~(1 << TXEN0);
}

typedef Uart<0> uart0;

#endif // UART_0_HPP
