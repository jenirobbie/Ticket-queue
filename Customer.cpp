/***************************************************************************************************
File: Customer.cpp
Author : <Jeni Robbie>
Description: function finitions for customer class
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/

#include "Customer.h"

//Constructors
Customer::Customer() {
	surname = "Unknown";


}
Customer::Customer(string name, string num) {
	surname = name;
    phoneNum = num;

}

//Getters
string Customer::getSurname()
{
	return surname;
}



string Customer::getPhoneNum()
{
	return phoneNum;
}

//Setters
void Customer::setPhoneNum(string pNum) {
	phoneNum = pNum;
}

void Customer::setSurname(string name) {
	surname = name;

}