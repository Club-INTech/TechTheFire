#ifndef _TIMER_0_HPP
#define _TIMER_0_HPP

#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<class TimerSize>
class TimerRegisters<0, TimerSize>
{
public:
    static const TimerSize max_value = -1;

private:
    static uint8_t _prescaler;

public:
    static inline TimerSize counter()
    {
        return TCNT0;
    }

    static inline void counter(TimerSize value)
    {
        TCNT0 = value;
    }

    static inline void enable_overflow_interrupt()
    {
        TIMSK0 |= (1 << TOIE0);
    }

    static inline void disable_overflow_interrupt()
    {
        TIMSK0  &= ~(1 << TOIE0);
    }

    static inline void enable_output_compare_match_a_interrupt()
    {
        TIMSK0 |= (1 << OCIE0A);
    }

    static inline void disable_output_compare_match_a_interrupt()
    {
        TIMSK0  &= ~(1 << OCIE0A);
    }

    static inline void enable_output_compare_match_b_interrupt()
    {
        TIMSK0 |= (1 << OCIE0B);
    }

    static inline void disable_output_compare_match_b_interrupt()
    {
        TIMSK0  &= ~(1 << OCIE0B);
    }

    static inline TimerSize pwm_a()
    {
        return OCR0A;
    }

    static inline TimerSize pwm_b()
    {
        return OCR0B;
    }

    static inline void pwm_a(TimerSize value)
    {
        OCR0A = value;
    }

    static inline void pwm_b(TimerSize value)
    {
        OCR0B = value;
    }

    static inline void compare_output_disconnect_mode_a()
    {
        TCCR0A &= ~(1 << COM0A1) & ~(1 << COM0A0);
    }

    static inline void compare_output_disconnect_mode_b()
    {
        TCCR0A &= ~(1 << COM0B1) & ~(1 << COM0B0);
    }

    static inline void compare_output_non_inverting_mode_a()
    {
        TCCR0A = (TCCR0A & ~(1 << COM0A0)) | (1 << COM0A1);
    }

    static inline void compare_output_non_inverting_mode_b()
    {
        TCCR0A = (TCCR0A & ~(1 << COM0B0)) | (1 << COM0B1);
    }

    static inline void compare_output_inverting_mode_a()
    {
        TCCR0A |= (1 << COM0A0) | (1 << COM0A1);
    }

    static inline void compare_output_inverting_mode_b()
    {
        TCCR0A |= (1 << COM0B0) | (1 << COM0B1);
    }

    static inline void compare_output_toggle_mode_a()
    {
        TCCR0A = (TCCR0A & ~(1 << COM0A1)) | (1 << COM0A0);
    }

    static inline void waveform_generation_normal_mode()
    {
        TCCR0A &= ~(1 << WGM00) & ~(1 << WGM01);
        TCCR0B &= ~(1 << WGM02);
    }

    static inline void waveform_generation_phase_correct_mode()
    {
        TCCR0A = (TCCR0A & ~(1 << WGM01)) | (1 << WGM00);
        TCCR0B &= ~(1 << WGM02);
    }

    static inline void waveform_generation_ctc_mode()
    {
        TCCR0A = (TCCR0A & ~(1 << WGM00)) | (1 << WGM01);
        TCCR0B &= ~(1 << WGM02);
    }

    static inline void waveform_generation_fast_pwm_mode_1()
    {
        TCCR0A |= (1 << WGM00) | (1 << WGM01);
        TCCR0B &= ~(1 << WGM02);
    }

    static inline void waveform_generation_fast_pwm_mode_2()
    {
        TCCR0A |= (1 << WGM00) | (1 << WGM01);
        TCCR0B |= (1 << WGM02);
    }

    static inline void prescaler(const uint8_t prescaler)
    {
        TCCR0B = (TCCR0B & 0b11111000) | prescaler;
    }

    static inline uint8_t prescaler()
    {
        return (TCCR0B & 0b00000111);
    }

    static inline void disable()
    {
        _prescaler = TCCR0B & 0b00000111;
        TCCR0B &= 0b11111000;
    }

    static inline void enable()
    {
        _prescaler |= TCCR0B;
        TCCR0B |= _prescaler;
    }
};

template<class TimerSize>
uint8_t TimerRegisters<0, TimerSize>::_prescaler = 0;

template<>
class TimerPrescaler<0>
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
class TimerInterrupt<TimerRegisters<0, TimerSize>, 0>
{
public:
    static inline void enable()
    {
        TimerRegisters<0, TimerSize>::enable_overflow_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<0, TimerSize>::disable_overflow_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER0_OVF_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<0, TimerSize>, 1>
{
public:
    static inline void enable()
    {
        TimerRegisters<0, TimerSize>::enable_output_compare_match_a_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<0, TimerSize>::disable_output_compare_match_a_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER0_COMPA_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<0, TimerSize>, 2>
{
public:
    static inline void enable()
    {
        TimerRegisters<0, TimerSize>::enable_output_compare_match_b_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<0, TimerSize>::disable_output_compare_match_b_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER0_COMPB_vect_num, user_function);
    }
};

#ifdef TCNT0L
typedef Timer<0, uint16_t> timer0;
#else
typedef Timer<0, uint8_t> timer0;
#endif

#endif // TIMER_0_HPP
