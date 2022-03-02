/**
 * @file: timers.h
 * @brief: consists of 6 functions for configuring
 * and using the Systick Timer
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
*
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 *			Took help from Ishaan for debugging my code
 *
 */

#include <stdio.h>
#include<stdint.h>

#ifndef TIMERS_H_
#define TIMERS_H_
/*
 * Commenting done after suggestions by Ishaan
 */
typedef uint32_t ticktime_t;

/********************************************
 * @brief: initializes the Systick timer
 * @input: NULL
 * @output: Null
 *
 *********************************************/

void Init_Systick();

/*********************************************
 *@brief: This functrion initializes the interrupt in the  Systick timer
 *@@input: NULL
 *@@output: NULL
 *********************************************/

void SysTick_Handler();


ticktime_t Now();

/***********************************************
 *@brief: this function resets the timer
 *@input: NULL
 *@output: NULL
 ***********************************************/
void Reset_Timer();


ticktime_t Get_Timer();

/***********************************************
 *@brief: This function reset the counter of the counter
 *@input: NULL
 *@output: NULL
 *
 ***********************************************/
void Reset_Counter();


ticktime_t Get_Counter();

#endif /* TIMERS_H_ */
