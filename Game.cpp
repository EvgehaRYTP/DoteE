#pragma warning(disable : 4996)

#include "Game.h"

void Game::initAsteroids()
{
	spawnTimerMax = sf::seconds(5);
	spawnTimer = spawnTimerMax;

	canAttack;
}

Game::Game()
	//asteroids(20)
{
	speedTEST = 1;
	player = new Player();
	paticlecontroller = new PARTICLE_CONTROLLER2();
	particle_smoke_ship;

	attackTimer = sf::seconds(0.5);

	initAsteroids();
}

void Game::init()
{
	textureBackground.loadFromFile("res\\textures\\testfon.jpg");
	textureBackground.setSmooth(true);
	spriteBackground.setTexture(textureBackground);

	player->setPosition(sf::Vector2f(980.f, 540.f));
	planet.setPosition((float)textureBackground.getSize().x / 2, (float)textureBackground.getSize().y / 2);

	//asteroid.setPosition(sf::Vector2f(0, 500));
	view.reset(FloatRect(0, 0, 1920, 1080));
	//view.zoom(0.5);

	pause = 0;
	//time = 0;
//	countFrames = 0;
//	tmpPauseKey = 1;
}

void Game::initGUI()
{
	font.loadFromFile("res\\fonts\\AuX_DotBitC_Xtra_Bold.ttf");

	textscore.setFont(font);
	textscore.setCharacterSize(30);
	textscore.setColor(Color::Blue);
	textscore.setPosition(30, 0);
	
	std::ostringstream points;
	points << score;

	textscore.setString("SCORE " + points.str());
}

void Game::updatePlayer(sf::Time dt, sf::RenderWindow& window)
{
	sf::Vector2f bullet_position = player->playerSprite.getTransform().transformPoint(55, 18);
sf::Vector2f vd = player->mousePosition(window) - player->getPosition();

aimDir = vd;
aimDirNorm.x = aimDir.x / (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
aimDirNorm.y = aimDir.y / (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

player->setRotation(sf::Vector2f(vd.x, vd.y));


if (Keyboard::isKeyPressed(Keyboard::W))
{
	player->setMovable(true);
	//pp.push_back(new ParticleT(player->playerSprite.getTransform().transformPoint(-20, 10), 5));
	paticlecontroller->FireEngine(player->playerSprite.getTransform().transformPoint(-20, 15), player->getRotation() - 90);
	paticlecontroller->SmokeEngine(player->playerSprite.getTransform().transformPoint(-30, 15) + sf::Vector2f(cos((std::rand() % 360) * 3.14f / 180.f), sin((std::rand() % 360) * 3.14f / 180.f)) * 15.f, player->getRotation());
}
else {
	player->setMovable(false);
}
player->move(dt, player->mousePosition(window));

//else player->setScaleSpeed(50.f);




std::size_t counter = 0;
for (auto* p : pp)
{
	p->update(dt);
}

for (std::size_t i = 0; i < pp.size(); i++)
{

	if (pp[i]->getTime() <= sf::Time::Zero)
	{
		delete pp.at(i);
		pp.erase(pp.begin() + i);
	}
}
}


void Game::updateAsteroids(sf::Time dt)
{
	sf::Vector2f rSpawn1 = sf::Vector2f(math::randomFLOAT(0, 0), math::randomFLOAT(0, 2160));
	sf::Vector2f rSpawn2 = sf::Vector2f(math::randomFLOAT(0, 3840), math::randomFLOAT(0, 0));
	sf::Vector2f rSpawn3 = sf::Vector2f(math::randomFLOAT(3840, 3840), math::randomFLOAT(0, 2160));
	sf::Vector2f rSpawn4 = sf::Vector2f(math::randomFLOAT(0, 3840), math::randomFLOAT(2160, 2160));

	sf::Vector2f asteroid_spawn;

	int selectSpawn = rand() % 4;
	std::cout << selectSpawn << std::endl;
	spawnTimerMax -= dt;
	if (spawnTimerMax <= Time::Zero)
	{
		switch (selectSpawn)
		{
		case 0:
			asteroid_spawn = rSpawn1;
			break;
		case 1:
			asteroid_spawn = rSpawn2;
			break;
		case 2:
			asteroid_spawn = rSpawn3;
			break;
		case 3:
			asteroid_spawn = rSpawn4;
			break;
		}
		asteroids.push_back(new Asteroids(asteroid_spawn));

		spawnTimerMax = sf::seconds(3);
	}

	std::size_t counter = 0;
	for (std::size_t i = 0; i < asteroids.size(); i++)
	{
		paticlecontroller->SmokeAsteroidEngine(asteroids[i]->getPosition() + sf::Vector2f(cos((std::rand() % 360) * 3.14f / 180.f), sin((std::rand() % 360) * 3.14f / 180.f)) * 15.f, asteroids[i]->getRotation());
		asteroids[i]->update(dt);

		if (Collision::PixelPerfectTest(planet.getCircle(), asteroids[i]->getAsteroid()))
		{
			delete asteroids.at(i);
			asteroids.erase(asteroids.begin() + i);
		}
	}
}

void Game::updateBullets(sf::Time dt)
{
	attackTimer -= dt;
	if (attackTimer <= Time::Zero)
	{
		canAttack = true;
		attackTimer = sf::seconds(0.08);
	}
	else canAttack = false;

	if (Mouse::isButtonPressed(Mouse::Left) && canAttack)
	{
		bullets.push_back(new Bullet(500.f, player->getPosition(), player->getRotation() + 90, aimDirNorm));
	}
	std::size_t counter = 0;

	for (std::size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->update(dt);

		if (bullets[i]->getPosition().x < 0 ||
			bullets[i]->getPosition().x > 3840 ||
			bullets[i]->getPosition().y < 0 ||
			bullets[i]->getPosition().y > 2160)
		{
			delete bullets.at(i);
			bullets.erase(bullets.begin() + i);
		}

		/*if (checkcolissionCircleSprite(planet.getCircle(), bullets[i]->getBullet()))
		{
			delete bullets.at(i);
			bullets.erase(bullets.begin() + i);
		}*/

		if (Collision::PixelPerfectTest(planet.getCircle(), bullets[i]->getBullet()))
		{
			delete bullets.at(i);
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Game::updateCollision()
{
	for (std::size_t i = 0; i < asteroids.size(); i++)
	{
		for (std::size_t j = 0; j < bullets.size(); j++)
		{
			//if (asteroids[i]->getBounds().intersects(bullets[j]->getBounds()))
			//{
			//	//std::cout << "YES" << std::endl;
			//	delete asteroids[i];
			//	asteroids.erase(asteroids.begin() + i);

			//	delete bullets[j];
			//	bullets.erase(bullets.begin() + j);

			//	score++;
			//}

			if (Collision::PixelPerfectTest(bullets[j]->getBullet(), asteroids[i]->getAsteroid()))
			{
				delete asteroids[i];
				asteroids.erase(asteroids.begin() + i);

				delete bullets[j];
				bullets.erase(bullets.begin() + j);

				score++;
			}
		}
	}
}

void Game::update(sf::RenderWindow& window, sf::Time _elapsed)
{
	if (!pause)
	{
		updatePlayer(_elapsed, window);

		updateAsteroids(_elapsed);

		updateBullets(_elapsed);

		//planet.update(_elapsed);

		updateCollision();

		CoorPlayer(player->getPosition().x, player->getPosition().y);

		initGUI();

		//Particles
		particle_smoke_ship.SetPosition(player->playerSprite.getTransform().transformPoint(10, 5));
		particle_smoke_ship.setRotation((-std::atan2(player->getPosition().x, player->getPosition().y) * 180.f / 3.14f) + 90);
		particle_smoke_ship.update(_elapsed);

		//
		paticlecontroller->update(_elapsed);
		//std::cout << score << std::endl;

		/*if (Mouse::isButtonPressed(Mouse::Left))
		{
			bullet.setPosition(bullet_position);
			bullet.spriteBullet.setRotation((std::atan2(vd.y, vd.x) * 180.f / 3.14f) + 90);
			bullet.curretVelocity = aimDirNorm * bullet.maxspeed;

			this->bullets.push_back(Bullet(bullet));
		}

		for (std::size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].spriteBullet.move(bullets[i].curretVelocity);
		}*/
	}
}

void Game::setKey(int key, int playerNumber, bool value)
{
}

void Game::setPause(bool which)
{
	this->whichPause = which;
	this->pause = !this->pause;
}

void Game::render(sf::RenderWindow& window)
{
	window.draw(spriteBackground);


	paticlecontroller->render(window);


	window.setView(view);

	for (std::size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->render(window);
	}

	/*for (auto* _bullet : bullets)
	{
		_bullet->render(window);
	}*/

	planet.render(window);

	for (auto *_asteroid : asteroids)
	{
		_asteroid->render(window);
	}
	//particle_smoke_ship.render(window);

	for (auto *p : pp)
	{
		p->render(window);
	}

	player->render(window);

	//window.draw(textscore);



	/*if (pause) {
		if (whichPause) {
			gameInfo.draw(window, "pause_", "quit?_(ENTER_for_yes)", "quit_and_save?_(S_for_yes)");
		}
		else {
			gameInfo.draw(window, "pause_", "first_player:_WSAD_keys_and_SPACE", "second_player:_arrow_keys_and_ENTER");
		}
	}*/
}
