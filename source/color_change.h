/**
 * @file: color_change.h
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
  *@tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 *			 Took help from Ishaan for debugging my code
 *
 */
#ifndef COLOR_CHANGE_H_
#define COLOR_CHANGE_H_

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


/*
 * Commenting done after suggestions by Ishaan
 */


/********************************
 * @brief: This function stores the value of Color
 * @input: NULL
 * @ouptput: NULL
 ********************************/
void color_change();
/********************************
 * @brief: This function controls the LEd color upon interrupt
 * @input: 3 parameters r, g, b
 * @ouptput: NULL
 ********************************/
void led_rgb(unsigned int r, unsigned int g, unsigned int b);
#endif /* COLOR_CHANGE_H_ */
