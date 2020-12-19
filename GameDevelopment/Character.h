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

	void setPlayer();
	void setTexturaPlayer();
	void movePlayer(float frame);

};

