#include "main_game.h"
#include "main_menu.h"

main_game::main_game()
{
}
void main_game::Initialize(sf::RenderWindow* window)
{
	font = new sf::Font();
	font->loadFromFile("header.ttf");

	header = new sf::Text("Score: 0", *font, 32U);
	header->setPosition(10, 0);

	paddle = Paddle(window);
	ball = Ball(&paddle, window);

	scoreSystem = score_system();

	for (int y = 0; y < 10; y += 1)
	{
		for (int x = 0; x < 17; x += 1)
		{
			scoreSystem.addWall(&paddle, &ball, window, x * 40 + 50, y * 24 + 50);
		}
	}
}
void main_game::Update(sf::RenderWindow* window)
{
	if (!ball.Update(window))
	{
		ball.Reset(window);
	}
	paddle.Update();
	scoreSystem.Update(window);

	header->setString("Score: " + std::to_string(scoreSystem.Score()));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState->SetState(new main_menu());
	}
}
void main_game::Render(sf::RenderWindow* window)
{
	window->draw(this->ball);
	window->draw(this->paddle);
	scoreSystem.Render(window);

	window->draw(*header);
}
void main_game::Destroy(sf::RenderWindow* window)
{
}
