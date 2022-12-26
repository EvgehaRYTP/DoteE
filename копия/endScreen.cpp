#include "endScreen.h"

endScreen::endScreen()
{
	frames = 0;
	font.loadFromFile("res\\fonts\\AuX_DotBitC_Xtra_Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setString("game_over");
	text.setPosition(sf::Vector2f(40, 1080 - 100));
}

endScreen::~endScreen()
{
}

void endScreen::draw(sf::RenderWindow& window)
{
	window.draw(text);

	if (frames >= 50) 
		window.close();

	frames++;
}
