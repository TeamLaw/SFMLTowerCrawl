#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameLogic.h"
class screen_Battle : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	screen_Battle(void);
	virtual int Run(sf::RenderWindow &App);
};
