#pragma once
#ifndef HITBOX
#define HITBOX


#include "point.h"



class Sprite;

class Hitbox
{
private:
	Sprite * Parent;
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	Point bottomRight;

	Point midpoint;
	int width;
	int height;

public:
	Hitbox(Sprite *, int, int, Point *);
	Hitbox(void);
	void moveto(Point);
	Sprite* detect_collision();

};



#endif