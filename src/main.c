#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"functionality.h"
#include"model.h"
#include"trips.h"


int main(int argc, char *argv[]){

	
	// Methods and variables that will be used from the 
	// program 
	
	void readUserInput(char *inputValue);
	void printContent(char *data);	
	char userInput[80];    // Store users input
	void readSingleLine(char *inputValue);
	int commandEvaluation(char *inputValue);
	int code;
	void addPlane(struct Plane planeData);
	void searchPlane(int planeID);
	struct Plane collectPlaneData;
	bool running = true;
	struct FlightDetails collectFlightDetails;
	void addFlightID(struct FlightDetails flight);
	void createCircle();
	void calculateFlightDuration(char *destination);

	printf("International XYZ Airport\n");
	
	/* The purpose of this section is to read users input 
	 * and execute command.
	 */

	while (running){

		printf("Please give me the next command: ");
		readSingleLine(userInput);
		code = commandEvaluation(userInput);

		switch (code){
			case 1:
				struct Plane inputPlane = collectPlaneData;
				addPlane(inputPlane);
				break;
			case 2:
				int plane_id;
				printf("Give me the plane id you want me to search: ");
				scanf("%i", &plane_id);
				searchPlane(plane_id);
				break;
			case 3:
				running = false;
				break;
			case 4: 
				printAllIDs();
				break;
			case 5:
				struct FlightDetails flight = collectFlightDetails;
				addFlightID(flight);
				break;
			case 6:
				printf("Please provide destination: ");
				char inputValue[80];
				readSingleLine(inputValue);
				calculateFlightDuration(inputValue);
				break;
			default:
				printf("You didn't give a valid command\n");
				break;
		}
	}	

	return 0;

}


void calculateFlightDuration(char *destination){
	// Calculates the time it takes to travel
	// to the destination assuming the plane left 
	// from Newark airport.

	int num_elements = 0;
	char *start_ptr = destination;

	while (*destination != '\0'){
		num_elements++;
		destination++;
	}
	num_elements++;

	char *array = (char *) malloc(num_elements * sizeof(char));

	char letter;
	int i; 
	for (i=0; i < num_elements; i++){
		letter = toupper(start_ptr[i]);
		array[i] = letter;
	}
	i++;
	array[i] = '\0';
	
	for (int j = 0; j < 13; j++){
		if (strcmp(dest[j], array) == 0){
			float time_to_dest = miles[j] / (float) AVG_PLANE_SPEED;
			printf("The time to destination is: %.2f hours.\n", time_to_dest);
		}
	}

}