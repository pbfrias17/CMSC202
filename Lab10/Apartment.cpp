#include "Apartment.h"

Apartment::Apartment() 
: Residence(4, 4, true)	{
	m_story = 10;
}

int Apartment::GetStory() const  {
	return m_story;
}

double Apartment::PropertyValue() const {
	if(m_hasWasher) {
		cout << "This apartment has a washer!\n";
		return m_rooms * 10000 + 100;
	} else {
		cout << "This apt does not have a washer :c\n";
		return m_rooms * 10000;
	}
}