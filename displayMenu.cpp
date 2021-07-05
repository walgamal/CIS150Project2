#include "PlaneAndSeats.h"			//includes header file

/*

Purpose: Function displays menu options for the user to select from.
		 Function then intakes user choice as a string and passes it
		 to function validateUserInt for validation. Then, function 
		 passes this string to a switch statement that calls 
		 appropiate method or function based on valid user selection.
Author: Wasim Algamal
Creation Date:
Last Modification Date:

*/

void displayMenu(plane& airplane) {			//function passes through specific object to apply methods to 
	string userChoice;						//user choice is declared as a string

	static int reservedSeats = 0;			//reservedSeats is declared as a static so it may not be 
											//redeclared while counting seats

	cout << "------------------------ Menu ----------------------------" << endl << endl <<			//menu display
		"1. Display Seat Chart" << endl <<
		"2. Reserve Seat" << endl <<
		"3. Cancel Reservation" << endl <<
		"4. Save Seat Chart to File" << endl <<
		"5. Statistics" << endl <<
		"6. Help" << endl <<
		"7. Quit" << endl <<
		"-----------------------------------------------------------" << endl << endl <<
		"Please Enter Your Choice(1 - 7): ";														//prompts user for input

	cin >> userChoice;																				//user inputs string here

	switch (validateUserInt(userChoice)) {															//string is validated and turned into int *See validateUserInt.cpp
	case 1:																							//switch case determines what to run based on user selection
		airplane.displaySeatChart();				//calls method "displaySeatChart" for passed through object
		system("pause");
		cout << endl;
		displayMenu(airplane);						//returns user to the menu (used throughout the switch case)
		break;
	case 2:
		airplane.reserveSeat(reservedSeats);		//calls method "reserveSeat" for passed through object
		system("pause");
		cout << endl;
		displayMenu(airplane);
		break;
	case 3:
		airplane.cancelSeat(reservedSeats);			//calls method "cancelSeat" for passed through object
		system("pause");
		cout << endl;
		displayMenu(airplane);
		break;
	case 4:
		airplane.saveChartFile();					//calls method "saveChartFile" for passed through object
		system("pause");
		cout << endl;
		displayMenu(airplane);
		break;
	case 5:
		airplane.stats(reservedSeats);				//calls method "stats" for passed through object
		system("pause");
		cout << endl;
		displayMenu(airplane);
		break;
	case 6:
		help();										//calls function "help"
		system("pause");
		cout << endl;
		displayMenu(airplane);						
		break;
	case 7:
		cout << endl << "-Thank You for Choosing W.A. Airlines! Have a great day!-" << endl <<
			"----------------------- Goodbye -------------------------" << endl << endl;
		system("pause");
		return;
		break;
	default:										//default case, just in case comething goes terribly wrong ;)
		cout << "ERROR: INVALID INPUT!!" << endl;
		system("pause");
		cout << endl;
		displayMenu(airplane);
	}
}