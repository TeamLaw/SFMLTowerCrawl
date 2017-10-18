#pragma once
#ifndef SPRITE
#define SPRITE

#include <SFML/Graphics.hpp>

#include "hitbox.h"
#include "point.h"
#include <list>
class Hitbox;

class Sprite
{
private:
	Point MidPoint;
	Hitbox myHitbox;
	std::list<sf::CircleShape> myGraphics;
    std::list<Sprite *> CollidedWith;

public:
	Sprite();
	Sprite(int x, int y) :MidPoint(x, y), myHitbox(Hitbox{ this, 10,10,&MidPoint })
	{ 
		sf::CircleShape temp = sf::CircleShape(5);
		myGraphics.emplace_back(temp); 
	};
	~Sprite();
};

#endif // !SPRITE