#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "SFML/Audio.hpp"

enum class movement_type { UP, DOWN, LEFT, RIGHT };

class Character : public Entity
{
    public:
    Character(){};
    float frame = 0.f;
	float velocidad = 5.0f;

	int inteligencia = 0;
	int carisma = 0;
	int puntajeTotal = 0;

	bool izq = false;

	sf::SoundBuffer buffer2;
	sf::Sound walkSound;

	void setPlayer();
	void setTexturaPlayer();
	void movePlayer(float frame, movement_type movement);
	
};

