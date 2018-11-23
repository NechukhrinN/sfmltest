#include "player.h"
#include "map.h"

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

void Player::interactionWithMap()
{

	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (dy > 0)	y = i * 32 - h;
				if (dy < 0)	y = i * 32 + 32;
				if (dx > 0)	x = j * 32 - w;
				if (dx < 0)	x = j * 32 + 32;
			}

			if (TileMap[i][j] == 's')
			{
				x = 300; y = 300;
				TileMap[i][j] = ' ';
			}
		}
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
	interactionWithMap();
}




float Player::getplayercoordinateX()
{
	return x;
}

float Player::getplayercoordinateY()
{
	return y;
}


