#ifndef _PWM_HPP
#define _PWM_HPP

template<class TimerRegisters, class TimerSize>
class TimerPwm
{
public:
    enum PwmMode
    {
        PWM_FAST,
        PWM_PHASE_CORRECT
    };

    enum OutputMode
    {
        OUTPUT_NON_INVERTING,
        OUTPUT_INVERTING,
        OUTPUT_DISCONNECT
    };

public:
    static inline TimerSize pwm_a()
    {
        return TimerRegisters::pwm_a();
    }

    static inline void pwm_a(TimerSize value)
    {
        TimerRegisters::pwm_a(value);
    }

    static inline TimerSize pwm_b()
    {
        return TimerRegisters::pwm_b();
    }

    static inline void pwm_b(TimerSize value)
    {
        TimerRegisters::pwm_b(value);
    }

    static inline void waveform_mode(const PwmMode mode)
    {
        if (mode == PWM_FAST)
        {
            TimerRegisters::waveform_generation_fast_pwm_mode_1();
        }
        else if (mode == PWM_PHASE_CORRECT)
        {
            TimerRegisters::waveform_generation_phase_correct_mode();
        }
    }

    static inline void output_mode_a(const OutputMode mode)
    {
        if (mode == OUTPUT_NON_INVERTING)
        {
            TimerRegisters::compare_output_non_inverting_mode_a();
        }
        else if (mode == OUTPUT_INVERTING)
        {
            TimerRegisters::compare_output_inverting_mode_a();
        }
        else if (mode == OUTPUT_DISCONNECT)
        {
            TimerRegisters::compare_output_disconnect_mode_a();
        }
    }

    static inline void output_mode_b(const OutputMode mode)
    {
        if (mode == OUTPUT_NON_INVERTING)
        {
            TimerRegisters::compare_output_non_inverting_mode_b();
        }
        else if (mode == OUTPUT_INVERTING)
        {
            TimerRegisters::compare_output_inverting_mode_b();
        }
        else if (mode == OUTPUT_DISCONNECT)
        {
            TimerRegisters::compare_output_disconnect_mode_b();
        }
    }
};

#endif // PWM_HPP
