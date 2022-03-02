/**
 * @file: touch_sensor.c
 * @brief: This file contains 3 functions Touch_Init(), Touch_Scan_Lh() and Touch_Detect(void)
 *
 *	@author: Swapnil Ghonge
 * @date: February 25th 2022
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 * @Link: https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense/TSI/src
 *
 */
#include "touch_sensor.h"

/*
 * Commenting done after suggestions by Ishaan
 */
uint32_t touch_val;

/******************************************************************
 * @brief: this function sets the clock of the touch sensor and port to initialize
 *
 * @param: NULL
 * @return:  NULL
 *******************************************************************/

void Touch_Init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK;		//setting the clock for TSI
	TSI0->GENCS = TSI_GENCS_MODE(0u) | 		//operating in non-noise mode
			TSI_GENCS_REFCHRG(0u) | 		//reference oscillator charge and discharge value 500nA
			TSI_GENCS_DVOLT(0u) | 			//oscillator voltage rails set to default
			TSI_GENCS_EXTCHRG(0u) | 		//electrode oscillator charge and discharge value 500nA
			TSI_GENCS_PS(0u) | 				//frequency clock divided by one
			TSI_GENCS_NSCN (31u) | 			//scanning the electrode 32 times
			TSI_GENCS_TSIEN_MASK | 			//enabling the TSI module
			TSI_GENCS_EOSF_MASK; 			//writing one to clear the end of scan flag
}

/*************************************************************
 * @brief: function return the value of change in capcitance  when we touch the sensor
 * @param: NULL
 * @return: difference of scan value and offset
 *
 ***************************************************************/

int Touch_Scan_Lh(void)
{
	unsigned int scan=0; 							//initializing the value of scan as '0'
	TSI0->DATA = TSI_DATA_TSICH(10u); 				//selecting channel 10
	TSI0->DATA |= TSI_DATA_SWTS_MASK; 				//software trigger to start the scan
	while(!(TSI0->GENCS & TSI_GENCS_EOSF_MASK)); 	//waiting for the scan to complete 32 times
	scan = TSI0->DATA & 0xFFFF; 					//macro for extracting the count from data register
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK; 			//writing one to clear the end of the flag
	return scan;
}
/**********************************************************
 * @brief: This function returns 1 when value the value is greater then 640
 * @param: NULL
 * @return: 1 when the touch value>640 else returns 0
 *
 ***********************************************************/
int Touch_Detect(void)
{
	touch_val=0;
	touch_val=Touch_Scan_Lh(); // putting touch value in  touch_val
	if(touch_val>640)
	{
		return 1;				// returns 1 when touch value is greater then 640
	}
	return 0;					// return 0 in every other case
}
