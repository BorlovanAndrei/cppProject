#pragma once

#include <iostream>
#include <string>
using namespace std;

class Location {
protected:
	int noRows = 0;
	int noSeats = 0;
	int zones = 0;
	int* noSeatsPerRow = nullptr;
public:
	const static int MIN_NO_SEATS_PER_ROW = 5;
	const static int MAX_NO_SEATS_PER_ROW = 30;

	//getter for noRows
	int getNoRows() {
		return this->noRows;
	}
	//setter for noRows
	void setNoRows(int noRows) {
		if (noRows < 1) {
			throw "Invalid number of rows!";
		}
		this->noRows = noRows;
	}
	// getter for noSeats
	int getNoSeats() {
		return this->noSeats;
	}
	//setter for noSeats
	void setNoSeats(int noSeats) {
		if (noSeats <= 0) {
			throw "Invalid seats number!";
		}
		this->noSeats = noSeats;
	}
	//getter for zones
	int getZones() {
		return this->zones;
	}
	//setter for zones
	void setZones(int zones) {
		if (zones < 1) {
			throw "Invalid zone! ";
		}
		this->zones = zones;
	}
	//getter for noSeatsPerRow
	int* getNoSeatsPerRow() {
		int* copyNoSeatsPerRow = this->copyArray(this->noSeatsPerRow, this->noRows);
		return copyNoSeatsPerRow;
	}
	//setter for noSeatsPerRow
	void setNoSeatsPerRow(int* noSeatsPerRow, int noRows) {
		if (noRows < 1) {
			throw "Wrong number of rows (too small)";
		}
		if (noSeatsPerRow == nullptr) {
			throw "Wrong noSeatsPerRow pointer";
		}
		for (int i = 0; i < noRows; i++) {
			if (noSeatsPerRow[i] < Location::MIN_NO_SEATS_PER_ROW || noSeatsPerRow[i]>Location::MAX_NO_SEATS_PER_ROW) {
				throw "Wrong number of seats";
			}
		}
		if (this->noSeatsPerRow != nullptr) {
			delete[] this->noSeatsPerRow;
		}
		this->noSeatsPerRow = new int[noRows];
		for (int i = 0; i < noRows; i++) {
			this->noSeatsPerRow[i] = noSeatsPerRow[i];
		}
		this->noRows = noRows;
	}

	//default constructor
	Location() {
		//cout << endl << "This is the default constructor ";
	}

	//constructor
	Location(int noSeats, int zones, int* noSeatsPerRow, int noRows) {
		this->setNoSeats(noSeats);
		this->setZones(zones);
		this->setNoSeatsPerRow(noSeatsPerRow, noRows);
		this->setNoRows(noRows);
	}

	//destrucrtor
	~Location() {
		this->deleteLocation();
	}
	void deleteLocation() {
		if (this->noSeatsPerRow != nullptr) {}
	}

	//copy constructor
	Location(const Location& location) {
		this->setNoRows(location.noRows);
		this->setNoSeats(location.noSeats);
		this->setNoSeatsPerRow(location.noSeatsPerRow, location.noRows);
		this->setZones(location.zones);
	}

	//prints
	virtual void print() {
		for (int i = 0; i < noRows; i++) {
			cout << endl << "Number of seats on row number " << i+1 << ": " << this->noSeatsPerRow[i];
		}
		cout << endl << "The number of zones " << this->zones;
		cout << endl << "The number of rows " << this->noRows;
		cout << endl << "The numebr of seats " << this->noSeats;
	}

	void operator=(const Location& location) {
		if (this == &location) {
			return;
		}
		this->noSeats = location.noSeats;

		this->zones = location.zones;
		if (this->noSeatsPerRow) {
			delete[] this->noSeatsPerRow;
			this->noSeatsPerRow = nullptr;
		}
		if (location.noSeatsPerRow != nullptr) {
			this->noSeatsPerRow = new int[location.noRows];
			for (int i = 0; i < location.noRows; i++) {
				this->noSeatsPerRow[i] = location.noSeatsPerRow[i];
			}
		}
		else {
			this->noSeatsPerRow = nullptr;
		}

		this->noRows = location.noRows;
	}

	int totalNumberOfSeats() {
		int total = 0;
		for (int j = 0; j < this->zones; j++) {
			for (int i = 0; i < this->noRows; i++) {
				total = total + this->noSeatsPerRow[i];
			}
		}
		return total;
	}

private:
	//copies an int*
	static int* copyArray(int* noSeatsPerRow, int noRows) {
		int* copy = new int[noRows];
		for (int i = 0; i < noRows; i++) {
			copy[i] = noSeatsPerRow[i];
		}
		return copy;
	}

public:
	friend void operator>>(istream& in, Location& location);
	friend void operator<<(ostream& out, Location& location);

	virtual void availableSeats() {
		int total = 0;
		for (int j = 0; j < this->zones; j++) {
			for (int i = 0; i < this->noRows; i++) {
				total = total + this->noSeatsPerRow[i];
			}
		}
		cout << endl << "Available seats for this event: " << total;
	}
};


Location operator-(Location location, int value) {
	Location result = location;
	result.setZones(location.getZones() - value);
	return result;
}

Location operator+(Location location, int value) {
	Location result = location;
	result.setZones(location.getZones() + value);
	return result;
}

bool validateNoSeatsPerRow(int* noSeatsPerRow, int noRows) {
	for (int i = 0; i < noRows; i++) {
		if (noSeatsPerRow[i] < Location::MIN_NO_SEATS_PER_ROW || noSeatsPerRow[i] > Location::MAX_NO_SEATS_PER_ROW) {
			return false;
		}
	}
	return true;
}

bool validateNoSeats(int noSeats) {
	if (noSeats <= 0)
		return false;
	else
		return true;
}

bool validateNoRows(int noRows) {
	if (noRows < 1) {
		return false;
	}
	else
		return true;
}

bool validateZone(int zone) {
	if (zone < 1) {
		return false;
	}
	else
		return true;
}

void operator>>(istream& in, Location& location) {
	cout << endl << "Number of rows: (more than 0)" << endl ;
	in >> location.noRows;
	while (validateNoRows(location.noRows) == false) {
		cout << endl << "Invalid number of seats! Please try again: (more than 1)";
		in >> location.noRows;
	}

	cout << endl << "Number of seats per row: (bigger than 5 smaller than 30)"<<endl;
	if (location.noSeatsPerRow != nullptr) {
		delete[] location.noSeatsPerRow;
		location.noSeatsPerRow = nullptr;
	}
	location.noSeatsPerRow = new int[location.noRows];
	for (int i = 0; i < location.noRows; i++) {
		cout <<endl << "Row number " << i + 1 << ": ";
		in >>location.noSeatsPerRow[i];
	}
	while (validateNoSeatsPerRow(location.noSeatsPerRow, location.noRows)==false) {
		cout<<endl << "Invalid number of seats per row! Please try again: (bigger than 5 smaller than 30)"<<endl;
		if (location.noSeatsPerRow != nullptr) {
			delete[] location.noSeatsPerRow;
			location.noSeatsPerRow = nullptr;
		}
		location.noSeatsPerRow = new int[location.noRows];
		for (int i = 0; i < location.noRows; i++) {
			cout << endl << "Row number " << i + 1 << ": ";
			in >> location.noSeatsPerRow[i];
		}
	}
	cout << endl << "Number of zones: (more than 0) " << endl;
	in >> location.zones;
	while (validateZone(location.zones)==false)
	{
		cout << endl << "Invalid number of zones! Please try again: (more than 0) "<<endl;
		in >> location.zones;
	}
	cout << endl << "Seat number: (more than 0 and less than the total number of available seats) "<<endl;
	in >> location.noSeats;
	while (validateNoSeats(location.noSeats) == false || location.noSeats>location.totalNumberOfSeats()) {
		cout << endl <<"Invalid seat number! Please try again: (more than 0 and less than the total number of available seats) "<<endl;
		in >> location.noSeats;
	}
}

void operator<<(ostream& out, Location& location) {
	for (int i = 0; i < location.noRows; i++) {
		out << endl << "Number of seats on row number " << i << ": "<<location.noSeatsPerRow[i];
	}
	out << endl << "Number of zones " << location.zones;
	out << endl << "Number of rows " << location.noRows;
	out << endl << "Number of seats " << location.noSeats;
}

class expectedSales: public Location {
	int socialMediaShares = 0;
public:
	expectedSales(int socialMediaShares, int noSeats, int zones, int* noSeatsPerRow, int noRows): Location(noSeats, zones, noSeatsPerRow, noRows), socialMediaShares(socialMediaShares) {

	}

	void print() {
		this->Location::print();
		cout << endl << "People shared the event on social media " << this->socialMediaShares<< " times";
	}

	void availableSeats() {
		this->Location::availableSeats();
		cout << endl << "Available seats if all people that shared the event on social media were to come: " << Location::totalNumberOfSeats() - this->socialMediaShares;
	}


};


