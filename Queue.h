/***************************************************************************************************
File: Queue.h
Author : <Jeni Robbie>
Description: header file for template queue class declaration
Date Created: 09/02/20
Last Modified: 14/02/20

Reference: main structure taken from John Lawerence Advanced Programming techniques lecture notes.

/***************************************************************************************************/
#pragma once



template <class Type>

class Queue
{

private:
	Type* Contents;
	int Queue_size;
	int Front, Back;

public:
	Queue(); // Constructor
	~Queue(); // Deconstructor
	//Copy constructor
	Queue(const Queue*);




	// Returns the element at the front of the queue
	Type getEndElement();

	// Get the last element added to the queue
	Type getNewElement();

	// Check if queue is empty
	bool Empty() const;

	// Check if queue is full
	bool Full() const;

	// Remove front element from queue
	bool Remove(Type& front_element);

	// Add element to back of queue
	bool Add(const Type& new_element);

	// Return number of elements in queue
	int numOfItems();

	// Resets array index to empty queue
	void resetQueue();
	
};


