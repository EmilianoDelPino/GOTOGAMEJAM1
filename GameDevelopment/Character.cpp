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

void Character::movePlayer(float frame) {
	sf::Vector2u sizeTexture = _texture.getSize();
	sizeTexture.x /= 8;
	sizeTexture.y /= 4;
	sf::Vector2f pos = _sprite.getPosition();
	int sw = _sprite.getGlobalBounds().width;
	int sh = _sprite.getGlobalBounds().height;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		std::cout << "W." << std::endl;
		if (pos.y >= 0 + (sh / 2))
		{
			//_sprite.move(sf::Vector2f(0.f, -5.0f));
			_y -= 5.0f;
		}
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 3, sizeTexture.x, sizeTexture.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "A." << std::endl;

		izq = true;

		if (pos.x >= 0 + (sh / 2))
		{
			//_sprite.move(sf::Vector2f(-5.0f, 0.f));
			_x -= 5.0f;
		}
		_sprite.setScale(-1, 1);
		//_sprite.setPosition(sf::Vector2f(_x+_sprite.getGlobalBounds().width*2, _y));
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 2, sizeTexture.x, sizeTexture.y));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			std::cout << "S." << std::endl;

			if (pos.y <= 720 - (sw / 2))
			{
				//_sprite.move(sf::Vector2f(0.f, 5.0f));
				_y += 5.0f;
			}

			_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 2, sizeTexture.x, sizeTexture.y));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
	{
		std::cout << "S." << std::endl;

		if (pos.y <= 720 - (sw / 2))
		{
			//_sprite.move(sf::Vector2f(0.f, 5.0f));
			_y += 5.0f;
		}
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), 0, sizeTexture.x, sizeTexture.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		std::cout << "D." << std::endl;
		izq = false;
		if (pos.x <= 1280 - (sw / 2))
		{
			//_sprite.move(sf::Vector2f(5.0f, 0.f));
			_x+= 5.0f;
		}
		_sprite.setScale(1, 1);
		_sprite.setPosition(sf::Vector2f(_sprite.getGlobalBounds().width , _y));
		_sprite.setTextureRect(sf::IntRect(sizeTexture.x * ((int)frame % 8), sizeTexture.y * 2, sizeTexture.x, sizeTexture.y));
	}
}