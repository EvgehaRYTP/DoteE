#include "ParticleSystem.h"
#include "hMATH.h"

void ParticleSystem::init()
{
	texture.loadFromFile("res\\textures\\particle_smoke.png");
	texture.setSmooth(true);
}

void ParticleSystem::Reset(std::size_t index)
{
	//float _angle = random(0, 6.2831);
	float _angle = math::randomFLOAT(0, 360);
	float random_radius = math::randomFLOAT(0, 50);

	float speed = math::randomFLOAT(70, 100);
	float ANGLE = (std::rand() % 360) * 3.14f / 180.f;
	float scale = math::randomFLOAT(0.05, 0.17);

	/*m_particles[index].velocity = sf::Vector2f(std::cos(ANGLE) * speed, std::sin(ANGLE) * speed);*/
	m_particles[index].velocity = sf::Vector2f(5 + math::randomFLOAT(0, 20), 5 + math::randomFLOAT(0, 20));
	m_particles[index].lifetime = sf::milliseconds((std::rand() % 3000) + 1000);

	sprites[index].setTexture(texture);
	sprites[index].setScale(scale, scale);
	sprites[index].setPosition(start_pos + sf::Vector2f(cos(ANGLE), sin(ANGLE)) * random_radius);
}

ParticleSystem::ParticleSystem():
	m_lifetime(sf::seconds(3.f)),
	m_particles(100),
	sprites(100)
{
	this->init();
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::SetPosition(sf::Vector2f position)
{
	start_pos = position;
}

void ParticleSystem::setRotation(float rotate)
{
	coord_rotate = rotate;
}

void ParticleSystem::update(sf::Time elapsed)
{
	for (std::size_t i = 0; i < m_particles.size(); i++)
	{
		Particle& p = m_particles[i];
		p.lifetime -= elapsed;

		if (p.lifetime <= sf::Time::Zero) {
			Reset(i);
		}

		sprites[i].move(p.velocity * elapsed.asSeconds());
		//sprites[i].rotate(-1.5);
		sprites[i].setRotation(coord_rotate);

		float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
		color.a = static_cast<sf::Uint8>(ratio * 100);
		sprites[i].setColor(sf::Color(255, 255, 255, color.a));
	}
}

void ParticleSystem::render(sf::RenderWindow& window)
{
	for (std::size_t i = 0; i < m_particles.size(); i++)
	{
		window.draw(sprites[i]);
	}
}
