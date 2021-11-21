#pragma once

#include <stdio.h>

#include "game_state.hpp"
#include "entity.hpp"

#include "paddle.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "score.hpp"

class Game : public tiny_state
{
public:
	Game();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Paddle paddle;
	Ball ball;
	Score score;

	sf::Font* font;
	sf::Text* header;
};