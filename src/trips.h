/*
    File that contains all the distance between
    destinations. It takes the trip destination 
    and assumes the current airport is in Newark, NJ.
    It will return the distance and duration of the flight 
    as well as if there are any stops involved 

    Author: Konstantinos Drosos
    Date Created: 8/27/2023
    Latest Update: 8/27/2023

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LOS_ANGELES 2785
#define LONDON 3465
#define PARIS 3631
#define HONG_KONG 8042
#define TOKYO 6733
#define SYDNEY 9920
#define ROME 4285
#define ZURICH 3933
#define RIO_DE_JANEIRO 4824
#define MIAMI 1274
#define NEW_DELHI 7294
#define SEATTLE 2842
#define DC 217

#define AVG_PLANE_SPEED 525

extern char *dest[] = {"LOS_ANGELES", "LONDON", "PARIS", "HONG_KONG", "TOKYO", "SYDNEY", "ROME", "ZURICH", "RIO_DE_JANEIRO", "MIAMI",
"NEW_DEHLI", "SEATTLE", "DC"};

extern int miles[] = {2785, 3465, 3631, 8042, 6733, 9920, 4285, 3933, 4824, 1274, 7294, 2842, 217};