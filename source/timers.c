/*
 * @file: timers.c
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 */

#include <scheduler.h>
#include <stdio.h>
#include <stdio.h>
#include <timers.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "pin_mux.h"
#include "log.h"
#include "pwm.h"
#include "touch_sensor.h"
#include "core_cm0plus.h"

static volatile ticktime_t counter=0; // static variable to keep track counter
static volatile ticktime_t reset=0;	// static variable to reset the time
static volatile ticktime_t timer=0; // static variable to keep track timer count

/*
 * Commenting done after suggestions by Ishaan
 */

/********************************************
 * @brief: initializes the Systick timer
 * @input: NULL
 * @output: Null
 *
 *********************************************/
void Init_Systick()
{
	SysTick->LOAD = (48000000/16)/100; 	//10msecx48Mhz/16
	NVIC_SetPriority(SysTick_IRQn,1);  	//interrupt priority is set to 1
	SysTick->VAL=0;					   	//force load of reload value
	SysTick->CTRL=SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;	//enable interrupt and systick timer with alternative clock source
}

/*********************************************
 *@brief: This function initializes the interrupt in the  Systick timer
 *@input: NULL
 *@output: NULL
 *********************************************/
void SysTick_Handler()
{
	timer++;
	counter++;
}

ticktime_t Now()
{
	return timer;
}

/***********************************************
 *@brief: this function resets the timer
 *@input: NULL
 *@output: NULL
 ***********************************************/
void Reset_Timer()
{
	reset=Now();
}

ticktime_t Get_Timer()
{
	return (timer-reset);
}

/***********************************************
 *@brief: This function reset the counter of the counter
 *@input: NULL
 *@output: NULL
 *
 ***********************************************/

void Reset_Counter()
{
	counter=0;
}

ticktime_t Get_Counter()
{
	return counter;
}
