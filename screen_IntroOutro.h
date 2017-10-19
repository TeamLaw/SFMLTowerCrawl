#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class screen_IntroOutro : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	screen_IntroOutro(void);
	int Run(sf::RenderWindow &App, bool);
	virtual int Run(sf::RenderWindow &App) { return 0; };
	void screen_IntroOutro::RunIntro(sf::RenderWindow &App);
	void screen_IntroOutro::RunOutro(sf::RenderWindow &App);

};
