#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
public:
	Entity() {};
	
	Entity(std::string filename)
	{
		this->Load(filename);
	}

	Entity(std::string filename, int xOffset, int yOffset, int width , int height)
	{
		this->Load(filename, sf::IntRect(xOffset, yOffset, width, height));
	}

	void Load(std::string filename, sf::IntRect areaToLoad = sf::IntRect())
	{
		this->texture = new sf::Texture();
		texture->loadFromFile(filename, areaToLoad);
		this->setTexture(*this->texture);
	}

	bool Collision(Entity* entity)
	{
		return entity->getGlobalBounds().intersects(this->getGlobalBounds());
	}

private:
	sf::Texture* texture;
};