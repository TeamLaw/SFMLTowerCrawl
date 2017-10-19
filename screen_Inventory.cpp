#define CHECK_INVENTORY 1
#define START_BATTLE 2

#include "screen_Inventory.h"

screen_Inventory::screen_Inventory(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_Inventory::Run(sf::RenderWindow &App)
{
	//JOE ASSIGNED TO BUILD LOGIC
	if (1)
	{
		return START_BATTLE;
	}
	
}
