#pragma once
#include "Entity.hpp"

class Player :public Entity
{
public:
	Player(sf::Vector2f);
	~Player();

	void move(sf::Event*);
	void update();
};

