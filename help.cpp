#include "PlaneAndSeats.h"			//includes header file

/*

Purpose: Function that describes each menu selection's functionality
Author: Wasim Algamal
Creation Date:
Last Modification Date:

*/

void help() {			//displays help panel message
	cout << endl << "------------------------ HELP -----------------------------" << endl << endl <<		
		"Selection 1: Displays the seating chart of the airplane with " << endl <<
		"numbered rows and lettered columns.If there is an 'X' on a " << endl <<
		"seat, this indicates that the seat is reserved." << endl << endl <<

		"Selection 2: Prompts the user for a seat to reserve. User must " << endl <<
		"enter a valid seat in order to reserve seat (EX: 1A or 12C)." << endl << endl <<

		"Selection 3: Prompts the user for a seat to cancel reservation " << endl <<
		"for. User must enter a valid seat in order to reserve seat " << endl <<
		"(EX: 2D or 10B)." << endl << endl <<

		"Selection 4: Saves changes made to the airplane's seating chart." << endl << endl <<

		"Selection 5: Displays statistics such as:" << endl <<
		"a.) Number of available seats" << endl <<
		"b.) Percentage of seats that are reserved" << endl <<
		"c.) List of window seats that are available" << endl <<
		"d.) List of aisle seats that are available" << endl << endl <<

		"Selection 6: Calls the help panel." << endl << endl <<

		"Selection 7: Exits the program." << endl <<
		"-----------------------------------------------------------" << endl << endl;
}