/*  The purpose of this file is to work as the model part 
 *  of the application that will manage the data and interaction
 *  with the database
 *  Created: 8-21-2023
 *  Last updated: 8-22-2023
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
	ptr = fopen("airplane.bin", "r");
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
	} else {
		printf("Plane with ID number %d wasn't found.\n", planeID);
	}

}

void readString(char *array){
	// Gets user input and stores it in an array
	
	char character = getchar();
	int i = 0;

	while (character != '\n'){
		array[i] = character;
		i++;
		character = getchar();
	}

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
	scanf("%i\n", &temp);
	result.plane_id = temp;

	printf("Number of passengers: ");
	scanf("%i\n", &temp);
	result.passangersNumber = temp;

	char companyName[80];
	printf("Name of Company: ");
	readString(companyName);
	printf("\n");
	
	printf("Flight Number (give 0 if you don't have fligth number at this point): ");
	scanf("%i\n", &temp);
	result.flight_id = temp;

	return result;

}

