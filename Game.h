#pragma once
#include "SFML\Graphics\RenderWindow.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Draw.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();
	void Draw();
private:
	sf::RenderWindow* window;
	sf::Event event;

	enum state {
		GAME,
		END
	};
	state states;

	Player *player;
	Enemy *enemy;
	Drawing draw;
};

