#ifndef _COUNTER_HPP
#define _COUNTER_HPP

#include <stdint.h>
#include "interrupt.hpp"

template<class TimerRegisters, class TimerSize>
class TimerCounter
{
public:
    typedef TimerInterrupt<TimerRegisters, 0> overflow_interrupt;
    typedef TimerInterrupt<TimerRegisters, 1> compare_a_interrupt;
    typedef TimerInterrupt<TimerRegisters, 2> compare_b_interrupt;
    enum CounterMode
    {
        COUNTER_NORMAL,
        COUNTER_CLEAR_TIMER_ON_COMPARE_MATCH
    };

public:
    static inline void mode(const CounterMode mode)
    {
        if (mode == COUNTER_NORMAL)
        {
            TimerRegisters::waveform_generation_normal_mode();
        }
        else if (mode == COUNTER_CLEAR_TIMER_ON_COMPARE_MATCH)
        {
            TimerRegisters::waveform_generation_ctc_mode();
        }
    }

    static inline TimerSize value()
    {
        return TimerRegisters::counter();
    }

    static inline TimerSize max_value()
    {
        return TimerRegisters::max_value;
    }

    static inline void value(TimerSize value)
    {
        TimerRegisters::counter(value);
    }

    static inline void disable()
    {
        TimerRegisters::disable();
    }

    static inline void enable()
    {
        TimerRegisters::enable();
    }

    static inline void output_compare_register_a(TimerSize value)
    {
        TimerRegisters::pwm_a(value);
    }

    static inline void output_compare_register_b(TimerSize value)
    {
        TimerRegisters::pwm_b(value);
    }

    static inline void frequency(uint32_t f)
    {
        //TODO il faudra passer en mode CTC
    }
};

#endif // COUNTER_HPP
