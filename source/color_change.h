/*
 * color_change.h
 *
 *  Created on: Mar 1, 2022
 *      Author: SWAPNIL
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
