/**
 * @file: pwm.h
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo
 * and KL25Z Reference Manual.
 */

#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>
#include <stdio.h>
#include <timers.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "pin_mux.h"

#define RED_LED_PIN 	(18)
#define GREEN_LED_PIN 	(19)
#define BLUE_LED_PIN 	(1)

void Init_Pwm(void);

#endif /* PWM_H_ */
