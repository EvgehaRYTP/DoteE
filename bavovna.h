#pragma once
//DODELAT SROCHNO!!!!!!!!
#include <SFML/Graphics.hpp>

class bavovna
{
private:
	
public:
	struct Particle
	{
		sf::Time lifetime;
		sf::Vector2f velocity;
	};
	sf::Texture* texture;
	sf::Sprite sprite;
;
	sf::Time m_lifetime;

	sf::Color color;
	sf::Vector2f emmiter;

	float scale;

	std::vector<sf::Sprite> sp;
	std::vector<Particle> m_particle;

	void init()
	{
		scale = 0.25f;
		texture->loadFromFile("res\\textures\\particle_fire2.png");
		texture->setSmooth(true);

		sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
		sprite.setScale(scale, scale);
	}

	bavovna(sf::Vector2f _emmiter):
		sp(10),
		m_particle(10),
		m_lifetime(sf::seconds(3))
	{
		init();
		emmiter = _emmiter;
	}

	void update(sf::Time dt)
	{
		for (int i = 0; i < m_particle.size(); i++)
		{
			Particle& p = m_particle[i];
			p.lifetime -= dt;

			if (p.lifetime <= sf::Time::Zero)
			{
				m_particle.erase(m_particle.begin() + i);
			}

			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
			color.a = static_cast<sf::Uint8>(ratio * 100);
			sp[i].setColor(sf::Color(255, 255, 255, color.a));
		}
	}

	void render(sf::RenderWindow& window)
	{
		for (int i = 0; i < m_particle.size(); i++)
		{
			window.draw(sp[i]);
		}
	}
};