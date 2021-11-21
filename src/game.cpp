#include "game.hpp"
#include "menu.hpp"

Game::Game()
{
}

void Game::Initialize(sf::RenderWindow *window)
{
	font = new sf::Font();
	font->loadFromFile("assets/collegiate.ttf");

	header = new sf::Text("Score: 0", *font, 32U);
	header->setPosition(10, 0);

	paddle = Paddle(window);
	ball = Ball(&paddle, window);

	score = Score();

	for (int y = 0; y < 15; y += 1)
	{
		for (int x = 0; x < 28; x += 1)
		{
			score.addWall(&paddle, &ball, window, x * 40 + 50, y * 24 + 50);
		}
	}
}
void Game::Update(sf::RenderWindow *window)
{
	if (!ball.Update(window))
	{
		ball.Reset(window);
	}
	paddle.Update();
	score.Update(window);

	header->setString("Score: " + std::to_string(score.getScore()));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState->SetState(new Menu());
	}
}
void Game::Render(sf::RenderWindow *window)
{
	window->draw(this->ball);
	window->draw(this->paddle);
	score.Render(window);

	window->draw(*header);
}
void Game::Destroy(sf::RenderWindow *window)
{
}
