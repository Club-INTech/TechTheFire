#ifndef _TIMER_4_HPP
#define _TIMER_4_HPP

#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<class TimerSize>
class TimerRegisters<4, TimerSize>
{
public:
    static const TimerSize max_value = -1;

private:
    static uint8_t _prescaler;

public:
    static inline TimerSize counter()
    {
        return TCNT4;
    }

    static inline void counter(TimerSize value)
    {
        TCNT4 = value;
    }

    static inline void enable_overflow_interrupt()
    {
        TIMSK4 |= (1 << TOIE4);
    }

    static inline void disable_overflow_interrupt()
    {
        TIMSK4  &= ~(1 << TOIE4);
    }

    static inline void enable_output_compare_match_a_interrupt()
    {
        TIMSK4 |= (1 << OCIE4A);
    }

    static inline void disable_output_compare_match_a_interrupt()
    {
        TIMSK4  &= ~(1 << OCIE4A);
    }

    static inline void enable_output_compare_match_b_interrupt()
    {
        TIMSK4 |= (1 << OCIE4B);
    }

    static inline void disable_output_compare_match_b_interrupt()
    {
        TIMSK4  &= ~(1 << OCIE4B);
    }

    static inline TimerSize pwm_a()
    {
        return OCR4A;
    }

    static inline TimerSize pwm_b()
    {
        return OCR4B;
    }

    static inline void pwm_a(TimerSize value)
    {
        OCR4A = value;
    }

    static inline void pwm_b(TimerSize value)
    {
        OCR4B = value;
    }

    static inline void compare_output_disconnect_mode_a()
    {
        TCCR4A &= ~(1 << COM4A1) & ~(1 << COM4A0);
    }

    static inline void compare_output_disconnect_mode_b()
    {
        TCCR4A &= ~(1 << COM4B1) & ~(1 << COM4B0);
    }

    static inline void compare_output_non_inverting_mode_a()
    {
        TCCR4A = (TCCR4A & ~(1 << COM4A0)) | (1 << COM4A1);
    }

    static inline void compare_output_non_inverting_mode_b()
    {
        TCCR4A = (TCCR4A & ~(1 << COM4B0)) | (1 << COM4B1);
    }

    static inline void compare_output_inverting_mode_a()
    {
        TCCR4A |= (1 << COM4A0) | (1 << COM4A1);
    }

    static inline void compare_output_inverting_mode_b()
    {
        TCCR4A |= (1 << COM4B0) | (1 << COM4B1);
    }

    static inline void compare_output_toggle_mode_a()
    {
        TCCR4A = (TCCR4A & ~(1 << COM4A1)) | (1 << COM4A0);
    }

    static inline void waveform_generation_normal_mode()
    {
        TCCR4A &= ~(1 << WGM40) & ~(1 << WGM41);
        TCCR4B &= ~(1 << WGM42);
    }

    static inline void waveform_generation_phase_correct_mode()
    {
        TCCR4A = (TCCR4A & ~(1 << WGM41)) | (1 << WGM40);
        TCCR4B &= ~(1 << WGM42);
    }

    static inline void waveform_generation_ctc_mode()
    {
        TCCR4A = (TCCR4A & ~(1 << WGM40)) | (1 << WGM41);
        TCCR4B &= ~(1 << WGM42);
    }

    static inline void waveform_generation_fast_pwm_mode_1()
    {
        TCCR4A |= (1 << WGM40) | (1 << WGM41);
        TCCR4B &= ~(1 << WGM42);
    }

    static inline void waveform_generation_fast_pwm_mode_2()
    {
        TCCR4A |= (1 << WGM40) | (1 << WGM41);
        TCCR4B |= (1 << WGM42);
    }

    static inline void prescaler(const uint8_t prescaler)
    {
        TCCR4B = (TCCR4B & 0b11111000) | prescaler;
    }

    static inline uint8_t prescaler()
    {
        return (TCCR4B & 0b00000111);
    }

    static inline void disable()
    {
        _prescaler = TCCR4B & 0b00000111;
        TCCR4B &= 0b11111000;
    }

    static inline void enable()
    {
        _prescaler |= TCCR4B;
        TCCR4B |= _prescaler;
    }
};

template<class TimerSize>
uint8_t TimerRegisters<4, TimerSize>::_prescaler = 0;

template<>
class TimerPrescaler<4>
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
class TimerInterrupt<TimerRegisters<4, TimerSize>, 0>
{
public:
    static inline void enable()
    {
        TimerRegisters<4, TimerSize>::enable_overflow_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<4, TimerSize>::disable_overflow_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER4_OVF_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<4, TimerSize>, 1>
{
public:
    static inline void enable()
    {
        TimerRegisters<4, TimerSize>::enable_output_compare_match_a_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<4, TimerSize>::disable_output_compare_match_a_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER4_COMPA_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<4, TimerSize>, 2>
{
public:
    static inline void enable()
    {
        TimerRegisters<4, TimerSize>::enable_output_compare_match_b_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<4, TimerSize>::disable_output_compare_match_b_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER4_COMPB_vect_num, user_function);
    }
};

#ifdef TCNT4L
typedef Timer<4, uint16_t> timer4;
#else
typedef Timer<4, uint8_t> timer4;
#endif

#endif // TIMER_4_HPP
