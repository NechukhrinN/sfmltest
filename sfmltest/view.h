#ifndef VIEW
#define VIEW
#include <SFML/Graphics.hpp>

sf::View view;

void getplayercoordinateforview(float x, float y) 
{ 
	float tempX = x; float tempY = y;
	if (x < 320) tempX = 320;
	if (x > 960) tempX = 960;
	if (y < 240) tempY = 240;
	if (y > 554) tempY = 554;
	view.setCenter(tempX, tempY);
	
}

void viewmap(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		view.move(0.1*time, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		view.move(0,0.1*time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		view.move(-0.1*time, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		view.move(0, -0.1*time);
	}
}

void changeview() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		view.zoom(1.0100f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		view.rotate(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		view.setSize(640,480);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		view.setSize(540, 380);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		view.setViewport(sf::FloatRect(0,0,0.5f,1));
	}
}

#endif