#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

sf::View viewPlayer;

View getPlayerCoor(float _PlayerPosX, float _PlayerPosY)
{
	float tempX = _PlayerPosX;
	float tempY = _PlayerPosY;
	
	//if (_PlayerPosX < 600) tempX = 600; //Left
	//if (_PlayerPosY < 800) tempY = 880; //Up
	//if (_PlayerPosY > 0) tempY = 0; //Down
	//if (_PlayerPosX > 1980) tempX = 0; // Right

	viewPlayer.setCenter(tempX, tempY);
	return viewPlayer;
}
