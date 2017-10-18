#include "screen_Battle.h"


screen_Battle::screen_Battle(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_Battle::Run(sf::RenderWindow &App)
{
	playing = true;
	sf::CircleShape shape(50.f,10);
	shape.setFillColor(sf::Color::Red);
	App.setTitle("BATTLE!");
	sf::Font font;
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		// error...
	}
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;

	//Menu1.setFont(sf::Font());
	Menu1.setFont(font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Play");
	Menu1.setPosition({ 280.f, 160.f });

	//Menu2.setFont(sf::Font());
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280.f, 220.f });

	//Menu3.setFont(sf::Font());
	Menu3.setCharacterSize(20);
	Menu3.setString("Continue");
	Menu3.setPosition({ 280.f, 160.f });

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



		App.clear(sf::Color::White);
		App.draw(Menu1);
		App.draw(Menu2);
		//App.draw(shape);
		App.display();

	}

	return 0;
}
