/*
 * @file: scheduler.c
 *
 * @author: Swapnil Ghonge
 * @date: February 25th 2022
 *
  *@tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Arm Cortex-M based Microcontrollers by Alexander G.Dean
 *			 Took help from Ishaan for debugging my code
 *
 */


#include <scheduler.h>

int start_red;
int end_red;
int start_green;
int end_green;
int start_blue;
int end_blue;

volatile state_e state=STOP;

/*
 * Commenting done after suggestions by Ishaan
 */

/********************************
 * @brief: This function definition of the function of state machine
 * @input: NULL
 * @ouptput: NULL
 ********************************/


void Statemachine(void)
{
	state_e prev_state=state; //setting the initial state to be previous state

	while(1)
	{
		if(Touch_Detect() && state!=CROSSWALK && state!=CROSSWALK_TRANS) // When the touch sensor is detected
		{

			state=CROSSWALK_TRANS; // the state changes to CROSSWALK
		}

		if(state != prev_state)
		{

			prev_state=state;
			Reset_Timer(); //Reset the timer if not in CROSSWALK state
		}

		switch(state)
		{
		case STOP:
			if(Get_Timer()>DELAY_STATE) // change the state time elapsed is greater then 500msec
			{
				state=STOP_GO_TRANS;
				LOG("Transition from STOP to STOP_GO_TRANS state: Time = %d msec\n\r", Now()*10);
			}
			// value to be assigned #611E3C
			start_red=STOP_RED;// assign the value of macro STOP_red  to start red which
			start_green=STOP_GREEN; // assign the value of macro STOP_green  to start green
			start_blue=STOP_BLUE;// assign the value of macro STOP_blue  to start

			led_rgb(STOP_RED,STOP_GREEN,STOP_BLUE);
			break;

		case STOP_GO_TRANS:
			if(Get_Timer()>DELAY_TRANS)  // change the state if the timer is greater then 100ms
			{
				state=GO;
				LOG("Transition from STOP_GO_TRANS to GO state: Time = %d msec\n\r", Now()*10);
			}
			//the end value for red is #22
			start_red=STOP_RED;
			end_red=GO_RED;
			//the end value for green is #96
			start_green=STOP_GREEN;
			end_green=GO_GREEN;

			//the end value for green is #22
			start_blue=STOP_BLUE;
			end_blue=GO_BLUE;

			color_change(); // actuates the transition of LED
			break;

		case GO:
			if(Get_Timer()>DELAY_STATE) // change the state if the timer is greater then 500ms
			{
				state=GO_WARNING_TRANS;
				LOG("Transition from GO to GO_WARNING_TRANSITION state: Time = %d msec\n\r", Now()*10);
			}
			// for the go state the value to be //#229622
			start_red=GO_RED; // now the new start value for red is 22
			start_green=GO_GREEN; //now the new value to green is 96
			start_blue=GO_BLUE; //new value for blue is 22

			led_rgb(GO_RED,GO_GREEN,GO_BLUE); // change the color of the LED
			break;

		case GO_WARNING_TRANS:
			if(Get_Timer()>DELAY_TRANS) // change the state only after waiting for 100ms
			{
				state=WARNING;
				LOG("Transition from GO_WARNING_TRANSITION TO WARNING state: Time = %d msec\n\r", Now()*10);
			}
			//the end value for red is #FF
			start_red=GO_RED;
			end_red=WARN_RED;
			//the end value for green is #B2
			start_green=GO_GREEN;
			end_green=WARN_GREEN;
			//the end value for red is #00
			start_blue=GO_BLUE;
			end_blue=WARN_BLUE;

			color_change(); // actuates the color change
			break;

		case WARNING:
			if(Get_Timer()>DELAY_WARNING) // wait for 300ms
			{
				state=WARNING_STOP_TRANS;
				LOG("Transition from WARNING TO WARNING_STOP_TRANS state: Time = %d msec\n\r", Now()*10);
			}
			start_red=WARN_RED; // new start value in warning state for red is FF
			start_green=WARN_GREEN; // new start value in warning state for green is B2
			start_blue=WARN_BLUE; // new start value in warning state for blue is 00

			led_rgb(WARN_RED,WARN_GREEN,WARN_BLUE);
			break;

		case WARNING_STOP_TRANS:
			if(Get_Timer()>DELAY_TRANS) // wait for 100ms
			{
				state=STOP;
			}
			// the end value for red is #61
			start_red=WARN_RED;
			end_red=STOP_RED;
			// the end value for green is #1E
			start_green=WARN_GREEN;
			end_green=STOP_GREEN;
			// the end value for blue is #3C
			start_blue=WARN_BLUE;
			end_blue=STOP_BLUE;

			color_change();
			break;

		case CROSSWALK_TRANS:
			if(Get_Timer()>DELAY_TRANS) // wait for 100ms
			{
				state=CROSSWALK;
				LOG("Transition from CROSSWALK TRANSITION TO CROSSWALK state: Time = %d msec\n\r", Now()*10);
				Reset_Counter();
			}
			//the value to red, green blue in cross walk state is #001030
			end_red=CROSS_RED;
			end_green=CROSS_GREEN;
			end_blue=CROSS_BLUE;

			color_change();
			break;

		case CROSSWALK:
			if(Get_Timer()>DELAY_CROSS) // wait for 1000ms
			{
				state=CROSSWALK_GO_TRANS;
				LOG("Transition from CROSSWALK TRANSITION TO CROSSWALK GO TRANS state: Time = %d msec\n\r", Now()*10);
			}
			if(Get_Counter()<=DELAY_CROSS_ON) // if the value of the timer is less then 750 ms
			{
				led_rgb(CROSS_RED,CROSS_GREEN,CROSS_BLUE); // the value to led be #001030
			}
			else if(Get_Counter()>DELAY_CROSS_ON && Get_Counter()<=DELAY_CROSS_OFF) // if the value of timer is greater then  250ms and less then 750ms
			{
				led_rgb(0,0,0);// All LED off
			}
			else
				Reset_Counter();
			break;

		case CROSSWALK_GO_TRANS:
			if(Get_Timer()>DELAY_TRANS) // wait for 100ms
			{
				state=GO;
				LOG("Transition from CROSSWALK GO TRANS TO GO STATE state: Time = %d msec\n\r", Now()*10);
			}
			start_red=CROSS_RED; // change the value #00
			end_red=GO_RED; // change the value #22
			start_green=CROSS_GREEN; // change the value #10
			end_green=GO_GREEN; // change the value #96
			start_blue=CROSS_BLUE; // change the value #30
			end_blue=GO_BLUE; // change the value #22

			color_change();
			break;
		}
	}
}


