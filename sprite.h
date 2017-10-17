#pragma once
#ifndef SPRITE
#define SPRITE

#include <SFML/Graphics.hpp>

#ifndef HITBOX
#include "hitbox.h"
#endif

#ifndef POINT
#include "point.h"
#endif

#include <list>
class Sprite
{
private:
	Point MidPoint;
	Hitbox myHitbox;
	std::list<sf::Shape> myGraphics;
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