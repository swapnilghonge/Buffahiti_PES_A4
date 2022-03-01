/*
 * @file: scheduler.c
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo, the code
 * and KL25Z Reference Manual.
 */


#include <scheduler.h>

int start_red;
int end_red;
int start_green;
int end_green;
int start_blue;
int end_blue;

volatile state_e state=STOP;

void Statemachine(void)
{
	state_e prev_state=state;

	while(1)
	{
		if(Touch_Detect() && state!=CROSSWALK && state!=CROSSWALK_TRANS)
		{

			state=CROSSWALK_TRANS;
		}

		if(state != prev_state)
		{

			prev_state=state;
			Reset_Timer();
		}

		switch(state)
		{
		case STOP:
			if(Get_Timer()>DELAY_STATE)
			{
				state=STOP_GO_TRANS;
			}
			start_red=STOP_RED;
			start_green=STOP_GREEN;
			start_blue=STOP_BLUE;

			led_rgb(STOP_RED,STOP_GREEN,STOP_BLUE);
			break;

		case STOP_GO_TRANS:
			if(Get_Timer()>DELAY_TRANS)
			{
				state=GO;
			}
			start_red=STOP_RED;
			end_red=GO_RED;
			start_green=STOP_GREEN;
			end_green=GO_GREEN;
			start_blue=STOP_BLUE;
			end_blue=GO_BLUE;

			color_change();
			break;

		case GO:
			if(Get_Timer()>DELAY_STATE)
			{
				state=GO_WARNING_TRANS;
			}
			start_red=GO_RED;
			start_green=GO_GREEN;
			start_blue=GO_BLUE;

			led_rgb(GO_RED,GO_GREEN,GO_BLUE);
			break;

		case GO_WARNING_TRANS:
			if(Get_Timer()>DELAY_TRANS)
			{
				state=WARNING;
			}
			start_red=GO_RED;
			end_red=WARN_RED;
			start_green=GO_GREEN;
			end_green=WARN_GREEN;
			start_blue=GO_BLUE;
			end_blue=WARN_BLUE;

			color_change();
			break;

		case WARNING:
			if(Get_Timer()>DELAY_WARNING)
			{
				state=WARNING_STOP_TRANS;
			}
			start_red=WARN_RED;
			start_green=WARN_GREEN;
			start_blue=WARN_BLUE;

			led_rgb(WARN_RED,WARN_GREEN,WARN_BLUE);
			break;

		case WARNING_STOP_TRANS:
			if(Get_Timer()>DELAY_TRANS)
			{
				state=STOP;
			}
			start_red=WARN_RED;
			end_red=STOP_RED;
			start_green=WARN_GREEN;
			end_green=STOP_GREEN;
			start_blue=WARN_BLUE;
			end_blue=STOP_BLUE;

			color_change();
			break;

		case CROSSWALK_TRANS:
			if(Get_Timer()>DELAY_TRANS)
			{
				state=CROSSWALK;
				Reset_Counter();
			}
			end_red=CROSS_RED;
			end_green=CROSS_GREEN;
			end_blue=CROSS_BLUE;

			color_change();
			break;

		case CROSSWALK:
			if(Get_Timer()>DELAY_CROSS)
			{
				state=CROSSWALK_GO_TRANS;
			}
			if(Get_Counter()<=DELAY_CROSS_ON)
			{
				led_rgb(CROSS_RED,CROSS_GREEN,CROSS_BLUE);
			}
			else if(Get_Counter()>DELAY_CROSS_ON && Get_Counter()<=DELAY_CROSS_OFF)
			{
				led_rgb(0,0,0);
			}
			else
				Reset_Counter();
			break;

		case CROSSWALK_GO_TRANS:
			if(Get_Timer()>DELAY_TRANS)
			{
				state=GO;
			}
			start_red=CROSS_RED;
			end_red=GO_RED;
			start_green=CROSS_GREEN;
			end_green=GO_GREEN;
			start_blue=CROSS_BLUE;
			end_blue=GO_BLUE;

			color_change();
			break;
		}
	}
}


