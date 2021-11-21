#include "menu.hpp"

void main_menu::Initialize(sf::RenderWindow* window)
{
	font = new sf::Font();
	font->loadFromFile("assets/collegiate.ttf");


	header = new sf::Text("Breakout\nClone", *font, 128U);
	header->setPosition(30, 0);

	play = new sf::Text("Play", *font, 64U);
	play->setPosition(500, 250);
	play->setOrigin((float)play->getCharacterSize() / 2, (float)play->getCharacterSize() / 2);

	quit = new sf::Text("Quit", *font, 64U);
	quit->setPosition(500, 250 + (play->getCharacterSize() * 1.5f));
	quit->setOrigin((float)quit->getCharacterSize() / 2, (float)quit->getCharacterSize() / 2);

	this->currentSelection = 0;
	this->scaleSpeed = 0.0075f;
	this->scale = sf::Vector2f(1, 1);

	this->keyDownPreviousDown = false;
	this->keyDownPreviousUp = false;

	ball = Ball(NULL, window);

	score = Score();
	for (int i = 0; i < 30; i += 1)
	{
		float x = rand() % 800;
		float y = rand() % 600;

		score.addWall(NULL, &ball, window, x, y);
	}
}
void main_menu::Update(sf::RenderWindow* window)
{
	ball.Update(window);
	score.Update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (!this->keyDownPreviousDown)
		{
			this->currentSelection += 1;
		}
		this->keyDownPreviousDown = true;
	}
	else if (this->keyDownPreviousDown)
	{
		this->keyDownPreviousDown = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (!this->keyDownPreviousUp)
		{
			this->currentSelection -= 1;
		}
		this->keyDownPreviousUp = true;
	}
	else if (this->keyDownPreviousUp)
	{
		this->keyDownPreviousUp = false;
	}

	if (this->currentSelection > 1)
	{
		this->currentSelection = 0;
	}
	if (this->currentSelection < 0)
	{
		this->currentSelection = 1;
	}
	play->setScale(sf::Vector2f(1.0f, 1.0f));
	quit->setScale(sf::Vector2f(1.0f, 1.0f));

	if (scale.x > 1.5f || scale.y > 1.5f || scale.x < 1.0f || scale.y < 1.0f)
	{
		scaleSpeed *= -1.0f;
	}

	scale.x += scaleSpeed;
	scale.y += scaleSpeed;

	switch (this->currentSelection)
	{
	case 0:
		play->setScale(scale);
		break;
	case 1:
		quit->setScale(scale);
		break;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->currentSelection)
		{
		case 0:
			coreState->SetState(new Game());
			break;
		case 1:
			endGame = true;
			break;
		}
	}
}
void main_menu::Render(sf::RenderWindow* window)
{
	window->draw(ball);
	score.Render(window);
	window->draw(*header);
	window->draw(*play);
	window->draw(*quit);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
}