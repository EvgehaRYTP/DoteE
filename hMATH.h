#pragma once

#include <iostream>
#include <cmath>
namespace math {
	inline float randomFLOAT(float min, float max)
	{
		return (float)(std::rand()) / RAND_MAX * (max - min) + min;
	}

	inline int randomINT(int min, int max)
	{
		return (std::rand()) / RAND_MAX * (max - min) + min;
	}
}


inline float distance(sf::Vector2f v1, sf::Vector2f v2)
{
	return sqrtf((v1 - v2).x * (v1 - v2).x + (v1 - v2).y * (v1 - v2).y);
}

inline float lenght(sf::Vector2f v1)
{
	return sqrtf(v1.x * v1.x + v1.y * v1.y);
}