#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"functionality.h"
#include"model.h"
#include"trips.h"
#include<windows.h>

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
	struct Plane collectPlaneData();
	bool running = true;
	struct FlightDetails collectFlightDetails;
	void addFlightID(struct FlightDetails flight);
	void createCircle();
	void calculateFlightDuration(char *destination);
	struct Terminal collectTerminalDetails();
	void storeTerminalDetails(struct Terminal details);
	void printAirportStatus();
	void printCommandSelection();
	void populateDatabaseMetrics();
	void readFileContent(char *fileStream);

	printCommandSelection();
	populateDatabaseMetrics();
	/* The purpose of this section is to read users input 
	 * and execute command.
	 */


	while (running){

		printf("Please give a command (help for a list of command options): ");
		readSingleLine(userInput);
		code = commandEvaluation(userInput);

		switch (code){
			case 1:
				struct Plane inputPlane = collectPlaneData();
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
			case 7:
				struct Terminal newTerm = collectTerminalDetails();
				storeTerminalDetails(newTerm);
				break;
			case 8:
				char terminal_id[10];
				printf("What is the terminal you want to modify? ");
				readSingleLine(terminal_id);
				manageTerminal(terminal_id);
				break;
			case 9:
				char terminal_num[10];
				printf("Which terminal are you looking for? ");
				readSingleLine(terminal_num);
				printTerminalDetails(terminal_num);
				break;
			case 10:
				printAirportStatus();
				break;
			case 11:
				printCommandSelection();
				break;
			case 12:
				if (argc > 1){
					readFileContent(argv[1]);
				} else {
					printf("You haven't provided an additional file\n");
					
				}
				break;
			default:
				printf("You didn't give a valid command\n");
				printCommandSelection();
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

void printAirportStatus(){
	//Helper method that prints overall airport status after every change 
	//from the user. 

	//TODO: Need to develop method that shows airport status
	printf("\n");
	printf("########################################################################\n\n");
	printf("                          XYZ International Airport                     \n\n");
	printf("########################################################################\n\n");
	printf("Number of Airplanes Landed: %i\n", INDEX);
	printf("Number of Fligths Scheduled: %i\n", FLIGHT_INDEX);
	printf("\n");

}

void printCommandSelection(){
	// Prints the list of command options 
	printf("########################################################################################################\n\n");
	printf("                                      International Airport XYZ\n\n");
	printf("#########################################################################################################\n\n");
	printf("1. add plane: To add a new plane in database     2. search plane: To search plane by flight id\n");
	printf("3. print all ids: To return all flight ids       4. add flight: To add a new flight in the database\n");
	printf("5. flight time: To find duration of a flight     6. add terminal: To add a new terminal in the database\n");
	printf("7. modify terminal: To change terminal details   8. terminal details: To get details for all terminals\n");
	printf("9: quit: To terminate the program               10. airport view: Returns an overview of the airport\n");
	printf("#########################################################################################################\n\n");
}

bool credentialCheckIn(char *username, char *password){
	// Helper method that checks user credentials. If the user
	//doesn't provide correct info it will not be granted access. Returns a bool
	// and takes as argument two char pointers for username and password.

	//TODO
}

void readFileContent(char * fileInput){
	// Method that reads a file location passed as an argument and prints its content

	FILE *ptr; 
	char character;
	ptr = fopen(fileInput, "r");
	if (ptr == NULL ){
		printf("System couldn't open the file\n");
		exit(1);
	}

	char * content = (char *) malloc(80 * sizeof(char));
	character = fgetc(ptr);
	do {
		printf("%c", character);
		character = fgetc(ptr);
	} while (character != '\0' && !feof(ptr));
	printf("\nThat was the end of the file\n");
	fclose(ptr);
}