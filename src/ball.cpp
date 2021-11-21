#include "ball.hpp"

Ball::Ball(Paddle* paddle, sf::RenderWindow* window)
{
	this->paddle = paddle;

	this->Load("assets/ball.png");
	this->Reset(window);
}

void Ball::Bounce(bool bounceY)
{
	if (bounceY)
	{
		this->velocity.y *= -1;
	}
	else
	{
		this->velocity.x *= -1;
	}
}

void Ball::Reset(sf::RenderWindow* window)
{
	this->velocity = sf::Vector2f(0.75f, -0.75f);
	this->setPosition(window->getSize().x / 2 - this->getTextureRect().width / 2.0f, window->getSize().y - this->getTextureRect().height * 4.0f);
}

bool Ball::Update(sf::RenderWindow* window)
{
	if (this->paddle)
	{
		if (this->paddle->Collision(this))
		{
			this->velocity.y *= -1;
		}
	}

	if (this->getPosition().x > window->getSize().x - this->getGlobalBounds().width || this->getPosition().x < 0)
	{
		this->velocity.x *= -1;
	}
	if (this->getPosition().y > window->getSize().y - this->getGlobalBounds().height || this->getPosition().y < 0)
	{
		this->velocity.y *= -1;
	}

	if (this->getPosition().y > window->getSize().y - this->getGlobalBounds().height)
	{
		this->move(this->velocity);
		return false;
	}
	else
	{
		this->move(this->velocity);
		return true;
	}
}