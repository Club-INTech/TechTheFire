
#include <avr/interrupt.h>
#include "interrupt_manager.hpp"

#if defined(ADC_vect) && !defined(IGNORE_ADC_vect)
ISR(ADC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[ADC_vect_num]();
}
#endif

#if defined(ANALOG_COMP_0_vect) && !defined(IGNORE_ANALOG_COMP_0_vect)
ISR(ANALOG_COMP_0_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[ANALOG_COMP_0_vect_num]();
}
#endif

#if defined(ANALOG_COMP_1_vect) && !defined(IGNORE_ANALOG_COMP_1_vect)
ISR(ANALOG_COMP_1_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[ANALOG_COMP_1_vect_num]();
}
#endif

#if defined(ANALOG_COMP_2_vect) && !defined(IGNORE_ANALOG_COMP_2_vect)
ISR(ANALOG_COMP_2_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[ANALOG_COMP_2_vect_num]();
}
#endif

#if defined(ANALOG_COMP_vect) && !defined(IGNORE_ANALOG_COMP_vect)
ISR(ANALOG_COMP_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[ANALOG_COMP_vect_num]();
}
#endif

#if defined(ANA_COMP_vect) && !defined(IGNORE_ANA_COMP_vect)
ISR(ANA_COMP_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[ANA_COMP_vect_num]();
}
#endif

#if defined(CANIT_vect) && !defined(IGNORE_CANIT_vect)
ISR(CANIT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[CANIT_vect_num]();
}
#endif

#if defined(EEPROM_READY_vect) && !defined(IGNORE_EEPROM_READY_vect)
ISR(EEPROM_READY_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[EEPROM_READY_vect_num]();
}
#endif

#if defined(EE_RDY_vect) && !defined(IGNORE_EE_RDY_vect)
ISR(EE_RDY_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[EE_RDY_vect_num]();
}
#endif

#if defined(EE_READY_vect) && !defined(IGNORE_EE_READY_vect)
ISR(EE_READY_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[EE_READY_vect_num]();
}
#endif

#if defined(LCD_vect) && !defined(IGNORE_LCD_vect)
ISR(LCD_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[LCD_vect_num]();
}
#endif

#if defined(OVRIT_vect) && !defined(IGNORE_OVRIT_vect)
ISR(OVRIT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[OVRIT_vect_num]();
}
#endif

#if defined(PSC0_CAPT_vect) && !defined(IGNORE_PSC0_CAPT_vect)
ISR(PSC0_CAPT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[PSC0_CAPT_vect_num]();
}
#endif

#if defined(PSC0_EC_vect) && !defined(IGNORE_PSC0_EC_vect)
ISR(PSC0_EC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[PSC0_EC_vect_num]();
}
#endif

#if defined(PSC1_CAPT_vect) && !defined(IGNORE_PSC1_CAPT_vect)
ISR(PSC1_CAPT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[PSC1_CAPT_vect_num]();
}
#endif

#if defined(PSC1_EC_vect) && !defined(IGNORE_PSC1_EC_vect)
ISR(PSC1_EC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[PSC1_EC_vect_num]();
}
#endif

#if defined(PSC2_CAPT_vect) && !defined(IGNORE_PSC2_CAPT_vect)
ISR(PSC2_CAPT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[PSC2_CAPT_vect_num]();
}
#endif

#if defined(PSC2_EC_vect) && !defined(IGNORE_PSC2_EC_vect)
ISR(PSC2_EC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[PSC2_EC_vect_num]();
}
#endif

#if defined(SPI_STC_vect) && !defined(IGNORE_SPI_STC_vect)
ISR(SPI_STC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[SPI_STC_vect_num]();
}
#endif

#if defined(SPM_RDY_vect) && !defined(IGNORE_SPM_RDY_vect)
ISR(SPM_RDY_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[SPM_RDY_vect_num]();
}
#endif

#if defined(SPM_READY_vect) && !defined(IGNORE_SPM_READY_vect)
ISR(SPM_READY_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[SPM_READY_vect_num]();
}
#endif

#if defined(TWI_vect) && !defined(IGNORE_TWI_vect)
ISR(TWI_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[TWI_vect_num]();
}
#endif

#if defined(TXDONE_vect) && !defined(IGNORE_TXDONE_vect)
ISR(TXDONE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[TXDONE_vect_num]();
}
#endif

#if defined(TXEMPTY_vect) && !defined(IGNORE_TXEMPTY_vect)
ISR(TXEMPTY_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[TXEMPTY_vect_num]();
}
#endif

#if defined(UART0_RX_vect) && !defined(IGNORE_UART0_RX_vect)
ISR(UART0_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART0_RX_vect_num]();
}
#endif

#if defined(UART0_TX_vect) && !defined(IGNORE_UART0_TX_vect)
ISR(UART0_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART0_TX_vect_num]();
}
#endif

#if defined(UART0_UDRE_vect) && !defined(IGNORE_UART0_UDRE_vect)
ISR(UART0_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART0_UDRE_vect_num]();
}
#endif

#if defined(UART1_RX_vect) && !defined(IGNORE_UART1_RX_vect)
ISR(UART1_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART1_RX_vect_num]();
}
#endif

#if defined(UART1_TX_vect) && !defined(IGNORE_UART1_TX_vect)
ISR(UART1_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART1_TX_vect_num]();
}
#endif

#if defined(UART1_UDRE_vect) && !defined(IGNORE_UART1_UDRE_vect)
ISR(UART1_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART1_UDRE_vect_num]();
}
#endif

#if defined(UART_RX_vect) && !defined(IGNORE_UART_RX_vect)
ISR(UART_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART_RX_vect_num]();
}
#endif

#if defined(UART_TX_vect) && !defined(IGNORE_UART_TX_vect)
ISR(UART_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART_TX_vect_num]();
}
#endif

#if defined(UART_UDRE_vect) && !defined(IGNORE_UART_UDRE_vect)
ISR(UART_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[UART_UDRE_vect_num]();
}
#endif

#if defined(USART0_RXC_vect) && !defined(IGNORE_USART0_RXC_vect)
ISR(USART0_RXC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART0_RXC_vect_num]();
}
#endif

#if defined(USART0_RX_vect) && !defined(IGNORE_USART0_RX_vect)
ISR(USART0_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART0_RX_vect_num]();
}
#endif

#if defined(USART0_TXC_vect) && !defined(IGNORE_USART0_TXC_vect)
ISR(USART0_TXC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART0_TXC_vect_num]();
}
#endif

#if defined(USART0_TX_vect) && !defined(IGNORE_USART0_TX_vect)
ISR(USART0_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART0_TX_vect_num]();
}
#endif

#if defined(USART0_UDRE_vect) && !defined(IGNORE_USART0_UDRE_vect)
ISR(USART0_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART0_UDRE_vect_num]();
}
#endif

#if defined(USART1_RXC_vect) && !defined(IGNORE_USART1_RXC_vect)
ISR(USART1_RXC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART1_RXC_vect_num]();
}
#endif

#if defined(USART1_RX_vect) && !defined(IGNORE_USART1_RX_vect)
ISR(USART1_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART1_RX_vect_num]();
}
#endif

#if defined(USART1_TXC_vect) && !defined(IGNORE_USART1_TXC_vect)
ISR(USART1_TXC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART1_TXC_vect_num]();
}
#endif

#if defined(USART1_TX_vect) && !defined(IGNORE_USART1_TX_vect)
ISR(USART1_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART1_TX_vect_num]();
}
#endif

#if defined(USART1_UDRE_vect) && !defined(IGNORE_USART1_UDRE_vect)
ISR(USART1_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART1_UDRE_vect_num]();
}
#endif

#if defined(USART2_RX_vect) && !defined(IGNORE_USART2_RX_vect)
ISR(USART2_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART2_RX_vect_num]();
}
#endif

#if defined(USART2_TX_vect) && !defined(IGNORE_USART2_TX_vect)
ISR(USART2_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART2_TX_vect_num]();
}
#endif

#if defined(USART2_UDRE_vect) && !defined(IGNORE_USART2_UDRE_vect)
ISR(USART2_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART2_UDRE_vect_num]();
}
#endif

#if defined(USART3_RX_vect) && !defined(IGNORE_USART3_RX_vect)
ISR(USART3_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART3_RX_vect_num]();
}
#endif

#if defined(USART3_TX_vect) && !defined(IGNORE_USART3_TX_vect)
ISR(USART3_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART3_TX_vect_num]();
}
#endif

#if defined(USART3_UDRE_vect) && !defined(IGNORE_USART3_UDRE_vect)
ISR(USART3_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART3_UDRE_vect_num]();
}
#endif

#if defined(USART_RXC_vect) && !defined(IGNORE_USART_RXC_vect)
ISR(USART_RXC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART_RXC_vect_num]();
}
#endif

#if defined(USART_RX_vect) && !defined(IGNORE_USART_RX_vect)
ISR(USART_RX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART_RX_vect_num]();
}
#endif

#if defined(USART_TXC_vect) && !defined(IGNORE_USART_TXC_vect)
ISR(USART_TXC_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART_TXC_vect_num]();
}
#endif

#if defined(USART_TX_vect) && !defined(IGNORE_USART_TX_vect)
ISR(USART_TX_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART_TX_vect_num]();
}
#endif

#if defined(USART_UDRE_vect) && !defined(IGNORE_USART_UDRE_vect)
ISR(USART_UDRE_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USART_UDRE_vect_num]();
}
#endif

#if defined(USI_OVERFLOW_vect) && !defined(IGNORE_USI_OVERFLOW_vect)
ISR(USI_OVERFLOW_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USI_OVERFLOW_vect_num]();
}
#endif

#if defined(USI_OVF_vect) && !defined(IGNORE_USI_OVF_vect)
ISR(USI_OVF_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USI_OVF_vect_num]();
}
#endif

#if defined(USI_START_vect) && !defined(IGNORE_USI_START_vect)
ISR(USI_START_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USI_START_vect_num]();
}
#endif

#if defined(USI_STRT_vect) && !defined(IGNORE_USI_STRT_vect)
ISR(USI_STRT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USI_STRT_vect_num]();
}
#endif

#if defined(USI_STR_vect) && !defined(IGNORE_USI_STR_vect)
ISR(USI_STR_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[USI_STR_vect_num]();
}
#endif

#if defined(WATCHDOG_vect) && !defined(IGNORE_WATCHDOG_vect)
ISR(WATCHDOG_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[WATCHDOG_vect_num]();
}
#endif

#if defined(WDT_OVERFLOW_vect) && !defined(IGNORE_WDT_OVERFLOW_vect)
ISR(WDT_OVERFLOW_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[WDT_OVERFLOW_vect_num]();
}
#endif

#if defined(WDT_vect) && !defined(IGNORE_WDT_vect)
ISR(WDT_vect, __attribute__((weak)))
{
	InterruptManager::interrupts[WDT_vect_num]();
}
#endif
