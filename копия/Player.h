#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Player
{
private:
	sf::Texture playerTexture;

	float energy;
	float movementSpeed;
	float speedMax;
	float testspeed;
	float _xPosition;
	float _yPosition;

	sf::Vector2f velocity;
	sf::Vector2f direction;

	bool movable;

	void initVariables();
	void setTextureSprite();

public:
	Player();
	virtual ~Player();

	sf::Sprite playerSprite;
	sf::Vector2f getPosition();
	float getRotation();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f mousePosition(RenderWindow& window);
	bool getMovable() { return movable; };

	void setMovable(bool _movable);
	void addForces(sf::Vector2f _forces);
	void setEnergy(float _energy);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setRotation(sf::Vector2f raznica);
	void move(sf::Time dt, sf::Vector2f test);
	void update();

	void render(sf::RenderWindow& window);
};

