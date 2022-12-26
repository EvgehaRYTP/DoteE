#pragma once
#include <SFML/Graphics.hpp>
class PARTICLE_SYSTEM2
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Color color;

	sf::Vector2f velocity;
	sf::Vector2f position;

	float angle;
	float angle_vel;
	float size;
	float size_vel;

	sf::Time lifetime;
public:
	PARTICLE_SYSTEM2(sf::Texture _texture, sf::Vector2f _velocity, sf::Vector2f _position, float _angle, float _angle_vel, float _size, float _size_vel, sf::Time _lifetime, sf::Color _color)
	{
		texture = _texture;
		color = _color;

		velocity = _velocity;
		position = _position;

		angle = _angle;
		angle_vel = _angle_vel;
		size = _size;
		size_vel = _size_vel;

		lifetime = _lifetime;
		//?
		//texture.loadFromFile("res\\textures\\fire_splash_particle.png");
		texture.setSmooth(true);
		float ANGLE = (std::rand() % 360) * 3.14f / 180.f;
		sprite.setTexture(texture);
		sprite.setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().y / 2);
		sprite.setPosition(position);
		sprite.setRotation(angle);
	}

	bool Dissapear()
	{
		return lifetime <= sf::Time::Zero || size <= 0;
	}

	void update(sf::Time dt)
	{
		lifetime -= dt;

		position += velocity * dt.asSeconds();
		angle += angle_vel * dt.asSeconds();
		size += size_vel * dt.asSeconds();

		sprite.setPosition(position);
		sprite.setScale(size, size);
		sprite.setColor(color);

	}

	void render(sf::RenderWindow& window)
	{
		window.draw(sprite);
	}
};

