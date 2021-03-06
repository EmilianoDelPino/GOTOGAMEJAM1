#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	Entity() {
		_life = 1;
	};
	float _x, _y;
	Entity(std::string name, sf::Texture& ,int x , int y);
	bool _life;
	std::string _name;
	sf::Sprite _sprite;
	sf::Texture _texture;
	virtual void draw(sf::RenderWindow& app)
	{
		app.draw(_sprite);
	}
};

