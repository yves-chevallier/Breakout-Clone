#pragma once

#include <stdio.h>

#include "game.hpp"

class main_menu : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Font* font;
	sf::Text* header;

	sf::Text* play;
	sf::Text* quit;

	int currentSelection;
	sf::Vector2f scale;
	float scaleSpeed;

	bool keyDownPreviousDown;
	bool keyDownPreviousUp;

	Ball ball;

	Score score;
};