#include "Entity.h"



Entity::Entity()
{
	this->spriteCharacter = NULL;
	this->spriteCharacter = new sf::Sprite();
}


Entity::~Entity()
{
}

void Entity::setTexture(std::string filename)
{
	this->texture.loadFromFile("data/" + filename);
	this->spriteCharacter->setTexture(texture);
	if (this->spriteCharacter != NULL)
		spriteCharacter->setOrigin(sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f));
}

void Entity::Move(sf::Event*)
{
}

void Entity::Update()
{
}

void Entity::Rotate(unsigned dir)
{
	switch (dir)
	{
	case 0:
		this->spriteCharacter->setRotation(-180.f);
		break;
	case 1:
		this->spriteCharacter->setRotation(0.f);
		break;
	case 2:
		this->spriteCharacter->setRotation(-90.f);
		break;
	case 3:
		this->spriteCharacter->setRotation(90.f);
		break;
	}
}
