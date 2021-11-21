#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "wall.hpp"
#include "ball.hpp"

class Score
{
public:
	Score();
	void addWall(Paddle *paddle, Ball *ball, sf::RenderWindow *window, float x, float y);
	void Update(sf::RenderWindow *window);
	void Render(sf::RenderWindow *window);
	int getScore();

private:
	int score;

	std::vector<Wall> walls;
};