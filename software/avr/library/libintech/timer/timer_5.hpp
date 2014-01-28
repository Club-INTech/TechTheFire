#ifndef _TIMER_5_HPP
#define _TIMER_5_HPP

#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<class TimerSize>
class TimerRegisters<5, TimerSize>
{
public:
    static const TimerSize max_value = -1;

private:
    static uint8_t _prescaler;

public:
    static inline TimerSize counter()
    {
        return TCNT5;
    }

    static inline void counter(TimerSize value)
    {
        TCNT5 = value;
    }

    static inline void enable_overflow_interrupt()
    {
        TIMSK5 |= (1 << TOIE5);
    }

    static inline void disable_overflow_interrupt()
    {
        TIMSK5  &= ~(1 << TOIE5);
    }

    static inline void enable_output_compare_match_a_interrupt()
    {
        TIMSK5 |= (1 << OCIE5A);
    }

    static inline void disable_output_compare_match_a_interrupt()
    {
        TIMSK5  &= ~(1 << OCIE5A);
    }

    static inline void enable_output_compare_match_b_interrupt()
    {
        TIMSK5 |= (1 << OCIE5B);
    }

    static inline void disable_output_compare_match_b_interrupt()
    {
        TIMSK5  &= ~(1 << OCIE5B);
    }

    static inline TimerSize pwm_a()
    {
        return OCR5A;
    }

    static inline TimerSize pwm_b()
    {
        return OCR5B;
    }

    static inline void pwm_a(TimerSize value)
    {
        OCR5A = value;
    }

    static inline void pwm_b(TimerSize value)
    {
        OCR5B = value;
    }

    static inline void compare_output_disconnect_mode_a()
    {
        TCCR5A &= ~(1 << COM5A1) & ~(1 << COM5A0);
    }

    static inline void compare_output_disconnect_mode_b()
    {
        TCCR5A &= ~(1 << COM5B1) & ~(1 << COM5B0);
    }

    static inline void compare_output_non_inverting_mode_a()
    {
        TCCR5A = (TCCR5A & ~(1 << COM5A0)) | (1 << COM5A1);
    }

    static inline void compare_output_non_inverting_mode_b()
    {
        TCCR5A = (TCCR5A & ~(1 << COM5B0)) | (1 << COM5B1);
    }

    static inline void compare_output_inverting_mode_a()
    {
        TCCR5A |= (1 << COM5A0) | (1 << COM5A1);
    }

    static inline void compare_output_inverting_mode_b()
    {
        TCCR5A |= (1 << COM5B0) | (1 << COM5B1);
    }

    static inline void compare_output_toggle_mode_a()
    {
        TCCR5A = (TCCR5A & ~(1 << COM5A1)) | (1 << COM5A0);
    }

    static inline void waveform_generation_normal_mode()
    {
        TCCR5A &= ~(1 << WGM50) & ~(1 << WGM51);
        TCCR5B &= ~(1 << WGM52);
    }

    static inline void waveform_generation_phase_correct_mode()
    {
        TCCR5A = (TCCR5A & ~(1 << WGM51)) | (1 << WGM50);
        TCCR5B &= ~(1 << WGM52);
    }

    static inline void waveform_generation_ctc_mode()
    {
        TCCR5A = (TCCR5A & ~(1 << WGM50)) | (1 << WGM51);
        TCCR5B &= ~(1 << WGM52);
    }

    static inline void waveform_generation_fast_pwm_mode_1()
    {
        TCCR5A |= (1 << WGM50) | (1 << WGM51);
        TCCR5B &= ~(1 << WGM52);
    }

    static inline void waveform_generation_fast_pwm_mode_2()
    {
        TCCR5A |= (1 << WGM50) | (1 << WGM51);
        TCCR5B |= (1 << WGM52);
    }

    static inline void prescaler(const uint8_t prescaler)
    {
        TCCR5B = (TCCR5B & 0b11111000) | prescaler;
    }

    static inline uint8_t prescaler()
    {
        return (TCCR5B & 0b00000111);
    }

    static inline void disable()
    {
        _prescaler = TCCR5B & 0b00000111;
        TCCR5B &= 0b11111000;
    }

    static inline void enable()
    {
        _prescaler |= TCCR5B;
        TCCR5B |= _prescaler;
    }
};

template<class TimerSize>
uint8_t TimerRegisters<5, TimerSize>::_prescaler = 0;

template<>
class TimerPrescaler<5>
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
class TimerInterrupt<TimerRegisters<5, TimerSize>, 0>
{
public:
    static inline void enable()
    {
        TimerRegisters<5, TimerSize>::enable_overflow_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<5, TimerSize>::disable_overflow_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER5_OVF_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<5, TimerSize>, 1>
{
public:
    static inline void enable()
    {
        TimerRegisters<5, TimerSize>::enable_output_compare_match_a_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<5, TimerSize>::disable_output_compare_match_a_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER5_COMPA_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<5, TimerSize>, 2>
{
public:
    static inline void enable()
    {
        TimerRegisters<5, TimerSize>::enable_output_compare_match_b_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<5, TimerSize>::disable_output_compare_match_b_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER5_COMPB_vect_num, user_function);
    }
};

#ifdef TCNT5L
typedef Timer<5, uint16_t> timer5;
#else
typedef Timer<5, uint8_t> timer5;
#endif

#endif // TIMER_5_HPP
