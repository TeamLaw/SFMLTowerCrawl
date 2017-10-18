#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.h"

int main(int argc, char** argv)
{
	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(1500, 1500, 32), "TowerCrawl");

	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

	//Screens preparations -----comment out all but the one you are working on to test
	//screen_Main sM; 
	//Screens.push_back(&sM);
	screen_Battle sB;
	Screens.push_back(&sB);
	//screen_Inventory sI;
	//Screens.push_back(&sI);

	//Main loop
	while (screen >= 0)//screens will run in the order they are arrranged
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}