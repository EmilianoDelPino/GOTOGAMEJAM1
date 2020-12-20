#include "Character.h"
#include <iostream>

void Character::setTexturaPlayer() {
	if (!_texture.loadFromFile("images/girl.png")) {
		std::cout << "Error girl.png" << std::endl;
	}

	_sprite.setTexture(_texture);

	sf::Vector2u sizeTexture = _texture.getSize();
	sizeTexture.x /= 8;
	sizeTexture.y /= 4;

	_sprite.setTextureRect(sf::IntRect(0, 0, sizeTexture.x, sizeTexture.y));
}

void Character::setPlayer() {
	_sprite.setPosition(sf::Vector2f(60.0f, 110.0f));
	_sprite.setOrigin(24, 44);
}

void Character::movePlayer(float frame, movement_type movement) 
{
	sf::Vector2u sizeTexture = _texture.getSize();
	sizeTexture.x /= 8;
	sizeTexture.y /= 4;

	switch (movement)
	{
	case movement_type::UP:
		_sprite.move(0.0f, -this->velocidad);
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 3, sizeTexture.x, sizeTexture.y));
		break;
	case movement_type::LEFT:
		_sprite.move(-this->velocidad, 0.0f);
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 1, sizeTexture.x, sizeTexture.y));
		break;
	case movement_type::DOWN:
		_sprite.move(0.0f, this->velocidad);
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), 0, sizeTexture.x, sizeTexture.y));
		break;
	case movement_type::RIGHT:
		_sprite.move(+this->velocidad, 0.0f);
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 2, sizeTexture.x, sizeTexture.y));
	}

}