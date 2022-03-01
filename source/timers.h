/**
 * @file: timers.h
 * @brief: consists of 6 functions for configuring
 * and using the Systick Timer
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo and
 * KL25Z Reference Manual.
 */

#include <stdio.h>
#include<stdint.h>

#ifndef SYSTICK_H_
#define SYSTICK_H_

typedef uint32_t ticktime_t;


void Init_Systick();


void SysTick_Handler();


ticktime_t Now();


void Reset_Timer();


ticktime_t Get_Timer();


void Reset_Counter();


ticktime_t Get_Counter();

#endif /* SYSTICK_H_ */
