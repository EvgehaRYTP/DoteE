#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:
	sf::Texture textureBullet;
	sf::Sprite sprite;

	float moventspeed;
	sf::Vector2f setpos;
	sf::Vector2f velocity;
	void init();

public:
	Bullet();
	Bullet(float _moventSpeed, sf::Vector2f _setpos, float VV, sf::Vector2f _velocity);
	~Bullet();

	sf::Sprite getBullet();
	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	void setPosition();
	void setRotation(sf::Vector2f v);
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);
};

