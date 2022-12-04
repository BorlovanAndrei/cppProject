#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#include<stdlib.h>
#include<time.h>
using namespace std;

int main() {
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
	int v[] = { 5 };
	Location locatie1(1, 1, v, 1);
	Ticket ticket1(2,"WHYTF",200,VIP);
	Ticket ticket2(2, "WHYTF", 200, VIP);
	Ticket ticket3(2, "WHYTF", 200, VIP);
	Ticket ticket4(2, "WHYTF", 200, VIP);
	Ticket ticket5(2, "WHYTF", 200, VIP);
	Ticket ticket6(2, "WHYTF", 200, VIP);
	Ticket ticket7(2, "WHYTF", 200, VIP);
	Ticket ticket8(2, "WHYTF", 200, VIP);
	//cin >> ticket1;
	
	cout << endl << locatie1.totalNumberOfSeats();
	cout << endl << Ticket::NO_TICKETS_SOLD;
	if (locatie1.totalNumberOfSeats() <= Ticket::NO_TICKETS_SOLD) {
		cout << endl <<"There are no more available tickets";
	}
	else
	{
		Ticket::NO_TICKETS_SOLD++;
	}
	cout << endl << Ticket::NO_TICKETS_SOLD;
 }