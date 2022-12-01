#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Event.h"

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
}