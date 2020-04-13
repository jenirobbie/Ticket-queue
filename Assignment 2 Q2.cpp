
/**
****************************************************************************************************
File: Assignment 2 Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
Author : <Jeni Robbie>
Assignment 1- Question 2
Program description:
Program Objective: Allow staff to edit event waiting list information. Staff navigate via main menu and sub menus. 
The main menu has 3 options- 1. print event list and the number of people waiting in that queue, 2. maintain event waiting list and 3. exit. 
The sub menu then asks the user to select an event (numbered 1 through 10) to edit. 
The sub menu allows further options- to add person to selected waiting list, remove person from the waiting list, search the waiting list, reset and rename event and finally return to main menu.

Date Created : 09 / 02 / 20
Last Modified 14/ 02 / 20
* ***************************************************************************************************
*/

#include <string>
#include <iostream>
#include "Event.h"
#include "Customer.h"
#include "OtherFunctions.h"
using namespace std;


int main()
{
	int menuChoice2 = 0, eventNum = 0;
	string exitChoice = "0";
	bool exit = false, returnToMainMenu = false; // Used for menu navigation
	bool isValid = true;
	const int exitNum = 3, printListNum = 1, maintainListNum = 2; // Constant menu choices so changing in future is flexible
	const int numOfEvents = 10;
	
	//instansiate events
	Event musicEvents[numOfEvents]{ Event("Metallica Concert"),Event("Royal Republic Concert"),Event("Iron Maiden Concert"),Event("Prodigy Concert"),Event("Clutch Concert"),Event("Ghost Concert"),Event("Pendulum Concert"),Event("Skindred Concert"),Event("ACDC Concert"),Event("Cake Concert") };

	//Instructions
	cout << "Event WaitingList Maintenance Program" << endl << endl;



	while (exit == false)
	{
		//Event Menu Display
		displayEventMenu(numOfEvents, musicEvents);



		//Get and Validate Option
		eventNum = (getMenuOption((numOfEvents + 1), 0) - 1);


		if ((eventNum + 1) == (numOfEvents + 1))
		{
			exit = true;
			continue;
		}

		//Display sub menu
		displaySubMenu(musicEvents, eventNum);
		do {
			isValid = true;
			//Get and Validate Option
			menuChoice2 = getMenuOption(5, 0);
			returnToMainMenu = false;
			switch (menuChoice2)
			{
			case 1: //Add person to event queue

				addToWaitingList(musicEvents, eventNum);

				continue;
			case 2: //Remove person from Queue
				musicEvents[eventNum].removeFromQueue();
				break;
			case 3: //Search for person by surname in queue
				musicEvents[eventNum].searchQueue();
				break;
			case 4:
				//Reset the waiting list queue and change the event name
				musicEvents[eventNum].emptyWaitList();
				break;
			case 5: //Go back to main menu
				returnToMainMenu = true;
				break;

			default:    //All other inputs			Note: May not need default as I test input validation as option entered
				cout << "Invalid option. Please re-enter menu option" << endl;
				isValid = false;
				break;

			}

		} while (isValid == false);	//Loop until menu option is valid

		if (returnToMainMenu == true) {
			continue;
		}
	

			//Other return options from case proccess 1-4
			cout << "Return to main menu? Enter 0 to return or anything else to exit" << endl;
			cin >> exitChoice;
			if (exitChoice == "0")
			{
				continue;
			}
			else
			{
				exit = true;
				continue;
			}
		
	}
}
