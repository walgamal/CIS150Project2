#include "PlaneAndSeats.h"			//includes header file

/*

Purpose: Function that ensures user inputs a valid selection from the menu
Author: Wasim Algamal
Creation Date:
Last Modification Date:

*/

int validateUserInt(string userChoice) {	//passing through user's choice as a string
	bool leave;								//boolean that determines whether to leave a do-while loop
	int userInteger = 0;

	do {														//do-while loop
		leave = false;
		for (int i = 0; i < userChoice.size(); ++i) {			//tests if user input is made of digits, if not it sets bool leave to "true"
			if ((!isdigit(userChoice[i]))) {
				leave = true;
			}
		}

		userInteger = atoi(userChoice.c_str());					//converts user string of digits to actual integer	

		if (userInteger > 7 || userInteger < 1) {				//tests if user input is between 1 & 7, if not it sets bool leave to "true"
			leave = true;
		}

		if (leave == true) {										//tests if boolean "leave" is true 
			cout << "That is not a valid selection! Try again: ";	//and if so, asks user to redo input
			cin >> userChoice;
		}
	} while (leave == true);									//if boolean "leave" is true, loop ensues with new input until "leave" is false

	return userInteger;											//returns user's string as a VALID int
}