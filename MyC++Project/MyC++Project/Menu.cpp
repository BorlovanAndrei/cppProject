//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include "Menu.h"
//#include "Location.h"
//#include "Event.h"
//#include "Ticket.h"


//void Menu::Run() {
//	int option;
//	do {
//		DisplayMenu();
//		cout << endl << "Please select an option: ";
//		cin >> option;
//		switch (option) {
//		case 1:
//			AddAnEvent();
//			system("PAUSE");
//			system("CLS");
//			break;
//
//		case 2:
//			AddATicket();
//			system("PAUSE");
//			system("CLS");
//			break;
//
//		case 3:
//			AddALocation();
//			system("PAUSE");
//			system("CLS");
//			break;
//		case 0:
//			break;
//		default:
//			cout << endl << "Please choose a valid option:" <<endl
//				<< "-------------------" << endl;
//			cin.ignore();
//		}
//
//	} while (option != 4);
//}
//void Menu::DisplayMenu() {
//	cout << "----Ticketing App----" << endl;
//	cout << "_____________________" << endl;
//	cout << "1-> Add an event " << endl;
//	cout << "2-> Add a ticket " << endl;
//	cout << "3-> Add a location " << endl;
//	cout << "--------------------" << endl;
//	cout << "0-> Exit " << endl;
//
//}

//void Menu::AddAnEvent() {
//	/*int choice = 1;
//	int locations = Location::getNumberOfTotalLocations();
//	while (choice != 0) {
//		system("CLS");
//		cout << "----Add An Event----" << endl;
//		cout << "--------------------------" << endl;
//		cout << "Locations: " << locations << endl;
//		for (int i = 0; i < locations; i++)
//			cout << endl;
//	}*/
//	system("CLS");
//	string name = "";
//	int duration = 0;
//	int day = 0;
//	string month = "";
//	int year = 0;
//	int min = 0;
//	int hour = 0;
//	cout << "----Add An Event----" << endl;
//	cout << "--------------------" << endl;
//	cout << "Event name: ";
//	cin >> name;
//	cout << "Runtime (minutes): " << endl;
//	cin >> duration;
//	cout << "Hour: "; cin >> hour;
//	cout << "Minutes: "; cin >> min;
//	cout << "Day: "; cin >> day;
//	cout << "Month: "; cin >> month;
//	cout << "Year: "; cin >> year;
//	cout << "Event created!";
//	system("PAUSE");
//}
//
//void Menu::AddATicket() {
//	system("CLS");
//	string name = "";
//	int noTickets;
//	int ticketPrice = 25;
//	cout << "Please enter event's name: ";
//	cin >> name;
//	cout << "Please enter the amount of tickets you want to purchase: ";
//	cin >> noTickets;
//	//might need to use a pointer for events so we have actual prices, names, etc
//	double totalCost = purchaseTicket(noTickets);
//	if (totalCost == -1) {
//		cout << endl << "This event has been sold out! ";
//	}
//	else {
//		cout << endl << "Your total comes out to: " << totalCost << endl;
//	}
//	system("PAUSE");
//	system("CLS");
//}
//Menu::Menu() {
//	ticketsAvailable = 0;
//	ticketPrice = 1;
//	eventName = "";
//}
////Menu::Menu(string name, int ticketAvailable, double price) {
////	eventName = name;
////	ticketsAvailable = ticketAvailable;
////	ticketPrice = price;
////}
//Menu::~Menu() {
//	cout << endl << "Event no longer available!";
//}
//string Menu::getName() {
//	return eventName;
//}
//int Menu::getAvailableTickets() {
//	return ticketsAvailable;
//}
//double Menu::getTicketPrice() {
//	return ticketPrice;
//}
//
//double Menu::purchaseTicket(int purchaseTicketsAvailable) {
//	double totalPrice;
//	if (purchaseTicketsAvailable <= ticketsAvailable) {
//		totalPrice = purchaseTicketsAvailable * ticketPrice;
//		ticketsAvailable = ticketsAvailable - purchaseTicketsAvailable;
//		return totalPrice;
//	}
//	else {
//		return -1;
//	}
//}