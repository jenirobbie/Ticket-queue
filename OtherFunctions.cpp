/***************************************************************************************************
File: OtherFunctions.cpp
Author : <Jeni Robbie>
Description: function definitions for functions out with class scope
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/
#include "OtherFunctions.h"


// Gets the number of the event the user would like to edit
int getMenuOption( int maxNum, int minNum) {
    string menuChoice; //Take in as string for specific validation tests
    int menuInt;  //User menu option as integer
    bool valid=false;
    bool isInteger;

        do {
        cout << "Please enter valid menu option (1 to "<< maxNum <<")." << endl; 
        cin >> menuChoice;

        //Check if option added is a individual integer character
        isInteger = integerValidation(menuChoice); 
        if (isInteger == false)
        {
            cout << "Invalid option." << endl;
            continue;
        }
        

        menuInt = stoi(menuChoice);     //Need to return event number to integer for using to index events array or for case statement
        valid = isBetweenRange(menuInt, maxNum, minNum);

        if (valid == false)
            cout << "Invalid option." << endl;
    } while (valid == false || isInteger==false);

    return menuInt;    //Returns minus 1 to align with array index
}


// Validates that all characters in string are integers
bool integerValidation(string input) {
   
    for (int i = 0; i < input.length();i++)
    {
   
        if (!isdigit(input[i]))        //Checks if character is not a digit and returns false
            return false;
    }
    return true;    //if all character in string are digit, return true.
    
}
// Validates integer value is between specified min and max values
bool isBetweenRange(int userInput, const int maxNum, const int minNum )
{
    //If beyond range return false
    if (userInput > maxNum || userInput <= minNum)
    {
        return false;
    }
    else
        return true;    //if in range of max and minimum parameters return true
}

// Displays sub-menu options
void displaySubMenu(Event thisEvent[], int num)
{
    //Show event selected
    cout << "Editing event: " << thisEvent[num].getName() << endl;

    //Event option Menu
    cout << "Please select waitinglist option number" << endl;
    cout << "1. Add Person to queue" << endl;
    cout << "2. Remove person from queue" << endl;
    cout << "3. Search Queue Position" << endl;
    cout << "4.Reset Waiting list" << endl;
    cout << "5. Return to Main Menu " << endl << endl;

}




// Getcustomer credentials and begins the add customer to a waiting list process
void addToWaitingList(Event e[], int num)
{
    bool isValid = false;
    string surname;
    string number;
    do {
        
        cout << "Please enter surname " << endl;
        cin >> surname;
        isValid = alphabetValidation(surname);      //validates that all characters in string are alphabetical
        //tolower(surname);
    } while (isValid == false);   
        
    do {
        //Get customer phone number
        cout << "Please enter 11 digit phone number" << endl;
        cin >> number;

        isValid = integerValidation(number);
        if (isValid == false)
        {
            cout << "Invalid charcters entered." << endl;
            continue;
        }

        isValid = stringLengthValid(number, 11);

        //validate length and characters
    } while (isValid == false);

    
        Customer* person;       //Create person pointer to dynamically allocated memory only when customer needs to be added.
        person = new Customer(surname, number);
        e[num].addToQueue(*person); //calls event add to queue function to add validated customer credentials

}

// Displays a list of all current events and the number of people in each waiting list
void displayEventMenu(int numOfEvents, Event thisEvent[]) {
   


    //Instructions
    cout << " Please select an event waiting list to edit by entering the corresponding option number. " << endl;
    //Event Menu Display
    for (int i = 0;i < numOfEvents; i++)
    {
        cout << (i + 1) << ". " << thisEvent[i].getName() << "      Number of people waiting: " << thisEvent[i].numItemsInQ() << endl;  //Loops through until all events in array are printed
    }
    cout << (numOfEvents + 1) << ". Exit" << endl;

}



//Validates string length is exact length
bool stringLengthValid(string pNum, int target) {
    if (pNum.length() != target)
    {
        cout << "Incorrect length." << endl;
        return false;
    }
    else
        return true;

}

//Validates that only alphabetical characters are entered
bool alphabetValidation(string userInput)
{
    for (int i = 0; i < userInput.length(); i++)        //Loops through string length
    {
        
        if (!isalpha(userInput[i]))                         //If not a alphabet character, loop stops prematurely, false is returned
        {
            cout << "Invalid Input. Non alphabetical chracacter entered." << endl;
            return false;
        }
    }
    return true;
}