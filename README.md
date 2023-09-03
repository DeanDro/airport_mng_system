# airport_mng_system
An airport management system build in C. The project utilizes the standard C library, along with stdlib.h, string.h, stdbool.h. The purpose of this project is to learn and practice on the basic capabilities of C. 

## Structure
The project utilizes 3 header files to manage storing and retrieving information from binary files that hold the data for our database localy. 

## main.c
The purpose of this file is to bring together all functionality from header files functionality.h, trips.h and model.h. This is the main process that will read user's input and will call the correct function from the other files. 

## functionality.h
This header file's primary purpose is to collect and evaluate users input. The primary function used here is the commandEvaluation and the readSingleLine that collects one line of input from the user and returns an integer that corresponds to a different functionality called in the main.c file. 

## model.h 
The database for this project is controlled and managerd through the model.h file. Within the header file we define structures Terminals, Planes and Gates. Functions inside the header file are responsible for collecting user's input, create a database binary file if it is not available or update an existing one with the information provided by the user. There is also functionality available to search through the database for a particular input and to modify an existing registration. 

## Libraries 
The libraries used in this project are: 
* stdio.h
* string.h
* stdbool.h
* stdlib.h
