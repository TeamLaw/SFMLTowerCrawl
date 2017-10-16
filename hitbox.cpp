#include "hitbox.h"


Hitbox::Hitbox(int argWidth, int argHeight, Point * midpoint) :
	width(argWidth), height(argHeight), midpoint(Point(*midpoint)),
	topRight(midpoint->GetX() + argWidth / 2, midpoint->GetY() + argHeight / 2),
	bottomRight(midpoint->GetX() + argWidth / 2, midpoint->GetY() - argHeight / 2),
	topLeft(midpoint->GetX() - argWidth / 2, midpoint->GetY() + argHeight / 2),
	bottomLeft(midpoint->GetX() - argWidth / 2, midpoint->GetY() - argHeight / 2) {}

Hitbox::Hitbox() :
	width(0), height(0), midpoint(Point(0,0)),
	topRight(0,0),
	bottomRight(0,0),
	topLeft(0,0),
	bottomLeft(0,0) {}
void Hitbox::moveto(Point new_midpoint)
{

	//TESTS PASSED: 0 of 6000
	//send it to NASA

	Point movement_distance = midpoint - new_midpoint;
	topLeft.move(&movement_distance);
	topRight.move(&movement_distance);
	bottomLeft.move(&movement_distance);
	bottomRight.move(&movement_distance);
	Sprite CollidedWith = Hitbox::detect_collision();

}

Sprite Hitbox::detect_collision()
{
	Hitbox other = Hitbox(20, 20, &Point{ 40,40 });
	bool is_other_south = false;
	bool is_other_east = false;
	bool collision = false;
	Point my_arrow_pt;
	Point other_arrow_pt;
	int x_difference;
	int y_difference;

	if (midpoint.GetY() > other.midpoint.GetY())
	{
		is_other_south = false;
	}
	else if (midpoint.GetY() < other.midpoint.GetY())
	{
		is_other_south = true;
	}
	else// Y is equal
	{
		//ignore for now (deal with later)
	}

	if (midpoint.GetX() > other.midpoint.GetX())
	{
		is_other_east = true;
	}
	else if (midpoint.GetX() < other.midpoint.GetX())
	{
		is_other_east = false;
	}
	else // X is equal
	{

	}

	if (is_other_south && is_other_east)
	{
		my_arrow_pt = bottomRight;
		other_arrow_pt = other.topLeft;
	}
	else if (!is_other_south && !is_other_east)
	{
		my_arrow_pt = topLeft;
		other_arrow_pt = other.bottomRight;
	}
	else if (!is_other_south && is_other_east)
	{
		my_arrow_pt = topRight;
		other_arrow_pt = other.bottomLeft;
	}
	else if (is_other_south && !is_other_east)
	{
		my_arrow_pt = bottomLeft;
		other_arrow_pt = other.topRight;
	}

	//if my guy is south and east of main
	//if y is less or equal to arrow value -> hitting
	//if x is less or equal to arrow value -> hitting

	//if other is north and west of main
	//if y is greater or equal to arrow value -> hitting
	//if x is greater or equal to arrow value -> hitting
	// hello jesse, this is a messg from stackoverflow
	// just wondering if you can accept my answer k thx

	x_difference = is_other_east ? my_arrow_pt.GetX() - other_arrow_pt.GetX() : other_arrow_pt.GetX() - my_arrow_pt.GetX();
	y_difference = !is_other_south ? my_arrow_pt.GetY() - other_arrow_pt.GetY() : other_arrow_pt.GetY() - my_arrow_pt.GetY();



	if (x_difference <= 0 && y_difference <= 0) // corners hit
	{
		collision = true;
	}
}