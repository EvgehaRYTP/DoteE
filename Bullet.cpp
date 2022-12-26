#include "Bullet.h"

void Bullet::init()
{
	textureBullet.loadFromFile("res\\textures\\bullet5.png");
	textureBullet.setSmooth(true);

	sprite.setTexture(this->textureBullet);
	sprite.setOrigin(
		(float)textureBullet.getSize().x / 2,
		(float)textureBullet.getSize().y / 2
	);

	//moventspeed = 500;
}

//Bullet::Bullet()
//{
//
//}

Bullet::Bullet()
{
}

Bullet::Bullet(float _moventSpeed, sf::Vector2f _setpos, float VV, sf::Vector2f _velocity)
{
	this->init();
	moventspeed = _moventSpeed;
	setpos = _setpos;
	velocity = _velocity;
	sprite.setPosition(_setpos);
	//sprite.setRotation((std::atan2(_setrotation.y, _setrotation.x) * 180.f / 3.14f) + 90);
	sprite.setRotation(VV);
}


Bullet::~Bullet()
{
}

sf::Sprite Bullet::getBullet()
{
	return sprite;
}

sf::FloatRect Bullet::getBounds()
{
	return sprite.getGlobalBounds();
}

sf::Vector2f Bullet::getPosition()
{
	return sprite.getPosition();
}

//void Bullet::setPosition()
//{
//	sprite.setPosition(setpos);
//}

void Bullet::setRotation(sf::Vector2f v)
{
	//sprite.setRotation((std::atan2(v.y, v.x) * 180.f / 3.14f) + 90);
}

void Bullet::update(sf::Time dt)
{
	sprite.move(velocity.x * moventspeed * dt.asSeconds(), velocity.y * moventspeed * dt.asSeconds());
}

void Bullet::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

