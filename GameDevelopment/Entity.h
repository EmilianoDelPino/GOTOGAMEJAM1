#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	bool _life;
	std::string _name;
	sf::Sprite _sprite;
	sf::Texture _texture;
	void draw(sf::RenderWindow& app)
	{
		app.draw(_sprite);
	}
};

