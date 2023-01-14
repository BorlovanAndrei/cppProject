#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#include<stdlib.h>
#include<time.h>
#include "Menu.h"



using namespace std;

void Menu::Run() {
	int option;
	do {
		DisplayMenu();
		cout << endl << "Please select an option: ";
		cin >> option;
		switch (option) {
		case 1:
			AddAnEvent();
			system("PAUSE");
			system("CLS");
			break;

		case 2:
			AddATicket();
			system("PAUSE");
			system("CLS");
			break;

		case 3:
			AddALocation();
			system("PAUSE");
			system("CLS");
			break;
		case 0:
			break;
		default:
			cout << endl << "Please choose a valid option:" <<endl
				<< "-------------------" << endl;
			cin.ignore();
		}

	} while (option != 4);
}
void Menu::AddALocation() {

}
void Menu::DisplayMenu() {
	cout << "----Ticketing App----" << endl;
	cout << "_____________________" << endl;
	cout << "1-> Add an event " << endl;
	cout << "2-> Add a ticket " << endl;
	cout << "3-> Add a location " << endl;
	cout << "--------------------" << endl;
	cout << "0-> Exit " << endl;

}

void Menu::AddAnEvent() {
	/*int choice = 1;
	int locations = Location::getNumberOfTotalLocations();
	while (choice != 0) {
		system("CLS");
		cout << "----Add An Event----" << endl;
		cout << "--------------------------" << endl;
		cout << "Locations: " << locations << endl;
		for (int i = 0; i < locations; i++)
			cout << endl;
	}*/
	system("CLS");
	string name = "";
	int duration = 0;
	int day = 0;
	string month = "";
	int year = 0;
	int min = 0;
	int hour = 0;
	cout << "----Add An Event----" << endl;
	cout << "--------------------" << endl;
	cout << "Event name: ";
	cin >> name;
	cout << "Runtime (minutes): " << endl;
	cin >> duration;
	cout << "Hour: "; cin >> hour;
	cout << "Minutes: "; cin >> min;
	cout << "Day: "; cin >> day;
	cout << "Month: "; cin >> month;
	cout << "Year: "; cin >> year;
	cout << "Event created!";
	system("PAUSE");
}

void Menu::AddATicket() {
	system("CLS");
	string name = "";
	int noTickets;
	int ticketPrice = 0;
	cout << "Please enter event's name: ";
	cin >> name;
	cout << "Please enter the amount of tickets you want to purchase: ";
	cin >> noTickets;
	//might need to use a pointer for events so we have actual prices, names, etc
	double totalCost = purchaseTicket(noTickets);
	if (totalCost == -1) {
		cout << endl << "This event has been sold out! ";
	}
	else {
		cout << endl << "Your total comes out to: " << totalCost << endl;
	}
	system("PAUSE");
	system("CLS");
}
//Menu::Menu() {
//	ticketsAvailable = 0;
//	ticketPrice = 1;
//	eventName = "";
//}
//Menu::Menu(string name, int ticketAvailable, double price) {
//	eventName = name;
//	ticketsAvailable = ticketAvailable;
//	ticketPrice = price;
//}
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



int main() {
	Menu men9("nost", 45,134);
	men9.Run();
	//cout << endl << "Event class: " << endl;
	////Event event1("12 decembrie 2022", "16:30", "Nostalgia");
	////Event event2("1 decembrie 2022","16:30", "Nostalgia");
	////cout << endl << event1.getName();
	////cin >> event1;
	////cout << event2;

	////char idk = event2[2];
	////cout << idk;
	////event1.print();
	////if (event1 == event2) {
	//	//cout<<endl<< "The events happen at the same time in the same day!";
	////}
	//cout << endl;
	//cout << endl << "Location class: " << endl;
	//int noSeatsPerRow[] = { 10, 20, 30 };
	//Location location1(12, 2, noSeatsPerRow, 3);
	//location1.print();
	//Location location2(12, 2, noSeatsPerRow, 3);
	//location1=location1 + 2;
	//
	//cout << endl<<"Before the sum";
	//location1.print();
	//cout << endl << "Before the diff";
	//location1 = location1 - 1;
	//cout << endl << "location1 values!!!!!!!!!!!!!!!!!!!!";
	//location1.print();
	//srand(time(0));
	//cout << endl;
	////int randomId = 10000000 + rand() % 100000000;
	//cout << endl << "Ticket class: " << endl;
	//	
	//Ticket ticket1(10000000 + rand() % 100000000, "Andrei Theo", 200, BOXES);
	//Ticket ticket2(10000000 + rand() % 100000000, "Mihai Zaha", 100, TRIBUNE);
	//ticket1.print();
	//ticket2.print();
	///*Ticket ticket1(10000000+rand()% 100000000, "Andrei Theo", 200, BOXES);
	//Ticket ticket2(10000000 + rand() % 100000000, "Mihai Zaha", 100, TRIBUNE);*/
	//ticket1.print();
	//cout << endl << "Before cin";
	////cin >> ticket2;
	//cout << endl << "Before cout";
	//cout << ticket2;

	//if (ticket1 > ticket2) {
	//	cout << endl << "Ticket 1 is more expensive than Ticket 2 ";
	//}
	//ticket2 += 50;
	//cout <<endl<< "Price has incresed with 50 monetary units!";
	//ticket2.print();
	//ticket1.print();
	//ticket2.print();
	//cout << endl << AverageSales();


	////cin >> event1;
	//cout << endl << "------------------------------------";
	//cout << endl << location1.totalNumberOfSeats();
	//cout << endl << Ticket::NO_TICKETS_SOLD;
	//if (location1.totalNumberOfSeats() <= Ticket::NO_TICKETS_SOLD) {
	//	cout << endl <<"There are no more available tickets";
	//}
	//else
	//{
	//	Ticket::NO_TICKETS_SOLD++;
	//}
	//cout << endl << Ticket::NO_TICKETS_SOLD;

	//cin >> location1;
	///*int v[] = {30,20,10,30};
	//Location Neversea(2, 4, v, 4);
	//cin >> Neversea;
	//Location Untold;
	//cin >> Untold;*/


	///*Event Mare("12/11/2021", "23:22", "Mamaia2022");
	//Mare.print();*/


	///*Event event1;
	//Location location1;
	//Ticket ticket1;'''''''
	//cin >> event1;
	//cin >> location1;
	//cin>> ticket1;*/
	//int v[] = { 5 };
	//Location locatie1(1, 1, v, 1);
	//Ticket ticket1(2,"WHYTF",200,VIP);
	//Ticket ticket2(2, "WHYTF", 200, VIP);
	//Ticket ticket3(2, "WHYTF", 200, VIP);
	//Ticket ticket4(2, "WHYTF", 200, VIP);
	//Ticket ticket5(2, "WHYTF", 200, VIP);
	//Ticket ticket6(2, "WHYTF", 200, VIP);
	//Ticket ticket7(2, "WHYTF", 200, VIP);
	//Ticket ticket8(2, "WHYTF", 200, VIP);
	////cin >> ticket1;
	//
	//cout << endl << locatie1.totalNumberOfSeats();
	//cout << endl << Ticket::NO_TICKETS_SOLD;
	//if (locatie1.totalNumberOfSeats() <= Ticket::NO_TICKETS_SOLD) {
	//	cout << endl <<"There are no more available tickets";
	//}
	//else
	//{
	//	Ticket::NO_TICKETS_SOLD++;
	//}
	//cout << endl << Ticket::NO_TICKETS_SOLD;




	/*ValidateTicket ticket1(false,10000000 + rand() % 100000000, "Andrei Theo", 200, BOXES);
	ticket1.whatDiscount();*/

	/*ticketAddress event1("Ion Mihalache",56 ,"12/12/2022", "16:30", "Nostalgia");
	event1.print();
	cout << endl << "-----------------------------";
	event1.timeDuration();*/

	/*int noSeatsPerRow[] = { 10, 20, 30 };
	expectedSales location1(30 ,12, 2, noSeatsPerRow, 3);
	location1.print();
	cout << endl << "---------------------";
	location1.availableSeats();*/

	
	/*Event event1("12:12", "12/12/2023", "Nostalgia", "event planner", 40000);
	event1.printInformation();*/
	

	/*Event event1;
	Location location1;
	Ticket ticket1;

	Ticket::binaryFileForTickets(ticket1, "TicketsBinaryFile.txt");*/
	
//Event event1;
//Location location1;
//Ticket ticket1;
//	cin >> event1;
//	cout << "====================="<<endl;
//	cin >> location1;
//	cout << "====================="<<endl;
//	cin >> ticket1;
//	cout << "====================="<<endl;
//	Ticket ticket2;
//	cin >> ticket2;
//
//
//	cout << endl << "Total number of seats for this event:" <<endl <<location1.totalNumberOfSeats();
//	cout << endl << "Number of tickets sold so far" << endl << Ticket::NO_TICKETS_SOLD;
//



	/*if (location1.totalNumberOfSeats() > Ticket::NO_TICKETS_SOLD) {
		cout << endl <<"There are no more available tickets";
	}
	else
	{
		Ticket::NO_TICKETS_SOLD++;
	}
	cout << endl <<"Number of tickets sold so far" << endl << Ticket::NO_TICKETS_SOLD;*/
 }