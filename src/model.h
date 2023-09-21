/*  The purpose of this file is to work as the model part 
 *  of the application that will manage the data and interaction
 *  with the database
 *  Author: Konstantinos Drosos
 *  Created: 8-21-2023
 *  Last updated: 8-25-2023
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<Ole2.h>


typedef struct Plane {
	int plane_id;
	int passangersNumber;
	char company[80];
	int flight_id;
} Plane;

typedef struct FlightDetails{
	int flight_id;
	char date[12];
	char destination[80];
	char departureTime[20];
	char arrivalTime[20];
	int gate_id;
	int numberPassangers;
} FlightDetails;

typedef struct Gate{
	int gate_id;
	int terminal_id;
} Gate;

typedef struct Terminal{
	char terminal_num;
	int listGates[100];
	int numberGates;
	int parkingCarVolume;
	int freeParkingSpots;
} Terminal;

int EXISTING_PLANE_IDS[100];
int INDEX = 0;  // Stores the number of airplanes in the database
int FLIGHTS_LIST[100];
int FLIGHT_INDEX = 0; 	// Stores the number of flights currently on schedule


void addPlane(struct Plane inputData){
	// Method to store the data for a plane in the 
	// database. 
	
	FILE *ptr;
	ptr = fopen("airplanes.bin", "a");
	if (ptr == NULL){
		printf("Couldn't open file.\n");
		exit(1);
	}

	fwrite(&inputData, sizeof(struct Plane), 1, ptr);
	fclose(ptr);

}

void searchPlane(int planeID){
	// Method that receives a plane id and 
	// returns the information about the plane
	
	FILE *ptr;
	ptr = fopen("airplanes.bin", "r");
	struct Plane temp;

	if (ptr == NULL){
		printf("File with plane data wasn't found\n");
		exit(1);
	}

	while (!feof(ptr) && temp.plane_id != planeID){
	       
		fread(&temp, sizeof(Plane), 1, ptr);
	}

	if (temp.plane_id == planeID){
		printf("Plane ID: %d\n", temp.plane_id);
		printf("Passangers Capacity: %d\n", temp.passangersNumber);
		printf("Company Name: %s\n", temp.company);
		printf("Scheduled Flight Number: %i\n", temp.flight_id);
	} else {
		printf("Plane with ID number %d wasn't found.\n", planeID);
	}

	fclose(ptr);

}

void readString(char *array){
	// Gets user input and stores it in an array
	
	char character = getchar();
	int i = 0;

	do{
		array[i] = character;
		i++;
		character = getchar();
	} while (character != '\n');

	array[i] = '\0';
}

struct Plane collectPlaneData(){
	// Collects user inputs to store in a 
	// Plane structure and return this structure
	// for the addPlane method to use it
		
	struct Plane result;
	int temp;
	void readString(char *array);
	
	printf("Collecting data\n");
	printf("Plane ID: ");
	scanf("%i", &result.plane_id);

	printf("Number of passengers: ");
	scanf("%i", &result.passangersNumber);

	printf("Name of Company: ");
	readString(result.company);
	
	printf("Flight Number (give 0 if you don't have fligth number at this point): ");
	scanf("%i", &result.flight_id);

	// Once all data have been collected add airoplane ID in array
	EXISTING_PLANE_IDS[INDEX] = result.plane_id;
	INDEX++;
	
	return result;

}

void printAllIDs(){
	// Method to print all ids of airplanes already used
	
	for (int i = 0; i <= INDEX; i++){
		printf("%i\n",EXISTING_PLANE_IDS[i]);
	}
}

void deletePlaneData(int planeID){
	// Method to remove the information for an airplane from the database
	
	struct Plane temp; 
	FILE *ptr;
	ptr = fopen("airplanes.bin", "a");
	if (ptr == NULL){
		printf("Error: File wasn't found\n");
		exit(1);
	}
	
	bool included = false;
	int loc;
	for (int i = 0; i<= INDEX; i++){
		if ( planeID == EXISTING_PLANE_IDS[i]){
			included = true;
			loc = i;
		}
	}

	if (!included) {
		printf("The Plane ID doesn't exist in the database\n");
	} else {
		
		while (!feof(ptr)){
			fread(&temp, sizeof(Plane), 1, ptr);

			if (temp.plane_id == planeID){
				temp.plane_id = 0;
				char newArray[80];
				memcpy(temp.company, newArray, 80);
				temp.passangersNumber = 0;
				temp.flight_id = 0;
				EXISTING_PLANE_IDS[loc] = 0;

			}
		}
	}

	fclose(ptr);

}

struct FlightDetails collectFlightDetails(){
	// Collects all information from user for the 
	// flight details and returns a Flight structure.
	
	struct FlightDetails result;
	void readString(char *array);
	bool validateFlightIdAvailable(int flight_id);

	printf("Provide Flight ID: ");
	scanf("%i", &result.flight_id);
	
	bool unique = validateFlightIdAvailable(result.flight_id);
	
	// Confirm it is a unique flight id
	while (!unique){
		printf("The Flight ID you provided already exists. Please give another number: \n");
		scanf("%i", &result.flight_id);
		unique = validateFlightIdAvailable(result.flight_id);
	}

	printf("Provide departure date: ");
	readString(result.date);

	printf("Provide destination: ");
	readString(result.destination);

	printf("Provide departure time: ");
	readString(result.departureTime);

	printf("Provide arrival time: ");
	readString(result.arrivalTime);

	printf("Departure gate: ");
	scanf("%i", &result.gate_id);

	printf("Number of passengers in the flight: ");
	scanf("%i", &result.numberPassangers);

	// Capture the list of flights 
	FLIGHTS_LIST[FLIGHT_INDEX] = result.flight_id;
	FLIGHT_INDEX++;

	return result;

}

bool validateFlightIdAvailable(int flight_id){
	// Validates the flight ID if it is unique.
	
	bool unique = true; 
	for (int i = 0; i <= FLIGHT_INDEX; i++){
		if (FLIGHTS_LIST[i] == flight_id){
			unique = false;
		}
	}

	return unique; 
}

void addFlightID(struct FlightDetails flight){
	// Adds a new flight details in the database
	
	FILE *ptr; 
	ptr = fopen("flightDetails.bin", "a");
	if (ptr == NULL){
		printf("The database isn't available.\n");
		exit(1);
	}

	fwrite(&flight, sizeof(FlightDetails), 1, ptr);
	fclose(ptr);
}


void addGateDetails(){
	// Adds details for a gate 
	
	struct Gate result;
	printf("Provide the gate number: ");
	scanf("%i", &result.gate_id);

	printf("Provide the terminal id: ");
	scanf("%i", &result.terminal_id);

	FILE *ptr;
	ptr = fopen("gates.bin", "a");
	if (ptr == NULL){
		printf("The gates database wasn't found.\n");
		exit(1);
	}

	fwrite(&result, sizeof(Gate), 1, ptr);
	fclose(ptr);

}

struct Terminal collectTerminalDetails(){
	// Method to collect the information for the creation
	// of a terminal 

	struct Terminal result; 

	printf("Provide the id of the terminal: ");
	scanf("%c", &result.terminal_num);

	int index = 0;
	printf("How many gates does the terminal have: ");
	scanf("%i", &index);

	int array[100];
	for (int i = 1; i <= index; i++){
		array[i-1] = i;
	}
	memcpy(result.listGates, array, 100);

	printf("Provide the number of parking spots available: ");
	scanf("%i", &result.freeParkingSpots);

	printf("Provide the number of cars curently on park: ");
	scanf("%i", &result.parkingCarVolume);

	return result;
	
}

void storeTerminalDetails(struct Terminal terminalInfo){
	// Method to store the information for a terminal to
	// the local file 

	FILE *ptr = fopen("terminals.bin", "a");
	if (ptr == NULL){
		printf("The terminal file couldn't open.\n");
		exit(1);
	}

	fwrite(&terminalInfo, sizeof(Terminal), 1, ptr);
	fclose(ptr);
}

struct Terminal getTerminal(char *terminalID){
	// This method takes as argument a terminal ID
	// and returns back a Terminal structure. If the terminal ID 
	// was found it will return the terminal with the ID.

	FILE *ptr = fopen("terminals.bin", "r");
	if (ptr == NULL){
		printf("The terminal wasn't found.\n");
		exit(1);
	}

	struct Terminal targetTerminal;

	while (!feof(ptr)){
		fread(&targetTerminal, sizeof(Terminal), 1, ptr);
		if (*terminalID == targetTerminal.terminal_num){
			break;
		}
	}

	fclose(ptr);

	// It will return the terminal struct regardless if it is the one we are searching for
	// The evaluation should take place in a later stage.
	return targetTerminal;

}

void manageTerminal(char *terminalID){
	// Method uses the getTerminal method to get the terminal
	// from the database and make any updates. 

	struct Terminal getTerminal(char *terminalID);
	struct Terminal target = getTerminal(terminalID);
	void storeTerminalDetails(struct Terminal targetTerminal);
	void readString(char *array);
	char command[80];

	// check if terminal correct
	if (target.terminal_num == *terminalID){
		printf("What element you want to update?\n");
		printf("#####################   Commands   ###################\n");
		printf("parking: To adjust number of cars parked\n");
		printf("parking size: To adjust the number of available spots\n");
		printf("######################################################\n\n");
		readString(command);

		if (strcmp("parking", command) == 0){
			int numCars = 0;
			printf("What is the change in the number of cars in the parking?");
			scanf("%i", &numCars);

			target.freeParkingSpots = target.parkingCarVolume - numCars;
			storeTerminalDetails(target);
		} else if (strcmp("parking size", command) == 0){
			int parkingSize;
			printf("How the parking capacity has changed?");
			scanf("%i", &parkingSize);

			target.parkingCarVolume += parkingSize;
			storeTerminalDetails(target);
		} else {
			printf("You didn't provide a valid command. Try parking or parking size.\n");
		}

	} else {
		printf("The terminal was not found in the database.\n");
		printf("Please try again.\n");
	}
}

void printTerminalDetails(char *terminalID){
	// Prints all information about the current status
	// of terminal

	struct Terminal targetTerminal = getTerminal(terminalID);
	
	printf("Terminal ID: %c\n", targetTerminal.terminal_num);
	printf("Number of gates in terminal: %i\n", targetTerminal.numberGates);
	printf("Parking size of the terminal: %i\n", targetTerminal.freeParkingSpots);
	printf("Number of free parking spots: %i\n", targetTerminal.freeParkingSpots - targetTerminal.parkingCarVolume);

}