#include <SFML\Graphics.hpp>


class Entity
{
public:
	sf::Sprite character_sprite;
	sf::Texture character_texture;
protected:
	bool isMonster;

	sf::Vector2f pos;
	sf::Vector2f velocity;
};