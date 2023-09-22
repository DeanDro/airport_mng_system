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

## Methods

### readString(char *array)
Method takes a pointer to an array structure of char elements and stores the user input in the given array. The user needs to ensure that the array that the pointer points to has enought space to store all elements plus the null element. 

### addPlane(struct Plane inputData)
Method takes as argument a Plane structure that has already been populated with user's input and stores it in a binary file named airplanes.bin. If the file doesn't exist the method will create it otherwise it will update the existing file. 

### searchPlane(int planeID)
Takes as argument an integer with the plane ID you want to search for. It will return all details of the plane with the given ID. If the method can't find a plane with the given ID in the airplanes.bin file, it will return a message that the plane wasn't found. 

### collectPlaneData()
Method that retunrs a Plane structure with the details of an airplane for the database. This is a method that is used before the **addPlane()** method to collect the information for the plane from the user that later on will be given as an argument to addPlane().

### printAllIDs()
Helper method that prints all plane ids currently stored in airplanes.bin. 

### deletePlaneData(int planeID)
It takes an integer as an argument with the ID with the planee you want to delete from the database and it removes all information for the matching id from the airplanes.bin file. If the airplane ID doesn't exist in the databse it will return a notification. 

### collectFlightDetails()
Method takes no arguments and is used to collect user inputs for a flight. It will return a structure Flight with the details of the fligth which can be used from **addFlightID** method to store the flight in the flightDetails.bin file. 

### addFlightID(struct FlightDetails flight)
Takes as argument a FlightDetails structure and stores it in the flightDetails.bin file. If the file doesn't exist it will create it otherwise will append the existing version.

### addGateDetails()
Method to add the details of a gate to the database. It creates file gates.bin if it doesn't exist or updates an existing file.

### collectTerminalDetails()
Helper method that returns a Terminal struct that will be later passed as an argument to method **storeTerminalDetails** to be stored in file terminals.bin.

### storeTerminalDetails(struct Terminal terminalInfo)
Method that takes as an argument a structure Terminal and stores the infomration into **terminals.bin**. The method creates the file if it doesn't exist, otherwise it will update an existing file.