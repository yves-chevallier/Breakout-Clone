#include "wall.hpp"

Wall::Wall(Paddle* paddle, Ball* ball, sf::RenderWindow* window)
{
	this->ball = ball;
	this->paddle = paddle;

	this->specialness = rand() % 2;

	switch (this->specialness)
	{
	case 0:
		this->Load("assets/wall.png");
		break;
	case 1:
		this->Load("assets/wall_speed.png");
		break;
	default:
		this->Load("assets/wall.png");
		break;
	}
	this->Reset(window);
}

void Wall::Reset(sf::RenderWindow* window)
{
	active = true;
}

bool Wall::Update(sf::RenderWindow* window)
{
	if (this->ball && this->paddle && active)
	{
		if (this->ball->Collision(this))
		{
			float x = this->ball->getPosition().x;
			if (x < this->getPosition().x || x + this->ball->getGlobalBounds().width > this->getPosition().x + this->getGlobalBounds().width)
			{
				this->ball->Bounce(false);
			}

			float y = this->ball->getPosition().y;
			if (y < this->getPosition().y || y + this->ball->getGlobalBounds().height / 4 > this->getPosition().y + this->getGlobalBounds().height)
			{
				this->ball->Bounce(true);
			}

			switch (specialness)
			{
			case 0:
				break;
			case 1:
				this->paddle->speed = 2;
				break;
			}

			active = false;
			return false;
		}
	}

	return true;
}