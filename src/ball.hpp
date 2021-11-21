#pragma once

#include "entity.hpp"
#include "paddle.hpp"

class Ball : public Entity
{
public:
	Ball() {}
	Ball(Paddle* paddle, sf::RenderWindow* window);
	void Bounce(bool bounceY);
	void Reset(sf::RenderWindow* window);
	bool Update(sf::RenderWindow* window);
private:
	sf::Vector2f velocity;
	Paddle* paddle;
};