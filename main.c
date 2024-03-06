/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Shorouk Shawky
 */


/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Shorouk Shawky
 */


#include <stdio.h>
#include <stdlib.h>


#define AC_ON 1
#define AC_OFF 0

#define EngineTempController_ON 1
#define EngineTempController_OFF 0

#define EngineState_ON 1
#define EngineState_OFF 0

char c;
char MenuOption;
char TrafficLightOption;
int EngineState=EngineState_OFF;
int RoomTemperature=35;
int EngineTemperature=90;
int speed=0;
int AC_state=AC_OFF;
int Engine_control_state=EngineTempController_OFF;


void GetUserOption(char option);
void GetMainOption(char MainOption);
void DisplayCurrentVehicle_state(int Engine_state, int AC_STATE, int VehicleSpeed, int roomTemp,int EngineCTRL_State ,int EngineTemp);

void TrafficLight(void){
	printf ("Choose A character:  \n");
	printf("G. For Green the traffic light \n");
	printf("O. For Orange the traffic light \n");
	printf("R. For Red the traffic light \n");
}
void RoomTemperatureData(void){
	printf ("Please Enter Temperature reading: \n");
}

void EngineTemperatureData(void){
	printf ("Please Enter Engine Temperature reading: \n");
}


void AskUser(void){
	printf ("Please choose what you want to do \n ");
	printf("a. Turn on the vehicle engine \n");
	printf("b. Turn off the vehicle engine \n");
	printf("c. Quit the system \n");
}

void SensorsSetMenu(void){
	printf ("Sensors set menu:  \n ");
	printf("a. Turn off the engine \n");
	printf("b. Set the traffic light color \n");
	printf("c. Set the room temperature \n");
	printf("d. Set the engine temperature \n");
}

void GetMainOption(char MainOption){
	char c= MainOption;
	switch(c){
		case 'c':
			printf(" the system state: Quit \n");
	        _Exit(0);
	        break;

		case 'b':
			AskUser();
			scanf(" %c", &c);
			GetMainOption(c);
			break;


		case 'a':
			EngineState=EngineState_ON;
			SensorsSetMenu();
			scanf(" %c", &MenuOption);
			GetUserOption(MenuOption);
			break;
		}

}

void GetUserOption(char option){
	char o = option;
	switch(o){
		case 'a':
		EngineState=EngineState_OFF;
		printf(" the system state: the vehicle engine turned off \n");
		AskUser();
		scanf(" %c", &o);
		GetMainOption(o);
		DisplayCurrentVehicle_state(EngineState,AC_state,speed,RoomTemperature,Engine_control_state,EngineTemperature);
        break;

		case 'b':
		TrafficLight();
		scanf(" %c", &TrafficLightOption);
		if (TrafficLightOption=='G'){
			speed=100;
			printf("The vehicle speed set to 100 km/hr \n");}
		else if (TrafficLightOption=='O'){
			speed=30;
			printf("The vehicle speed set to 30 km/hr \n");}
		else if (TrafficLightOption=='R'){
			speed=0;
			printf("The vehicle speed set to 0 km/hr \n");}

		if (speed ==30){
			if(AC_state== AC_OFF){
				AC_state= AC_ON;
				RoomTemperature=(RoomTemperature*(5/4))+1;
			}
			if(Engine_control_state==EngineTempController_OFF){
				Engine_control_state=EngineTempController_ON;
				EngineTemperature=(EngineTemperature*(5/4))+1;
			}
		}
		DisplayCurrentVehicle_state(EngineState,AC_state,speed,RoomTemperature,Engine_control_state,EngineTemperature);
		break;

		case 'c':
		RoomTemperatureData();
		scanf("%d",&RoomTemperature);
		if (RoomTemperature<10){
			printf(" AC turned on \n");
			AC_state=AC_ON;
			RoomTemperature=20;
		}
		else if(RoomTemperature>30){
			printf(" AC turned on \n");
			AC_state=AC_ON;
			RoomTemperature=20;
		}
		else {
			printf(" AC turned off \n");
			AC_state=AC_OFF;
		}

		DisplayCurrentVehicle_state(EngineState,AC_state,speed,RoomTemperature,Engine_control_state,EngineTemperature);
		break;

		case 'd':
		EngineTemperatureData();
		scanf("%d",&EngineTemperature);
		if (EngineTemperature<100){
			printf("Engine Temperature Controller turned on \n");
			Engine_control_state=EngineTempController_ON;
			EngineTemperature=125;
		}
		else if(EngineTemperature>150){
			printf("Engine Temperature Controller turned on \n");
			Engine_control_state=EngineTempController_ON;
			EngineTemperature=125;
		}
		else {
			printf(" Engine Temperature Controller turned off \n");
			Engine_control_state=EngineTempController_OFF;
		}
		DisplayCurrentVehicle_state(EngineState,AC_state,speed,RoomTemperature,Engine_control_state,EngineTemperature);
}
}



void DisplayCurrentVehicle_state(int Engine_state, int AC_STATE, int VehicleSpeed, int roomTemp,int EngineCTRL_State ,int EngineTemp){
	printf ("Engine State is %d \n",Engine_state);
	printf("AC State is %d  \n",AC_STATE);
	printf("Vehicle Speed is %d Km/Hr \n",VehicleSpeed);
	printf("Room Temperature is %d C \n",roomTemp );
	printf("Engine Temperature Controller State is %d \n",EngineCTRL_State );
	printf("Engine Temperature is %d C \n",EngineTemp );

	SensorsSetMenu();
	scanf(" %c", &c);
	GetUserOption(c);
}
int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	AskUser();
	scanf(" %c", &c);
	GetMainOption(c);








	}
