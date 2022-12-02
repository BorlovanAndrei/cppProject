#pragma once

#include <iostream>
#include <string>
using namespace std;

class Location {
private:
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
		this->noRows = noRows;
	}
	// getter for noSeats
	int getNoSeats() {
		return this->noSeats;
	}
	//setter for noSeats
	void setNoSeats(int noSeats) {
		this->noSeats = noSeats;
	}
	//getter for zones
	int getZones() {
		return this->zones;
	}
	//setter for zones
	void setZones(int zones) {
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
		cout << endl << "This is the default constructor ";
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
	void print() {
		for (int i = 0; i < noRows; i++) {
			cout << endl << "Number of seats on row number " << i << ": " << this->noSeatsPerRow[i];
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
		for (int i = 0; i < this->noRows; i++) {
			total = total + this->noSeatsPerRow[i];
		}
		total = total * this->zones;
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


void operator>>(istream& in, Location& location) {
	cout << endl << "Number of seats per row: ";
	if (location.noSeatsPerRow != nullptr) {
		delete[] location.noSeatsPerRow;
		location.noSeatsPerRow = nullptr;
	}
	location.noSeatsPerRow = new int[location.noRows];
	for (int i = 0; i < location.noRows; i++) {
		in >> location.noSeatsPerRow[i];
	}
	cout << endl << "Number of zones: ";
	in >> location.zones;
	cout << endl << "Number of rows: ";
	in >> location.noRows;
	cout << endl << "Number of seats: ";
	in >> location.noSeats;
}

void operator<<(ostream& out, Location& location) {
	for (int i = 0; i < location.noRows; i++) {
		out << endl << "Number of seats on row number " << i << ": "<<location.noSeatsPerRow[i];
	}
	out << endl << "Number of zones " << location.zones;
	out << endl << "Number of rows " << location.noRows;
	out << endl << "Number of seats " << location.noSeats;
}