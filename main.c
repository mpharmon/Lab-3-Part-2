/*  
 *  Class: ECE372a
 * 
 *  Group: 209
 *
 *  Lab: 3 Part 2
 * 
 *  File: main.c
 * 
 *  Member: Michael Harmon (Software)
 *          Abdul Rana (Hardware)
 *          James Beulke (System Integration)
 *          Ali Hassan (Quality Control)
 */
#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "interrupt.h"
#include "../delay.X/delay.h"
#include "../LCD.X/lcd.h"
#include "ADC.h"
#include "PWM.h"
#include "SW.h"

typedef enum STATEenum{
  FORWARD,
  FORWARD_IDLE,
  BACKWARD,
  BACKWARD_IDLE,
}STATE;

volatile STATE state = BACKWARD_IDLE;

void main(void){
  SYSTEMConfigPerformance(10000000);
  enableInterrupts();
  LCD_Init();
  ADC_Init();
  PWM_Init();
  SW_Init();
  char string[16];
  LCD_MoveCursor(1,1);
  while(1){
    LCD_MoveCursor(1,1);
    sprintf(string,"Voltage: %4.2fVdc",(ADC1BUF0/1023.0*3.3));
    LCD_PrintString(string);
    //LCD_MoveCursor(1,2);
    switch(state){
      case FORWARD:
        PWM_SetForward();
        if(ADC1BUF0 < 512){
          PWM_SetOC1DutyCycle(floor(200 * ADC1BUF0 / 1023.0));
          PWM_SetOC2DutyCycle(100);
          //sprintf(string,"OC: %5d.%5d",OC1RS,OC2RS);
          //LCD_PrintString(string);
        }else if(ADC1BUF0 > 512){
          PWM_SetOC1DutyCycle(100);
          PWM_SetOC2DutyCycle(floor(100.0 * (2.0 - (ADC1BUF0 / 512.0))));
          //sprintf(string,"OC: %5d.%5d",OC1RS,OC2RS);
          //LCD_PrintString(string);
        }else{
          PWM_SetOC1DutyCycle(100);
          PWM_SetOC2DutyCycle(100);
        };
        //LCD_PrintString("Mode: FORWARD   ");
        break;
      case FORWARD_IDLE:
        PWM_SetOC1DutyCycle(0);
        PWM_SetOC2DutyCycle(0);
        //LCD_PrintString("Mode: FORWARD_ID");
        break;
      case BACKWARD:
        PWM_SetBackward();
        if(ADC1BUF0 < 512){
          PWM_SetOC1DutyCycle(floor(200 * ADC1BUF0 / 1023));
          PWM_SetOC2DutyCycle(100);
          //sprintf(string,"OC: %5d.%5d",OC1RS,OC2RS);
          //LCD_PrintString(string);
        }else if(ADC1BUF0 > 512){
          PWM_SetOC1DutyCycle(100);
          PWM_SetOC2DutyCycle(floor(100.0 * (2.0 - (ADC1BUF0 / 512.0))));
          //sprintf(string,"OC: %5d.%5d",OC1RS,OC2RS);
          //LCD_PrintString(string);
        }else{
          PWM_SetOC1DutyCycle(100);
          PWM_SetOC2DutyCycle(100);
        };
        //LCD_PrintString("Mode: BACKWARD  ");
        break;
     case BACKWARD_IDLE:
        PWM_SetOC1DutyCycle(0);
        PWM_SetOC2DutyCycle(0);
        //LCD_MoveCursor(1,2);
        //LCD_PrintString("Mode: BACKWARD_I");
        break;
    };
  };
};

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt(void){
  PORTD;
  IFS1bits.CNDIF = 0; // Put Flag Down
  if(PORTDbits.RD2 == 1){
    if(state == BACKWARD_IDLE)state = FORWARD;
    else if(state == FORWARD)state = FORWARD_IDLE;
    else if(state == FORWARD_IDLE)state = BACKWARD;
    else if(state == BACKWARD)state = BACKWARD_IDLE;
  };
};