#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <libintech/capteur_infrarouge.hpp>
#include <libintech/capteur_srf05.hpp>
#include <libintech/timer.hpp>
#include <libintech/gpio.hpp>

#define NB_SRF_AVANT            1
//#define NB_INFRAROUGE_AVANT     0

#define TAILLE_BUFFER   50

//   /!\ A debuguer !!!!

/**
 * Gestion des actionneurs
 * 
 */

class Capteurs
{
public:
	//Le prescalaire 64 est nécessaire (sinon les valeurs retournées sont fausses)
	typedef timer1 timer_capteur_us;
	typedef timer0 timer_refresh;

	typedef CapteurSRFMono< timer_capteur_us, D5, pcint29 > capteur_us1_type;
	capteur_us1_type us1;

  //	typedef CapteurSRFMono< timer_capteur_us, A0, pcint0 > capteur_us2_type;
  //	capteur_us2_type us2;

private:
	uint8_t bufferContactGauche[TAILLE_BUFFER];
	uint8_t bufferContactMilieu[TAILLE_BUFFER];
	uint8_t bufferContactDroit[TAILLE_BUFFER];

public:

	Capteurs()
{
		timer_capteur_us::mode(timer_capteur_us::MODE_COUNTER);
		timer_refresh::mode(timer_refresh::MODE_COUNTER);
		timer_capteur_us::set_prescaler(timer_capteur_us::prescaler::PRESCALER_64);
		timer_refresh::set_prescaler(timer_refresh::prescaler::PRESCALER_1024); //normal = 1024
		timer_refresh::counter::overflow_interrupt::enable();
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
		{
			bufferContactGauche[i]=0;
			bufferContactMilieu[i]=0;
			bufferContactDroit[i]=0;
		}

}

	void maj()
	{
		uint8_t retenueAvant = B1::read(); // TODO actuel : C0 pour les nouvelles cartes, cela sera B1
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
		{
			uint8_t retenueApres = bufferContactDroit[i]&(1<<7)>>7;
			bufferContactDroit[i] <<= 1;
			bufferContactDroit[i] += retenueAvant;
			retenueAvant = retenueApres;
		}

		retenueAvant = B0::read(); // TODO actuel : C1 pour les nouvelles cartes, cela sera B0
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
		{
			uint8_t retenueApres = bufferContactMilieu[i]&(1<<7)>>7;
			bufferContactMilieu[i] <<= 1;
			bufferContactMilieu[i] += retenueAvant;
			retenueAvant = retenueApres;
		}

		retenueAvant = B2::read(); // TODO actuel C3 pour les nouvelles cartes, cela sera B2
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
		{
			uint8_t retenueApres = bufferContactGauche[i]&(1<<7)>>7;
			bufferContactGauche[i] <<= 1;
			bufferContactGauche[i] += retenueAvant;
			retenueAvant = retenueApres;
		}
	}

	uint8_t contactDroit()
	{
		uint8_t etat = 0;
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
			etat |= bufferContactDroit[i];
		return etat;
	}

	uint8_t contactMilieu()
	{
		uint8_t etat = 0;
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
			etat |= bufferContactMilieu[i];
		return etat;
	}

	uint8_t contactGauche()
	{
		uint8_t etat = 0;
		for(uint8_t i=0; i<TAILLE_BUFFER; i++)
			etat |= bufferContactGauche[i];
		return etat;
	}

};



#endif
