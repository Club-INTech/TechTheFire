#ifndef _WAVEFORM_HPP
#define _WAVEFORM_HPP

template<class TimerRegisters, class TimerSize>
class TimerWaveform
{
public:
    enum OutputMode
    {
        OUTPUT_NON_INVERTING,
        OUTPUT_INVERTING,
        OUTPUT_DISCONNECT
    };

public:
    static inline void frequency(uint32_t f)
    {
        //TODO frequency
    }

    static inline void duty_cycle()
    {
        //TODO duty_cylce
    }

    static inline void output_compare_register_a(TimerSize value)
    {
        TimerRegisters::pwm_a(value);
    }

    static inline void output_compare_register_b(TimerSize value)
    {
        TimerRegisters::pwm_b(value);
    }

    static inline void output_mode(const OutputMode mode)
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

    static inline void enable_frequency_output()
    {
        TimerRegisters::compare_output_toggle_mode_a();
    }

    static inline void disable_frequency_output()
    {
        TimerRegisters::compare_output_disconnect_mode_a();
    }
};

#endif // WAVEFORM_HPP
