#ifndef PLAYER
#define PLAYER
#include <SFML\Graphics.hpp>

class Player 
{
private: float x, y;
public:
	float w, h, dx, dy, speed;
	int dir, pScore;
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Player(sf::String F, float X, float Y, float W, float H);
	void interactionWithMap();
	void update(float time);
	float getplayercoordinateX();
	float getplayercoordinateY();
};

#endif