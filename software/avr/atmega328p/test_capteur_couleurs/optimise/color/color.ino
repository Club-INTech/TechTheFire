#include <avr/io.h>
#include <avr/interrupt.h>
#include <libintech/SimpleTimer.h>
#include <libintech/timer.hpp>

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define IN 2

/*#define DUMP_VAR(x)		\
{				\
	Serial.print(#x);	\
	Serial.print(" : ");    \
	Serial.println(x);	\
}
*/

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

enum Colors{
  RED=0,
  GREEN=1,
  BLUE=2,
  WHITE=3
};

#define OFFSET 70

int colorCount=0;
int currentcolor=0;
SimpleTimer myTimer;
int colorValues[4]={0,0,0,0};

void setup() 
{ 
  Serial.begin(115200);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(S0,OUTPUT);
  pinMode(IN,INPUT);
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  myTimer.begin(nextColor, 100000);
  
  attachInterrupt(IN, count, CHANGE);
  attachInterrupt(2, count, CHANGE);
  attachInterrupt(3, count, CHANGE);
  attachInterrupt(4, count, CHANGE);
  attachInterrupt(5, count, CHANGE);
  attachInterrupt(6, count, CHANGE);
} 


void count()
{
  colorCount++;
}


void nextColor()
{
  detachInterrupt(IN);
  colorValues[currentcolor]=colorCount;
  colorCount=0;
  currentcolor=(currentcolor+1)%4;
  switch (currentcolor) {
  case RED:
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    break;
  case GREEN:
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    break;
  case BLUE:
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    break;
  case WHITE:
    digitalWrite(S2,HIGH);
    digitalWrite(S3,LOW);
    break;
  }
  attachInterrupt(IN, count, CHANGE);
}

void loop() 
{
  delay(100);
  
  colorValues[RED]=MAX(colorValues[RED]-OFFSET,0);
  colorValues[GREEN]=MAX(colorValues[GREEN]-OFFSET,0);
  colorValues[BLUE]=MAX(colorValues[BLUE]-OFFSET,0);
  colorValues[WHITE]=MAX(colorValues[WHITE]-3*OFFSET,0);
  
  float red=((float)colorValues[RED]/(float)colorValues[WHITE])*255.;
  float blue=((float)colorValues[BLUE]/(float)colorValues[WHITE])*255.;
  float green=((float)colorValues[GREEN]/(float)colorValues[WHITE])*255.;
  
  float M = MAX(MAX(red,green),blue);  
  float m = MIN(MIN(red,green),blue);
  float T;
  float L;
  if(M==red) {
    //Serial.println("r");
    T=60.+(green-blue)/(M-m);
  } else if (M==green){
    //Serial.println("g");
    T=120.+(blue-red)/(M-m);    
  } else if (M==blue){
    //Serial.println("b");
    T=240.+(red-green)/(M-m);    
  }
  
  L=MIN(255,255.*(float)colorValues[WHITE]/3000.);
  
  //DUMP_VAR(colorValues[RED]);
  //DUMP_VAR(colorValues[GREEN]);
  //DUMP_VAR(colorValues[BLUE]);
  //DUMP_VAR(colorValues[WHITE]);
  //DUMP_VAR(red);
  //DUMP_VAR(green);
  //DUMP_VAR(blue);
  //DUMP_VAR(T);
  //DUMP_VAR(L);
  
  if(L<10)
  {
    Serial.println("NOIR");
  } else if (L>190){
    Serial.println("BLANC");
  } else {
    if (T>100) {
      Serial.println("VERT");
    } else {
      if (L>40) {
        Serial.println("JAUNE");
      }else{
        Serial.println("ROUGE");
      }
    }
  }
  
  
  
  Serial.println("");
}




