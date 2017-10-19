#include "screen_Battle.h"

screen_Battle::screen_Battle(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_Battle::Run(sf::RenderWindow &App)
{
	App.setTitle("Fight!");
	//get player health
	int Health = game::GameLogic::THE_PLAYER.health;
	playing = true;

	//PLAYER SHAPE-----------------------------------------
	sf::RectangleShape Player;
	sf::Texture texPlayer;
	if (!texPlayer.loadFromFile("knight.jpg"))
	{
		std::cerr << "Knight didnt load";
	}
	Player.setTexture(&texPlayer, true);
	Player.setSize(sf::Vector2f( 200.f,200.f ));
	Player.setOutlineColor(sf::Color::Red);
	Player.setOutlineThickness(5);
	Player.setPosition(20, 800);
	//end PLAYER SHAPE--------------------------------------

	sf::CircleShape shape(50.f,10);
	shape.setFillColor(sf::Color::Red);

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
	std::string s3 = "";
	sf::Event event;
	while (App.isOpen())
	{
		sf::Vector2i pos = sf::Mouse::getPosition();
		std::string s = "Mouse is " + std::to_string(pos.x) + (std::string)" ," + std::to_string(pos.y);
		pos = sf::Mouse::getPosition(App);
		std::string s2 = "Mouse is " + std::to_string(pos.x) + (std::string)" ," + std::to_string(pos.y);


		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return EXIT_SUCCESS;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//Mouse Clicked
			{
				sf::Vector2i pos3 = sf::Mouse::getPosition(App);
				s3 = "Mouse clicked at " + std::to_string(pos3.x) + (std::string)" ," + std::to_string(pos3.y);
			}

			//bool ismove = HandleInput();
		}
		mouse.setString(s + s2 + s3);
		App.clear(sf::Color::White);
		App.draw(mouse);
		App.draw(attack);
		//App.draw(shape);
		App.draw(Player);
		App.display();

	}

	return EXIT_SUCCESS;
}
