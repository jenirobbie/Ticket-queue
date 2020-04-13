/***************************************************************************************************
File: QueueTemplate.h
Author : <Jeni Robbie>
Description: header file for template queue class definitions
Date Created: 09/02/20
Last Modified: 14/02/20

Reference: main structure taken from John Lawerence Advanced Programming techniques lecture notes.

/***************************************************************************************************/
#include "Queue.h"



// Constructor
template <class Type>
Queue<Type> ::Queue() {
	Queue_size = 10;
	Contents = new Type[Queue_size + 1];
	Front = 0;
	Back = 0;

}


// Copy Constructor - Takes in existing queue and inintializes a new queue with the same element values
template <class Type>
Queue<Type> ::Queue(const Queue<Type>* original) {
	Queue_size = original.Queue_size;
	Contents = original.Contents;
	for (int s = 0; s < Queue_size; s++)
		Contents[s] = original.Contents[s];

	Front = 0;
	Back = 0;

}

// Destructor
template <class Type>
Queue<Type> :: ~Queue()
{
	delete[] Contents;

}

// Tests

// Check if queue is empty
template <class Type>
bool Queue<Type> ::Empty() const
{
	return (Front == Back) ? true : false;
}

// Check if queue is full
template <class Type>
bool Queue<Type> ::Full() const
{
	return ((1 + Back) % (Queue_size + 1) == Front) ? true : false;	//allows for circular queue
}

// Remove element from front of queue
template <class Type>
bool Queue<Type> ::Remove(Type& front_element)
{
	// Don't remove element if queue is empty
	if (Empty())
		return false;
	else
	{
		front_element = Contents[Front];
		Front = (Front + 1) % (Queue_size + 1);
		return true;
	}
}

// Add element to back of queue
template <class Type>
bool Queue<Type> ::Add(const Type& new_element)
{
	// Don't attempt to add element if queue is full
	if (Full())
		return false;
	else
	{
		Contents[Back] = new_element;
		Back = (Back + 1) % (Queue_size + 1);
		return true;
	}
}

// Return front element from queue
template <class Type>
Type Queue<Type>::getEndElement()
{
	return Contents[Front];

}

// Add element to back of queue
template <class Type>
Type Queue<Type>::getNewElement()
{
	return Contents[Back-1];

}

// Return number of elements in queue
template <class Type>
int Queue<Type>::numOfItems() {
	int size = abs(abs(Queue_size - Front) - abs(Queue_size - Back));	//source stack overflow https://stackoverflow.com/questions/4459141/how-to-find-number-of-elements-in-a-circular-queue
	return size;		
	
}


// Resets array index to empty queue
template <class Type>
void Queue<Type>::resetQueue() {
	Front = 0;
	Back = 0;		//if front==back queue is empty
}
#pragma once
