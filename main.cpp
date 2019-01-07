// Nikolai Alexander
// Assignment 3
// Christopher Godley

/* This program simulates a communications network using a doubley linked list. Each node
in the network represents a city. In this program, the user is able to build an initial
network, print the network path, transmit a message from coas-to-coast-to-coast, add or
delete a city, and completely clear the network. */

#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Used to call the ignore function in the invalid entry section
#include "CommunicationNetwork.h"

using namespace std;

int main(int argc, char* argv[1]){
	CommunicationNetwork network;

	int option = 0;

	while(option != 7){

		// Main Menu
		cout << "======Main Menu======" << endl;
		cout << "1. Build Network" << endl;
		cout << "2. Print Network Path" << endl;
		cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
		cout << "4. Add City" << endl;
		cout << "5. Delete City" << endl;
		cout << "6. Clear Network" << endl;
		cout << "7. Quit" << endl;

		cin >> option; // Input option

		//Build Network
		if(option == 1){
			network.buildNetwork();
		}
		// Print Network Path
		else if (option == 2){
			network.printNetwork();
		}
		// Transmit Message
		else if (option == 3){
			network.transmitMsg(argv[1]);
		}
		//Add City
		else if (option == 4){
			string newCity;
			string prevCity;

			cout << "Enter a city name:" << endl;
			cin >> ws; //Extracts whitespace (allows for a second command)
			getline(cin, newCity);

			cout << "Enter a previous city name:" << endl;
			cin >> ws; // Same as above ^^
			getline(cin, prevCity);

			network.addCity(prevCity, newCity);			
		}
		// Delete City
		else if (option == 5){
			string delCity;

			cout << "Enter a city name:" << endl;
			cin >> ws;
			getline(cin, delCity);

			network.deleteCity(delCity);
		}
		// Clear Network
		else if (option == 6){
			network.deleteNetwork();
		}
		// Quit Program
		else if(option == 7){
			cout << "Goodbye!" << endl;
		}
		// Invalid Entry
		else{
			cout << "Invalid entry. Please try again." << endl;

			// Prevent from infinite looping if a non-int input is entered
			// Source: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers/10829026#10829026
			cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	return 0;
}