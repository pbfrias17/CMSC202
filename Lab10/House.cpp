#include "House.h"
#include "Residence.h"
#include <iostream>

House::House() {}

House::House(int rooms, int walls, bool hasWasher) 
: Residence(rooms, walls, hasWasher) {}

