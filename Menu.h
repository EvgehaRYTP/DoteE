#pragma once

#include <SFML/Graphics.hpp>

#define MAX_MENU_LEVELS 4

class Menu
{
private:
	sf::Font font;
	sf::Text menuText[MAX_MENU_LEVELS];
	sf::Text scoresText[6];
	sf::Text clearScoresText;
	int selectedItem;
	bool next;
	int recordsN;
	bool loadAvailable;
	//void addScores(FILE* fp);

public:
	Menu();
	~Menu();

	void moveUp();
	void moveDown();
	int getSelectedItem() { return selectedItem; }
	void draw(sf::RenderWindow& window);
	void setNext();
	bool getNext() { return next; };
	//void clearScores();
};

