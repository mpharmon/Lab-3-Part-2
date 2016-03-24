/*  
 *  Class: ECE372a
 * 
 *  Group: 209
 *
 *  Lab: 1 Part 3
 * 
 *  File: ADC.c
 * 
 *  Member: Michael Harmon (Software)
 *          Abdul Rana (Hardware)
 *          James Beulke (System Integration)
 *          Ali Hassan (Quality Control)
 */

#include "ADC.h"

void ADC_Init(){
  AD1CON1bits.FORM = 0;   // Unsigned Integer Output
  AD1CON1bits.SSRC = 7;   // Auto Converstion
  AD1CON1bits.ASAM = 1;   // Enable Auto Sample
  AD1CON2bits.VCFG = 0;   // Voltage Refrence (Vdd & Vss)
  AD1CON2bits.CSCNA = 0;  // Do Not Scan Inputs
  AD1CON2bits.SMPI = 15;  //Interrupt after 16 Sample and Converts
  AD1CON2bits.BUFM = 0;   // Use a Single 16 Byte Buffer
  AD1CON2bits.ALTS = 0;   // Only Use Mux A
  AD1CON3bits.ADRC = 0;   // Clock Derived From Peripheral Bus
  AD1CON3bits.SAMC = 1;   // Sample Every ADC Clock Cycle
  AD1CON3bits.ADCS = 0;   // ADC Clock Set (2 * Peripheral Bus Clock)
  AD1CHSbits.CH0NA = 0;   // Negative as V_REFL
  AD1CHSbits.CH0SA = 0;   // Positive Input as AN1
  AD1CON1bits.ON = 1;     // Turn ADC On
}