#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//class Menu {
//	int ticketsAvailable=0;
//	string eventName="";
//	double ticketPrice=0;
//public:
//	
//	Menu() {
//
//	};
//	Menu(string name, int ticketAvailable, double price):eventName(name), ticketsAvailable(ticketAvailable), ticketPrice(price) {
//	
//	}
//	~Menu() {
//		//cout << endl << "Destructor! Event no longer available!";
//	};
//	string getName() {
//		return eventName;
//	}
//	int getAvailableTickets() {
//		return ticketsAvailable;
//	}
//	double getTicketPrice() {
//		return ticketPrice;
//	}
//	//string getName();
//	//int getAvailableTickets();
//	//double getTicketPrice();
//	double purchaseTicket(int purchaseTicketsAvailable) {
//		double totalPrice;
//		if (purchaseTicketsAvailable <= this->ticketsAvailable) {
//			totalPrice = purchaseTicketsAvailable * this->ticketPrice;
//			this->ticketsAvailable = this->ticketsAvailable - purchaseTicketsAvailable;
//			return totalPrice;
//		}
//		else {
//			return -1;
//		}
//	}
//	void Run();
//	void DisplayMenu();
//	void AddAnEvent();
//	void AddATicket();
//	void AddALocation();
//	bool ticketsForSale(int ticketsAvailable) {
//		if (ticketsAvailable > this->ticketsAvailable) {
//			return false;
//		}
//		else {
//			this->ticketsAvailable--;
//			return true;
//		}
//	};
//};
void displayMenu();
class Manage {
public:
	Manage() {
		displayMenu();
	}
};

class Details {
public:
	static string name;
	static int cId;
	char arr[100];
	int randomId = 10000000 + rand() % 100000000;
	 static string type;
	void information() {
		system("CLS");
		cout << "Customer ID: ";
		cId=randomId;
		cout << cId<<endl;
		cout << "Enter the name: ";
		cin >> name;
		cout << endl << "Ticket's type: (choose between: VIP, LAWN, TRIBUNE, BOXES)" <<endl;
		cin >> type;
		transform(type.begin(), type.end(), type.begin(), ::toupper);
		cout << "Your details are saved with us!" << endl;
		system("PAUSE");
		system("CLS");
	}
};
int Details::cId;
string Details::name;
string Details::type;

class Registration {
public:
	static int choice;
	int choice1=0;
	int back=0;
	static float charges;
	static int type;
	void events() {
		system("CLS");
		cout << "--------Welcome!--------" << endl;
		string eventsN[] = { "Cinema", "Footbal game" };
		for (int i = 0; i < 2; i++) {
			cout << i + 1 << "."  << eventsN[i]<<endl;
		}

		cout << "Press the number of the event you want to watch: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "------Welcome to the Cinema------" << endl;
			cout << "Here are the movies for today: " << endl;
			cout << "1. The Godfather " << endl;
			cout << "Time: 18:30" << endl;
			cout << "Duration: 125 minutes " << endl;
			cout << "Location: Cinema City Sun Plaza" << endl << endl;

			cout << "2. The Shawshank Redemption " << endl;
			cout << "Time: 20:00" << endl;
			cout << "Duration: 130 minutes " << endl << endl;
			cout << "Location: Cinema City Afi Palace Cotroceni" << endl << endl;

			cout << "3. Inception" << endl;
			cout << "Time: 19:30" << endl;
			cout << "Duration: 135 minutes " << endl << endl;
			cout << "Location: Cineplexx Baneasa" << endl << endl;

			cout << "Select the movie you want to book: ";
			cin >> choice1;

			if (choice1 == 1) {
				charges = 30;
				cout << "You have succesfully booked the ticket to the movie <The Godfather> " << endl;
				cout << "You can go back to the menu and take your ticket " << endl;
			}
			else if (choice1 == 2) {
				charges = 34;
				cout << "You have succesfully booked the ticket to the movie <The Shawshank Redemption> " << endl;
				cout << "You can go back to the menu and take your ticket " << endl;
			}
			else if (choice1 == 3) {
				charges = 40;
				cout << "You have succesfully booked the ticket to the movie <Inception> " << endl;
				cout << "You can go back to the menu and take your ticket " << endl;
			}
			else {
				cout << "Invalid input, shifting to the previous menu" << endl;
				events();
			}
			cout << endl << "Press 1 to go back to the main menu: " << endl;
			cin >> back;
			if (back == 1) {
				displayMenu();
			}
			else {
				displayMenu();
			}
		}
		case 2: {
			cout << "------Welcome to the list of football games------" << endl;
			cout << "Here are the games for today: " << endl;
			cout << "1. Reak Madrid VS Barcelona " << endl;
			cout << "Time: 21:30" << endl;

			cout << "2. Manchester United VS Manchester City " << endl;
			cout << "Time: 20:00" << endl;

			cout << "3. Milan VS Juventus" << endl;
			cout << "Time: 19:30" << endl;

			cout << "Select the match you want to book: ";
			cin >> choice1;

			if (choice1 == 1) {
				charges = 150;
				cout << "You have succesfully booked the ticket to the match <Real Madrid VS Barcelona> " << endl;
				cout << "You can go back to the menu and take your ticket " << endl;
			}
			else if (choice1 == 2) {
				charges = 200;
				cout << "You have succesfully booked the ticket to the match <Manchester United VS Manchester City> " << endl;
				cout << "You can go back to the menu and take your ticket " << endl;
			}
			else if (choice1 == 3) {
				charges = 130;
				cout << "You have succesfully booked the ticket to the match <Milan VS Juventus> " << endl;
				cout << "You can go back to the menu and take your ticket " << endl;
			}
			else {
				cout << "Invalid input, shifting to the previous menu" << endl;
				events();
			}
			cout << "Press 1 to go back to the main menu: " << endl;
			cin >> back;
			if (back == 1) {
				displayMenu();
			}
			else {
				displayMenu();
			}
		}
		default: {
			cout << "Invalid input, shifting to the main menu ! " << endl;
			displayMenu();
			break;
		}
		}
		system("PAUSE");
		system("CLS");
	}
};

float Registration::charges;
int Registration::choice;

class PrintTicket : public Registration, Details {
public:
	void Bill() {
		system("CLS");
		string customerEvent = "";
		string locationEvent = "";
		ofstream file("records.txt",ios::out | ios::app | ios::binary); {
			file <<endl<< "---------Ticketing app--------" << endl;
			file << "-----------Ticket----------" << endl;
			file << "---------------------------" << endl;
			file << "Customer ID: " << Details::cId << endl;
			file << "Name ID: " << Details::name << endl;
			/*file << "Ticket type: " << Details::type << endl;*/
			file <<endl<<"Description: " << endl;
			if (Registration::choice == 1) {
				customerEvent = "Cinema";
			}
			if (Registration::choice == 2) {
				customerEvent = "Footbal game";
			}
			file << "Event: " << customerEvent << endl;
			file << "Ticket's price: " << Registration::charges << endl;
			file << "Ticket type: " << Details::type << endl;
		}
		file.close();
		system("PAUSE");
		system("CLS");
	}
	void display() {
		system("CLS");
		ifstream file("records.txt",ios::out | ios::app); {
			if (!file) {
				cout << "******NO FILE******" << endl;
			}
			else {
				while (!file.eof()) {
					file.getline(arr, 100);
					cout << arr << endl;
				}
			}
		}
		file.close();
		system("PAUSE");
		system("CLS");
	}
};

void displayMenu() {
	system("CLS");
	int lchoice=0;
	int schoice=0;
	int back=0;

	cout << "----Ticketing App----" << endl;
	cout << "_____________________" << endl;
	cout << "1-> Add customer details. " << endl;
	cout << "2-> Event registration " << endl;
	cout << "3-> Get ticket " << endl;
	cout << "--------------------" << endl;
	cout << "0-> Exit " << endl;
	cout << "--------------------" << endl;

	cout << "Enter your choice : ";
	cin >> lchoice;

	Details d;
	Registration r;
	PrintTicket p;


	switch (lchoice) {
	case 1: {
		cout << "---------Customers---------" << endl;
		d.information();
		cout << "Press 1 to go back to the Main menu ";
		cin >> back;
		if (back == 1) {
			displayMenu();
		}
		else {
			displayMenu();
		}
		break;
	}
	case 2: {
		cout << "----Book an Event----" << endl;
		r.events();
		break;
	}
	case 3: {
		cout << "----Get your ticket----" << endl;
		p.Bill();
		cout << "Your ticket is printed, you can go back to collect it " << endl;
		cout << "Press 1 to display your ticket ";
		cin >> back;
		if (back == 1) {
			p.display();
			cout << "Press 1 to go back to the main menu ";
			cin >> back;
			if (back == 1) {
				displayMenu();
			}
			else {
				displayMenu();
			}
		}
		else {
			displayMenu();
		}
		break;
	}
	case 0: {
		cout << "Thank you!" << endl;
		break;
	}
	default: {
		cout << "Invalid input, please try again" << endl;
		displayMenu();
		break;
	}

	}
	system("PAUSE");
	system("CLS");
}