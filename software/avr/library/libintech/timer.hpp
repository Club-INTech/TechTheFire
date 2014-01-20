#ifndef _TIMER_HPP
#define _TIMER_HPP

#include <stdint.h>
#include <avr/io.h>

#include "timer/registers.hpp"
#include "timer/waveform.hpp"
#include "timer/pwm.hpp"
#include "timer/counter.hpp"
#include "timer/prescaler.hpp"

//NOTE on a fait ce choix pour éviter les if, à expliquer!
//TODO spécificités des Timers 16 bits (interrupt ICIE1 timer 16 bits)
//TODO spécificités du timers 2 par rapport au timer 0 du 328p
//TODO méthode pour gérer le passage de 16 bits à 8, 9 et 10 bits
template<uint8_t TimerId, class TimerSize>
class Timer
{
private:
    typedef TimerRegisters<TimerId, TimerSize> _registers;

public:
    static const uint8_t ID = TimerId;
    typedef TimerWaveform<_registers, TimerSize> waveform;
    typedef TimerPwm<_registers, TimerSize> pwm;
    typedef TimerCounter<_registers, TimerSize> counter;
    typedef TimerPrescaler <ID> prescaler;

    enum TimerMode
    {
        MODE_COUNTER,
        MODE_PWM,
        MODE_WAVEFORM
    };

public:
    static inline void mode(const TimerMode mode)
    {
        if (mode == MODE_COUNTER)
        {
            _registers::waveform_generation_normal_mode();
        }
        else if (mode == MODE_PWM)
        {
            _registers::waveform_generation_fast_pwm_mode_1();
        }
        else if (mode == MODE_WAVEFORM)
        {
            _registers::waveform_generation_fast_pwm_mode_2();
        }
    }

    static inline void disable()
    {
        _registers::disable();
    }

    static inline void enable()
    {
        _registers::enable();
    }

    static inline void set_prescaler(const typename prescaler::PrescalerValue p)
    {
        _registers::prescaler(p);
    }

    static inline uint8_t get_prescaler()
    {
        return _registers::prescaler();
    }
};

#ifdef TCNT0
#include "timer/timer_0.hpp"
#endif

#ifdef TCNT1
#include "timer/timer_1.hpp"
#endif

#ifdef TCNT2
#include "timer/timer_2.hpp"
#endif

#ifdef TCNT3
#include "timer/timer_3.hpp"
#endif

#ifdef TCNT4
#include "timer/timer_4.hpp"
#endif

#ifdef TCNT5
#include "timer/timer_5.hpp"
#endif

#endif // TIMER_HPP
