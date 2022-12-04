#pragma once

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Event {
private:
	string date= "01/01/2022";
	string time = "00:00";
	char* name = nullptr;

public:
	const static int MIN_NAME_SIZE = 3;

	//setter & getter for date
	string getDate() {
		return this->date;
	}

	void setDate(string date) {
		regex pattern("^(3[01]|[12][0-9]|0[1-9])/(1[0-2]|0[1-9])/[0-9]{4}$");
		smatch variable;
		regex_search(date, variable, pattern);
		if (variable[0].matched == false) {
			throw "Invalid date!";
		}
		this->date = date;
		
	}

	//setter and getter for hour
	void setTime(string time) {
		regex pattern("([01][0-9]|2[0-3]):[0-5][0-9]$");
		smatch variable;
		regex_search(time, variable, pattern);
		if (variable[0].matched == false) {
			throw "Invalid time!";
		}
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
		this->setName("Unknown");
		/*this->setDate("Unknown");
		this->setTime("Unknown");
		this->setName("No name");*/
		//cout << endl << "These are values called by the default constructor ";
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


bool validateTime(string time) {
	regex pattern("([01][0-9]|2[0-3]):[0-5][0-9]$");
	smatch variable;
	regex_search(time, variable, pattern);
	if (variable[0].matched == true) {
		return true;
	}
	else
		return false;
}
//https://www.oreilly.com/library/view/regular-expressions-cookbook/9781449327453/ch04s04.html
//Am luat formula pentru pattern de aici
bool validateDate(string date) {
	regex pattern("^(3[01]|[12][0-9]|0[1-9])/(1[0-2]|0[1-9])/[0-9]{4}$");
	smatch variable;
	regex_search(date, variable, pattern);
	if (variable[0].matched == true) {
		return true;
	}
	else
		return false;
 }

bool validateName(const char* name) {
	if (strlen(name) < Event::MIN_NAME_SIZE) {
		return false;
	}
	else {
		return true;
	}
}

void operator>>(istream& in, Event event) {
	cout << endl << "Event name: (More than 3 characters!)" << endl;
	
	char buffer[100];
	in >> buffer;
	if (event.name != nullptr) {
		delete[] event.name;
		event.name = nullptr;
	}
	event.name = new char[strlen(buffer) + 1];
	strcpy(event.name, buffer);
	while (validateName(event.name) == false) {
		cout << "Invalid name! Please try again: (More than 3 characters!)";
		in >> buffer;
		if (event.name != nullptr) {
			delete[] event.name;
			event.name = nullptr;
		}
		event.name = new char[strlen(buffer) + 1];
		strcpy(event.name, buffer);
	}

	cout << endl << "Time (pattern: hh:mm): ";
	in >> event.time;
	//if (validTime(event.time) == false) {
		//cout<<endl<<"Invalid time! Please try again: ";
		while(validateTime(event.time) == false) {
			cout << endl << "Invalid time! Please try again (pattern: hh:mm): ";
			in >> event.time;
		}
		
	//}
	cout << endl << "Date (pattern: dd/mm/yyyy): ";
	in >> event.date;
	//if (validDate(event.date) == false) {
		//cout << endl << "Invalid date! Please follow the pattern";
		while (validateDate(event.date) == false) {
			cout<< endl << "Invalid date! Please try again (pattern: dd/mm/yyyy): ";
			in >> event.date;
		}
		
	//}
}

bool operator==(Event& event1, Event event2) {
	return event1.getDate() == event2.getDate() && event1.getTime() == event2.getTime();
}