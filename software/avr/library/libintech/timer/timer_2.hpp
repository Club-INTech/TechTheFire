#ifndef _TIMER_2_HPP
#define _TIMER_2_HPP

#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<class TimerSize>
class TimerRegisters<2, TimerSize>
{
public:
    static const TimerSize max_value = -1;

private:
    static uint8_t _prescaler;

public:
    static inline TimerSize counter()
    {
        return TCNT2;
    }

    static inline void counter(TimerSize value)
    {
        TCNT2 = value;
    }

    static inline void enable_overflow_interrupt()
    {
        TIMSK2 |= (1 << TOIE2);
    }

    static inline void disable_overflow_interrupt()
    {
        TIMSK2  &= ~(1 << TOIE2);
    }

    static inline void enable_output_compare_match_a_interrupt()
    {
        TIMSK2 |= (1 << OCIE2A);
    }

    static inline void disable_output_compare_match_a_interrupt()
    {
        TIMSK2  &= ~(1 << OCIE2A);
    }

    static inline void enable_output_compare_match_b_interrupt()
    {
        TIMSK2 |= (1 << OCIE2B);
    }

    static inline void disable_output_compare_match_b_interrupt()
    {
        TIMSK2  &= ~(1 << OCIE2B);
    }

    static inline TimerSize pwm_a()
    {
        return OCR2A;
    }

    static inline TimerSize pwm_b()
    {
        return OCR2B;
    }

    static inline void pwm_a(TimerSize value)
    {
        OCR2A = value;
    }

    static inline void pwm_b(TimerSize value)
    {
        OCR2B = value;
    }

    static inline void compare_output_disconnect_mode_a()
    {
        TCCR2A &= ~(1 << COM2A1) & ~(1 << COM2A0);
    }

    static inline void compare_output_disconnect_mode_b()
    {
        TCCR2A &= ~(1 << COM2B1) & ~(1 << COM2B0);
    }

    static inline void compare_output_non_inverting_mode_a()
    {
        TCCR2A = (TCCR2A & ~(1 << COM2A0)) | (1 << COM2A1);
    }

    static inline void compare_output_non_inverting_mode_b()
    {
        TCCR2A = (TCCR2A & ~(1 << COM2B0)) | (1 << COM2B1);
    }

    static inline void compare_output_inverting_mode_a()
    {
        TCCR2A |= (1 << COM2A0) | (1 << COM2A1);
    }

    static inline void compare_output_inverting_mode_b()
    {
        TCCR2A |= (1 << COM2B0) | (1 << COM2B1);
    }

    static inline void compare_output_toggle_mode_a()
    {
        TCCR2A = (TCCR2A & ~(1 << COM2A1)) | (1 << COM2A0);
    }

    static inline void waveform_generation_normal_mode()
    {
        TCCR2A &= ~(1 << WGM20) & ~(1 << WGM21);
        TCCR2B &= ~(1 << WGM22);
    }

    static inline void waveform_generation_phase_correct_mode()
    {
        TCCR2A = (TCCR2A & ~(1 << WGM21)) | (1 << WGM20);
        TCCR2B &= ~(1 << WGM22);
    }

    static inline void waveform_generation_ctc_mode()
    {
        TCCR2A = (TCCR2A & ~(1 << WGM20)) | (1 << WGM21);
        TCCR2B &= ~(1 << WGM22);
    }

    static inline void waveform_generation_fast_pwm_mode_1()
    {
        TCCR2A |= (1 << WGM20) | (1 << WGM21);
        TCCR2B &= ~(1 << WGM22);
    }

    static inline void waveform_generation_fast_pwm_mode_2()
    {
        TCCR2A |= (1 << WGM20) | (1 << WGM21);
        TCCR2B |= (1 << WGM22);
    }

    static inline void prescaler(const uint8_t prescaler)
    {
        TCCR2B = (TCCR2B & 0b11111000) | prescaler;
    }

    static inline uint8_t prescaler()
    {
        return (TCCR2B & 0b00000111);
    }

    static inline void disable()
    {
        _prescaler = TCCR2B & 0b00000111;
        TCCR2B &= 0b11111000;
    }

    static inline void enable()
    {
        _prescaler |= TCCR2B;
        TCCR2B |= _prescaler;
    }
};

template<class TimerSize>
uint8_t TimerRegisters<2, TimerSize>::_prescaler = 0;

template<>
class TimerPrescaler<2>
{
public:
  enum PrescalerValue
  {
      PRESCALER_DISABLE,
      PRESCALER_1,
      PRESCALER_8,
      PRESCALER_32,
      PRESCALER_64,
      PRESCALER_128,
      PRESCALER_256,
      PRESCALER_1024
  };
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<2, TimerSize>, 0>
{
public:
    static inline void enable()
    {
        TimerRegisters<2, TimerSize>::enable_overflow_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<2, TimerSize>::disable_overflow_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER2_OVF_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<2, TimerSize>, 1>
{
public:
    static inline void enable()
    {
        TimerRegisters<2, TimerSize>::enable_output_compare_match_a_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<2, TimerSize>::disable_output_compare_match_a_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER2_COMPA_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<2, TimerSize>, 2>
{
public:
    static inline void enable()
    {
        TimerRegisters<2, TimerSize>::enable_output_compare_match_b_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<2, TimerSize>::disable_output_compare_match_b_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER2_COMPB_vect_num, user_function);
    }
};

#ifdef TCNT2L
typedef Timer<2, uint16_t> timer2;
#else
typedef Timer<2, uint8_t> timer2;
#endif

#endif // TIMER_2_HPP
