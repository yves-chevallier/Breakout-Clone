#pragma once

#include "entity.h"

class Paddle : public Entity
{
public:
	float speed;

	Paddle()
	{
	}
	Paddle(sf::RenderWindow* window);
	void Update();
private:
};