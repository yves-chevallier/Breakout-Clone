#include <SFML/Window.hpp>
#include <Windows.h>

#include "main_menu.h"

bool endGame = false;
game_state* coreState;

int main()
{
	srand(NULL);
	sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout");

	coreState = new game_state();
	coreState->SetWindow(&window);
	coreState->SetState(new main_menu());

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

		window.clear(sf::Color::Black);

		coreState->Update();
		coreState->Render();

		window.display();

		Sleep(2);
	}

	return 0;
}
