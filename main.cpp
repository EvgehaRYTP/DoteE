#pragma warning(disable : 4996)
#include "Menu.h"
#include "Game.h"
#include "endScreen.h"

using namespace sf;

int main()
{
    srand((unsigned int)time(NULL));

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	//window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Time time;
	sf::Time elapsed;
	int activity = 0;

    Menu menu;
	Game game;
    endScreen end;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (activity == 0) {
					if (event.key.code == sf::Keyboard::Up) {
						menu.moveUp();
					}
					else if (event.key.code == sf::Keyboard::Down) {
						menu.moveDown();
					}
					else if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1) {
						if (!menu.getNext()) {
							//other::DIFFICULTY = 0;
							activity = 1;
							game.init();
						}
						else {
							//other::MAX_PLAYERS = 1;
							menu.setNext();
						}
					}
					else if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2) {
						if (menu.getNext()) {
							//other::DIFFICULTY = 1;
							activity = 1;
							game.init();
						}
						else {
							//other::MAX_PLAYERS = 2;
							menu.setNext();
						}
					}
					else if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3) {
						window.close();
						return 0;
					}
					/*else if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 4) {
						window.close();
						return 0;
					}*/
					else if (event.key.code == sf::Keyboard::C) {
						//menu.clearScores();
					}
				}
				else if (activity == 1) {
					if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Space) {
						game.setKey(event.key.code, 0, true);
					}
					else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Enter) {
						game.setKey(event.key.code, 1, true);
						if (event.key.code == sf::Keyboard::Enter && game.getPause()) {
							window.close();
						}
					}
					else if (event.key.code == sf::Keyboard::P) {
						std::cout << "Pause true" << std::endl;
						game.setPause(0);
					}
					else if (event.key.code == sf::Keyboard::Escape) {
						std::cout << "Pause false" << std::endl;
						game.setPause(1);
					}
					else if (event.key.code == sf::Keyboard::S && game.getPause()) {
						//game.saveGameStatus();
						window.close();
						return 0;
					}
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (activity == 1) {
					if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Space) {
						game.setKey(event.key.code, 0, false);
					}
					else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Enter) {
						game.setKey(event.key.code, 1, false);
					}
				}
			}
			if (event.type == sf::Event::Resized) {
				//sf::Vector2u size(WIDTH, HEIGHT);
				//window.setSize(size);
			}
		}
		time = clock.getElapsedTime();
		if (1 < 2) {
			if (activity == 1) {
				game.update(window, elapsed);
				//game.detectCollisions(window);
				if (game.getGameOver()) activity = 2;
			}
			window.clear();
			if (activity == 0) {
				menu.draw(window);
			}
			else if (activity == 1) {
				game.render(window);
			}
			else if (activity == 2) {
				end.draw(window);
			}
			elapsed = clock.restart();
			window.display();
			//clock.restart();
		}
	}

    return 0;
}