#ifndef _TIMER_3_HPP
#define _TIMER_3_HPP

#include <avr/io.h>
#include "../interrupt_manager.hpp"

template<class TimerSize>
class TimerRegisters<3, TimerSize>
{
public:
    static const TimerSize max_value = -1;

private:
    static uint8_t _prescaler;

public:
    static inline TimerSize counter()
    {
        return TCNT3;
    }

    static inline void counter(TimerSize value)
    {
        TCNT3 = value;
    }

    static inline void enable_overflow_interrupt()
    {
        TIMSK3 |= (1 << TOIE3);
    }

    static inline void disable_overflow_interrupt()
    {
        TIMSK3  &= ~(1 << TOIE3);
    }

    static inline void enable_output_compare_match_a_interrupt()
    {
        TIMSK3 |= (1 << OCIE3A);
    }

    static inline void disable_output_compare_match_a_interrupt()
    {
        TIMSK3  &= ~(1 << OCIE3A);
    }

    static inline void enable_output_compare_match_b_interrupt()
    {
        TIMSK3 |= (1 << OCIE3B);
    }

    static inline void disable_output_compare_match_b_interrupt()
    {
        TIMSK3  &= ~(1 << OCIE3B);
    }

    static inline TimerSize pwm_a()
    {
        return OCR3A;
    }

    static inline TimerSize pwm_b()
    {
        return OCR3B;
    }

    static inline void pwm_a(TimerSize value)
    {
        OCR3A = value;
    }

    static inline void pwm_b(TimerSize value)
    {
        OCR3B = value;
    }

    static inline void compare_output_disconnect_mode_a()
    {
        TCCR3A &= ~(1 << COM3A1) & ~(1 << COM3A0);
    }

    static inline void compare_output_disconnect_mode_b()
    {
        TCCR3A &= ~(1 << COM3B1) & ~(1 << COM3B0);
    }

    static inline void compare_output_non_inverting_mode_a()
    {
        TCCR3A = (TCCR3A & ~(1 << COM3A0)) | (1 << COM3A1);
    }

    static inline void compare_output_non_inverting_mode_b()
    {
        TCCR3A = (TCCR3A & ~(1 << COM3B0)) | (1 << COM3B1);
    }

    static inline void compare_output_inverting_mode_a()
    {
        TCCR3A |= (1 << COM3A0) | (1 << COM3A1);
    }

    static inline void compare_output_inverting_mode_b()
    {
        TCCR3A |= (1 << COM3B0) | (1 << COM3B1);
    }

    static inline void compare_output_toggle_mode_a()
    {
        TCCR3A = (TCCR3A & ~(1 << COM3A1)) | (1 << COM3A0);
    }

    static inline void waveform_generation_normal_mode()
    {
        TCCR3A &= ~(1 << WGM30) & ~(1 << WGM31);
        TCCR3B &= ~(1 << WGM32);
    }

    static inline void waveform_generation_phase_correct_mode()
    {
        TCCR3A = (TCCR3A & ~(1 << WGM31)) | (1 << WGM30);
        TCCR3B &= ~(1 << WGM32);
    }

    static inline void waveform_generation_ctc_mode()
    {
        TCCR3A = (TCCR3A & ~(1 << WGM30)) | (1 << WGM31);
        TCCR3B &= ~(1 << WGM32);
    }

    static inline void waveform_generation_fast_pwm_mode_1()
    {
        TCCR3A |= (1 << WGM30) | (1 << WGM31);
        TCCR3B &= ~(1 << WGM32);
    }

    static inline void waveform_generation_fast_pwm_mode_2()
    {
        TCCR3A |= (1 << WGM30) | (1 << WGM31);
        TCCR3B |= (1 << WGM32);
    }

    static inline void prescaler(const uint8_t prescaler)
    {
        TCCR3B = (TCCR3B & 0b11111000) | prescaler;
    }

    static inline uint8_t prescaler()
    {
        return (TCCR3B & 0b00000111);
    }

    static inline void disable()
    {
        _prescaler = TCCR3B & 0b00000111;
        TCCR3B &= 0b11111000;
    }

    static inline void enable()
    {
        _prescaler |= TCCR3B;
        TCCR3B |= _prescaler;
    }
};

template<class TimerSize>
uint8_t TimerRegisters<3, TimerSize>::_prescaler = 0;

template<>
class TimerPrescaler<3>
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
class TimerInterrupt<TimerRegisters<3, TimerSize>, 0>
{
public:
    static inline void enable()
    {
        TimerRegisters<3, TimerSize>::enable_overflow_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<3, TimerSize>::disable_overflow_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER3_OVF_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<3, TimerSize>, 1>
{
public:
    static inline void enable()
    {
        TimerRegisters<3, TimerSize>::enable_output_compare_match_a_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<3, TimerSize>::disable_output_compare_match_a_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER3_COMPA_vect_num, user_function);
    }
};

template<class TimerSize>
class TimerInterrupt<TimerRegisters<3, TimerSize>, 2>
{
public:
    static inline void enable()
    {
        TimerRegisters<3, TimerSize>::enable_output_compare_match_b_interrupt();
    }

    static inline void disable()
    {
        TimerRegisters<3, TimerSize>::disable_output_compare_match_b_interrupt();
    }

    static inline void attach(void (*user_function)(void))
    {
        InterruptManager::attach(TIMER3_COMPB_vect_num, user_function);
    }
};

#ifdef TCNT3L
typedef Timer<3, uint16_t> timer3;
#else
typedef Timer<3, uint8_t> timer3;
#endif

#endif // TIMER_3_HPP
