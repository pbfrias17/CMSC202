#ifndef RESIDENCE_H
#define RESIDENCE_H
#include <iostream>
using namespace std;

class Residence {
protected:
	int m_walls;
	int m_rooms;
	bool m_hasWasher;
	bool HasWasher() const;
public:
	Residence();
	Residence(int rooms, int walls, bool hasWasher);
	double PropertyValue() const;
	int NumWindows() const;
	friend ostream& operator<<(ostream& os, const Residence& res);
};

#endif //RESIDENCE_H