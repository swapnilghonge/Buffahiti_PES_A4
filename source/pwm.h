/**
 * @file: pwm.h
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
  *@tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 *			 Took help from Ishaan for debugging my code
 *
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


/*
 * Commenting done after suggestions by Ishaan
 */


/********************************
 * @brief: This function initialize the PWM of Timer/PWM module
 * @input: NULL
 * @ouptput: NULL
 ********************************/
void Init_Pwm(void);

#endif /* PWM_H_ */
