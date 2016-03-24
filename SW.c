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

void SW_init(){
  TRISxbits.TRISxy = 1; // Set Tristate Register to Input
  CNPUxbits.CNPUxy = 1; // Enable Pull UP Resistor
  IFS1bits.CNxIF = 0;   // Turn Down Interrupt Flag
  IEC1bits.CNxIE = 1;   // Enable Interrupt
  IPC8bits.CNIP = 7;    // Set Interrupt Priority
}
#endif