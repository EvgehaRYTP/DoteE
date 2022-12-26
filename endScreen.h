#pragma once

#include <SFML/Graphics.hpp>

class endScreen
{
private:
	sf::Font font;
	sf::Text text;
	int frames;
public:
	endScreen();
	~endScreen();

	void draw(sf::RenderWindow& window);
};

