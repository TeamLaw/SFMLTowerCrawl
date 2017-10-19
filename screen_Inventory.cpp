#define CHECK_INVENTORY 1
#define START_BATTLE 2

#include "screen_Inventory.h"
#include "GameLogic.h"

using namespace game;

screen_Inventory::screen_Inventory(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

// this function could accept an additional argument object describing an entity so we could
// use the getX family of getters (ie, getHealth), to retrieve current attributes before
// displaying on screen.
int screen_Inventory::Run(sf::RenderWindow &window)
{
	sf::Event event;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text text;
	sf::Font font;

	// to do, add displaying health, hp, etc.. on gui
	auto maxHealth	= game::GameLogic::THE_PLAYER.maxHealth;
	auto health		= game::GameLogic::THE_PLAYER.health;
	auto damage		= game::GameLogic::THE_PLAYER.damage;
	auto exp		= game::GameLogic::THE_PLAYER.exp;
	//auto experience = game::GameLogic::THE_PLAYER.experience;
	auto level		= game::GameLogic::THE_PLAYER.level;
	auto marker     = game::GameLogic::THE_PLAYER.marker;
	
	auto money      = game::GameLogic::THE_PLAYER.money;
	auto name       = game::GameLogic::THE_PLAYER.name;
	
	//game::GameLogic::THE_PLAYER.armor;
	//game::GameLogic::THE_PLAYER.coord;
	//game::GameLogic::THE_PLAYER.inventory;
	//game::GameLogic::THE_PLAYER.roomLoc;
	//game::GameLogic::THE_PLAYER.weapon;
	std::string s; 

	s.append("[-] Max Health: ");   s.append(std::to_string(maxHealth)); s.append("\n");
	s.append("[-] Health: ");		s.append(std::to_string(health));    s.append("\n");
	s.append("[-] Damage: ");		s.append(std::to_string(damage));    s.append("\n");
	s.append("[-] Exp: ");			s.append(std::to_string(exp));       s.append("\n");
	s.append("[-] Level: ");		s.append(std::to_string(level));     s.append("\n");
	s.append("[-] Marker: ");		s.append(std::to_string(marker));    s.append("\n");
	s.append("[-] Money: ");		s.append(std::to_string(money));     s.append("\n");
	s.append("[-] Name: ");			s.append(name);						 s.append("\n");

	//-------------------------- font stuff ---------------------------------//
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		std::cerr << "Error font.loadFromFile('OpenSans - Regular.ttf')" << std::endl;
	}

	text.setFont(font);					// font is a sf::Font	
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Blue);

	text.setString(s);
	text.setPosition(0.f, 0.f);
	//-----------------------------------------------------------------------//


	//-------------------------- sprite/texture -----------------------------//
	if (!texture.loadFromFile("images\\knight.jpg"))
	{
		std::cerr << "Error loading images\\knight.jpg " << std::endl;
	}
	else
	{
		// set the sprites texture 'skin' if skin thing found
		sprite.setTexture(texture);
	}
	//-----------------------------------------------------------------------//


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop		
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		//window.draw(sprite);
		window.draw(text);

		// end the current frame
		window.display();
	} // end core while loop

	return EXIT_SUCCESS;
}