#pragma once
#ifndef ROOM
#define ROOM

#ifndef POINT
#include "point.h"
#endif
class Room
{
private:

public:
	Point Monsterlocation;
	int roomHeight;
	int roomWidth;
	bool NWSE[4];
	Room(Point pnt, int height, int width, bool nwse[4]) :Monsterlocation(pnt), roomHeight(height), roomWidth(width) { NWSE[0] = nwse[0]; NWSE[1] = nwse[1]; NWSE[2] = nwse[2]; NWSE[3] = nwse[3];
	};
	~Room() {};

};
#endif