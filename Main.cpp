#include "PlaneAndSeats.h"			//includes header file

//--------------------MAIN------------------------------------------------------------------------------------------------------\\

int main() {

	plane airplane;				//creating instance of object plane named "airplane"
	airplane.readSeatChart();	//method called to read and fill in seat chart from given file "chartIn.txt"

	cout << endl << "-Hello and Thank You for Choosing W.A. Airlines! Please Make a Selection!-" << endl << endl; //welcome message

	displayMenu(airplane);		//function called to display menu options for the user to select from

	return 0;
}

//-------------------METHODS-------------------------------------------------------------------------------------------------------\\

void plane::readSeatChart() {					//method that reads and fills seat chart from given file "chartIn.txt'
	ifstream inFile;							//ifstream file declares as "inFile"
	inFile.open("chartIn.txt");					//opens given file "chartIn.txt" and sets it to inFile								

	for (int i = 0; i < NUM_ROWS; i++) {		//nested for loop to sift through string array of seatChart
		for (int j = 0; j < NUM_COLS; j++) {
			inFile >> seatChart[i][j];			//reads and fills each value from inFile to string array seatChart
		}
	}

	inFile.close();								//explicit close of inFile
}

void plane::displaySeatChart() {				//method that displays seat chart with available seats
	int x = 1;

	cout << endl << "------------------------ Seats ----------------------------" << endl;

	for (int i = 0; i < 9; i++) {					//for-loop for numbers 1-9
		for (int j = 0; j < NUM_COLS; j++) {
			if (j == 0)
				cout << seatChart[i][j] << "  ";	//double space used for single digit rows (looks better)
			else
				cout << seatChart[i][j] << " ";
			if (x % NUM_COLS == 0)					//if statement that end lines after every row
				cout << endl; x++;
		}
	}

	for (int i = 9; i < NUM_ROWS; i++) {		//for-loop similar to the one above for numbers 10-15
		for (int j = 0; j < NUM_COLS; j++) {
			cout << seatChart[i][j] << " ";
			if (x % NUM_COLS == 0)
				cout << endl; x++;
		}
	}

	cout << "-----------------------------------------------------------" << endl << endl;
}

void plane::reserveSeat(int& reservedSeats) {				//method that allows user to reserve a seat
	ostringstream oss;					//variables declared first
	string seat;
	bool validSeat;
	bool availabilityFalse = false;		//bool used to set occupied seats
	int tempInt;


	if (reservedSeats == 60) {				//if statement tests if seats are full
		cout << "Sorry, all seats are occupied.";
	}
	else {
		cout << "Enter a valid seat to reserve (EX: 1A): ";			//if seats are not full, user is prompted to enter a valid seat

		do {						//do-while loop used to validate seat input
			validSeat = true;		//if bool "validSeat" remains true, will exit loop
			cin >> seat;			//string input for seat

			if (!isdigit(seat[1])) {			//if statement tests if second char in string is NOT a digit
				if (seat[0] < '1' || seat[1] > 'D' || seat[1] < 'A') {		//if statement tests seat number and letter	
					validSeat = false;
					cout << "Invalid seat! Try Again: ";
				}
			}
			else {		//else statement takes any input with double digit
				if (seat[0] != '1' || seat[1] > '5' || seat[1] < '0' || seat[2] < 'A' || seat[2] > 'D') {		//if statement tests seat numbers and letter
					validSeat = false;
					cout << "Invalid seat! Try Again: ";
				}
			}
		} while (validSeat == false);		//while bool "validSeat" is false, loop goes on

		if (!isdigit(seat[1])) {		//if statement tests if second char in string is NOT a digit
			tempInt = seat[0] - '0';	//converts first char to int

			tempInt -= 1;				//int is subtracted by 1 to be read correctly in array 

			if (seat[1] == 'A') {		//tests seat availability for column 'A'
				if (seats[tempInt][0].getAvailability() == true) {			//if statement tests if seat is available
					seatChart[tempInt][1] = 'X';							//sets seat chosen to 'X' on seatChart array
					seats[tempInt][0].setAvailability(availabilityFalse);	//sets seat	availability of seat to "false" in seat array
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;										//adds to the count of reserved seats
				}
				else {													//else statement informs user seat is unavailable
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;					
				}
			}

			//above logic is repeated for all letter columns and two digit rows!!

			if (seat[1] == 'B') {		//tests seat availability for column 'B'
				if (seats[tempInt][1].getAvailability() == true) {
					seatChart[tempInt][2] = 'X';
					seats[tempInt][1].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}

			if (seat[1] == 'C') {		//tests seat availability for column 'C'
				if (seats[tempInt][2].getAvailability() == true) {
					seatChart[tempInt][3] = 'X';
					seats[tempInt][2].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}

			if (seat[1] == 'D') {		//tests seat availability for column 'D'
				if (seats[tempInt][3].getAvailability() == true) {
					seatChart[tempInt][4] = 'X';
					seats[tempInt][3].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}
		}
		else {			//else statement takes any input with double digit (USES SAME LOGIC AS ABOVE)
			oss << seat[0] << seat[1];	//uses ostringstream to intake double digits

			tempInt = atoi(oss.str().c_str());		//sets tempInt to row digits

			tempInt -= 1;							//int is subtracted by 1 to be read correctly in array 

			if (seat[2] == 'A') {					//tests seat availability for column 'A'
				if (seats[tempInt][0].getAvailability() == true) {
					seatChart[tempInt][1] = 'X';
					seats[tempInt][0].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}

			if (seat[2] == 'B') {					//tests seat availability for column 'B'
				if (seats[tempInt][1].getAvailability() == true) {
					seatChart[tempInt][2] = 'X';
					seats[tempInt][1].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}

			if (seat[2] == 'C') {					//tests seat availability for column 'C'
				if (seats[tempInt][2].getAvailability() == true) {
					seatChart[tempInt][3] = 'X';
					seats[tempInt][2].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}

			if (seat[2] == 'D') {					//tests seat availability for column 'D'
				if (seats[tempInt][3].getAvailability() == true) {
					seatChart[tempInt][4] = 'X';
					seats[tempInt][3].setAvailability(availabilityFalse);
					cout << "Your seat is reserved!" << endl;
					reservedSeats++;
				}
				else {
					cout << "I'm sorry, that seat is not available. Sending you back to menu..." << endl;
				}
			}
		}
	}
	cout << endl << "-----------------------------------------------------------" << endl << endl;
}

void plane::cancelSeat(int& reservedSeats) {			//method that allows user to cancel reserved seat (USES SAME LOGIC AS METHOD "reserveSeat", BUT REVERSED)
	ostringstream oss;		//variables declared
	string seat;
	bool validSeat;
	bool availabilityTrue = true;		//sets availability to TRUE
	int tempInt;

	if (reservedSeats == 0) {				//if statement tests if seats are empty
		cout << "Sorry, no seats are reserved." << endl;
	}
	else {
		cout << "Enter a valid seat to cancel (EX: 1A): ";				//if seats are not all empty, user is prompted to enter a valid seat

		do {		//EXACT SAME loop to validate seat is a valid seat as above method
			validSeat = true;
			cin >> seat;

			if (!isdigit(seat[1])) {
				if (seat[0] < '1' || seat[1] > 'D' || seat[1] < 'A') {
					validSeat = false;
					cout << "Invalid seat! Try Again: ";

				}
			}
			else {
				if (seat[0] != '1' || seat[1] > '5' || seat[1] < '0' || seat[2] < 'A' || seat[2] > 'D') {
					validSeat = false;
					cout << "Invalid seat! Try Again: ";
				}
			}
		} while (validSeat == false);

		if (!isdigit(seat[1])) {
			tempInt = seat[0] - '0';

			tempInt -= 1;

			if (seat[1] == 'A') {
				if (seats[tempInt][0].getAvailability() == false) {			//if statement tests if seat is available
					seatChart[tempInt][1] = 'A';							//sets seat chosen to back to 'A' on seatChart array
					seats[tempInt][0].setAvailability(availabilityTrue);	//sets availability of seat back to TRUE in seat array
					cout << "This seat is now available!" << endl;
					reservedSeats--;										//SUBTRACTS to the count of reserved seats (applied throughout)
				}
				else {														//else statement informs user seat IS ACTUALLY available
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}

			if (seat[1] == 'B') {
				if (seats[tempInt][1].getAvailability() == false) {
					seatChart[tempInt][2] = 'B';							//sets seat chosen to back to 'B' on seatChart array
					seats[tempInt][1].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}

			if (seat[1] == 'C') {
				if (seats[tempInt][2].getAvailability() == false) {
					seatChart[tempInt][3] = 'C';							//sets seat chosen to back to 'C' on seatChart array
					seats[tempInt][2].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}

			if (seat[1] == 'D') {
				if (seats[tempInt][3].getAvailability() == false) {
					seatChart[tempInt][4] = 'D';							//sets seat chosen to back to 'D' on seatChart array
					seats[tempInt][3].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}
		}
		else {			//else statement takes any input with double digit (USES SAME LOGIC AS ABOVE METHOD)
			oss << seat[0] << seat[1];

			tempInt = atoi(oss.str().c_str());

			tempInt -= 1;

			if (seat[2] == 'A') {
				if (seats[tempInt][0].getAvailability() == false) {
					seatChart[tempInt][1] = 'A';							//sets seat chosen to back to 'D' on seatChart array
					seats[tempInt][0].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}

			if (seat[2] == 'B') {
				if (seats[tempInt][1].getAvailability() == false) {
					seatChart[tempInt][2] = 'B';							//sets seat chosen to back to 'D' on seatChart array
					seats[tempInt][1].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}

			if (seat[2] == 'C') {
				if (seats[tempInt][2].getAvailability() == false) {
					seatChart[tempInt][3] = 'C';							//sets seat chosen to back to 'D' on seatChart array
					seats[tempInt][2].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}

			if (seat[2] == 'D') {
				if (seats[tempInt][3].getAvailability() == false) {
					seatChart[tempInt][4] = 'D';							//sets seat chosen to back to 'D' on seatChart array
					seats[tempInt][3].setAvailability(availabilityTrue);
					cout << "This seat is now available!" << endl;
					reservedSeats--;
				}
				else {
					cout << "I'm sorry, that seat is not reserved. Sending you back to menu..." << endl;
				}
			}
		}
	}
	cout << endl << "-----------------------------------------------------------" << endl << endl;
}

void plane::saveChartFile() {		//method that saves a copy of the current seat chart in a user-defined file
	ofstream outFile;		//ofstream declared
	string userFile;		//variables declared
	int x = 1;	

	cout << "Please enter a file name to save your chart in: ";				//prompts user for file name
	cin >> userFile;

	outFile.open(userFile);													//opens file explicitly

	for (int i = 0; i < 9; i++) {											//EXACT SAME for-loop and logic as method "displaySeatChart"
		for (int j = 0; j < NUM_COLS; j++) {
			if (j == 0)
				outFile << seatChart[i][j] << "  ";
			else
				outFile << seatChart[i][j] << " ";
			if (x % NUM_COLS == 0)
				outFile << endl; x++;
		}
	}

	for (int i = 9; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			outFile << seatChart[i][j] << " ";
			if (x % NUM_COLS == 0)
				outFile << endl; x++;
		}
	}

	cout << "Your file has been saved to " << userFile << "!" << endl <<
		"-----------------------------------------------------------" << endl << endl;
}

void plane::stats(int& reservedSeats) {				//method that displays varying statistics about the current seat chart
	cout << endl << "------------------------ Seats ----------------------------" << endl <<
		"A.) Number of available seats: " << 60 - reservedSeats << endl << endl <<							//subtracts seats reserved from total seats to display # of available seats (int subtraction)
		"B.) Percentage of reserved seats: " << (reservedSeats / 60.0) * 100.0 << "%" << endl << endl <<	//uses float division to display percentage of reserved seats
		"C.) List of window seats available: " << endl;														//uses two for-loops to diplay available window seats

	for (int i = 0; i < 8; i++) {																			//for window seats numbered 1-8
		for (int j = 0; j < NUM_COLS; j++) {
			if (seatChart[i][j] == "A" || seatChart[i][j] == "D") {
				cout << " ~" << i + 1 << seatChart[i][j] << "~ ";
			}
		}
	}

	cout << endl;

	for (int i = 8; i < NUM_ROWS; i++) {																	//for window seats numbered 8-15
		for (int j = 0; j < NUM_COLS; j++) {
			if (seatChart[i][j] == "A" || seatChart[i][j] == "D") {
				cout << " ~" << i + 1 << seatChart[i][j] << "~ ";
			}
		}
	}

	cout << endl << endl;

	cout << "D.) List of aisle seats available: " << endl;													//uses two for-loops to diplay available aisle seats
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < NUM_COLS; j++) {																//for aisle seats numbered 1-8
			if (seatChart[i][j] == "B" || seatChart[i][j] == "C") {
				cout << " ~" << i + 1 << seatChart[i][j] << "~ ";
			}
		}
	}

	cout << endl;

	for (int i = 8; i < NUM_ROWS; i++) {																	//for aisle seats numbered 8-15
		for (int j = 0; j < NUM_COLS; j++) {
			if (seatChart[i][j] == "B" || seatChart[i][j] == "C") {
				cout << " ~" << i + 1 << seatChart[i][j] << "~ ";
			}
		}
	}

	cout << endl << "-----------------------------------------------------------" << endl << endl;
}