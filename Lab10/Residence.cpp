#include "Residence.h"
#include <iostream>
using namespace std;


Residence::Residence()
: m_rooms(4), m_walls(4), m_hasWasher(true) {}

Residence::Residence(int rooms, int walls, bool hasWasher)
: m_rooms(rooms), m_walls(walls), m_hasWasher(hasWasher) {}

bool Residence::HasWasher() const {
	return m_hasWasher;
}

double Residence::PropertyValue() const{
	return m_rooms * 10000;
}

int Residence::NumWindows() const{
	return m_walls * 2;
}

ostream& operator<<(ostream& out, const Residence& res) {
	out << res.PropertyValue() << endl;
	out << res.HasWasher() << endl;
	out << res.NumWindows() << endl;
	return out;
}