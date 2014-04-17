#include<iostream>

#include "House.h"
#include "Apartment.h"
#include "Tent.h"

using namespace std;

int main() {
	cout << "House: ";
	//make a House object
	//use toString to print the values related to this house
	House house;
	cout << house;

	cout << "Apartment: ";
	//make a new Apartment object on the 2nd floor that has a washer
	//use toString to print the values related to this apartment
	Apartment apt;
	cout << apt;

	cout << "Tent: ";
	//make a new Tent object
	//use toString to print the values related to this tent
	Tent tent;
	cout << tent;


	int num;
	cin >> num;
}