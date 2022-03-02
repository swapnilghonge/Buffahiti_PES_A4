/*
 * color_change.c
 *
 *  Created on: Mar 1, 2022
 *      Author: SWAPNIL
 */

#include "color_change.h"

extern int start_red;
extern int end_red;
extern int start_green;
extern int end_green;
extern int start_blue;
extern int end_blue;
/*
 * Commenting done after suggestions by Ishaan
 */


int r1,g1,b1;

int time =0;
/********************************
 * @brief: This function controls the LEd color upon interrupt
 * @input: 3 parameters r, g, b
 * @ouptput: NULL
 ********************************/
void led_rgb(unsigned int r,unsigned int g, unsigned int b)
{
	int red=(r*48000)/255;
	int green=(g*48000)/255;
	int blue=(b*48000)/255;

	TPM2->CONTROLS[0].CnV=red;
	TPM2->CONTROLS[1].CnV=green;
	TPM0->CONTROLS[1].CnV=blue;
}

/********************************
 * @brief: This function stores the value of Color
 * @input: NULL
 * @ouptput: NULL
 ********************************/



void color_change(void)
{
	time=Get_Timer();
	r1=((end_red-start_red)*0.01*time)+start_red;
	g1=((end_green-start_green)*0.01*time)+start_green;
	b1=((end_blue-start_blue)*0.01*time)+start_blue;
	led_rgb(r1,g1,b1);
}



