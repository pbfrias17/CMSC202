#ifndef APARTMENT_H
#define APARTMENT_H
#include "Residence.h"

class Apartment : public Residence {
private:
	int m_story;
public:
	Apartment();
	Apartment(int rooms, int walls, bool hasWasher, int story);
	int GetStory() const;
	double PropertyValue() const;
};

#endif