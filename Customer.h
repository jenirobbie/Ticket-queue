/***************************************************************************************************
File: Customer.h
Author : <Jeni Robbie>
Description: header file for customer class declaration
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Customer
{
private:
	string surname;
	string phoneNum;
public:
	Customer(); // Constructor	
	Customer(string, string);	// Constructor

	string	getSurname(); // Return Surname
	void setSurname(string);	// Set Surname value

	string getPhoneNum(); // Get Phone number
	void setPhoneNum(string); // Set phone number value



};





