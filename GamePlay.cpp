#include "GamePlay.hpp"



GamePlay::GamePlay(Game* game)
{
	this->game = game;

	player = new Player(sf::Vector2f(0.f, 0.f));

}


GamePlay::~GamePlay()
{
}

void GamePlay::draw(const float dt)
{
	this->game->window.draw(player->character_sprite);
}

void GamePlay::update(const float dt)
{
	player->move(&this->game->event);
	player->update();
}

void GamePlay::handleInput()
{
}
