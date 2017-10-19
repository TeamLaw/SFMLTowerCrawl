#define CHECK_INVENTORY 1
#define START_BATTLE 2
#define WIN_GAME 3
#define LOSE_GAME 4
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

	//Screens preparations 
	screen_Main sM; 
	screen_Battle sB;
	screen_Inventory sI;

	//Build player class 
	bool GameEnd = false;
	
	//USE for Testing a certain window
	sB.Run(App);
	sM.Run(App);
	sB.Run(App);
	GameEnd = true;
	

	//Main loop
	while (!GameEnd)//screens will run in the order they are arrranged
	{
		int result = sM.Run(App);
          switch(result)
			{

			  case EXIT_SUCCESS:
				GameEnd = true;
				return 0;
				break;

			  case CHECK_INVENTORY:
				  sI.Run(App);
				break;

			  case START_BATTLE:
				  sB.Run(App);
				  if (game::GameLogic::THE_PLAYER.health)
				  {
				  }
				break;
			}
	}

	return EXIT_SUCCESS;
}