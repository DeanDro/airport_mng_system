
/*  The purpose of this file is to provide functionality
 *  functions for the main program.
 *	Author: Konstantinos Drosos
 *  Created on August, 20th 2023 
 *  Last updated: 8/29/2023
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


void readUserInput(char *inputValue){
	// Method to read and store user input 
	// in an argument array
	
	char character = getchar();
	int i = 0;
	bool reading = true;
	bool lineChange = false;

	while (reading){
		if (character == '\n'){
			if (!lineChange){
				lineChange = true;
			} else {
				break;
			}
		} else {
			lineChange = false;
		}
		
		inputValue[i] = character;
		i++;
		character = getchar();
	
	}
	
	inputValue[i] = '\0';
}


void printContent(char *data){
	// Helper method that reads the data from 
	// an array and prints result on the 
	// command interface
	

	while (*data != '\0'){
		printf("%c",*data);
		data++;
	}
}

void readSingleLine(char *inputValue){
	// Read a command but stop when 
	// user adds a new line
	
	int i = 0;
	char character = getchar();

	while (character != '\n'){

		inputValue[i] = character;
		i++;
		character = getchar();
	}
	
	inputValue[i] = '\0';
}

int commandEvaluation(char *inputValue){
	// The purpose of this method is to take an argument string and 
	// return a number based on the command given so the program can 
	// execute 
	
	if (strcmp("add plane", inputValue) == 0){
		return 1;
	} else if (strcmp("search plane", inputValue) == 0){
		return 2;
	} else if (strcmp("quit", inputValue) == 0){
		return 3;
	} else if (strcmp("print all ids", inputValue) == 0){
		return 4;
	} else if (strcmp("add flight", inputValue) == 0){
		return 5;
	} else if (strcmp("flight time", inputValue) == 0){
		return 6;
	} else if (strcmp("add terminal", inputValue) == 0){
		return 7;
	} else if (strcmp("modify terminal", inputValue) == 0){
		return 8;
	} else if (strcmp("terminal details", inputValue) == 0){
		return 9;
	} else if (strcmp("airport view", inputValue) == 0){
		return 10;
	} else if (strcmp("help", inputValue) == 0){
		return 11;
	} else if (strcmp("read data", inputValue) == 0){
		return 12;
	}
	return 0;
}

