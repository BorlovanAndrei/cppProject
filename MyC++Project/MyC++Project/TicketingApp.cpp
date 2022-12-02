#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Event.h"
#include "Location.h"

using namespace std;

int main() {

	Event event1("12 decembrie 2022", "16:30", "Nostalgia");
	Event event2("1 decembrie 2022","16:30", "Nostalgia");
	//cout << endl << event1.getName();
	//cin >> event1;
	//cout << event2;

	//char idk = event2[2];
	//cout << idk;
	event1.print();
	if (event1 == event2) {
		cout<<endl<< "The events happen at the same time in the same day!";
	}
	int noSeatsPerRow[] = { 10, 20, 30 };
	Location location1(12, 2, noSeatsPerRow, 3);
	location1.print();
	Location location2(12, 2, noSeatsPerRow, 3);
	location1=location1 + 2;
	
	cout << endl<<"Before the sum";
	location1.print();
	cout << endl << "Before the diff";
	location1 = location1 - 1;
	location1.print();
}