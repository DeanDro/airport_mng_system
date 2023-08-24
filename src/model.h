/*  The purpose of this file is to work as the model part 
 *  of the application that will manage the data and interaction
 *  with the database
 *  Author: Konstantinos Drosos
 *  Created: 8-21-2023
 *  Last updated: 8-23-2023
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
	int terminal_id;
	int listGates[100];
	int numberGates;
	int parkingCarVolume;
	int freeParkingSpots;
} Terminal;

int EXISTING_PLANE_IDS[100];
int INDEX = 0;

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
				temp.company = NULL;
				temp.passangersNumber = 0;
				temp.flight_id = 0;
				EXISTING_PLANE_IDS[loc] = 0;

			}
		}
	}
}


