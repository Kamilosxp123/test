#include "Player.hpp"



Player::Player(sf::Vector2f pos)
{
	this->isMonster = false;
	this->pos = sf::Vector2f(pos.x, pos.y);

	if (!this->character_texture.loadFromFile("data/player.png"))
		printf("ERROR PLAYER");

	this->character_sprite.setTexture(this->character_texture);
}


Player::~Player()
{
}

void Player::move(sf::Event* event)
{
	if (event->type == sf::Event::KeyPressed)
	{
		printf("test");
		if (event->key.code == sf::Keyboard::Left)
		{
			this->velocity.x = -5.f;
		}
		else if (event->key.code == sf::Keyboard::Right)
		{
			this->velocity.x = 5.f;
		}
		else if (event->key.code == sf::Keyboard::Up)
		{
			this->velocity.y = -5.f;
		}
		else if (event->key.code == sf::Keyboard::Down)
		{
			this->velocity.y = 5.f;
		}
	}
	else
	{
		this->velocity.x = 0.f;
		this->velocity.y = 0.f;
	}
}

void Player::update()
{
	this->character_sprite.move(sf::Vector2f(velocity.x, velocity.y));
}
