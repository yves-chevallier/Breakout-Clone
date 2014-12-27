#pragma once

#include <stdio.h>

#include "game_state.h"
#include "entity.h"

#include "paddle.h"
#include "ball.h"
#include "wall.h"
#include "score_system.h"

class main_game : public tiny_state
{
public:
	main_game();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Paddle paddle;
	Ball ball;
	score_system scoreSystem;

	sf::Font* font;
	sf::Text* header;
};