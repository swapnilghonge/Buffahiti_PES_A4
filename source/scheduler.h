/**
 * @file: scheduler.h
 *
 * @author: Swapnil Ghonge
 * @date: February 22th 2022
  *@tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 *			 Took help from Ishaan for debugging my code
 *
 */

#ifndef scheduler_H_
#define scheduler_H_

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
#include "color_change.h"

/*
 * Commenting done after suggestions by Ishaan
 */


/*
 * Defining the #defines values
 */
#define STOP_RED 		(0x61)
#define STOP_GREEN 		(0x1E)
#define STOP_BLUE 		(0x3C)

#define GO_RED 			(0x22)
#define GO_GREEN 		(0x96)
#define GO_BLUE 		(0x22)

#define WARN_RED 		(0xFF)
#define WARN_GREEN 		(0xB2)
#define WARN_BLUE 		(0x00)

#define CROSS_RED 		(0x00)
#define CROSS_GREEN 	(0x10)
#define CROSS_BLUE 		(0x30)

#define DELAY_TRANS  	(100)
#define DELAY_CROSS  	(1000)

#define DELAY_CROSS_ON 	(75)
#define DELAY_CROSS_OFF (100)

#ifdef DEBUG
#define DELAY_STATE 	(500)
#define DELAY_WARNING 	(300)
#else
#define DELAY_STATE 	(2000)	//20sec stay in STOP and GO state in PRODUCTION mode
#define DELAY_WARNING 	(500)	//5sec stay in WARNING state in PRODUCTION mode
#endif

/*
 * Commenting done after suggestions by Ishaan
 */
typedef enum
{
	STOP,
	STOP_GO_TRANS,
	GO,
	GO_WARNING_TRANS,
	WARNING,
	WARNING_STOP_TRANS,
	CROSSWALK_TRANS,
	CROSSWALK,
	CROSSWALK_GO_TRANS
}state_e;

/********************************
 * @brief: This function definition of the function of state machine
 * @input: NULL
 * @ouptput: NULL
 ********************************/
void Statemachine(void);




#endif /* SCHEDULER_H_ */
