#include "Menu.hpp"



Menu::Menu(Game* game)
{
	this->game = game;

	this->selected = 1;

	this->title_name = new sf::Text();
	this->start = new sf::Text();
	this->settings = new sf::Text();
	this->exit = new sf::Text();
	this->authors = new sf::Text();

	this->menu_music = new sf::Music();

	this->bg_texture = new sf::Texture();
	this->background = new sf::Sprite();

	///////////////////////////////////////////
	if (!font.loadFromFile("data/font.ttf"))
		std::cout << "ERROR!";
	if (!menu_music->openFromFile("data/menu_music.ogg"))
		std::cout << "ERROR MUSIC";
	if (!bg_texture->loadFromFile("data/bg.jpg"))
		std::cout << "ERROR TEXTURE";

	this->background->setTexture(*bg_texture);

	this->menu_music->setVolume(25);
	this->menu_music->setLoop(true);
	this->menu_music->play();

	this->title_name->setFont(font);
	this->start->setFont(font);
	this->settings->setFont(font);
	this->exit->setFont(font);
	this->authors->setFont(font);

	this->title_name->setString("PAPAJMAN");
	this->title_name->setCharacterSize(80);
	this->title_name->setPosition(sf::Vector2f(this->game->window.getSize().x / 2 - title_name->getGlobalBounds().width/2, 50.f));
	this->title_name->setFillColor(sf::Color(101, 105, 0));

	this->start->setString("Start");
	this->start->setCharacterSize(60);
	this->start->setPosition(sf::Vector2f(this->game->window.getSize().x / 2 - title_name->getGlobalBounds().width / 2, 200.f));

	this->settings->setString("Settings");
	this->settings->setCharacterSize(60);
	this->settings->setPosition(sf::Vector2f(this->game->window.getSize().x / 2 - title_name->getGlobalBounds().width / 2, 275.f));

	this->exit->setString("Exit");
	this->exit->setCharacterSize(60);
	this->exit->setPosition(sf::Vector2f(this->game->window.getSize().x / 2 - title_name->getGlobalBounds().width / 2, 350.f));

	this->authors->setString("by kamilosxp & StreetWorkoutPoland Urban II");
	this->authors->setCharacterSize(15);
	this->authors->setPosition(sf::Vector2f(this->game->window.getSize().x - 170.f - title_name->getGlobalBounds().width / 2, 570.f));
}


Menu::~Menu()
{
	delete this->title_name;
	delete this->start;
	delete this->settings;
	delete this->exit;
	delete this->authors;
	delete this->menu_music;
}

void Menu::draw(const float dt)
{

	this->start->setFillColor(sf::Color(101, 76, 99));
	this->settings->setFillColor(sf::Color(101, 76, 99));
	this->exit->setFillColor(sf::Color(101, 76, 99));

	if (selected == 1)
		start->setFillColor(sf::Color::Green);
	else if (selected == 2)
		settings->setFillColor(sf::Color::Green);
	else
		exit->setFillColor(sf::Color::Green);

	//this->game->window.draw(*background);
	this->game->window.draw(*title_name);
	this->game->window.draw(*start);
	this->game->window.draw(*settings);
	this->game->window.draw(*exit);
	this->game->window.draw(*authors);
}

void Menu::update(const float dt)
{

}

void Menu::handleInput()
{
	while (this->game->window.pollEvent(this->game->event))
	{
		if (this->game->event.type == sf::Event::Closed || this->game->event.key.code == sf::Keyboard::Escape)
			this->game->window.close();
		if (this->game->event.type == sf::Event::KeyPressed || this->game->event.key.code == sf::Keyboard::Up)
		{
			if (selected == 1)
				selected = 3;
			else
				selected -= 1;
		}

		if (this->game->event.type == sf::Event::KeyPressed || this->game->event.key.code == sf::Keyboard::Down)
		{
			if (selected < 3)
				selected += 1;
			else
				selected = 1;
		}
		if (this->game->event.key.code == sf::Keyboard::Return)
		{
			switch (selected)
			{
			case 1:
			{
				menu_music->stop();
				this->game->pushState(new GamePlay(game));
			}
			break;
			case 2:
			{

			}
			break;
			case 3:
			{
				this->game->window.close();
			}
			break;
			}
		}

	}
}
