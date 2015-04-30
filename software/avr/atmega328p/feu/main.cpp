#include <stdint.h>
#include <libintech/gpio.hpp>
#include <libintech/timer.hpp>
#include <util/delay.h>
#define ABWABWA 7

inline void pwm_vert(int value)
{
    timer2::pwm::pwm_b(value);
}

inline void pwm_orange(int value)
{
    timer0::pwm::pwm_b(value);
}

inline void pwm_rouge(int value)
{
    timer0::pwm::pwm_a(value);
}
int main()
{
    timer0::mode(timer0::MODE_PWM);
    timer0::set_prescaler(timer0::prescaler::PRESCALER_1);
    timer0::pwm::output_mode_a(timer0::pwm::OUTPUT_NON_INVERTING);
    timer0::pwm::output_mode_b(timer0::pwm::OUTPUT_NON_INVERTING);
    timer0::pwm::waveform_mode(timer0::pwm::PWM_FAST);

    timer2::mode(timer2::MODE_PWM);
    timer2::set_prescaler(timer2::prescaler::PRESCALER_1);
    timer2::pwm::output_mode_a(timer2::pwm::OUTPUT_NON_INVERTING);
    timer2::pwm::output_mode_b(timer2::pwm::OUTPUT_NON_INVERTING);
    timer2::pwm::waveform_mode(timer2::pwm::PWM_FAST);

    D3::output(); //timer2 pwm b vert
    D5::output(); //timer0 pwm b orange
    D6::output(); //timer0 pwm a rouge

    while (1)
    {
        int vert = 0;
        int orange = 0;
        int rouge = 0;

        for(int i = 0; i <= 40*ABWABWA; i++)
        {
            if (vert)
            {
                pwm_vert(15);
                vert = 0;
            }
            else
            {
                pwm_vert(255);
                vert = 1;
            }
            if (vert)
            {
                if (orange)
                {
                    pwm_orange(15);
                    orange = 0;
                }
                else
                {
                    pwm_orange(255);
                    orange = 1;
                }
                if (orange)
                {
                    if (rouge)
                    {
                        pwm_rouge(15);
                        rouge = 0;
                    }
                    else
                    {
                        pwm_rouge(255);
                        rouge = 1;
                    }
                }
            }
            _delay_ms(1000);
        }
        for(int i = 0; i <= 10; i++)
        {
            timer0::pwm::pwm_a(255);
            _delay_ms(50);
            timer0::pwm::pwm_a(15);
            _delay_ms(50);
            timer0::pwm::pwm_b(255);
            _delay_ms(50);
            timer0::pwm::pwm_b(15);
            _delay_ms(50);
            timer2::pwm::pwm_b(255);
            _delay_ms(50);
            timer2::pwm::pwm_b(15);
            _delay_ms(50);
        }
    }
    return 0 ;
}
