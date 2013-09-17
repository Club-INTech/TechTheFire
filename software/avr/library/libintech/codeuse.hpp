#ifndef CODEUSE_HPP 
#define CODEUSE_HPP

#include "gpio.hpp"

template<class PinA, class PcintA, class PinB, class PcintB, bool DeuxCanaux>
class Codeuse
{

private:
	int32_t _compteur;
	uint8_t mb;  //Mise en mémoire de l'ancienne valeur de cb

public:
	Codeuse():
		_compteur(0)
	{
		//Mise en lecture des Pins des codeuses
		PinA::input();
		PinB::input();

		// Initialisation interruptions codeurs
		PcintB::enable();
        if (DeuxCanaux) PcintA::enable();

		mb = PinB::read();
	}
	inline void interruption()
	{
		if(PinA::read() == mb) ++_compteur; // Test du sens de rotation de la roue. Ecrire la table de vérité pour comprendre.
		else --_compteur;
		mb = PinB::read(); //Mise en mémoire de l'ancienne valeur de cb
	}

	inline int32_t compteur()
	{
		return _compteur;
	}

	inline void compteur(int32_t c)
	{
		_compteur = c;
	}

};

#endif
