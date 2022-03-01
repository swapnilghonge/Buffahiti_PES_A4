/**
 * @file: touch_sensor.h
 * @brief: consists of three functions
 * namely Touch_Init(), Touch_Scan_Lh()
 * and Touch_Detect(void);
 *
 *	@author: Swapnil Ghonge
 * @date: February 25th 2022
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and GitHub repo
 * @Link: https://github.com/alexander-g-dean/ESF/tree/
 * master/NXP/Misc/Touch%20Sense/TSI/src
 */

#ifndef TOUCH_H_
#define TOUCH_H_

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


void Touch_Init(void);


int Touch_Scan_Lh(void);


int Touch_Detect(void);

#endif /* TOUCH_H_ */
