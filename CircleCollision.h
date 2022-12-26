#pragma once
#include <SFML/Graphics.hpp>

inline bool checkcolissionCircleSprite(sf::CircleShape circle, sf::Sprite sprite)
{
	sf::Vector2f CircleDistance;
	float CircleDistance_sq;

	CircleDistance.x = abs(circle.getPosition().x - sprite.getPosition().x);
	CircleDistance.y = abs(circle.getPosition().y - sprite.getPosition().y);

	if (CircleDistance.x > (sprite.getGlobalBounds().width / 2 + circle.getRadius())) 
	{
		return false; 
	}
	if (CircleDistance.y > (sprite.getGlobalBounds().height / 2 + circle.getRadius())) 
	{
		return false; 
	}
	if (CircleDistance.x <= (sprite.getGlobalBounds().width / 2)) 
	{ 
		return true; 
	}
	if (CircleDistance.y <= (sprite.getGlobalBounds().height / 2)) 
	{ 
		return true; 
	}

	CircleDistance_sq = (pow(CircleDistance.x - sprite.getGlobalBounds().width / 2, 2) +
					     pow(CircleDistance.y - sprite.getGlobalBounds().height / 2, 2));


	if (CircleDistance_sq <= (pow(circle.getRadius(), 2)))
	{
		return true;
	}
}