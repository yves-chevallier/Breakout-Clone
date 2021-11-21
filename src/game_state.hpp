#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class tiny_state
{
public:
	virtual void Initialize(sf::RenderWindow* window)
	{
	}
	virtual void Update(sf::RenderWindow* window)
	{
	}
	virtual void Render(sf::RenderWindow* window)
	{
	}
	virtual void Destroy(sf::RenderWindow* window)
	{
	}
};

class game_state
{
public:
	game_state()
	{
	}

	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(tiny_state* newState)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(window);
		}

		this->state = newState;

		if (this->state != NULL)
		{
			this->state->Initialize(window);
		}
	}

	void Update()
	{
		this->state->Update(window);
	}

	void Render()
	{
		this->state->Render(window);
	}

	~game_state()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(window);
		}
	}
private:
	sf::RenderWindow* window;
	tiny_state* state;
};

extern game_state* coreState;
extern bool endGame;