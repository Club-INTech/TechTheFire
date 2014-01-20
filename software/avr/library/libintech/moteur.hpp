/** 
 * Classe de contrôle d'un moteur (PWM et Direction)
 * 
 * @author Philippe TILLET phil.tillet@gmail.com
 * @author Marc BLANC-PATIN marc.blancpatin@gmail.com
 * 
 */

#ifndef MOTEUR_HPP
#define MOTEUR_HPP

#include "utils.h"
#include "timer.hpp"
#include "gpio.hpp"
#include "safe_enum.hpp"

/**
 * 
 * PWM                  Timer en mode PWM utilisé pour générer le PWM du moteur (cf pwm.hpp)
 * DirectionRegister    Pin utilisé pour la sortie de la direction (cf register.hpp)
 * 
 */
template<class Timer, char Channel, class DirectionRegister>
class Moteur {

public:
	static const uint8_t TIMER_ID = Timer::ID;

public:

	Moteur() : maxPWM_(255), pwm_(0) {
		Timer::mode(Timer::MODE_PWM);
		Timer::set_prescaler(Timer::prescaler::PRESCALER_1);
		Timer::pwm::waveform_mode(Timer::pwm::PWM_FAST);
		if (Channel == 'A')
		{
			Timer::pwm::output_mode_a(Timer::pwm::OUTPUT_NON_INVERTING);
		}
		else
		{
			Timer::pwm::output_mode_b(Timer::pwm::OUTPUT_NON_INVERTING);
		}
		DirectionRegister::output();
	}

private:
	int16_t maxPWM_;
	int16_t pwm_;

public:

	/**
	 * Fixe la valeur du PWM du moteur, et prend en compte le signe pour la direction
	 * 
	 * @param pwm       Valeur du PWM ([-255,255] pour un timer 8 bit, [-65535,65535] pour un 16 bit)
	 */
	void envoyerPwm(int16_t pwm) {
		pwm_ = pwm;

		if (pwm > 0) {
			DirectionRegister::low();
		}
		else {
			DirectionRegister::high();
			pwm *= -1;
		}
		if (Channel == 'A')
		{
			Timer::pwm::pwm_a(min(pwm, maxPWM_)); //Bridage
		}
		else
		{
			Timer::pwm::pwm_b(min(pwm, maxPWM_)); //Bridage
		}
	}

	/**
	 * @return Retourne la valeur courante du PWM
	 */
	int16_t pwm() {
		return pwm_;
	}

	/**
	 * Fixe le PWM max pour le moteur
	 * 
	 * @param maxPWM
	 */
	void maxPWM(int16_t maxPWM) {
		maxPWM_ = maxPWM;
	}

	/**
	 * @return Retourne la valeur du PWM max fixé pour ce moteur
	 */
	int16_t maxPWM() const {
		return maxPWM_;
	};

};


#endif
