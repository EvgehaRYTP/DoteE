#pragma once
#include <SFML/Graphics.hpp>

class ParticleSystem
{
private:
	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time lifetime;
	};

	std::vector<Particle> m_particles;
	std::vector<sf::Sprite> sprites;

	sf::Time m_lifetime;
	sf::Texture texture;
	sf::Vector2f start_pos;
	float coord_rotate;
	sf::Vector2f particles_scale;
	sf::Color color;

	void init();
	void Reset(std::size_t index);
public:
	ParticleSystem();
	~ParticleSystem();

	void SetPosition(sf::Vector2f position);
	void setRotation(float rotate);
	void update(sf::Time elapsed);
	void render(sf::RenderWindow& window);

};

