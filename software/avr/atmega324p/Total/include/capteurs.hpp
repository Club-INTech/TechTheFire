#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <libintech/capteur_infrarouge.hpp>
#include <libintech/capteur_srf05.hpp>

#define NB_SRF_AVANT            1
#define NB_INFRAROUGE_AVANT     0

class Capteurs
{
	public:
            //Le prescalaire 64 est nécessaire (sinon les valeurs retournées sont fausses)
        typedef timer1 timer_ultra;
        typedef timer0 timer_refresh;
        
        typedef CapteurSRFMono< timer_capteur_us, D5, pcint29 > capteur_us1_type;
        capteur_us1_type us1;

Capteurs::Capteurs()
{


		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);

		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_StructInit(&GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM13);

		TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
			TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
			TIM_TimeBaseStructure.TIM_Prescaler = 64;
			TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
			TIM_TimeBaseStructure.TIM_Period = 0;
			TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
			TIM_TimeBaseInit(TIM13, &TIM_TimeBaseStructure);

			TIM_Cmd(TIM13, ENABLE);

			TIM_SetCounter(TIM13, 2147483647);
//		code � traduire :
//    timer_capteur_us::mode(timer_capteur_us::MODE_COUNTER);
//    timer_refresh::mode(timer_refresh::MODE_COUNTER);
//    timer_capteur_us::set_prescaler(timer_capteur_us::prescaler::PRESCALER_64);
//    timer_refresh::set_prescaler(timer_refresh::prescaler::PRESCALER_1024); //normal = 1024
//    timer_refresh::counter::overflow_interrupt::enable();

}

 void Capteurs::Maj(){

 }

//	uint_16 ultra_front_left () {
//		return 0;
//	}
};



#endif
