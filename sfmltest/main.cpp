#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <sstream>
#include "view.h"
#include "player.h"
#include "map.h"


using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson SFML");
	view.reset(sf::FloatRect(0, 0, 640, 480));
	float CurrentFrame = 0;
	sf::Clock clock;
	
	sf::Font font;
	font.loadFromFile("fonts/CyrilicOld.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	Image map_image;
	map_image.loadFromFile("images/map.png");
	
	Texture map;
	map.loadFromImage(map_image);
	
	Sprite s_map;
	s_map.setTexture(map);
	Player p("hero.png", 250, 250, 96.0, 96.0);
		
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
		
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 0; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p.dir = 3; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 307, 96, 96));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) { 
			p.dir = 2; p.speed = 0.1;
			CurrentFrame += 0.005*time; 
			if (CurrentFrame > 3) CurrentFrame -= 3; 
			p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96)); 
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}
		
		p.update(time);
		viewmap(time);
		changeview();
		window.setView(view);
		window.clear(Color(128, 106, 89));

		for (int i = 0; i<HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ') s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's') s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(64, 0, 32, 32));

				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);
			}
		
		std::ostringstream playerScoreString;
		playerScoreString << p.pScore;
		text.setString("Get points:" + playerScoreString.str());
		text.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
		
		window.draw(p.sprite);
		window.draw(text);
		window.display();
	}

	
	//system("pause");
	return 0;
}