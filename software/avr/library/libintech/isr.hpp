#include <avr/interrupt.h>
#include <avr/io.h>
#include "interrupt_manager.hpp"
#include "uart.hpp"

#if defined(ADC_vect) && !defined(IGNORE_ADC_vect)
ISR(ADC_vect)
{
	InterruptManager::interrupts[ADC_vect_num]();
}
#endif

#if defined(ANALOG_COMP_0_vect) && !defined(IGNORE_ANALOG_COMP_0_vect)
ISR(ANALOG_COMP_0_vect)
{
	InterruptManager::interrupts[ANALOG_COMP_0_vect_num]();
}
#endif

#if defined(ANALOG_COMP_1_vect) && !defined(IGNORE_ANALOG_COMP_1_vect)
ISR(ANALOG_COMP_1_vect)
{
	InterruptManager::interrupts[ANALOG_COMP_1_vect_num]();
}
#endif

#if defined(ANALOG_COMP_2_vect) && !defined(IGNORE_ANALOG_COMP_2_vect)
ISR(ANALOG_COMP_2_vect)
{
	InterruptManager::interrupts[ANALOG_COMP_2_vect_num]();
}
#endif

#if defined(ANALOG_COMP_vect) && !defined(IGNORE_ANALOG_COMP_vect)
ISR(ANALOG_COMP_vect)
{
	InterruptManager::interrupts[ANALOG_COMP_vect_num]();
}
#endif

#if defined(ANA_COMP_vect) && !defined(IGNORE_ANA_COMP_vect)
ISR(ANA_COMP_vect)
{
	InterruptManager::interrupts[ANA_COMP_vect_num]();
}
#endif

#if defined(CANIT_vect) && !defined(IGNORE_CANIT_vect)
ISR(CANIT_vect)
{
	InterruptManager::interrupts[CANIT_vect_num]();
}
#endif

#if defined(EEPROM_READY_vect) && !defined(IGNORE_EEPROM_READY_vect)
ISR(EEPROM_READY_vect)
{
	InterruptManager::interrupts[EEPROM_READY_vect_num]();
}
#endif

#if defined(EE_RDY_vect) && !defined(IGNORE_EE_RDY_vect)
ISR(EE_RDY_vect)
{
	InterruptManager::interrupts[EE_RDY_vect_num]();
}
#endif

#if defined(EE_READY_vect) && !defined(IGNORE_EE_READY_vect)
ISR(EE_READY_vect)
{
	InterruptManager::interrupts[EE_READY_vect_num]();
}
#endif

#if defined(EXT_INT0_vect) && !defined(IGNORE_EXT_INT0_vect)
ISR(EXT_INT0_vect)
{
	InterruptManager::interrupts[EXT_INT0_vect_num]();
}
#endif

#if defined(INT0_vect) && !defined(IGNORE_INT0_vect)
ISR(INT0_vect)
{
	InterruptManager::interrupts[INT0_vect_num]();
}
#endif

#if defined(INT1_vect) && !defined(IGNORE_INT1_vect)
ISR(INT1_vect)
{
	InterruptManager::interrupts[INT1_vect_num]();
}
#endif

#if defined(INT2_vect) && !defined(IGNORE_INT2_vect)
ISR(INT2_vect)
{
	InterruptManager::interrupts[INT2_vect_num]();
}
#endif

#if defined(INT3_vect) && !defined(IGNORE_INT3_vect)
ISR(INT3_vect)
{
	InterruptManager::interrupts[INT3_vect_num]();
}
#endif

#if defined(INT4_vect) && !defined(IGNORE_INT4_vect)
ISR(INT4_vect)
{
	InterruptManager::interrupts[INT4_vect_num]();
}
#endif

#if defined(INT5_vect) && !defined(IGNORE_INT5_vect)
ISR(INT5_vect)
{
	InterruptManager::interrupts[INT5_vect_num]();
}
#endif

#if defined(INT6_vect) && !defined(IGNORE_INT6_vect)
ISR(INT6_vect)
{
	InterruptManager::interrupts[INT6_vect_num]();
}
#endif

#if defined(INT7_vect) && !defined(IGNORE_INT7_vect)
ISR(INT7_vect)
{
	InterruptManager::interrupts[INT7_vect_num]();
}
#endif

#if defined(IO_PINS_vect) && !defined(IGNORE_IO_PINS_vect)
ISR(IO_PINS_vect)
{
	InterruptManager::interrupts[IO_PINS_vect_num]();
}
#endif

#if defined(LCD_vect) && !defined(IGNORE_LCD_vect)
ISR(LCD_vect)
{
	InterruptManager::interrupts[LCD_vect_num]();
}
#endif

#if defined(LOWLEVEL_IO_PINS_vect) && !defined(IGNORE_LOWLEVEL_IO_PINS_vect)
ISR(LOWLEVEL_IO_PINS_vect)
{
	InterruptManager::interrupts[LOWLEVEL_IO_PINS_vect_num]();
}
#endif

#if defined(OVRIT_vect) && !defined(IGNORE_OVRIT_vect)
ISR(OVRIT_vect)
{
	InterruptManager::interrupts[OVRIT_vect_num]();
}
#endif

#if defined(PCINT0_vect) && !defined(IGNORE_PCINT0_vect)
ISR(PCINT0_vect)
{
	InterruptManager::interrupts[PCINT0_vect_num]();
}
#endif

#if defined(PCINT1_vect) && !defined(IGNORE_PCINT1_vect)
ISR(PCINT1_vect)
{
	InterruptManager::interrupts[PCINT1_vect_num]();
}
#endif

#if defined(PCINT2_vect) && !defined(IGNORE_PCINT2_vect)
ISR(PCINT2_vect)
{
	InterruptManager::interrupts[PCINT2_vect_num]();
}
#endif

#if defined(PCINT3_vect) && !defined(IGNORE_PCINT3_vect)
ISR(PCINT3_vect)
{
	InterruptManager::interrupts[PCINT3_vect_num]();
}
#endif

#if defined(PCINT_vect) && !defined(IGNORE_PCINT_vect)
ISR(PCINT_vect)
{
	InterruptManager::interrupts[PCINT_vect_num]();
}
#endif

#if defined(PSC0_CAPT_vect) && !defined(IGNORE_PSC0_CAPT_vect)
ISR(PSC0_CAPT_vect)
{
	InterruptManager::interrupts[PSC0_CAPT_vect_num]();
}
#endif

#if defined(PSC0_EC_vect) && !defined(IGNORE_PSC0_EC_vect)
ISR(PSC0_EC_vect)
{
	InterruptManager::interrupts[PSC0_EC_vect_num]();
}
#endif

#if defined(PSC1_CAPT_vect) && !defined(IGNORE_PSC1_CAPT_vect)
ISR(PSC1_CAPT_vect)
{
	InterruptManager::interrupts[PSC1_CAPT_vect_num]();
}
#endif

#if defined(PSC1_EC_vect) && !defined(IGNORE_PSC1_EC_vect)
ISR(PSC1_EC_vect)
{
	InterruptManager::interrupts[PSC1_EC_vect_num]();
}
#endif

#if defined(PSC2_CAPT_vect) && !defined(IGNORE_PSC2_CAPT_vect)
ISR(PSC2_CAPT_vect)
{
	InterruptManager::interrupts[PSC2_CAPT_vect_num]();
}
#endif

#if defined(PSC2_EC_vect) && !defined(IGNORE_PSC2_EC_vect)
ISR(PSC2_EC_vect)
{
	InterruptManager::interrupts[PSC2_EC_vect_num]();
}
#endif

#if defined(SPI_STC_vect) && !defined(IGNORE_SPI_STC_vect)
ISR(SPI_STC_vect)
{
	InterruptManager::interrupts[SPI_STC_vect_num]();
}
#endif

#if defined(SPM_RDY_vect) && !defined(IGNORE_SPM_RDY_vect)
ISR(SPM_RDY_vect)
{
	InterruptManager::interrupts[SPM_RDY_vect_num]();
}
#endif

#if defined(SPM_READY_vect) && !defined(IGNORE_SPM_READY_vect)
ISR(SPM_READY_vect)
{
	InterruptManager::interrupts[SPM_READY_vect_num]();
}
#endif

#if defined(TIM0_COMPA_vect) && !defined(IGNORE_TIM0_COMPA_vect)
ISR(TIM0_COMPA_vect)
{
	InterruptManager::interrupts[TIM0_COMPA_vect_num]();
}
#endif

#if defined(TIM0_COMPB_vect) && !defined(IGNORE_TIM0_COMPB_vect)
ISR(TIM0_COMPB_vect)
{
	InterruptManager::interrupts[TIM0_COMPB_vect_num]();
}
#endif

#if defined(TIM0_OVF_vect) && !defined(IGNORE_TIM0_OVF_vect)
ISR(TIM0_OVF_vect)
{
	InterruptManager::interrupts[TIM0_OVF_vect_num]();
}
#endif

#if defined(TIM1_CAPT_vect) && !defined(IGNORE_TIM1_CAPT_vect)
ISR(TIM1_CAPT_vect)
{
	InterruptManager::interrupts[TIM1_CAPT_vect_num]();
}
#endif

#if defined(TIM1_COMPA_vect) && !defined(IGNORE_TIM1_COMPA_vect)
ISR(TIM1_COMPA_vect)
{
	InterruptManager::interrupts[TIM1_COMPA_vect_num]();
}
#endif

#if defined(TIM1_COMPB_vect) && !defined(IGNORE_TIM1_COMPB_vect)
ISR(TIM1_COMPB_vect)
{
	InterruptManager::interrupts[TIM1_COMPB_vect_num]();
}
#endif

#if defined(TIM1_OVF_vect) && !defined(IGNORE_TIM1_OVF_vect)
ISR(TIM1_OVF_vect)
{
	InterruptManager::interrupts[TIM1_OVF_vect_num]();
}
#endif

#if defined(TIMER0_CAPT_vect) && !defined(IGNORE_TIMER0_CAPT_vect)
ISR(TIMER0_CAPT_vect)
{
	InterruptManager::interrupts[TIMER0_CAPT_vect_num]();
}
#endif

#if defined(TIMER0_COMPA_vect) && !defined(IGNORE_TIMER0_COMPA_vect)
ISR(TIMER0_COMPA_vect)
{
	InterruptManager::interrupts[TIMER0_COMPA_vect_num]();
}
#endif

#if defined(TIMER0_COMPB_vect) && !defined(IGNORE_TIMER0_COMPB_vect)
ISR(TIMER0_COMPB_vect)
{
	InterruptManager::interrupts[TIMER0_COMPB_vect_num]();
}
#endif

#if defined(TIMER0_COMP_A_vect) && !defined(IGNORE_TIMER0_COMP_A_vect)
ISR(TIMER0_COMP_A_vect)
{
	InterruptManager::interrupts[TIMER0_COMP_A_vect_num]();
}
#endif

#if defined(TIMER0_COMP_vect) && !defined(IGNORE_TIMER0_COMP_vect)
ISR(TIMER0_COMP_vect)
{
	InterruptManager::interrupts[TIMER0_COMP_vect_num]();
}
#endif

#if defined(TIMER0_OVF0_vect) && !defined(IGNORE_TIMER0_OVF0_vect)
ISR(TIMER0_OVF0_vect)
{
	InterruptManager::interrupts[TIMER0_OVF0_vect_num]();
}
#endif

#if defined(TIMER0_OVF_vect) && !defined(IGNORE_TIMER0_OVF_vect)
ISR(TIMER0_OVF_vect)
{
	InterruptManager::interrupts[TIMER0_OVF_vect_num]();
}
#endif

#if defined(TIMER1_CAPT1_vect) && !defined(IGNORE_TIMER1_CAPT1_vect)
ISR(TIMER1_CAPT1_vect)
{
	InterruptManager::interrupts[TIMER1_CAPT1_vect_num]();
}
#endif

#if defined(TIMER1_CAPT_vect) && !defined(IGNORE_TIMER1_CAPT_vect)
ISR(TIMER1_CAPT_vect)
{
	InterruptManager::interrupts[TIMER1_CAPT_vect_num]();
}
#endif

#if defined(TIMER1_CMPA_vect) && !defined(IGNORE_TIMER1_CMPA_vect)
ISR(TIMER1_CMPA_vect)
{
	InterruptManager::interrupts[TIMER1_CMPA_vect_num]();
}
#endif

#if defined(TIMER1_CMPB_vect) && !defined(IGNORE_TIMER1_CMPB_vect)
ISR(TIMER1_CMPB_vect)
{
	InterruptManager::interrupts[TIMER1_CMPB_vect_num]();
}
#endif

#if defined(TIMER1_COMP1_vect) && !defined(IGNORE_TIMER1_COMP1_vect)
ISR(TIMER1_COMP1_vect)
{
	InterruptManager::interrupts[TIMER1_COMP1_vect_num]();
}
#endif

#if defined(TIMER1_COMPA_vect) && !defined(IGNORE_TIMER1_COMPA_vect)
ISR(TIMER1_COMPA_vect)
{
	InterruptManager::interrupts[TIMER1_COMPA_vect_num]();
}
#endif

#if defined(TIMER1_COMPB_vect) && !defined(IGNORE_TIMER1_COMPB_vect)
ISR(TIMER1_COMPB_vect)
{
	InterruptManager::interrupts[TIMER1_COMPB_vect_num]();
}
#endif

#if defined(TIMER1_COMPC_vect) && !defined(IGNORE_TIMER1_COMPC_vect)
ISR(TIMER1_COMPC_vect)
{
	InterruptManager::interrupts[TIMER1_COMPC_vect_num]();
}
#endif

#if defined(TIMER1_COMPD_vect) && !defined(IGNORE_TIMER1_COMPD_vect)
ISR(TIMER1_COMPD_vect)
{
	InterruptManager::interrupts[TIMER1_COMPD_vect_num]();
}
#endif

#if defined(TIMER1_COMP_vect) && !defined(IGNORE_TIMER1_COMP_vect)
ISR(TIMER1_COMP_vect)
{
	InterruptManager::interrupts[TIMER1_COMP_vect_num]();
}
#endif

#if defined(TIMER1_OVF1_vect) && !defined(IGNORE_TIMER1_OVF1_vect)
ISR(TIMER1_OVF1_vect)
{
	InterruptManager::interrupts[TIMER1_OVF1_vect_num]();
}
#endif

#if defined(TIMER1_OVF_vect) && !defined(IGNORE_TIMER1_OVF_vect)
ISR(TIMER1_OVF_vect)
{
	InterruptManager::interrupts[TIMER1_OVF_vect_num]();
}
#endif

#if defined(TIMER2_COMPA_vect) && !defined(IGNORE_TIMER2_COMPA_vect)
ISR(TIMER2_COMPA_vect)
{
	InterruptManager::interrupts[TIMER2_COMPA_vect_num]();
}
#endif

#if defined(TIMER2_COMPB_vect) && !defined(IGNORE_TIMER2_COMPB_vect)
ISR(TIMER2_COMPB_vect)
{
	InterruptManager::interrupts[TIMER2_COMPB_vect_num]();
}
#endif

#if defined(TIMER2_COMP_vect) && !defined(IGNORE_TIMER2_COMP_vect)
ISR(TIMER2_COMP_vect)
{
	InterruptManager::interrupts[TIMER2_COMP_vect_num]();
}
#endif

#if defined(TIMER2_OVF_vect) && !defined(IGNORE_TIMER2_OVF_vect)
ISR(TIMER2_OVF_vect)
{
	InterruptManager::interrupts[TIMER2_OVF_vect_num]();
}
#endif

#if defined(TIMER3_CAPT_vect) && !defined(IGNORE_TIMER3_CAPT_vect)
ISR(TIMER3_CAPT_vect)
{
	InterruptManager::interrupts[TIMER3_CAPT_vect_num]();
}
#endif

#if defined(TIMER3_COMPA_vect) && !defined(IGNORE_TIMER3_COMPA_vect)
ISR(TIMER3_COMPA_vect)
{
	InterruptManager::interrupts[TIMER3_COMPA_vect_num]();
}
#endif

#if defined(TIMER3_COMPB_vect) && !defined(IGNORE_TIMER3_COMPB_vect)
ISR(TIMER3_COMPB_vect)
{
	InterruptManager::interrupts[TIMER3_COMPB_vect_num]();
}
#endif

#if defined(TIMER3_COMPC_vect) && !defined(IGNORE_TIMER3_COMPC_vect)
ISR(TIMER3_COMPC_vect)
{
	InterruptManager::interrupts[TIMER3_COMPC_vect_num]();
}
#endif

#if defined(TIMER3_OVF_vect) && !defined(IGNORE_TIMER3_OVF_vect)
ISR(TIMER3_OVF_vect)
{
	InterruptManager::interrupts[TIMER3_OVF_vect_num]();
}
#endif

#if defined(TIMER4_CAPT_vect) && !defined(IGNORE_TIMER4_CAPT_vect)
ISR(TIMER4_CAPT_vect)
{
	InterruptManager::interrupts[TIMER4_CAPT_vect_num]();
}
#endif

#if defined(TIMER4_COMPA_vect) && !defined(IGNORE_TIMER4_COMPA_vect)
ISR(TIMER4_COMPA_vect)
{
	InterruptManager::interrupts[TIMER4_COMPA_vect_num]();
}
#endif

#if defined(TIMER4_COMPB_vect) && !defined(IGNORE_TIMER4_COMPB_vect)
ISR(TIMER4_COMPB_vect)
{
	InterruptManager::interrupts[TIMER4_COMPB_vect_num]();
}
#endif

#if defined(TIMER4_COMPC_vect) && !defined(IGNORE_TIMER4_COMPC_vect)
ISR(TIMER4_COMPC_vect)
{
	InterruptManager::interrupts[TIMER4_COMPC_vect_num]();
}
#endif

#if defined(TIMER4_OVF_vect) && !defined(IGNORE_TIMER4_OVF_vect)
ISR(TIMER4_OVF_vect)
{
	InterruptManager::interrupts[TIMER4_OVF_vect_num]();
}
#endif

#if defined(TIMER5_CAPT_vect) && !defined(IGNORE_TIMER5_CAPT_vect)
ISR(TIMER5_CAPT_vect)
{
	InterruptManager::interrupts[TIMER5_CAPT_vect_num]();
}
#endif

#if defined(TIMER5_COMPA_vect) && !defined(IGNORE_TIMER5_COMPA_vect)
ISR(TIMER5_COMPA_vect)
{
	InterruptManager::interrupts[TIMER5_COMPA_vect_num]();
}
#endif

#if defined(TIMER5_COMPB_vect) && !defined(IGNORE_TIMER5_COMPB_vect)
ISR(TIMER5_COMPB_vect)
{
	InterruptManager::interrupts[TIMER5_COMPB_vect_num]();
}
#endif

#if defined(TIMER5_COMPC_vect) && !defined(IGNORE_TIMER5_COMPC_vect)
ISR(TIMER5_COMPC_vect)
{
	InterruptManager::interrupts[TIMER5_COMPC_vect_num]();
}
#endif

#if defined(TIMER5_OVF_vect) && !defined(IGNORE_TIMER5_OVF_vect)
ISR(TIMER5_OVF_vect)
{
	InterruptManager::interrupts[TIMER5_OVF_vect_num]();
}
#endif

#if defined(TWI_vect) && !defined(IGNORE_TWI_vect)
ISR(TWI_vect)
{
	InterruptManager::interrupts[TWI_vect_num]();
}
#endif

#if defined(TXDONE_vect) && !defined(IGNORE_TXDONE_vect)
ISR(TXDONE_vect)
{
	InterruptManager::interrupts[TXDONE_vect_num]();
}
#endif

#if defined(TXEMPTY_vect) && !defined(IGNORE_TXEMPTY_vect)
ISR(TXEMPTY_vect)
{
	InterruptManager::interrupts[TXEMPTY_vect_num]();
}
#endif

#if defined(UART0_RX_vect) && !defined(IGNORE_UART0_RX_vect)
ISR(UART0_RX_vect)
{
	InterruptManager::interrupts[UART0_RX_vect_num]();
}
#endif

#if defined(UART0_TX_vect) && !defined(IGNORE_UART0_TX_vect)
ISR(UART0_TX_vect)
{
	InterruptManager::interrupts[UART0_TX_vect_num]();
}
#endif

#if defined(UART0_UDRE_vect) && !defined(IGNORE_UART0_UDRE_vect)
ISR(UART0_UDRE_vect)
{
	InterruptManager::interrupts[UART0_UDRE_vect_num]();
}
#endif

#if defined(UART1_RX_vect) && !defined(IGNORE_UART1_RX_vect)
ISR(UART1_RX_vect)
{
	InterruptManager::interrupts[UART1_RX_vect_num]();
}
#endif

#if defined(UART1_TX_vect) && !defined(IGNORE_UART1_TX_vect)
ISR(UART1_TX_vect)
{
	InterruptManager::interrupts[UART1_TX_vect_num]();
}
#endif

#if defined(UART1_UDRE_vect) && !defined(IGNORE_UART1_UDRE_vect)
ISR(UART1_UDRE_vect)
{
	InterruptManager::interrupts[UART1_UDRE_vect_num]();
}
#endif

#if defined(UART_RX_vect) && !defined(IGNORE_UART_RX_vect)
ISR(UART_RX_vect)
{
	InterruptManager::interrupts[UART_RX_vect_num]();
}
#endif

#if defined(UART_TX_vect) && !defined(IGNORE_UART_TX_vect)
ISR(UART_TX_vect)
{
	InterruptManager::interrupts[UART_TX_vect_num]();
}
#endif

#if defined(UART_UDRE_vect) && !defined(IGNORE_UART_UDRE_vect)
ISR(UART_UDRE_vect)
{
	InterruptManager::interrupts[UART_UDRE_vect_num]();
}
#endif

#if defined(USART0_RXC_vect) && !defined(IGNORE_USART0_RXC_vect)
ISR(USART0_RXC_vect)
{
	InterruptManager::interrupts[USART0_RXC_vect_num]();
}
#endif

#if defined(USART0_RX_vect) && !defined(IGNORE_USART0_RX_vect)
ISR(USART0_RX_vect)
{
	Uart<0>::store_char(UDR0);
}
#endif

#if defined(USART0_TXC_vect) && !defined(IGNORE_USART0_TXC_vect)
ISR(USART0_TXC_vect)
{
	InterruptManager::interrupts[USART0_TXC_vect_num]();
}
#endif

#if defined(USART0_TX_vect) && !defined(IGNORE_USART0_TX_vect)
ISR(USART0_TX_vect)
{
	InterruptManager::interrupts[USART0_TX_vect_num]();
}
#endif

#if defined(USART0_UDRE_vect) && !defined(IGNORE_USART0_UDRE_vect)
ISR(USART0_UDRE_vect)
{
	InterruptManager::interrupts[USART0_UDRE_vect_num]();
}
#endif

#if defined(USART1_RXC_vect) && !defined(IGNORE_USART1_RXC_vect)
ISR(USART1_RXC_vect)
{
	InterruptManager::interrupts[USART1_RXC_vect_num]();
}
#endif

#if defined(USART1_RX_vect) && !defined(IGNORE_USART1_RX_vect)
ISR(USART1_RX_vect)
{
	Uart<1>::store_char(UDR1);
}
#endif

#if defined(USART1_TXC_vect) && !defined(IGNORE_USART1_TXC_vect)
ISR(USART1_TXC_vect)
{
	InterruptManager::interrupts[USART1_TXC_vect_num]();
}
#endif

#if defined(USART1_TX_vect) && !defined(IGNORE_USART1_TX_vect)
ISR(USART1_TX_vect)
{
	InterruptManager::interrupts[USART1_TX_vect_num]();
}
#endif

#if defined(USART1_UDRE_vect) && !defined(IGNORE_USART1_UDRE_vect)
ISR(USART1_UDRE_vect)
{
	InterruptManager::interrupts[USART1_UDRE_vect_num]();
}
#endif

#if defined(USART2_RX_vect) && !defined(IGNORE_USART2_RX_vect)
ISR(USART2_RX_vect)
{
	Uart<2>::store_char(UDR2);
}
#endif

#if defined(USART2_TX_vect) && !defined(IGNORE_USART2_TX_vect)
ISR(USART2_TX_vect)
{
	InterruptManager::interrupts[USART2_TX_vect_num]();
}
#endif

#if defined(USART2_UDRE_vect) && !defined(IGNORE_USART2_UDRE_vect)
ISR(USART2_UDRE_vect)
{
	InterruptManager::interrupts[USART2_UDRE_vect_num]();
}
#endif

#if defined(USART3_RX_vect) && !defined(IGNORE_USART3_RX_vect)
ISR(USART3_RX_vect)
{
	Uart<3>::store_char(UDR3);
}
#endif

#if defined(USART3_TX_vect) && !defined(IGNORE_USART3_TX_vect)
ISR(USART3_TX_vect)
{
	InterruptManager::interrupts[USART3_TX_vect_num]();
}
#endif

#if defined(USART3_UDRE_vect) && !defined(IGNORE_USART3_UDRE_vect)
ISR(USART3_UDRE_vect)
{
	InterruptManager::interrupts[USART3_UDRE_vect_num]();
}
#endif

#if defined(USART_RXC_vect) && !defined(IGNORE_USART_RXC_vect)
ISR(USART_RXC_vect)
{
	InterruptManager::interrupts[USART_RXC_vect_num]();
}
#endif

#if defined(USART_RX_vect) && !defined(IGNORE_USART_RX_vect)
ISR(USART_RX_vect)
{
	Uart<0>::store_char(UDR0);
}
#endif

#if defined(USART_TXC_vect) && !defined(IGNORE_USART_TXC_vect)
ISR(USART_TXC_vect)
{
	InterruptManager::interrupts[USART_TXC_vect_num]();
}
#endif

#if defined(USART_TX_vect) && !defined(IGNORE_USART_TX_vect)
ISR(USART_TX_vect)
{
	InterruptManager::interrupts[USART_TX_vect_num]();
}
#endif

#if defined(USART_UDRE_vect) && !defined(IGNORE_USART_UDRE_vect)
ISR(USART_UDRE_vect)
{
	InterruptManager::interrupts[USART_UDRE_vect_num]();
}
#endif

#if defined(USI_OVERFLOW_vect) && !defined(IGNORE_USI_OVERFLOW_vect)
ISR(USI_OVERFLOW_vect)
{
	InterruptManager::interrupts[USI_OVERFLOW_vect_num]();
}
#endif

#if defined(USI_OVF_vect) && !defined(IGNORE_USI_OVF_vect)
ISR(USI_OVF_vect)
{
	InterruptManager::interrupts[USI_OVF_vect_num]();
}
#endif

#if defined(USI_START_vect) && !defined(IGNORE_USI_START_vect)
ISR(USI_START_vect)
{
	InterruptManager::interrupts[USI_START_vect_num]();
}
#endif

#if defined(USI_STRT_vect) && !defined(IGNORE_USI_STRT_vect)
ISR(USI_STRT_vect)
{
	InterruptManager::interrupts[USI_STRT_vect_num]();
}
#endif

#if defined(USI_STR_vect) && !defined(IGNORE_USI_STR_vect)
ISR(USI_STR_vect)
{
	InterruptManager::interrupts[USI_STR_vect_num]();
}
#endif

#if defined(WATCHDOG_vect) && !defined(IGNORE_WATCHDOG_vect)
ISR(WATCHDOG_vect)
{
	InterruptManager::interrupts[WATCHDOG_vect_num]();
}
#endif

#if defined(WDT_OVERFLOW_vect) && !defined(IGNORE_WDT_OVERFLOW_vect)
ISR(WDT_OVERFLOW_vect)
{
	InterruptManager::interrupts[WDT_OVERFLOW_vect_num]();
}
#endif

#if defined(WDT_vect) && !defined(IGNORE_WDT_vect)
ISR(WDT_vect)
{
	InterruptManager::interrupts[WDT_vect_num]();
}
#endif
