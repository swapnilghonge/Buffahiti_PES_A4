/**
 * @file: touch_sensor.h
 * @brief: This file contains 3 functions Touch_Init(), Touch_Scan_Lh() and Touch_Detect()
 *
 *	@author: Swapnil Ghonge
 * @date: February 25th 2022
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 * @Link: https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense/TSI/src
 *
 */

#ifndef TOUCH_SENSOR_H_
#define TOUCH_SENSOR_H_

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

/**********************************************
 *
 * @brief: this function sets the clock of the touch sensor and port to initialize
 *
 * @param: NULL
 * @return:  NULL
 ***********************************************/
void Touch_Init(void);
/***********************************************
 * @brief: function return the value of change in capcitance  when we touch the sensor
 * It has a offset of 550 to avoid anamolous results
 * @param: NULL
 * @return: difference of scan value and offset
 *
 ************************************************/
int Touch_Scan_Lh(void);

/************************************************
 * @brief: This function returns 1 when value the value is greater then 640
 * @param: NULL
 * @return: 1 when the touch value>640 else returns 0
 *
 ****************************************************/
int Touch_Detect(void);

#endif /* TOUCH_SENSOR_H_ */
