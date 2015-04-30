#include <stdint.h>
#include <util/delay.h>
#include <libintech/utils.h> //controle de la led
#include <libintech/serial/serial_0_interrupt.hpp>
#include <libintech/serial/serial_0.hpp>
#include <avr/interrupt.h>

#define PIN_DIR PORTD4
#define PIN_DEP PORTD5
#define NOP     __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");\
                __asm__ ("nop");

#define DOB     -1
#define DO      0
#define DOD     1
#define REB     1
#define RE      2
#define RED     3
#define MIB     3
#define MI      4
#define MID     5
#define FAB     4
#define FA      5
#define FAD     6
#define SOLB    6
#define SOL     7
#define SOLD    8
#define LAB     8
#define LA      9
#define LAD     10
#define SIB     10
#define SI      11
#define OCTAVE  12

void joue(uint32_t freq, uint32_t rythme);
void silence(uint32_t rythme);

uint32_t tempo = 700;
uint8_t unite = 1;
uint8_t octave_base = 1;
uint8_t transposition = 0;
uint8_t volume = 1;

int main(){
  //port serie
  char reception[10];
  Serial<0>::init();
  Serial<0>::change_baudrate(9600);
  Serial<0>::print("Floppy prêt");
  sbi(DDRD, DDD4); // pin de direction
  sbi(DDRD, DDD5); // pin de déplacement
  cbi(PORTD, PIN_DIR);
  cbi(PORTD, PIN_DEP);

  while(1)
  {
    Serial<0>::read(reception);
    if(strcmp(reception,"+")==0)
    {
            cbi(PORTD, PIN_DIR);
            sbi(PORTD, PIN_DEP);
                NOP
            cbi(PORTD, PIN_DEP);
    }
    else if(strcmp(reception,"-")==0)
    {
            sbi(PORTD, PIN_DIR);
            sbi(PORTD, PIN_DEP);
                NOP
            cbi(PORTD, PIN_DEP);
    }
    else if(strcmp(reception,"gamme")==0)
    {
    uint8_t i;
        tempo = 100;
        unite = 6;
        octave_base = 1;
        transposition = 0;
        for(i = 0; i < 28; i++)
        {
        joue(i, 1);
        silence(1);
        }
    }
    else if(strcmp(reception,"metroid")==0)
    {
        Serial<0>::print("Metroid (Kraid's Theme)");
        uint8_t i;
        tempo = 280;
        unite = 3;
        octave_base = 0;
        transposition = 0;

        for(i = 0; i < 4; i++)
        {
            joue(OCTAVE+MI, 4);
            joue(SI, 2);
            joue(OCTAVE+LA, 4);
            joue(OCTAVE+DO, 2);
            joue(OCTAVE+FAD, 4);
            joue(OCTAVE+RE, 2);
            joue(SI, 4);
            joue(SIB, 2);
        }

        for(i = 0; i < 4; i++)
        {
            joue(OCTAVE+SOL, 4);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 4);
            joue(SI, 2);
            joue(OCTAVE+FAD, 4);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+LA, 4);
            joue(OCTAVE+MI, 2);
        }

        for(i = 0; i < 2; i++)
        {
            joue(OCTAVE+SOL, 1);
            joue(SI, 1);
            joue(OCTAVE+SOL, 1);
            joue(SI, 1);
            joue(OCTAVE+SOL, 1);
            joue(SI, 1);

            joue(OCTAVE+SIB, 1);
            joue(OCTAVE+MI, 1);
            joue(OCTAVE+SIB, 1);
            joue(OCTAVE+MI, 1);
            joue(OCTAVE+SIB, 1);
            joue(OCTAVE+MI, 1);

            joue(OCTAVE+LA, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+LA, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+LA, 1);
            joue(OCTAVE+DO, 1);

            joue(OCTAVE+LA, 1);
            joue(OCTAVE+RED, 1);
            joue(OCTAVE+FAD, 1);
            joue(OCTAVE+RE, 1);
            joue(OCTAVE+SI, 1);
            joue(OCTAVE+RE, 1);
        }

        for(i = 0; i < 2; i++)
        {
            joue(OCTAVE+FAD, 1);
            joue(OCTAVE+SOL, 1);
            joue(OCTAVE+LA, 1);
            joue(OCTAVE+SI, 1);
            joue(2*OCTAVE+RE, 1);
            joue(OCTAVE+SI, 1);
            joue(2*OCTAVE+FAD, 1);
            joue(2*OCTAVE+RE, 1);
            joue(OCTAVE+LA, 1);
            joue(OCTAVE+SOL, 1);
            joue(OCTAVE+FA, 1);
            joue(OCTAVE+SI, 1);

            joue(2*OCTAVE+LA, 1);
            joue(2*OCTAVE+FAD, 1);
            joue(2*OCTAVE+RE, 1);
            joue(OCTAVE+LA, 1);
            joue(OCTAVE+SOL, 1);
            joue(OCTAVE+FAD, 1);
            joue(OCTAVE+MI, 1);
            joue(OCTAVE+SOL, 1);
            joue(OCTAVE+LA, 1);
            joue(2*OCTAVE+RE, 1);
            joue(2*OCTAVE+MI, 1);
            silence(1);
        }

        for(i = 0; i < 4; i++)
        {
            joue(2*OCTAVE+LA, 1);
            silence(1);
            joue(2*OCTAVE+SOL, 1);
            silence(1);
            joue(2*OCTAVE+FAD, 1);
            silence(1);
            joue(2*OCTAVE+MI, 1);
            silence(1);
            joue(2*OCTAVE+FAD, 1);
            silence(1);
            joue(2*OCTAVE+SOL, 1);
            silence(1);
        }

    }
    else if(strcmp(reception,"tetris")==0)
    {
        Serial<0>::print("Tetris (Theme A)");
        tempo = 200;
        unite = 6;
        octave_base = 1;
        transposition = 0;

        uint8_t i;
        for(i = 0; i < 2; i++)
        {
            joue(OCTAVE+MI, 2);

            joue(SI, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 2);

            joue(OCTAVE+DO, 1);
            joue(SI, 1);
            joue(LA, 2);

            joue(LA, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+MI, 2);

            joue(OCTAVE+RE, 1);
            joue(OCTAVE+DO, 1);
            joue(SI, 3);

            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 2);
            joue(OCTAVE+DO, 2);
            joue(LA, 2);

            joue(LA, 1);
            joue(LA, 1);
            joue(SI, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 3);
            joue(OCTAVE+FA, 1);
            joue(OCTAVE+LA, 2);
            joue(OCTAVE+SOL, 1);
            joue(OCTAVE+FA, 1);
            joue(OCTAVE+MI, 3);


            joue(OCTAVE+DO, 1);
            joue(OCTAVE+MI, 2);

            joue(OCTAVE+RE, 1);
            joue(OCTAVE+DO, 1);
            joue(SI, 2);

            joue(SI, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 2);
            joue(OCTAVE+DO, 2);
            joue(LA, 2);
            joue(LA, 2);
            silence(2);
        }

        joue(OCTAVE+MI, 4);
        joue(OCTAVE+DO, 4);
        joue(OCTAVE+RE, 4);
        joue(SI, 4);
        joue(OCTAVE+DO, 4);
        joue(LA, 4);
        joue(SOLD, 4);
        joue(SI, 2);
        silence(2);
        joue(OCTAVE+MI, 4);
        joue(OCTAVE+DO, 4);
        joue(OCTAVE+RE, 4);
        joue(SI, 4);
        joue(OCTAVE+DO, 2);
        joue(OCTAVE+MI, 2);
        joue(OCTAVE+LA, 4);
        joue(OCTAVE+SOLD, 4);
        silence(4);
    }
    else if(strcmp(reception,"fou")==0)
    {
        Serial<0>::print("Tetris (Theme A) version folle");
        tempo = 200;
        unite = 6;
        octave_base = 1;
        transposition = 0;

        uint8_t i;
        for(i = 0; i < 4; i++)
        {
            joue(OCTAVE+MI, 2);

            joue(SI, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 2);

            joue(OCTAVE+DO, 1);
            joue(SI, 1);
            joue(LA, 2);

            joue(LA, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+MI, 2);

            joue(OCTAVE+RE, 1);
            joue(OCTAVE+DO, 1);
            joue(SI, 3);

            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 2);
            joue(OCTAVE+DO, 2);
            joue(LA, 2);

            joue(LA, 1);
            joue(LA, 1);
            joue(SI, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 3);
            joue(OCTAVE+FA, 1);
            joue(OCTAVE+LA, 2);
            joue(OCTAVE+SOL, 1);
            joue(OCTAVE+FA, 1);
            joue(OCTAVE+MI, 3);


            joue(OCTAVE+DO, 1);
            joue(OCTAVE+MI, 2);

            joue(OCTAVE+RE, 1);
            joue(OCTAVE+DO, 1);
            joue(SI, 2);

            joue(SI, 1);
            joue(OCTAVE+DO, 1);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 2);
            joue(OCTAVE+DO, 2);
            joue(LA, 2);
            joue(LA, 2);
            silence(2);
            transposition+=2;
            tempo -= 40;
        }
    }
    else if(strcmp(reception,"portal")==0)
    {
        Serial<0>::print("Portal: Still Alive");
        Serial<0>::print("");
        tempo = 270;
        unite = 6;
        octave_base = 1;
        transposition = 3;

        Serial<0>::print("This was a triumph");

        joue(OCTAVE+SOL, 1); // This was a triumph
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+FAD, 4);
        silence(7);

        Serial<0>::print("I'm making a note here");
        joue(LA, 1);          // I'm making a note here
        joue(OCTAVE+SOL, 1);
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+MI, 2);
        joue(OCTAVE+FAD, 3);

        Serial<0>::print("Huge success");
        joue(OCTAVE+RE, 2);     // huge success
        joue(OCTAVE+MI, 1);
        joue(LA, 4);
        silence(4);

        Serial<0>::print("It's hard to overstake my satisfaction");
        joue(LA, 1);            // It's hard to overstake my satisfaction
        joue(OCTAVE+MI, 2);
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+SOL, 3);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+DOD, 2);
        joue(OCTAVE+RE, 3);
        joue(OCTAVE+MI, 2);
        joue(LA, 1);
        joue(LA, 2);
        joue(OCTAVE+FAD, 4);
        silence(7);

        Serial<0>::print("Aperture science");
        joue(OCTAVE+SOL, 1);    // Aperture science
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+FAD, 4);
        silence(7);

        Serial<0>::print("We do what we must because we can");
        joue(LA, 1);            // We do what we must because we can
        joue(OCTAVE+SOL, 1);
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+MI, 3);
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+RE, 3);
        joue(OCTAVE+MI, 1);
        joue(LA, 5);
        silence(4);

        Serial<0>::print("For the good of all of us");
        joue(OCTAVE+MI, 2); // For the good of all of us, except the ones who are dead
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+SOL, 3);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+DOD, 3);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+MI, 2);

        Serial<0>::print("Except the ones who are dead");
        joue(LA, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+FA, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+DO, 1);
        silence(2);

        Serial<0>::print("But there's no sense crying over ev'ry mistake");
        joue(LA, 1);        // But there's no sense crying over ev'ry mistake
        joue(SIB, 1);
        joue(OCTAVE+DO, 2);
        joue(OCTAVE+FA, 2);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+DO, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+DO, 1);
        joue(OCTAVE+DO, 2);
        joue(OCTAVE+DO, 2);

        Serial<0>::print("You just keep on trying till you run out of cake");
        joue(LA, 1);        // You just keep on trying till you run out of cake
        joue(SIB, 1);
        joue(OCTAVE+DO, 2);
        joue(OCTAVE+FA, 2);
        joue(OCTAVE+SOL, 1);
        joue(OCTAVE+FA, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+FA, 2);
        joue(OCTAVE+FA, 2);

        Serial<0>::print("And the Science gets done");
        joue(OCTAVE+SOL, 1); // And the Science gets done
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+SIB, 1);
        joue(OCTAVE+SIB, 1);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+SOL, 2);

        Serial<0>::print("And you make a neat gun");
        joue(OCTAVE+FA, 1); // and you make a neat gun
        joue(OCTAVE+SOL, 1);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+FA, 2);

        Serial<0>::print("For the people who are still alive");
        joue(OCTAVE+RE, 1); // for the people who are still alive
        joue(OCTAVE+DO, 1);
        joue(OCTAVE+RE, 1);
        joue(OCTAVE+FA, 1);
        joue(OCTAVE+FA, 1);
        joue(OCTAVE+MI, 2);
        joue(OCTAVE+MI, 1);
        joue(OCTAVE+FAD, 1);
        joue(OCTAVE+FAD, 3);

    }
    else if(strcmp(reception,"king")==0)
    {
        Serial<0>::print("In the Hall of the Mountain King");
        tempo = 240;
        unite = 3;
        octave_base = 0;
        transposition = 0;

        volume = 3;
        uint8_t i;
        for(i = 0; i < 2; i++)
        {
            joue(SI, 2);
            joue(OCTAVE+DOD, 2);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 2);
            joue(OCTAVE+FAD, 1);
            silence(1);
            joue(OCTAVE+RE, 1);
            silence(1);
            joue(OCTAVE+FAD, 1);
            silence(3);

            joue(OCTAVE+MID, 1);
            silence(1);
            joue(OCTAVE+DOD, 1);
            silence(1);
            joue(OCTAVE+MID, 1);
            silence(3);

            joue(OCTAVE+MI, 1);
            silence(1);
            joue(OCTAVE+DO, 1);
            silence(1);
            joue(OCTAVE+MI, 1);
            silence(3);

            joue(SI, 2);
            joue(OCTAVE+DOD, 2);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+MI, 2);
            joue(OCTAVE+FAD, 2);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+FAD, 2);
            joue(OCTAVE+SI, 2);
            joue(OCTAVE+LA, 2);
            joue(OCTAVE+FAD, 2);
            joue(OCTAVE+RE, 2);
            joue(OCTAVE+FAD, 2);
            joue(OCTAVE+LA, 8);

            octave_base = 1;
            volume--;
        }

        volume = 1;
        octave_base = 1;
        unite = 6;

        for(i = 0; i < 2; i++)
        {
            joue(OCTAVE+FAD, 1);
            joue(OCTAVE+SOLD, 1);
            joue(OCTAVE+LAD, 1);
            joue(OCTAVE+SI, 1);
            joue(2*OCTAVE+DOD, 1);
            joue(OCTAVE+LAD, 1);
            joue(2*OCTAVE+DOD, 2);

            joue(2*OCTAVE+RE, 1);
            joue(OCTAVE+LAD, 1);
            joue(2*OCTAVE+RE, 2);

            joue(2*OCTAVE+DOD, 1);
            joue(OCTAVE+LAD, 1);
            joue(2*OCTAVE+DOD, 2);

            joue(OCTAVE+FAD, 1);
            joue(OCTAVE+SOLD, 1);
            joue(OCTAVE+LAD, 1);
            joue(OCTAVE+SI, 1);
            joue(2*OCTAVE+DOD, 1);
            joue(OCTAVE+LAD, 1);
            joue(2*OCTAVE+DOD, 2);

            joue(2*OCTAVE+RE, 1);
            joue(OCTAVE+LAD, 1);
            joue(2*OCTAVE+RE, 2);

            joue(2*OCTAVE+DOD, 4);

            octave_base = 1;
        }
    }
/*    else if(strcmp(reception,"pokemon")==0)
    {
        Serial<0>::print("Pokemon: Blue & Red Intro");
        tempo = 150;
        unite = 3;
        octave_base = 1;
        transposition = 0;

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+REB, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+RE, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+REB, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(LA, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+REB, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+SOLB, 4);

        joue(OCTAVE+LAB, 8);
        joue(LAB, 8);
        joue(2*OCTAVE+SIB, 8);
        joue(OCTAVE+SIB, 8);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+REB, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+DO, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+REB, 4);

        joue(LAB, 1);
        silence(1);
        joue(LAB, 1);
        silence(1);
        joue(OCTAVE+SOLB, 4);

        joue(2*OCTAVE+FA, 16);
        joue(2*OCTAVE+FA, 2);


    }*/
/*    else if(strcmp(reception,"007")==0)
    {
        Serial<0>::print("James Bond Theme");
        tempo = 300;
        unite = 3;
        octave_base = 1;
        transposition = 0;

        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 4);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SOL, 2);

        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SIB, 1);
        joue(OCTAVE+SIB, 1);
        joue(OCTAVE+SIB, 2);
        joue(OCTAVE+SIB, 4);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 2);

        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 4);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SOL, 2);

        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SIB, 1);
        joue(OCTAVE+SIB, 1);
        joue(OCTAVE+SIB, 2);
        joue(OCTAVE+SIB, 4);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 2);

        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 1);
        joue(OCTAVE+LA, 2);
        joue(OCTAVE+LA, 4);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SOL, 2);
        joue(OCTAVE+SOL, 2);

        joue(OCTAVE+FAD, 2);
        joue(OCTAVE+LA, 2);

    }*/
  }

  return 0;
}

void silence(uint32_t rythme)
{
    rythme *= unite;
    uint32_t duree = rythme*(tempo >> 4);
    uint32_t nb = (duree*1600000) / (1024);
    uint32_t i;
    for(i = 0; i < nb; i++)
    {
        NOP
    }
}

void joue(uint32_t freq, uint32_t rythme)
{
        uint32_t notes[12] = {523, 554, 587, 622, 659, 698, 740, 784, 830, 880, 932, 987};
        uint32_t k, j;
        freq += transposition;
        rythme *= unite;
        uint32_t note = notes[freq%12];
        note <<= freq/12+octave_base;
        note >>=1;
        uint32_t duree = rythme*(tempo >> 4);
        uint16_t nb = (2*1600000 / note);
        uint16_t nbk = (note * duree) / (2*1024);

        if(nbk <= 0)
            nbk = 1;

        for(k = 0; k < nbk; k++)
        {
            if((k/8)%volume == 0)
            {
                tbi(PORTD, PIN_DIR);
                sbi(PORTD, PIN_DEP);
            }
// 16Mhz
            for(j = 0; j < nb; j++)
            {
                NOP
            }
            cbi(PORTD, PIN_DEP);
        }
}   

