#include "Entity.h"
Entity::Entity(std::string name, sf::Texture& texture, int x , int y)
{
	_life = 1;
	_name = name;
	_texture = texture;
	_sprite.setTexture(_texture);
	_sprite.setPosition(x, y);
}