#pragma once					//replaces header guards (ifndef, define, endif)

//-----------------LIBRARIES---------------------\\

using namespace std;			//header files includes libraries and namespace 
#include <iostream>				//so that they do not need to be redeclared in
#include <iostream>				//each file				
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

//-------------------CONSTS-----------------------\\

const int NUM_ROWS = 15;		//initialized constant int variables of
const int NUM_COLS = 5;			//seat rows and columns

//------------------CLASSES------------------------\\

class seat {					//decleration of class "seat"
private:
	bool availability;			//private boolean attribute that detemines the availability of each seat
public:
	seat(bool available = true) { availability = available; }							//in-line constructor that creates an object of type "seat" with bool attribute "availability" set to true by default
	~seat() { cout << "Seat destroyed." << endl; }										//destructor that destroys an object of type "seat" at end of program and declares "Seat destroyed."
	void setAvailability(bool seatAvailability) { availability = seatAvailability; }	//method used to set status of "availability" of an object of type "seat"
	bool getAvailability() const { return availability; }								//method used to retrieve status of "availability" of an object of type "seat"
};

class plane {					//decleration of class "plane"
private:
	string seatChart[NUM_ROWS][NUM_COLS];				//array of strings to represent seats that will be diplayed in the seat chart
	seat seats[NUM_ROWS][NUM_COLS - 1];					//array of class "seat" that represents the availability of each seat
public:
	plane() { }											//in-line plane constructor that creates an object of type "plane"
	~plane() { cout << "Plane destroyed." << endl; }	//destructor that destroys an object of type "plane" at end of program and declares "Plane destroyed."

	void readSeatChart();					//method that reads and fills seat chart from given file "chartIn.txt'
	void displaySeatChart();				//method that displays seat chart with available seats; taken seats are represented by an 'X'
	void reserveSeat(int& reservedSeats);	//method that allows user to reserve a seat
	void cancelSeat(int& reservedSeats);	//method that allows user to cancel reserved seat
	void saveChartFile();					//method that saves a copy of the current seat chart in a user-defined file
	void stats(int& reservedSeats);			//method that displays varying statistics about the current seat chart
};

//-------------------PROTOTYPES---------------------\\

int validateUserInt(string userChoice);		//function that ensures user inputs a valid selection from the menu
void displayMenu(plane& airplane);			//function that displays menu options for the user to select from
void help();								//function that describes each menu selection's functionality