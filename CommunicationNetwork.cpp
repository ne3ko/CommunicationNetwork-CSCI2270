// Nikolai Alexander
// Assignment 3
// Christopher Godley

#include <iostream>
#include <fstream>
#include <string>
#include "CommunicationNetwork.h"

using namespace std;

// Constructor
CommunicationNetwork::CommunicationNetwork(){
	head = new City();
	head->previous = NULL;

	City* tmp = head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	tail = tmp;
	tail->next = NULL;
}
// Destructor
CommunicationNetwork::~CommunicationNetwork(){
	// Only call deleteNetwork if there are any cities in the network.
	if(head->cityName != ""){
		deleteNetwork();
	}

	// Delete head and tail
	delete head;
	delete tail;
}

// Inserts a new city into the network.
//		- string prevCity - The city that the new city is inserted after
//		- string newCity - the new city that is being inserted into the network
void CommunicationNetwork::addCity(string prevCity, string newCity){
	City* newNode = new City();
	newNode->cityName = newCity;
	newNode->previous = NULL;
	newNode->next = NULL;

	if(prevCity == "First"){ // Insert at the head
		newNode->next = head;
		head = newNode;
		head->next->previous = head;
	}
	else{
		City* tmp = head;
		while(tmp->cityName != prevCity){
			if(tmp == tail){ // Loop reaches the end of the linked list
				if(prevCity == "\"\""){ // If the user types "" break loop and add to tail
					break;
				}
					cout << "Unable to locate previous city." << endl;
					return;
			}
			tmp = tmp->next;
		}

		newNode->next = tmp->next;
		newNode->previous = tmp;
		tmp->next = newNode;
		if(newNode->next != NULL){ // Add to
			newNode->next->previous = newNode;
		}
		else{
			tail = newNode;
		}
	}
}

// Builds the initial network - The initial cities are fixed in the function.
void CommunicationNetwork::buildNetwork(){
	// Create an array of the initial cities for easier calling
	string initCity[] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};

	// Initialize the head
	head->cityName = initCity[0];
	head->next = NULL;
	head->previous = NULL;

	// Recursively call the addCity function to build the network
	for(int i = 0; i < 9; i++){
		addCity(initCity[i], initCity[i+1]);
	}

}

// Opens a text file, and sends the message from the head of the network to the tail of the
// network back to the head one word at a time.
//		- char* txtFile - the txtFile being read. Determined in the first line argument.
void CommunicationNetwork::transmitMsg(char* txtFile){
	if(head->cityName == ""){ // If the list is empty, return "Empty list"
		cout << "Empty list" << endl;
		return;
	}

	ifstream message(txtFile);

	// Read through text file
	while(!message.eof()){
		City* tmp = head;
		message >> tmp->message; // Send the message to the head

		cout << tmp->cityName << " received " << tmp->message << endl;

		while(tmp->next != NULL){ // Send message from head to tail
			tmp->next->message = tmp->message;
			tmp->message = "";
			tmp = tmp->next;
			cout << tmp->cityName << " received " << tmp->message << endl;
		}

		while(tmp->previous != NULL){ // Send message from tail to head
			tmp->previous->message = tmp->message;
			tmp->message = "";
			tmp = tmp->previous;
			cout << tmp->cityName << " recieved " << tmp->message << endl;
		}
	}
}

// Prints the network of cities from head to tail.
void CommunicationNetwork::printNetwork(){
	City* tmp = head;

	cout << "===CURRENT PATH===" << endl;

	cout << "NULL <- ";

	if(tmp->cityName != ""){

		while(tmp != tail){
			cout << tmp->cityName << " <-> ";
			tmp = tmp->next;
		}	

		cout << tail->cityName << " -> NULL";
	}

	cout << endl;

	cout << "==================" << endl;
}

// Deletes the determined city from the network.
//		- string city - the city that is deleted
void CommunicationNetwork::deleteCity(string city){
	City* tmp = head;

	if(head->cityName == city){ // Delete city at the head
		head = head->next;
		tmp->next = NULL;
		head->previous = NULL;
	}
	else{ // Delete city in the middle or at the tail
		while(tmp->next->cityName != city){
			// If the city is not found, return a message
			if(tmp->next->next == NULL){
				cout << city << " not found" << endl;
				return;
			}
			tmp = tmp->next;
		}

		City* delCity = tmp->next;

		// Move pointers to no longer connect to city you want to delete
		tmp->next = delCity->next;
		delCity->next = NULL;
		delCity->previous = NULL;
		if(tmp->next != NULL){ // If the city is in the middle
			tmp->next->previous = tmp;
		}
		else{ // If the city is at the end
			tail = tmp;
		}

		delete delCity; // Deletes the node containing the city
	}
}

// Completely clears the network of cities - Called in the destructor.
void CommunicationNetwork::deleteNetwork(){
	City* tmp = head;

	while(tmp != tail){ // Recursivley delete cities until the tail
		 cout << "deleting " << tmp->cityName << endl;
		 tmp = tmp->next;
		 deleteCity(tmp->previous->cityName);
	}

	// Completely delete the head and tail
	cout << "deleting " << tail->cityName << endl;
	delete head;
	delete tail;

	// Reinitialize head and tail to avoid completely deconstructing
	head = new City();
	head->previous = NULL;

	tmp = head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	tail = tmp;
	tail->next = NULL;
}