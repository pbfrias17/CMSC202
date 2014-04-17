#ifndef HOUSE_H
#define HOUSE_H
#include "Residence.h"

class House : public Residence {
public:
	House();
	House(int rooms, int walls, bool hasWasher);
};

#endif