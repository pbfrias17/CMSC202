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
		return m_rooms * 10000 + 100;
	} else {
		return m_rooms * 10000;
	}
}