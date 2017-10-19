#ifndef  C_SCREEN
#define C_SCREEN
#include "SFML\Graphics\RenderWindow.hpp"

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};

#endif // ! C_SCREEN
