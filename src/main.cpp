#include <chrono>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "menu.hpp"

bool endGame = false;
GameState* coreState;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Breakout");

	coreState = new GameState();
	coreState->SetWindow(&window);
	coreState->SetState(new Menu());

	while (window.isOpen())
	{
		if (endGame)
		{
			window.close();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(40, 44, 52));

		coreState->Update();
		coreState->Render();

		window.display();

		//std::this_thread::sleep_for(std::chrono::milliseconds(3));
	}
}
