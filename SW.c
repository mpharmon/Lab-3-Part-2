/*  
 *  Class: ECE372a
 * 
 *  Group: 209
 *
 *  Lab: 3 Part 2
 * 
 *  File: SW.c
 * 
 *  Member: Michael Harmon (Software)
 *          Abdul Rana (Hardware)
 *          James Beulke (System Integration)
 *          Ali Hassan (Quality Control)
 */
#include "SW.h"
#ifndef SW_H_
#define SW_H_

void SW_Init(){
  ANSELDbits.ANSD2 = 0; // Disable Analog
  TRISDbits.TRISD2 = 1; // Set Tristate Register to Input
  CNPUDbits.CNPUD2 = 1; // Enable Pull UP Resistor
  CNCONDbits.ON = 1;    // Enable Change Notify on Port
  CNENDbits.CNIED2 = 1; // Enable Change Notify on Pin
  IFS1bits.CNDIF = 0;   // Turn Down Interrupt Flag
  IEC1bits.CNDIE = 1;   // Enable Interrupt
  IPC8bits.CNIP = 7;    // Set Interrupt Priority
}
#endif