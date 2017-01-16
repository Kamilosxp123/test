#pragma once
#include "GameState.hpp"
#include <iostream>
#include <SFML\Audio.hpp>
#include "GamePlay.hpp"

class Menu :
	public GameState
{
public:
	Menu(Game*);
	~Menu();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

private:
	sf::Font font;
	sf::Text *title_name, *start, *settings, *exit, *authors;

	sf::Music *menu_music;

	sf::Sprite *background;
	sf::Texture *bg_texture;

	uint8_t selected;
};

