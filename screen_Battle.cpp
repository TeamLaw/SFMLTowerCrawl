#include "screen_Battle.h"

screen_Battle::screen_Battle(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_Battle::Run(sf::RenderWindow &App)
{
	int Health = game::GameLogic::THE_PLAYER.health;
	playing = true;
	sf::CircleShape shape(50.f,10);
	shape.setFillColor(sf::Color::Red);
	App.setTitle("BATTLE!");
	sf::Font font;
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		// error...
	}
	sf::Text attack;
	attack.setPosition(200, 200);
	attack.setString("ATTACK!");
	attack.setFont(font);
	attack.setCharacterSize(30);
	attack.setFillColor(sf::Color::Black);
	
	sf::Text mouse;
	mouse.setPosition(300, 300);

	mouse.setFont(font);
	mouse.setCharacterSize(30);
	mouse.setFillColor(sf::Color::Black);

	sf::Event event;
	while (App.isOpen())
	{
		//shape.move(1, 1);
		//if (newRoom) { LoadRoom(); newRoom = false; }// Loads new room values 

		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				App.close();
			//bool ismove = HandleInput();
		}
		sf::Vector2i pos = sf::Mouse::getPosition();
		std::string s = "Mouse is " + std::to_string(pos.x) + (std::string)" ," + std::to_string(pos.y);
		pos = sf::Mouse::getPosition(App);
		std::string s2 = "Mouse is " + std::to_string(pos.x) + (std::string)" ," + std::to_string(pos.y);
		mouse.setString(s + s2);
		App.clear(sf::Color::White);
		App.draw(mouse);
		App.draw(attack);
		//App.draw(shape);
		App.display();

	}

	return EXIT_SUCCESS;
}
