#pragma once

#include "entity.hpp"
#include "ball.hpp"
#include "paddle.hpp"

class Wall : public Entity
{
public:
	bool active;
	Wall()
	{
	}
	Wall(Paddle* paddle, Ball* ball, sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);
	bool Update(sf::RenderWindow* window);
private:
	Ball* ball;
	Paddle* paddle;

	int specialness;
};