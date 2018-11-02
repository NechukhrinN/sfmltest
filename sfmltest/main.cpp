#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 3", sf::Style::Default);
	
	sf::Image heroimage;
	heroimage.loadFromFile("images/hero.png");
	
	sf::Texture herotexture;
	herotexture.loadFromImage(heroimage);
	
	sf::Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(50, 25);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		window.draw(herosprite);
		window.display();
	}

	
	//system("pause");

	return 0;
}