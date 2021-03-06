#include "Game.hpp"
#include "GameState.hpp"

void Game::pushState(GameState* state)
{
	this->states.push(state);
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);
}

GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Papajman", sf::Style::Close);
	this->window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}