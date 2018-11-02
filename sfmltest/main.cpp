#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 5", sf::Style::Default);

	//Get Image, texture & sprite
	sf::Image heroimage;
	heroimage.loadFromFile("images/hero.png");
	sf::Texture herotexture;
	herotexture.loadFromImage(heroimage);
	
	sf::Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96)); 
	herosprite.setPosition(250, 250);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { herosprite.move(-0.1, 0); herosprite.setTextureRect(sf::IntRect(0, 96, 96, 96)); }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { herosprite.move(0.1, 0); herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96)); }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { herosprite.move(0, -0.1); herosprite.setTextureRect(sf::IntRect(0, 288, 96, 96)); }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { herosprite.move(0, 0.1); herosprite.setTextureRect(sf::IntRect(0, 0, 96, 96)); }
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) herosprite.setColor(sf::Color::Red);
		
		window.clear();
		window.draw(herosprite);
		window.display();
	}

	
	//system("pause");

	return 0;
}