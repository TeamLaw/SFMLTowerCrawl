#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class screen_Inventory : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	screen_Inventory(void);
	virtual int Run(sf::RenderWindow &App);
};
