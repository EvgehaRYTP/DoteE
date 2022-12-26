#pragma once
#include "PARTICLE_SYSTEM2.h"
#include "hMATH.h"
class PARTICLE_CONTROLLER2
{
private:
	
	std::vector<PARTICLE_SYSTEM2*> particles;
	//sf::Texture fire_texture;
public:

	PARTICLE_CONTROLLER2()
	{
	}

	void FireEngine(sf::Vector2f position, float angle)
	{
		sf::Texture texture;
		sf::Color color;

		texture.loadFromFile("res\\textures\\fire_splash_particle.png");
		/*position.x += 2;
		position.y += ;*/
		//Skorost
		sf::Vector2f velocity = AngleToVecto2(angle, math::randomFLOAT(0, 5));
		//Ugol
		//float angle = 3.14f * 2 * math::randomFLOAT(0, 360);
		//float angle_vel = (-5.f + 1.f * math::randomFLOAT(0, 360));
		float angle_vel = 1;
		//float size = math::randomFLOAT(0.02, 0.09);
		float size = 0.05;
		float size_vel = 0.f;

		sf::Time lifetime = sf::seconds(0.05);
		color = sf::Color(255, 255, 255, 255);

		ParticleGeneration(texture, velocity, position, angle, angle_vel, size, size_vel, lifetime, color);
	}

	void SmokeEngine(sf::Vector2f position, float angle)
	{
		sf::Texture texture;
		sf::Color color;

		texture.loadFromFile("res\\textures\\fire_particle3.png");
		/*position.x += 2;
		position.y += ;*/
		//Skorost
		sf::Vector2f velocity = AngleToVecto2(angle, math::randomFLOAT(40, 60));
		//Ugol
		//float angle = 3.14f * 2 * math::randomFLOAT(0, 360);
		float angle_vel = (-5.f + 1.f * math::randomFLOAT(0, 360));
		//float angle_vel = 1;
		float size = math::randomFLOAT(0.08, 0.23);
		float size_vel = 0.0015f;

		sf::Time lifetime = sf::seconds(3);
		//color = sf::Color(255, 130, 0, 145);
		color = sf::Color(255, 255, 255, 145);
		ParticleGeneration(texture, velocity, position, angle, angle_vel, size, size_vel, lifetime, color);
	}

	void SmokeAsteroidEngine(sf::Vector2f position, float angle)
	{
		sf::Texture texture;
		sf::Color color;

		texture.loadFromFile("res\\textures\\particle_smoke.png");
		//position + (position * 20.f);
		/*position.x += 2;
		position.y += ;*/
		//Skorost
		sf::Vector2f velocity = AngleToVecto2(angle, math::randomFLOAT(40, 60));
		//Ugol
		//float angle = 3.14f * 2 * math::randomFLOAT(0, 360);
		float angle_vel = (-5.f + 1.f * math::randomFLOAT(0, 360));
		//float angle_vel = 1;
		float size = math::randomFLOAT(0.08, 0.13);
		float size_vel = 0.0015f;

		sf::Time lifetime = sf::seconds(2);
		color = sf::Color(255, 255, 255, 145);
		ParticleGeneration(texture, velocity, position, angle, angle_vel, size, size_vel, lifetime, color);
	}

	void update(sf::Time dt)
	{
		for (std::size_t i = 0; i < particles.size(); i++)
		{
			if (!particles[i]->Dissapear())
			{
				particles[i]->update(dt);
			}
			else
			{
				delete particles.at(i);
				particles.erase(particles.begin() + i);
				//i--;
			}

			//float ratio = lifetime;
		}
	}

	void render(sf::RenderWindow& window)
	{
		for (int i = 0; i < particles.size(); i++)
		{
			particles[i]->render(window);
		}
	}

	sf::Vector2f AngleToVecto2(float angle, float speed)
	{
		sf::Vector2f direction;

		direction.x = speed * cos(angle);
		direction.y = speed * sin(angle);

		return direction;
	}

	void ParticleGeneration(sf::Texture _texture, sf::Vector2f _velocity, sf::Vector2f _position, float _angle, float _angle_vel, float _size, float _size_vel, sf::Time _lifetime, sf::Color _color)
	{
		particles.push_back(new PARTICLE_SYSTEM2(_texture, _velocity, _position, _angle, _angle_vel, _size, _size_vel, _lifetime, _color));
	}
};

