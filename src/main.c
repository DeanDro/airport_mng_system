#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"functionality.h"

int main(int argc, char *argv[]){


	void readUserInput(char *inputValue);
	void printContent(char *data);
	char userInput[80];    // Store users input
	void readSingleLine(char *inputValue);
	int commandEvaluation(char *inputValue);

	printf("International XYZ Airport\n");
	printf("Please provide command:\n");
	
	/* The purpose of this section is to read users input 
	 * and execute command.
	 */

	readSingleLine(userInput);
	commandEvaluation(userInput);
		

	return 0;
}
