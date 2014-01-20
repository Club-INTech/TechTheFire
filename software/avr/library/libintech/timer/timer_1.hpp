#ifndef _TIMER_1_HPP
#define _TIMER_1_HPP

#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<class TimerSize>
class TimerRegisters<1, TimerSize>
{
public:
    static const TimerSize max_value = -1;

private:
    static uint8_t _prescaler;

public:
    static inline TimerSize counter()
    {
        return TCNT1;
    }

    static inline void counter(TimerSize value)
    {
        TCNT1 = value;
    }

    static inline void enable_overflow_interrupt()
    {
        TIMSK1 |= (1 << TOIE1);
    }

    static inline void disable_overflow_interrupt()
    {
        TIMSK1  &= ~(1 << TOIE1);
    }

    static inline void enable_output_compare_match_a_interrupt()
    {
        TIMSK1 |= (1 << OCIE1A);
    }

    static inline void disable_output_compare_match_a_interrupt()
    {
        TIMSK1  &= ~(1 << OCIE1A);
    }

    static inline void enable_output_compare_match_b_interrupt()
    {
        TIMSK1 |= (1 << OCIE1B);
    }

    static inline void disable_output_compare_match_b_interrupt()
    {
        TIMSK1  &= ~(1 << OCIE1B);
    }

    static inline TimerSize pwm_a()
    {
        return OCR1A;
    }

    static inline TimerSize pwm_b()
    {
        return OCR1B;
    }

    static inline void pwm_a(TimerSize value)
    {
        OCR1A = value;
    }

    static inline void pwm_b(TimerSize value)
    {
        OCR1B = value;
    }

    static inline void compare_output_disconnect_mode_a()
    {
        TCCR1A &= ~(1 << COM1A1) & ~(1 << COM1A0);
    }

    static inline void compare_output_disconnect_mode_b()
    {
        TCCR1A &= ~(1 << COM1B1) & ~(1 << COM1B0);
    }

    static inline void compare_output_non_inverting_mode_a()
    {
        TCCR1A = (TCCR1A & ~(1 << COM1A0)) | (1 << COM1A1);
    }

    static inline void compare_output_non_inverting_mode_b()
    {
        TCCR1A = (TCCR1A & ~(1 << COM1B0)) | (1 << COM1B1);
    }

    static inline void compare_output_inverting_mode_a()
    {
        TCCR1A |= (1 << COM1A0) | (1 << COM1A1);
    }

    static inline void compare_output_inverting_mode_b()
    {
        TCCR1A |= (1 << COM1B0) | (1 << COM1B1);
    }

    static inline void compare_output_toggle_mode_a()
    {
        TCCR1A = (TCCR1A & ~(1 << COM1A1)) | (1 << COM1A0);
    }

    static inline void waveform_generation_normal_mode()
    {
        TCCR1A &= ~(1 << WGM10) & ~(1 << WGM11);
        TCCR1B &= ~(1 << WGM12);
    }

    static inline void waveform_generation_phase_correct_mode()
    {
        TCCR1A = (TCCR1A & ~(1 << WGM11)) | (1 << WGM10);
        TCCR1B &= ~(1 << WGM12);
    }

    static inline void waveform_generation_ctc_mode()
    {
        TCCR1A = (TCCR1A & ~(1 << WGM10)) | (1 << WGM11);
        TCCR1B &= ~(1 << WGM12);
    }

    static inline void waveform_generation_fast_pwm_mode_1()
    {
        TCCR1A |= (1 << WGM10) | (1 << WGM11);
        TCCR1B &= ~(1 << WGM12);
    }

    static inline void waveform_generation_fast_pwm_mode_2()
    {
        TCCR1A |= (1 << WGM10) | (1 << WGM11);
        TCCR1B |= (1 << WGM12);
    }

    static inline void prescaler(const uint8_t prescaler)
    {
        TCCR1B = (TCCR1B & 0b11111000) | prescaler;
    }

    static inline uint8_t prescaler()
    {
        return (TCCR1B & 0b00000111);
    }

    static inline void disable()
    {
        _prescaler = TCCR1B & 0b00000111;
        TCCR1B &= 0b11111000;
    }

    static inline void enable()
    {
        _prescaler |= TCCR1B;
        TCCR1B |= _prescaler;
    }
};

template<class TimerSize>
uint8_t TimerRegisters<1, TimerSize>::_prescaler = 0;

template<>
class TimerPrescaler<1>
{
public:
  enum PrescalerValue
  {
      PRESCALER_DISABLE,
      PRESCALER_1,
      PRESCALER_8,
      PRESCALER_64,
      PRESCALER_256,
      PRESCALER_1024,
      EXTERNAL_FALLING,
      EXTERNAL_RISING
  };
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<1, TimerSize>, 0>
{
public:
    static inline void enable()
    {
        TimerRegisters<1, TimerSize>::enable_overflow_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<1, TimerSize>::disable_overflow_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER1_OVF_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<1, TimerSize>, 1>
{
public:
    static inline void enable()
    {
        TimerRegisters<1, TimerSize>::enable_output_compare_match_a_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<1, TimerSize>::disable_output_compare_match_a_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER1_COMPA_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<1, TimerSize>, 2>
{
public:
    static inline void enable()
    {
        TimerRegisters<1, TimerSize>::enable_output_compare_match_b_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<1, TimerSize>::disable_output_compare_match_b_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER1_COMPB_vect_num, user_function);
    }
};

#ifdef TCNT1L
typedef Timer<1, uint16_t> timer1;
#else
typedef Timer<1, uint8_t> timer1;
#endif

#endif // TIMER_1_HPP
