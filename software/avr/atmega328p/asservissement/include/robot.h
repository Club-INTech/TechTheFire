#ifndef robot_h
#define robot_h

#include "Cos.h"
#include "twi_master.h"

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#include <libintech/asservissement.hpp>
#include <libintech/uart.hpp>
#include <libintech/timer.hpp>
#include <libintech/gpio.hpp>
#include <libintech/moteur.hpp>
#include <libintech/singleton.hpp>

#define PI 3.14159265
#define PI_TIC 4255

#define LARGEUR_ROBOT 200.0
#define LONGUEUR_TABLE 3000.0

#define CONVERSION_TIC_MM 0.10392 //0.10341
#define CONVERSION_TIC_RADIAN -0.0007401//0.0007382 No hack here, follow your path

class Robot : public Singleton<Robot>{
// Par défaut les attributs sont publics dans une struct


private:

	typedef timer0 timerMoteurs;
    //Moteur sur le Timer 0 sur la pin B. Pont en H sur le PORTD4
    Moteur< timerMoteurs, 'B', D4 > moteurGauche;
    
    //Moteur sur le Timer 0 sur la pin A. Pont en H sur le port B0
    Moteur< timerMoteurs, 'A', B0 > moteurDroit;
    
    //Timer 1 en mode compteur, Prescaler de 1
    typedef timer1 timerCompteur;
    
    typedef uart0 serial_t_;
    
    float x_;
    float y_;
    float angle_origine_;
    
    bool etat_rot_;
    bool etat_tra_;
    
    int32_t mesure_distance_;
    int32_t mesure_angle_;
    
    
    Asservissement translation;
    Asservissement rotation;
    
public:
    
    Robot();
    
    //gestion des mesures courantes
    void mesure_angle(int32_t); 
    void mesure_distance(int32_t); 
    float get_angle_radian();

    void changer_orientation(float new_angle);
    
    void changerVitesseTra(float kp, float kd, uint32_t brid);
    void changerVitesseRot(float kp, float kd, uint32_t brid);
    
    void asservir();
    void update_position();
    void communiquer_pc();
    
    int32_t angle_optimal(int32_t angle, int32_t angleBkp);
    
    void tourner(float angle);
    void translater(float distance);

    void stopper();
};

#endif
