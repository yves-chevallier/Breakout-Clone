#include "paddle.hpp"

Paddle::Paddle(sf::RenderWindow* window)
{
	this->speed = 1;
	this->Load("assets/paddle.png");
	this->setPosition(
		window->getSize().x / 2 - this->getTextureRect().width / 2.0, 
		window->getSize().y - this->getTextureRect().height * 0.5);
}

void Paddle::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		this->move(sf::Vector2f(-speed, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		this->move(sf::Vector2f(speed, 0));
	}
}