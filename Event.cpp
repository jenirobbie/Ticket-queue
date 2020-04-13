/***************************************************************************************************
File: Event.cpp
Author : <Jeni Robbie>
Description: function finitions for the event class
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/

#include "Event.h"
#include "QueueTemplate.h"

//Constructors
Event::Event() {
	eventName = "unknown";
	waitingList;
}
Event::Event(string inputName) {
	eventName = inputName;
}
//Getters
string Event::getName()
{
	return eventName;
}
int Event::numItemsInQ()
{
	return waitingList.numOfItems();
}


// Add person to back of waiting list
void Event::addToQueue(Customer temp) {

	bool hasSpace = waitingList.Add(temp);		//Past int customer obeject to add to queue


	// If we fail to add person to waiting list, return error message
	if (hasSpace == false)
	{
		cout << "Error waitinglist is already full" << endl;
	}
	else {
		Customer newest;
		newest = waitingList.getNewElement();							//If successful return name of newest customer added to queue
		cout << newest.getSurname() << ": was successfully added to event waiting list" << endl;
		cout << "There are now " << waitingList.numOfItems() << " person(s) in the waiting list" << endl << endl;

	}
}

// Search waiting list for a person with a specific surname
void Event::searchQueue() {

	Queue<Customer>* listCopy;
	listCopy = new Queue<Customer>(waitingList); // Use a copy constructor to make an identical queue
	Customer temp;	//create customer object to hold queue object details
	

	bool found= false;
	string inputSurname;

	cout << "Please enter surname of customer to search waiting list: " << endl;
	cin >> inputSurname;

	int count = 1;	//count starts at 1 as although index is 0 position in queue is incremented by 1;

	// Remove items from copy queue until the person is found or the queue is empty
	while (listCopy->Empty() == false)
	{
		//listCopy->getEndElement(x);
		if (inputSurname == temp.getSurname())				
		{
			cout << "Position in queue is: " << count << endl;
			found = true;
			break;												//Exits loop prematurely if customer found
		}	
		else
		{
			listCopy->Remove(temp);				//Remove another customber object from queue if not found at current index
			count++;			//Increase found position number as loops through queue
		}
		

	}

	if (found==false)
			cout << "Customer not  found in waiting list." << endl; 



}


// Remove person from front of waiting list
void Event::removeFromQueue() {
	bool notEmpty;

	// Retrieve the person at the front of the queue in order to print message
	Customer first= waitingList.getEndElement();
	
	//Attempt to remove person from queue using queue remove function and return conformation
	notEmpty=waitingList.Remove(first);

	// If queue is empty, print appropriate message
	if (notEmpty == false)
	{
		cout << "Invalid option, queue is empty." << endl;
	}
	else
	{
	
		cout << "Name: " << first.getSurname() << " Number: "<< first.getPhoneNum() <<" was sucessfully Removed." << endl;
	}
}

// Returns the first person in the waiting list
void Event::firstInLine(){
	Customer first =waitingList.getEndElement();			//gets first element in waiting list and stores temporarily in customer variable.
	cout << "Surname: " << first.getSurname() << '\t'<< "Phone Number:" << first.getPhoneNum() << endl;
}

// Remove all people from waiting list and rename
void Event::emptyWaitList() {

	waitingList.resetQueue();	//Call queue object function to clear the queue
	string name;	
	cout << "Please enter new Event name." << endl;
	cin >> name;
	eventName = name;	//Set new event name
	
}