#pragma once
#include "GameState.hpp"
#include "Player.hpp"

class GamePlay :public GameState
{
public:
	GamePlay(Game*);
	~GamePlay();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

private:
	Player* player;
};

