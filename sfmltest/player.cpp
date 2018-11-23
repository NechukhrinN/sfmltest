#include "player.h"

	Player::Player(sf::String F, float X, float Y, float W, float H)
	{
		dx = 0; dy = 0; speed = 0;
		File = F;
		w = W; h = H;
		image.loadFromFile("images/" + File);
		image.createMaskFromColor(sf::Color(41, 33, 59));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	}
	void Player::update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		default: dx = 0; dy = 0; break;
		}
		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}
	float Player::getplayercoordinateX()
	{
		return x;
	}

	float Player::getplayercoordinateY()
	{
		return y;
	}


