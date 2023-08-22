/*  The purpose of this file is to work as the model part 
 *  of the application that will manage the data and interaction
 *  with the database
 *  Created: 8-21-2023
 *  Last updated: 8-21-2023
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct plane {
	int plane_id;
	int passangersNumber;
	char company[];
	int flight_id;
};

struct flightDetails{
	int flight_id;
	char date[];
	char destination[];
	char departureTime[];
	char arrivalTime[];
	int gate_id;
	int numberPassangers;
};

struct gate{
	int gate_id;
	int terminal_id;
};

struct terminal{
	int terminal_id;
	int listGates[];
	int numberGates;
	int parkingCarVolume;
	int freeParkingSpots;
};




