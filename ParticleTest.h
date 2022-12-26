#pragma once

#include <SFML/Graphics.hpp>
#include "hMATH.h"
#include "Player.h"

class ParticleT
{
private:



public:
	sf::Time lifetime;
	sf::Time _lifetime;
	sf::Vector2f velocity;

	sf::Sprite sprite;
	sf::Texture texture;
	sf::Color color;
	Player player;
	sf::Vector2f emmiter;

	float ANGLE;
	float scale;
	float rotate;

	void init()
	{
		ANGLE = (std::rand() % 360) * 3.14f / 180.f;
		texture.loadFromFile("res\\textures\\particle_smoke2.png");
		texture.setSmooth(true);
		sprite.setTexture(texture);
		scale = math::randomFLOAT(0.06, 0.2);
		sprite.setScale(scale, scale);
		sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	
		lifetime = sf::seconds(3);
	
		_lifetime = sf::milliseconds((std::rand() % 3000) + 1000);
	}
	ParticleT(sf::Vector2f _pos, float _rotate)
	{
		init();
		emmiter = _pos;
		//sprite.setPosition(_pos);
		//sprite.setPosition(emmiter + sf::Vector2f(cos(player.getRotation()), sin(player.getRotation())) * 40.f);
		sprite.setPosition(emmiter);
		rotate = _rotate;
	}
	~ParticleT() {}

	void update(sf::Time dt)
	{

		
		float SPEED = 0.0000000055;
		velocity = sf::Vector2f(cos(player.getRotation()), sin(player.getRotation()));

		_lifetime -= dt;

		float ratio = _lifetime.asSeconds() / lifetime.asSeconds();
		color.a = static_cast<sf::Uint8>(ratio * 100);

		sprite.setColor(Color(123, 255, 255, color.a));
		sprite.move((emmiter + velocity) / 5.f * dt.asSeconds());
	
		sprite.setRotation(rotate);
	}

	sf::Time getTime()
	{
		return _lifetime;
	}

	void render(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
};