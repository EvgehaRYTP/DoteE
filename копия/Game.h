#pragma once

#include <sstream>

#include "Player.h"
#include "Bullet.h"
//#include "View.h"
#include "Planet.h"
#include "ParticleSystem.h"
#include "Asteroids.h"

//Test
#include "CircleCollision.h"
#include "ParticleTest.h"

#include <list>

const float W = 3840;
const float H = 2160;

class Game
{
private:
	/*
	playerInfo* playersInfoArray;
	backgroundAsteroid* backgroundAsteroidsArray;
	gui gameGui;
	info gameInfo;*/
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	Player *player;
	Bullet bullet;
	Planet planet;
	
	std::vector<Bullet*> bullets;
	std::vector<Asteroids*> asteroids;
	ParticleSystem particle_smoke_ship;

	std::vector<ParticleT*> pp;

	View view;

	int nGui;
	bool stateGui;
	bool pause;
	bool tmpPauseKey;

	int time;
	int countFrames;
	int score;

	bool whichPause;
	bool gameOver;
	bool canAttack;

	float speedTEST;

	sf::Vector2f aimDir;
	sf::Vector2f mouse_position;
	sf::Vector2f aimDirNorm;

	sf::Time spawnTimer;
	sf::Time spawnTimerMax;
	sf::Time attackTimer;

	sf::Text textscore;
	sf::Font font;

	void initAsteroids();
public:
	Game();
	sf::View CoorPlayer(float _PlayerPosX, float _PlayerPosY)
	{
		float tempX = _PlayerPosX;
		float tempY = _PlayerPosY;


		//2716
		//1810
		//3840
		//2160
		if (_PlayerPosX < W / 4) tempX = W / 4; //Left
		if (_PlayerPosY < H / 4) tempY = H / 4; //Up
		if (_PlayerPosX > W - (W / 4)) tempX = W - (W / 4); //Right
		if (_PlayerPosY > H - (H / 4)) tempY = H - (H / 4); //Down

		//formula

		view.setCenter(tempX, tempY);
		return view;
	}
	void init();
	void initGUI();
	void updatePlayer(sf::Time dt, sf::RenderWindow& window);
	void updateAsteroids(sf::Time dt);
	void updateBullets(sf::Time dt);
	void updateCollision();
	void update(sf::RenderWindow& window, sf::Time _elapsed);
	//void detectCollisions(sf::RenderWindow& window);
	void setKey(int key, int playerNumber, bool value);
	void setPause(bool which);
	bool getPause() { return pause; };
	//void savePlayerInfo();
	//void saveGameStatus();
	//void loadGame();
	bool getGameOver() { return gameOver; };
	void render(sf::RenderWindow& window);
};

