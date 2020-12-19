#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Character : public Entity
{
    public:
    Character(){};
    float frame = 0.f;

	float inteligencia = 0;
	float carisma = 0;
	float puntajeTotal = 0;

	bool izq = false;

	void setPlayer();
	void setTexturaPlayer();
	void movePlayer(float frame);
	
	void draw(sf::RenderWindow& app)
	{
		if (!izq)
		{
			_sprite.setPosition(_x, _y);
		}
		else
		{
			_sprite.setPosition(_x+_sprite.getGlobalBounds().width, _y);
		}
		
		app.draw(_sprite);
	}

};

