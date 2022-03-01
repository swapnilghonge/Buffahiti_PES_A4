/*
 * @file: Buffahiti_Traffic_Light.c
 * @brief:This file calls all the functions that are needed to run the Traffic Light System
 *
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo
 * and KL25Z Reference Manual.
 */

#include <scheduler.h>
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
#include "color_change.h"

int main(void)
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

	Init_Systick();
	Touch_Init();
	Init_Pwm();
	color_change();
	Statemachine();

    return 0 ;
}
