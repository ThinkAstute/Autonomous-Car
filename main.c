#include <hidef.h>
#include <math.h>
#include "derivative.h"

#pragma CODE_SEG NON_BANKED 

byte sensor;

void main(void) {
  // Set variables for the Pulse Width Modulation (PWM) Signal.
   unsigned int k;
   unsigned int i; 
   unsigned int j;
   PWMCLK = 0x03;
   PWMSCLA = 2;
   PWMPOL = 0x03;
   
   PWMPER0 = 200;
   PWMPER1 = 200;
   
   PWMDTY0 = 143;
   PWMDTY1 = 146;

   CPMUCOP_CR = 0; // disable COP
   DDRA = 0x00;
    

   TFLG2 = 0x80; //Reset TOF.
   TSCR2 = 0x87; //Enable timer interrupt and prescaler.
   TSCR1 = 0x80; //Enable timer.

    for(k = 0; k < 32999; k++){
      sensor = PORTA & 0x03;
      
      switch(sensor){ 
        case 0:        // Both sensors are off.
        PWME = 0x03; // Turn both motors on.
        break;
  
        case 1:       // Right sensor is on.  
        PWME = 0x01;  // Turn right motor on, left motor off.
        break;

        case 2:       // Left sensor is on.
        PWME = 0x02;   //Turn left motor on, right motor off.
        break;      

        case 3:       //Both sensors are on.
        PWME = 0x00; // Turn both motors off.      
        break;
      }
  
      for (i = 0; i < 1300; i++){
      }
          for (j = 0; j < 675; j++){
          }
    }
  
  PWME = 0x00; // Turn both motors off.  

  for(;;){
  }         
}
   /* loop forever */