#pragma once

#include <SFML/Graphics.hpp>
#include "hMATH.h"

class Asteroids
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	void init();

public:
	Asteroids();
	~Asteroids();

	bool Destroy() { return true; };
	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	float getRotation();
	void setRot(float angle);
	void setPosition(sf::Vector2f position);
	void update(sf::Time dt);
	void render(sf::RenderWindow &window);
};

