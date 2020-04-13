/***************************************************************************************************
File: Event.h
Author : <Jeni Robbie>
Description: header file for Event class declaration
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/


#pragma once
#include <string>
#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;


class Event
{
	
private:
	
	string eventName;
	Queue<Customer> waitingList; // Instance of queue object
public:
	
	Event(); // Constructor
	Event(string); // Constructor

	// Gets the name of the Event
	string getName();



	// Return number of items in event waiting list
	int numItemsInQ();
	
	
	// Returns the first person in the waiting list
	void firstInLine();

	// Add person to back of waiting list
	void addToQueue(Customer temp);

	// Remove person from front of waiting list
	void removeFromQueue();

	// Remove all people from waiting list and rename
	void emptyWaitList();

	// Search waiting list for a person with a specific surname
	void searchQueue();

};

