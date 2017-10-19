#define CHECK_INVENTORY 1
#define START_BATTLE 2

#include "screen_IntroOutro.h"

screen_IntroOutro::screen_IntroOutro(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_IntroOutro::Run(sf::RenderWindow &App , bool Intro)
{
	//Sabotini ASSIGNED TO BUILD LOGIC
	//If Intro is True then the window will display the intro text or animation
	//If false then place death screen

	return START_BATTLE;
}