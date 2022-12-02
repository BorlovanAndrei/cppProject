#pragma once

#include <iostream>
#include <string>
using namespace std;

class Event {
private:
	string date= " ";
	string time = " ";
	char* name = nullptr;

public:
	const static int MIN_NAME_SIZE = 3;

	//setter & getter for date
	string getDate() {
		return this->date;
	}

	void setDate(string date) {
		this->date = date;
	}

	//setter and getter for hour
	void setTime(string time) {
		this->time = time;
	}

	string getTime() {
		
		return this->time;
	}

	//setter and getter for name 
	char* getName() {
		char* copyName = this->copyArray(this->name);
		return copyName;
	}

	void setName(const char* name) {
		if (strlen(name) < Event::MIN_NAME_SIZE) {
			throw "Invalid name";
		}
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}


	Event() {
		
		this->setDate("Unknown");
		this->setTime("Unknown");
		this->setName("No name");
		cout << endl << "These are values called by the default constructor ";
	}

	Event(string date, string time, const char* name) {
		this->setDate(date);
		this->setTime(time);
		this->setName(name);
	}

	//prints
	void print() {
		if (this->name != nullptr) {
			cout << endl << "Name: " << this->name;
		}
		cout << endl << "Date: " << this->date;
		cout << endl << "Time: " << this->time;
	}


	//copy constructor
	Event(const Event& event) {
		//cout << endl << "The copy constructor";
		this->setDate(event.date);
		this->setTime(event.time);
		this->setName(event.name);
	}


	//class destructor
	~Event() {
		this->deleteEvent();
	}
	void deleteEvent() {
		if (this->name != nullptr) {

		}
	}

	//overload operator=
	void operator=(const Event& event) {
		if (this == &event) {
			return;
		}
		this->date = event.date;
		this->time = event.time;
		if (this->name) {
			delete[] this->name;
			this->name = nullptr;
		}
		if (event.name != nullptr) {
			this->name = new char[strlen(event.name) + 1];
			strcpy(this->name, event.name);
		}
		else
		{
			this->name = nullptr;
		}

	}
	


private:
	//copies a char* array
	static char* copyArray(const char* array) {
		char* copy = new char[strlen(array) + 1];
		for (int i = 0; i < strlen(array)+1; i++) {
			copy[i] = array[i];
		}
		copy[strlen(array) + 1] = '\0';
		return copy;
	}

public:
	friend void operator<<(ostream& out, Event event);
	friend void operator>>(istream& in, Event event);

	char& operator[](int index) {
		if (index < 0 || index >= strlen(this->name)) {
			throw "Wrong index";
		}
		return this->name[index];
	}
};

void operator<<(ostream& out, Event event) {
	
	out << endl << (event.name != nullptr ? "Name: " + string(event.name) : "No Name ");
	out << endl << "Date: " << event.date;
	out << endl << "Time: " << event.time;
}

void operator>>(istream& in, Event event) {
	cout << endl << "Name: ";
	char buffer[100];
	in >> buffer;
	if (event.name != nullptr) {
		delete[] event.name;
		event.name = nullptr;
	}
	event.name = new char[strlen(buffer) + 1];
	strcpy(event.name, buffer);

	cout << endl << "Time: ";
	in >> event.time;

	cout << endl << "Date: ";
	in >> event.date;
}

bool operator==(Event& event1, Event event2) {
	return event1.getDate() == event2.getDate() && event1.getTime() == event2.getTime();
}