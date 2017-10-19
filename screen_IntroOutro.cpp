#define CHECK_INVENTORY 1
#define START_BATTLE 2

#include "screen_IntroOutro.h"

screen_IntroOutro::screen_IntroOutro(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_IntroOutro::Run(sf::RenderWindow &App, bool Intro)
{
	if (Intro)
	{
		RunIntro(App);
	}
	else
	{
		RunOutro(App);
	}
	return 0;
}
void screen_IntroOutro::RunIntro(sf::RenderWindow &App)
{
	
		sf::Event event;
		App.setTitle("WELCOME!");
		sf::Font font;
		if (!font.loadFromFile("OpenSans-Regular.ttf"))
		{
			std::cerr << "Error font.loadFromFile('OpenSans - Regular.ttf')" << std::endl;
		}
		sf::Text display_intro;
		display_intro.setPosition(0.f, 0.f);
		display_intro.setString("Welcome to Tower Crawl!");
		display_intro.setFont(font);
		display_intro.setCharacterSize(30);
		display_intro.setFillColor(sf::Color::Black);

		while (App.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop        
			while (App.pollEvent(event))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//Mouse Clicked
				{
					return;
				}
				// "close requested" event: we close the window
				else if (event.type == sf::Event::Closed)
					App.close();
			}//end poll event

			App.clear(sf::Color::White);

			//window.draw(sprite);
			App.draw(display_intro);

			// end the current frame
			App.display();
		} // end core while loop
	
}
void screen_IntroOutro::RunOutro(sf::RenderWindow &App)
{
	sf::Event event;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text text;
	sf::Font font;


	//-------------------------- font stuff ---------------------------------//
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		std::cerr << "Error font.loadFromFile('OpenSans - Regular.ttf')" << std::endl;
	}

	text.setFont(font);                    // font is a sf::Font    
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Blue);

	text.setString("Bye Felicia!");
	text.setPosition(0.f, 0.f);
	//-----------------------------------------------------------------------//


	//-------------------------- sprite/texture -----------------------------//
	if (!texture.loadFromFile("grim.jpg"))
	{
		std::cerr << "Error loading grim.jpg " << std::endl;
	}
	else
	{
		// set the sprites texture 'skin' if skin thing found
		sprite.setTexture(texture);
	}
	//-----------------------------------------------------------------------//


	// run the program as long as the window is open
	while (App.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop        
		while (App.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				App.close();
		}

		App.clear(sf::Color::White);

		//window.draw(sprite);
		App.draw(text);

		// end the current frame
		App.display();
	} // end core while loop

	//Sabatini ASSIGNED TO BUILD LOGIC
	//If Intro is True then the window will display the intro text or animation
	//If false then place death screen
}

