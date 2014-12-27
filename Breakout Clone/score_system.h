#pragma once

#include <vector>
#include <SFML/graphics.hpp>
#include "wall.h"
#include "ball.h"

class score_system
{
public:
	score_system();
	void addWall(Paddle* paddle, Ball* ball, sf::RenderWindow* window, float x, float y);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	int Score();
private:
	int score;

	std::vector<Wall> walls;
};