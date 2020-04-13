/***************************************************************************************************
File: Event.h
Author : <Jeni Robbie>
Description: header file for other functions out with present classes scope.
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/

#pragma once
#include "Event.h"
using namespace std;

// Validates integer value is between specified min and max values
bool isBetweenRange(int, const int, const int);

// Displays sub-menu options
void displaySubMenu(Event [], int);

// Adds a customer to a waiting list
void addToWaitingList(Event e[], int num);

// Displays a list of all current events and the number of people in each waiting list
void displayEventMenu(int, Event[]);


// Gets the number of the event the user would like to edit
int getMenuOption( int, int);


// Validates that all characters in string are integers
bool integerValidation(string);

//Validates string length is exactly target size
bool stringLengthValid(string, int); 


bool intStringValidation(string);

//Validates that only alphabetical characters are entered
bool alphabetValidation(string);

