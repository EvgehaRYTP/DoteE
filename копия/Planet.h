#pragma once
#include <SFML/Graphics.hpp>

class Planet
{
private:
	sf::Texture texturePlanet;
	sf::CircleShape earth;

	void initTextureSprite();

public:
	Planet();
	~Planet();

	sf::FloatRect getGlobalBoundsPlanet();
	sf::CircleShape getCircle();
	void setPosition(float x, float y);
	void update(sf::Time dt);

	void render(sf::RenderWindow& window);
};