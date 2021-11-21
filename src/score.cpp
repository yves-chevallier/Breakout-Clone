#include "score.hpp"

Score::Score()
{
	this->score = 0;
	this->walls = std::vector<Wall>();
}

void Score::addWall(Paddle *paddle, Ball *ball, sf::RenderWindow *window, float x, float y)
{
	this->walls.push_back(Wall(paddle, ball, window));
	this->walls[this->walls.size() - 1].setPosition(x, y);
}

void Score::Update(sf::RenderWindow *window)
{
	for (int i = 0; i < this->walls.size(); i += 1)
	{
		if (!this->walls[i].Update(window))
		{
			this->score += 1;
		}
	}
}

void Score::Render(sf::RenderWindow *window)
{
	for (int i = 0; i < this->walls.size(); i += 1)
	{
		if (this->walls[i].active)
		{
			window->draw(this->walls[i]);
		}
	}
}

int Score::getScore()
{
	return this->score;
}