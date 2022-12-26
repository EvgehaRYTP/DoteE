#pragma once

#include <SFML/Graphics.hpp>
#include "hMATH.h"

class Asteroids
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	sf::Vector2f position;

	float movementSpeed;
	void init();

public:
	Asteroids(sf::Vector2f _position);
	~Asteroids();

	bool Destroy() { return true; };
	sf::Sprite getAsteroid();
	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	float getRotation();

	void setRot(float angle);
	void setPosition(sf::Vector2f position);
	void update(sf::Time dt);
	void render(sf::RenderWindow &window);
};

