----------------------
COMMUNICATION NETWORK
----------------------
Author: Nikolai Alexander
Published: July 1, 2018
Course: CSCI2270-300


----------------------
DESCRIPTION
----------------------

This program simulates a communications network using a doubley linked list. Each node
in the network represents a city. In this program, the user is able to build an initial
network, print the network path, transmit a message from coas-to-coast-to-coast, add or
delete a city, and completely clear the network.


----------------------
FILE DESCRIPTION
----------------------

CommunicationNetwork.h - The header file containing the City structure, and the
			 CommunicationNetwork class. It also initializes all of the 
			 function prototypes in the CommunicationNetwork class

CommunicationNetwork.cpp - This is the file building all of the functions in the
			   CommunicationNetwork class.

	Functions:
	* CommunicationNetwork() - The constructor of the CommunicationNetwork class

	* ~CommunicationNetwork() - The destructor of the CommunicationNetwork class

	* void addCity(string, string) - Adds a new city into the doubley linked list

	* void buildNetwork() - Builds the initial linked list. The initial cities are fixed
				in the function.

	* void transmitMsg(char*) - Opens a txt file determined in the first command line
				    argument, and sends a message from the head of the doubley
				    linked list to the tail, and back to the head one word at
				    a time.
	
	* void printNetwork() - Prints the doubly linked list from head to tail.

	* void deleteCity(string) - Deletes the city, determined by the string, from the doubley
				    linked list.

	* void deleteNetwork() - Completely deletes the network (called in the destructor).

main.cpp - The main file of the program. Constructs the doubley linked list, and displays a
		  main menu showing options to select any of the functions written in
		  CommunicationNetwork.cpp.

	Functions:
	* int main(int, char*) - The main function of the file. Constructs the doubly linked list, and
				 uses a main menu to call all the functions written in
				 CommunicationNetwork.cpp




----------------------
BUILD INSTRUCTIONS
----------------------

To build and run the file, type the following commands in your terminal:

	g++ CommunicationNetwork.cpp Assignment3.cpp -o Assignment3

	./Assignment3 filename

	* Where filename is the name of the txt file containing the message you want to send throughout
	  the network.