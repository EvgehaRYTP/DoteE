#pragma once
#include <SFML/Graphics.hpp>

class Planet
{
private:
	sf::Texture texturePlanet;
	sf::Sprite earth;

	void initTextureSprite();

public:
	Planet();
	~Planet();

	sf::FloatRect getGlobalBoundsPlanet();
	sf::Sprite getCircle();
	void setPosition(float x, float y);
	void update(sf::Time dt);

	void render(sf::RenderWindow& window);
};