#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 6", sf::Style::Default);

	float CurrentFrame = 0;
	sf::Clock clock;


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
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) 
		{ 
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3; 
			herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96)); 
			herosprite.move(-0.1*time, 0);
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) 
		{
			CurrentFrame += 0.005*time; 
			if (CurrentFrame > 3) CurrentFrame -= 3;
			herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96)); 
			herosprite.move(0.1*time, 0); 
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
			herosprite.move(0, -0.1*time);
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) 
		{ 
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3; 
			herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96)); 
			herosprite.move(0, 0.1*time);
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) herosprite.setColor(sf::Color::Red);
		
		window.clear();
		window.draw(herosprite);
		window.display();
	}

	
	//system("pause");

	return 0;
}