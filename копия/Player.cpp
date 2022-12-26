#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 1.f;
	speedMax = 280.f;
	velocity.x = 1.f;
	velocity.y = 1.f;

	this->_xPosition;
	this->_yPosition;
}

void Player::setTextureSprite()
{
	this->playerTexture.loadFromFile("res\\textures\\player.png");
	this->playerTexture.setSmooth(true);

	this->playerSprite.setTexture(playerTexture);
	this->playerSprite.setOrigin(55.f / 2, 33.f / 2);
	this->playerSprite.setScale(0.7f, 0.7f);
}

Player::Player()
{
	this->setTextureSprite();
	this->initVariables();

}

Player::~Player()
{
}

Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

float Player::getRotation()
{
	return playerSprite.getRotation();
}

FloatRect Player::getGlobalBounds()
{
	return playerSprite.getGlobalBounds();
}

Vector2f Player::mousePosition(RenderWindow& window)
{
	return window.mapPixelToCoords(Mouse::getPosition(window));
}


void Player::setMovable(bool _movable)
{
	movable = _movable;
}

void Player::addForces(sf::Vector2f _forces)
{
	if (movable)
	{
		//_forces /= 10.f;
		velocity += _forces;
	}

	if (!movable)
	{
		velocity -= _forces;
		if (velocity.x < 0.f || velocity.y < 0.f)
			velocity.x = 1.f; velocity.y = 1.f;
	}
}

void Player::setEnergy(float _energy)
{
	energy = _energy;

	if (energy > 200.f)
		energy = 200.f;
}

void Player::setPosition(Vector2f position)
{
	playerSprite.setPosition(position);
}

void Player::setPosition(float x, float y)
{
	playerSprite.setPosition(x, y);
}

void Player::setRotation(Vector2f raznica)
{
	playerSprite.setRotation(std::atan2(raznica.y, raznica.x) * 180.f / 3.14f);
}


void Player::move(sf::Time dt, Vector2f test)
{
//	velocity.x += testspeed;
//	velocity.y += testspeed;

	/*if (std::abs(velocity.x) > speedMax)
	{
		velocity.x = speedMax * ((velocity.x < 0.f) ? -1.f : 1.f);
	}

	if (std::abs(velocity.y) > speedMax)
	{
		velocity.y = speedMax * ((velocity.y < 0.f) ? -1.f : 1.f);
	}*/

	/*float direction = sqrt((test.x - getPosition().x) * (test.x - getPosition().x) +
		(test.y - getPosition().y) * (test.y - getPosition().y))*/;

	direction.x = cos(((playerSprite.getRotation()) / 360) * 3.1426f * 2);
	direction.y = sin(((playerSprite.getRotation()) / 360) * 3.1416f * 2);

	addForces(direction);

	//_xPosition = 1 * dt.asSeconds() * (test.x - getPosition().x) * direction.x;
	//_yPosition = 1 * dt.asSeconds() * (test.y - getPosition().y) * direction.y;
	_xPosition = dt.asSeconds() * direction.x * 100;
	_yPosition = dt.asSeconds() * direction.y * 100;
	playerSprite.move(velocity * dt.asSeconds());

	/*if (!Keyboard::isKeyPressed(Keyboard::W))
	{
		velocity.x -= 10.f;
		velocity.y -= 10.f;
	}*/
}

void Player::update()
{
	_xPosition = 400;
	_yPosition = 400;
	setPosition(_xPosition, _yPosition);
}

void Player::render(RenderWindow& window)
{
	window.draw(playerSprite);
}