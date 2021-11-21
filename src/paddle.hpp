#pragma once

#include "entity.hpp"

class Paddle : public Entity
{
public:
	float speed;

	Paddle() {}
	Paddle(sf::RenderWindow* window);
	void Update();
private:
};