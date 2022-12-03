#pragma once

#include <iostream>
#include <string>
using namespace std;

enum TicketType { VIP, LAWN, TRIBUNE, BOXES };
 
class Ticket {
private:

	char* guestName = nullptr;
	const int ticketId;
	TicketType type = TRIBUNE;
	double ticketPrice = 0;
public:
	const static int MIN_NAME_SIZE = 3;
	static int NO_TICKETS_SOLD;
	static double SUM_OF_TICKETS_SOLD;
	//getter and setter for guestName
	char* getGuestName() {
		char* copyGuestName = this->copyArray(this->guestName);
		return copyGuestName;
	}

	void setGuestName(const char* guestName) {
		if (strlen(guestName) < Ticket::MIN_NAME_SIZE) {
			throw "Invalid name (too short) ";
		}
		if (this->guestName != nullptr) {
			delete[] this->guestName;
		}
		this->guestName = new char[strlen(guestName) + 1];
		strcpy(this->guestName, guestName);
	}

	//getter and setter for TicketType
	void setType(TicketType type) {
		this->type = (TicketType)type;
	}

	TicketType getType() {
		return this->type;
	}

	//getter and setter for ticketPrice
	void setTicketPrice(double ticketPrice) {
		this->ticketPrice = ticketPrice;
	}

	double getTicketPrice() {
		return this->ticketPrice;
	}

	//default constructor
	Ticket():ticketId(-1) {
		this->setGuestName("Unknown");
		this->setType(TRIBUNE);
		this->setTicketPrice(0);
		cout << endl << "These are values called by the default constructor! ";
	}

	Ticket(int ticketId,const char* guestName, double ticketPrice, TicketType type) :ticketId(ticketId) {
		this->setGuestName(guestName);
		this->setTicketPrice(ticketPrice);
		this->setType(type);
		Ticket::NO_TICKETS_SOLD++;
		Ticket::SUM_OF_TICKETS_SOLD = Ticket::SUM_OF_TICKETS_SOLD + this->ticketPrice;
	}

	void print() {
		if (this->guestName != nullptr) {
			cout << endl << "The guest's name: " << this->guestName;
		}
		cout << endl << "The ticket's id: " << this->ticketId;
		cout << endl << "The ticket's type: "; /*<< this->type;*/
		if (this->type == 0) {
			cout << "VIP";
		}
		if (this->type == 1) {
			cout << "LAWN";
		}
		if (this->type == 2) {
			cout << "TRIBUNE";
		}
		if (this->type == 3) {
			cout << "BOXES";
		}
		cout << endl << "The ticket's price: " << this->ticketPrice;
	}

	//destructor
	~Ticket() {
		this->deleteTicket();
		Ticket::SUM_OF_TICKETS_SOLD = Ticket::SUM_OF_TICKETS_SOLD - this->ticketPrice;
		Ticket::NO_TICKETS_SOLD--;
	}
	void deleteTicket() {
		if(this->guestName !=nullptr){}
	}

	//copy constructor
	Ticket(const Ticket& ticket):ticketId(ticket.ticketId) {
		this->setGuestName(ticket.guestName);
		this->setTicketPrice(ticket.ticketPrice);
		this->setType(ticket.type);
		Ticket::NO_TICKETS_SOLD++;
		Ticket::SUM_OF_TICKETS_SOLD = Ticket::SUM_OF_TICKETS_SOLD + ticket.ticketPrice;
	}

	//operator=
	void operator=(const Ticket& ticket) {
		if (this == &ticket) {
			return;
		}
		if (this->guestName) {
			delete[] this->guestName;
			this->guestName = nullptr;
		}
		if (ticket.guestName != nullptr) {
			this->guestName = new char[strlen(ticket.guestName) + 1];
			strcpy(this->guestName, ticket.guestName);
		}
		else {
			this->guestName = nullptr;
		}
		this->ticketPrice = ticket.ticketPrice;
		this->type = ticket.type;
		Ticket::NO_TICKETS_SOLD++;
		Ticket::SUM_OF_TICKETS_SOLD = Ticket::SUM_OF_TICKETS_SOLD + this->ticketPrice;
	}


private:
	static char* copyArray(const char* array) {
		char* copy = new char[strlen(array) + 1];
		for (int i = 0; i < strlen(array) + 1; i++) {
			copy[i] = array[i];
		}
		copy[strlen(array) + 1] = '\0';
		return copy;
	}

public:
	friend void operator<<(ostream& out, Ticket ticket);
	friend void operator>>(istream& in, Ticket ticket);

	bool operator>(Ticket& ticket) {
		return this->ticketPrice > ticket.ticketPrice;
	}

	void operator+=(int value) {
		this->ticketPrice += value;
		Ticket::SUM_OF_TICKETS_SOLD = Ticket::SUM_OF_TICKETS_SOLD + value;
	}
	//This function returns the money made devided by the tickets sold
	

};

int Ticket::NO_TICKETS_SOLD = 0;
double Ticket::SUM_OF_TICKETS_SOLD = 0;

double AverageSales() {
	double averageSale = 0;
	averageSale = Ticket::SUM_OF_TICKETS_SOLD / Ticket::NO_TICKETS_SOLD;
	return averageSale;
}

void operator<<(ostream& out, Ticket ticket) {
	out << endl << (ticket.guestName != nullptr ? "Guest's name: " + string(ticket.guestName) : "No name");
	out << endl << "Ticket's id: " << ticket.ticketId;
	out << endl << "Ticket's price: " << ticket.ticketPrice;
	out << endl << "Ticket's type: " << ticket.type;
}

void operator>>(istream& in, Ticket ticket) {
	cout << endl << "Guest's name: ";
	char buffer[100];
	in >> buffer;
	if (ticket.guestName != nullptr) {
		delete[] ticket.guestName;
		ticket.guestName = nullptr;
	}
	ticket.guestName = new char[strlen(buffer) + 1];
	strcpy(ticket.guestName, buffer);

	cout << endl << "Ticket's price: ";
	in >> ticket.ticketPrice;
	cout << endl << "Ticket's type: ";
	int type;
	in >> type;
	if (type == VIP) {
		ticket.type = VIP;
	}
	if (type == TRIBUNE) {
		ticket.type = TRIBUNE;
	}
	if (type == LAWN) {
		ticket.type = LAWN;
	}
	if (type == BOXES) {
		ticket.type = BOXES;
	}
	Ticket::NO_TICKETS_SOLD++;
}