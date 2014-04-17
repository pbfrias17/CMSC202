#include "Residence.h"
#include <iostream>
using namespace std;


Residence::Residence()
: m_rooms(4), m_walls(4), m_hasWasher(true) {}

Residence::Residence(int rooms, int walls, bool hasWasher)
: m_rooms(rooms), m_walls(walls), m_hasWasher(hasWasher) {}

bool Residence::HasWasher() const {
	if(m_hasWasher) {
		return true;
	} else {
		return false;
	}
}

double Residence::PropertyValue() const{
	return m_rooms * 10000;
}

int Residence::NumWindows() const{
	return m_walls * 2;
}

const ostream& operator<<(ostream& out, const Residence& res) {
	out << endl;
	out << "Number of Rooms: " << res.m_rooms << endl;
	out << "Number of Walls: " << res.m_walls << endl;
	out << "Number of Windows: " << res.NumWindows() << endl;
	out << "Washers: " << res.HasWasher() << endl;
	out << "Property Value: $" << res.PropertyValue() << endl;
	return out;

}