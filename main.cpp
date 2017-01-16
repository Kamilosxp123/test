#include "Game.hpp"
#include "Menu.hpp"

int main()
{
	Game Game;
	Game.pushState(new Menu(&Game));
	Game.gameLoop();

	return 0;
}