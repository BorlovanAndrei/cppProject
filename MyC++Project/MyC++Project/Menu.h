#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Menu {
	int ticketsAvailable=0;
	string eventName="";
	double ticketPrice=0;
public:
	
	Menu() {

	};
	Menu(string name, int ticketAvailable, double price):eventName(name), ticketsAvailable(ticketAvailable), ticketPrice(price) {
	
	}
	~Menu() {
		//cout << endl << "Destructor! Event no longer available!";
	};
	string getName() {
		return eventName;
	}
	int getAvailableTickets() {
		return ticketsAvailable;
	}
	double getTicketPrice() {
		return ticketPrice;
	}
	//string getName();
	//int getAvailableTickets();
	//double getTicketPrice();
	double purchaseTicket(int purchaseTicketsAvailable) {
		double totalPrice;
		if (purchaseTicketsAvailable <= this->ticketsAvailable) {
			totalPrice = purchaseTicketsAvailable * this->ticketPrice;
			this->ticketsAvailable = this->ticketsAvailable - purchaseTicketsAvailable;
			return totalPrice;
		}
		else {
			return -1;
		}
	}
	void Run();
	void DisplayMenu();
	void AddAnEvent();
	void AddATicket();
	void AddALocation();
};