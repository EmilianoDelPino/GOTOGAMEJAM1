#include "Entity.h"
Entity::Entity(std::string name, sf::Texture& texture)
{
	_name = name;
	_texture = texture;
}