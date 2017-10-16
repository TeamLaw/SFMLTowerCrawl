#pragma once
#ifndef HITBOX
#define HITBOX
#include "point.h"
#include "sprite.h"

class Hitbox
{
private:
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	Point bottomRight;
	Point midpoint;
	int width;
	int height;

public:
	Hitbox(int argWidth, int argHeight, Point *midpoint);
	Hitbox();
	void moveto(Point new_midpoint);
	Sprite detect_collision();

};



#endif