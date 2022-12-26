#include "Asteroids.h"

void Asteroids::init()
{
	texture.loadFromFile("res\\textures\\asteroid1.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.3f, 0.3f);
	sprite.setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().x / 2);
}

Asteroids::Asteroids(sf::Vector2f _position)
{
	position = _position;
	movementSpeed = 250;
	this->init();
	sprite.setPosition(position);
}

Asteroids::~Asteroids()
{
}

sf::Sprite Asteroids::getAsteroid()
{
	return sprite;
}

sf::FloatRect Asteroids::getBounds()
{
	return sprite.getGlobalBounds();
}

sf::Vector2f Asteroids::getPosition()
{
	return sprite.getPosition();
}

float Asteroids::getRotation()
{
	return sprite.getRotation();
}

void Asteroids::setRot(float angle)
{
	sprite.setRotation(angle);
}

void Asteroids::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Asteroids::update(sf::Time dt)
{
	

	sf::Vector2f v(1920, 1080);
	float _Distance = distance(v, sprite.getPosition());

	sprite.move(cos(1) * movementSpeed * dt.asSeconds() * (v.x - sprite.getPosition().x) / _Distance,
				sin(1) * movementSpeed * dt.asSeconds() * (v.y - sprite.getPosition().y) / _Distance);

	//
	//sf::Vector2f rSpawn1 = sf::Vector2f(math::randomFLOAT(0, 0), math::randomFLOAT(0, 2160));
	//sf::Vector2f rSpawn2 = sf::Vector2f(math::randomFLOAT(0, 3840), math::randomFLOAT(0, 0));
	//sf::Vector2f rSpawn3 = sf::Vector2f(math::randomFLOAT(3840, 3840), math::randomFLOAT(0, 2160));
	//sf::Vector2f rSpawn4 = sf::Vector2f(math::randomFLOAT(0, 3840), math::randomFLOAT(2160, 2160));

	//int selectSpawn = rand() % 4;
	//std::cout << selectSpawn << std::endl;

	//if (sprite.getPosition().x == 1920.f || sprite.getPosition().x == 1080.f)
	//{
	//	if (selectSpawn == 0) sprite.setPosition(rSpawn1);
	//	if (selectSpawn == 1) sprite.setPosition(rSpawn2);
	//	if (selectSpawn == 2) sprite.setPosition(rSpawn3);
	//	if (selectSpawn == 3) sprite.setPosition(rSpawn4);
	//}
	//
	////
	//setRot(1);
	//sf::Vector2f v(1920, 1080);
	//float _Distance = distance(v, sprite.getPosition());
	//sprite.move(cos(getRotation()) * movementSpeed * dt.asSeconds() * (v.x - sprite.getPosition().x) / _Distance,
	//			sin(getRotation()) * movementSpeed * dt.asSeconds() * (v.y - sprite.getPosition().y) / _Distance);
}

void Asteroids::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

/*
int selectSpawn = rand() % 4;

	sf::Vector2f rSpawn1 = sf::Vector2f(math::randomFLOAT(0, 0), math::randomFLOAT(0, 2160));
	sf::Vector2f rSpawn2 = sf::Vector2f(math::randomFLOAT(0, 3840), math::randomFLOAT(0, 0));
	sf::Vector2f rSpawn3 = sf::Vector2f(math::randomFLOAT(3840, 3840), math::randomFLOAT(0, 2160));
	sf::Vector2f rSpawn4 = sf::Vector2f(math::randomFLOAT(0, 3840), math::randomFLOAT(2160, 2160));

	if (selectSpawn == 0) _asteroids[index].setPosition(rSpawn1);
	if (selectSpawn == 1) _asteroids[index].setPosition(rSpawn2);
	if (selectSpawn == 2) _asteroids[index].setPosition(rSpawn3);
	if (selectSpawn == 3) _asteroids[index].setPosition(rSpawn4);
}
*/