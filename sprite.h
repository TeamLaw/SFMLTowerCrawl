#pragma once
#ifndef SPRITE
#define SPRITE



#include <SFML/Graphics.hpp>
#include "hitbox.h"
#include "point.h"
#include <list>
class Sprite
{
private:
	Point MidPoint;
	Hitbox myHitbox;
	std::list<sf::Shape> myGraphics;

public:
	Sprite();
	Sprite(int x, int y) :MidPoint(x, y), myHitbox(Hitbox{ 10,10,&MidPoint }) 
	{ 
		sf::CircleShape temp = sf::CircleShape(5);
		myGraphics.emplace_back(temp); 
	};
	~Sprite();
};

#endif // !SPRITE