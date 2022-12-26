#include "Menu.h"

Menu::Menu()
{
	selectedItem = 1;

	font.loadFromFile("res\\fonts\\AuX_DotBitC_Xtra_Bold.ttf");
	menuText[0].setFont(font);
	menuText[0].setCharacterSize(40);
	menuText[0].setString("DtE");
	menuText[0].setPosition(200, 200);

	menuText[1].setFont(font);
	menuText[1].setCharacterSize(40);
	menuText[1].setString("new_game <<");
	menuText[1].setPosition(200, 300);

	menuText[2].setFont(font);
	menuText[2].setCharacterSize(40);
	menuText[2].setString("about");
	menuText[2].setPosition(200, 350);

	menuText[3].setFont(font);
	menuText[3].setCharacterSize(40);
	menuText[3].setString("exit");
	menuText[3].setPosition(200, 500);
	menuText[3].setFillColor(loadAvailable ? sf::Color::White : sf::Color(128, 128, 128));
	
	//menuText[4].setFont(font);
	//menuText[4].setCharacterSize(40);
	//menuText[4].setString("quit");
	//menuText[4].setPosition(sf::Vector2f(40, 1080 - 40 - (MAX_MENU_LEVELS - 4) * 60));
}

Menu::~Menu()
{
}

void Menu::moveUp()
{
	if (selectedItem == 1) {
		if (!next) menuText[selectedItem].setString("new_game");
		//else menuText[selectedItem].setString("easy");
	}
	else if (selectedItem == 2) {
		if (!next) menuText[selectedItem].setString("about");
		//else menuText[selectedItem].setString("hard");
	}
	else if (selectedItem == 3) menuText[selectedItem].setString("exit");
	//else if (selectedItem == 4) menuText[selectedItem].setString("quit");

	if ((selectedItem == 4) && !loadAvailable) {
		selectedItem -= 2;
	}
	else selectedItem--;
	if (selectedItem < 1) selectedItem = MAX_MENU_LEVELS - 1;
	if (selectedItem == 1) {
		if (!next) menuText[selectedItem].setString("new_game <<");
		//else menuText[selectedItem].setString("easy <<");
	}
	else if (selectedItem == 2) {
		if (!next) menuText[selectedItem].setString("about <<");
		//else menuText[selectedItem].setString("hard <<");
	}
	else if (selectedItem == 3) menuText[selectedItem].setString("exit <<");
	//else if (selectedItem == 4) menuText[selectedItem].setString("quit <<");
}

void Menu::moveDown()
{
	if (selectedItem == 1) {
		if (!next) menuText[selectedItem].setString("new_game");
		//else menuText[selectedItem].setString("easy");
	}
	else if (selectedItem == 2) {
		if (!next) menuText[selectedItem].setString("about");
		//else menuText[selectedItem].setString("hard");
	}
	else if (selectedItem == 3) menuText[selectedItem].setString("exit");
	//else if (selectedItem == 4) menuText[selectedItem].setString("exit");
	if ((selectedItem == 4) && !loadAvailable) {
		selectedItem += 2;
	}
	else selectedItem++;
	if (selectedItem >= MAX_MENU_LEVELS) selectedItem = 1;
	if (selectedItem == 1) {
		if (!next) menuText[selectedItem].setString("new_game <<");
		//else menuText[selectedItem].setString("easy <<");
	}
	else if (selectedItem == 2) {
		if (!next) menuText[selectedItem].setString("about <<");
		//else menuText[selectedItem].setString("hard <<");
	}
	else if (selectedItem == 3) menuText[selectedItem].setString("exit <<");
	//else if (selectedItem == 4) menuText[selectedItem].setString("quit <<");
}

void Menu::draw(sf::RenderWindow& window)
{
	for (std::size_t i = 0; i < MAX_MENU_LEVELS; i++) {
		window.draw(menuText[i]);
	}
}

void Menu::setNext()
{
	next = 1;
	selectedItem = 1;

	/*menuText[1].setString("easy <<");
	menuText[2].setString("hard");*/
}
