#include "robot.h"
// Constructeur avec assignation des attributs
Robot::Robot() : 	
			x_(0)
			,y_(0)
			,angle_origine_(0.0)
			,etat_rot_(true)
			,etat_tra_(true)
			,translation(0.45,12.0,0.0) // 0.45,12.5 pour 90  0.52 17.0 pour 170 0.55,27 pour 200 0.5,4.0 pour 60
			,rotation(0.8,15.0,0.0)  //0,85, 15.0
{
	TWI_init();
	serial_t_::init();
	sei();
	timerCompteur::mode(timerCompteur::MODE_COUNTER);
	timerCompteur::set_prescaler(timerCompteur::prescaler::PRESCALER_1);
	timerCompteur::counter::overflow_interrupt::enable();
	D5::output();
	D6::output();
	serial_t_::change_baudrate(57600);
    serial_t_::activer_acquittement(true);
	translation.valeur_bridage(120);
	rotation.valeur_bridage   (100);
	changer_orientation(PI);
}

void Robot::asservir()
{
	int32_t pwmTranslation;
	int32_t pwmRotation;

	if (etat_rot_)
		pwmRotation = rotation.pwm(mesure_angle_,0);
	else
		pwmRotation = 0;

	if(etat_tra_)
		pwmTranslation = translation.pwm(mesure_distance_,0);
	else
		pwmTranslation = 0;
	moteurGauche.envoyerPwm(pwmTranslation - pwmRotation);
	moteurDroit.envoyerPwm(pwmTranslation + pwmRotation);
	
}

//calcul de la nouvelle position courante du robot, en absolu sur la table (mm et radians)
void Robot::update_position()
{
	static int32_t last_mesure_distance = 0;
	
	int32_t delta_distance_tic = mesure_distance_ - last_mesure_distance;
	
	float delta_distance_mm = delta_distance_tic * CONVERSION_TIC_MM;
	float angle_radian = get_angle_radian();
	
	x_ += ( delta_distance_mm * cos_table(angle_radian) );
	y_ += ( delta_distance_mm * sin_table(angle_radian) );
	
	last_mesure_distance = mesure_distance_;
	
}

////////////////////////////// PROTOCOLE SERIE ///////////////////////////////////
void Robot::communiquer_pc(){
	char buffer[17];
	serial_t_::read(buffer);

	//ping
	if(strcmp(buffer,"?") == 0)
	{
		serial_t_::print(0);
	}
	
	//maj des constantes d'asservissement en rotation
	else if(strcmp(buffer,"crp") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		rotation.kp(valeur);
	}
	else if(strcmp(buffer,"crd") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		rotation.kd(valeur);
	}
	else if(strcmp(buffer,"cri") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		rotation.ki(valeur);
	}
	else if(strcmp(buffer,"crm") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		rotation.valeur_bridage(valeur);
	}

	//maj des constantes d'asservissement en translation
	else if(strcmp(buffer,"ctp") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		translation.kp(valeur);
	}
	else if(strcmp(buffer,"ctd") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		translation.kd(valeur);
	}
	else if(strcmp(buffer,"cti") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		translation.ki(valeur);
	}
	else if(strcmp(buffer,"ctm") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		translation.valeur_bridage(valeur);
	}

	//maj de la position absolue du robot
	else if(strcmp(buffer,"cx") == 0)
	{
		serial_t_::read(x_);
	}
	else if(strcmp(buffer,"cy") == 0)
	{
		serial_t_::read(y_);
	}
	else if(strcmp(buffer,"co") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		changer_orientation(valeur);
	}
	
	//renvoi de la position absolue du robot
	else if(strcmp(buffer,"ex") == 0)
	{
		serial_t_::print((int32_t)x_);
	}
	else if(strcmp(buffer,"ey") == 0)
	{
		serial_t_::print((int32_t)y_);
	}
	else if(strcmp(buffer,"eo") == 0)
	{
		serial_t_::print((int32_t)(get_angle_radian() * 1000));
	}

	//ordre de translation
	else if(strcmp(buffer,"d") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		translater(valeur);
	}

	//ordre de rotation
	else if(strcmp(buffer,"t") == 0)
	{
		float valeur;
		serial_t_::read(valeur);
		tourner(valeur);
	}

	//ordre d'arret (asservissement aux angle et position courants)
	else if(strcmp(buffer,"stop") == 0)
	{
		stopper();
	}
	
	//stopper asservissement rotation/translation
	else if(strcmp(buffer,"cr0") == 0)
	{
		etat_rot_ = false;
	}
	else if(strcmp(buffer,"ct0") == 0)
	{
		etat_tra_ = false;
	}

	//démarrer asservissement rotation/translation
	else if(strcmp(buffer,"cr1") == 0)
	{
		etat_rot_ = true;
	}
	else if(strcmp(buffer,"ct1") == 0)
	{
		etat_tra_ = true;
	}

	// Changement de la vitesse de translation
	else if(strcmp(buffer,"ctv") == 0)
	{
		float kp, kd;
		uint32_t brid;
		
		serial_t_::read(kp);
		serial_t_::read(kd);
		serial_t_::read(brid);
		
		changerVitesseTra(kp, kd, brid);
	}
	
	// Changement de la vitesse de rotation
	else if(strcmp(buffer,"crv") == 0)
	{
		float kp, kd;
		uint32_t brid;
		
		serial_t_::read(kp);
		serial_t_::read(kd);
		serial_t_::read(brid);
		
		changerVitesseRot(kp, kd, brid);
	}
	
	//envoi des paramètres pour l'évaluation des conditions de blocage et d'arret
	else if(strcmp(buffer,"?infos") == 0)
	{
		serial_t_::print(moteurGauche.pwm());
		serial_t_::print(moteurDroit.pwm());
		serial_t_::print(rotation.erreur());
		serial_t_::print(translation.erreur());
	}
	
	//envoi des coordonnées du robot
	else if(strcmp(buffer,"?xyo") == 0)
	{
		serial_t_::print(x_);
		serial_t_::print(y_);
		serial_t_::print((int32_t)(get_angle_radian() * 1000));
	}
	
	//DEBUG des ticks
	else if(strcmp(buffer,"a") == 0)
    {
        serial_t_::print("posT,cT,posR,cR :");
        serial_t_::print(mesure_distance_);
        serial_t_::print(translation.consigne());
        serial_t_::print(mesure_angle_);
        serial_t_::print(rotation.consigne());
    }
}
////////////////////////////// VITESSES /////////////////////////////

// Changement de la vitesse de translation
void Robot::changerVitesseTra(float kp, float kd, uint32_t brid)
{
	translation.valeur_bridage(brid);
	translation.kp(kp);
	translation.kd(kd);

}
void Robot::changerVitesseRot(float kp, float kd, uint32_t brid)
{
	rotation.valeur_bridage(brid);
	rotation.kp(kp);
	rotation.kd(kd);

}
////////////////////////////// ACCESSEURS /////////////////////////////////
void Robot::mesure_angle(int32_t new_angle)
{
	mesure_angle_ = new_angle;
}
void Robot::mesure_distance(int32_t new_distance)
{
	mesure_distance_ = new_distance;
}
float Robot::get_angle_radian()
{
	return mesure_angle_ * CONVERSION_TIC_RADIAN + angle_origine_;
}
////////////////////////// MÉTHODES DE CALCUL ET DE DÉPLACEMENT ////////////////////////////
//calcule l'angle le plus court pour atteindre angle à partir de angleBkp (ie sans faire plusieurs tours)
// le déplacement DOIT etre relatif à angleBkp, et non pas sur un intervalle défini genre [0,2*PI[, 
// puisque angleBkp a enregistré les tours du robot sur lui meme, depuis l'initialisation.
int32_t Robot::angle_optimal(int32_t angle, int32_t angleBkp)
{
	while (angle > angleBkp+PI_TIC)
		angle -= 2*PI_TIC;
	while (angle <= angleBkp-PI_TIC)
		angle += 2*PI_TIC;
	return angle;
}

//attribuer une nouvelle orientation au robot, en radian.
// Les valeurs en tic (mesure_angle_) ne sont pas modifiées, car liées aux déplacement des codeuses.
void Robot::changer_orientation(float new_angle)
{
	angle_origine_ = new_angle - (get_angle_radian() - angle_origine_);
}

void Robot::tourner(float angle)
{
	float angle_tic = (angle - angle_origine_)/CONVERSION_TIC_RADIAN;
	rotation.consigne(angle_optimal( angle_tic, mesure_angle_ ));
	//attendre un tour de timer avant de continuer (éventuel problème avec attribut volatile)
// 	while(compteur.value()>0){ asm("nop"); }
}

void Robot::translater(float distance)
{
// 	translation.consigne(translation.consigne()+distance/CONVERSION_TIC_MM);
	
	translation.consigne(mesure_distance_+distance/CONVERSION_TIC_MM);
	//attendre un tour de timer avant de continuer (éventuel problème avec attribut volatile)
// 	while(compteur.value()>0){ asm("nop"); }
	
}

//pour stopper le robot on l'asservit sur sa position courante
void Robot::stopper()
{
	rotation.consigne(mesure_angle_);
	translation.consigne(mesure_distance_);
}
