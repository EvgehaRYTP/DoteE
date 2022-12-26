#include "Planet.h"

void Planet::initTextureSprite()
{
	this->texturePlanet.loadFromFile("res\\textures\\Earth.png");
	this->texturePlanet.setSmooth(true);

	//this->earth.setRadius(190.f / 2);
	//earth.setScale(190.f / 2, 190.f / 2);
	earth.setColor(sf::Color::Yellow);
	this->earth.setTexture(texturePlanet);
    this->earth.setOrigin(texturePlanet.getSize().x / 2, texturePlanet.getSize().y / 2);
}

Planet::Planet()
{
	initTextureSprite();
}

Planet::~Planet()
{
}

void Planet::setPosition(float x, float y)
{
	this->earth.setPosition(x, y);
}

sf::FloatRect Planet::getGlobalBoundsPlanet()
{
	return this->earth.getGlobalBounds();
}

sf::Sprite Planet::getCircle()
{
	return earth;
}

void Planet::update(sf::Time dt)
{
	//this->earth.rotate(-10.f * dt.asSeconds());
}

void Planet::render(sf::RenderWindow& window)
{
	window.draw(this->earth);
}