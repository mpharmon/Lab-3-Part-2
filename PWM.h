/*  
 *  Class: ECE372a
 * 
 *  Group: 209
 *
 *  Lab: 3 Part 2
 * 
 *  File: PWM.h
 * 
 *  Member: Michael Harmon (Software)
 *          Abdul Rana (Hardware)
 *          James Beulke (System Integration)
 *          Ali Hassan (Quality Control)
 */

#include <xc.h>
#include <math.h>

// Define Registers for Motor 1, A Input
#define MOTOR1A_TRIS    TRISDbits.TRISD0
#define MOTOR1A_ODC     ODCDbits.ODCD0
#define MOTOR1A_LAT     LATDbits.LATD0
#define MOTOR1A_RP      RPD0Rbits.RPD0R
//#define MOTOR2B_ANSEL 


// Define Registers for Motor 2, A Input
#define MOTOR2A_TRIS    TRISDbits.TRISD1
#define MOTOR2A_ODC     ODCDbits.ODCD1
#define MOTOR2A_LAT     LATDbits.LATD1
#define MOTOR2A_RP      RPD1Rbits.RPD1R
#define MOTOR2A_ANSEL   ANSELDbits.ANSD1


// Define Registers for Motor 2, B Input
#define MOTOR2B_TRIS    TRISDbits.TRISD5
#define MOTOR2B_ODC     ODCDbits.ODCD5
#define MOTOR2B_LAT     LATDbits.LATD5
#define MOTOR2B_RP      RPD5Rbits.RPD5R
//#define MOTOR2B_ANSEL 


// Define Registers for Motor 1, BInput
#define MOTOR1B_TRIS    TRISDbits.TRISD8
#define MOTOR1B_ODC     ODCDbits.ODCD8
#define MOTOR1B_LAT     LATDbits.LATD8
#define MOTOR1B_RP      RPD8Rbits.RPD8R
//#define MOTOR1B_ANSEL 

// Define OC1/OC2 Peripheral Select
#define OC1_OUTPUT 0b1100
#define OC2_OUTPUT 0b1011

// Define Tristate Output
#define TRIS_OUTPUT 0

// Define ODC Statuses
#define ODC_ENABLE 1
#define ODC_DISABLE 0

// Define Latch Statuses
#define LAT_ENABLE 1
#define LAT_DISABLE 0

// Initializes the PWM (Defaults to Forward with 0% Duty Cycle)
void PWM_Init();

// Changes the Duty Cycle for OC1 (takes 0-100.0)
void PWM_SetOC1DutyCycle(float newDutyCycle);

// Changes the Duty Cycle for OC2 (takes 0-100.0)
void PWM_SetOC2DutyCycle(float newDutyCycle);

// Remaps Motor Connections to Move the Motor Forward
void PWM_SetForward();

// Remaps Motor Connections to Move the Motor Backward
void PWM_SetBackward();