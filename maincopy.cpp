//#include <SFML/Graphics.hpp>
////sample page , basically parts page
//#include "sprite.h"
//
//void DrawSprites(sf::RenderWindow);
//bool HandleInput();
//void LoadRoom();
//
//int main9()
//{
//	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
//	sf::CircleShape shape(100.f);
//	//shape.setFillColor(sf::Color::Green);
//	bool bl[4] = {true,true,true,true };
//	bool newRoom = true;
//
//	while (window.isOpen())
//	{
//		//if (newRoom) { LoadRoom(); newRoom = false; }// Loads new room values 
//
//		Sprite Player;
//		Sprite Monster;
//		Sprite DoorNorth;
//		Sprite DoorSorth;
//
//
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			bool ismove = HandleInput();
//		}
//
//
//		window.clear();
//		window.display();
//
//	}
//
//	return 0;
//}
//void DrawSprites(sf::RenderWindow win)
//{
//	//win.draw(shape);
//	return;
//}
//bool HandleInput()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		// left key is pressed: move our character
//		//character.move(1, 0);
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		// left key is pressed: move our character
//		//character.move(1, 0);
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//	{
//		// left key is pressed: move our character
//		//character.move(1, 0);
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//	{
//		// left key is pressed: move our character
//		//character.move(1, 0);
//		return true;
//	}
//	return true;
//}
////add to array and draws onto screen
//void LoadRoom()
//{
//
//}