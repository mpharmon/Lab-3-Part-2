/*  
 *  Class: ECE372a
 * 
 *  Group: 209
 *
 *  Lab: 3 Part 1
 * 
 *  File: main.c
 * 
 *  Member: Michael Harmon (Software)
 *          Abdul Rana (Hardware)
 *          James Beulke (System Integration)
 *          Ali Hassan (Quality Control)
 */
#include <xc.h>
#include "config.h"
#include "interrupt.h"
#include "../LCD.X/lcd.h"
#include "ADC.h"
#include "PWM.h"

void main(void){
  SYSTEMConfigPerformance(10000000);
  //enableInterrupts();
  LCD_Init();
  ADC_Init();
  PWM_Init();
  char string[16];
  while(1){
    sprintf(string,"Voltage: %4.2fVdc",(ADC1BUF0/1023.0*3.3));
    LCD_PrintString(string);
    LCD_MoveCursor(1,1);
    PWM_SetBackward();
    PWM_SetOC1DutyCycle(25);
    PWM_SetOC2DutyCycle(75);
  };
}