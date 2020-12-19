#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Game
{
public:
    //Character player;
    float frame = 0.f;

    sf::RenderWindow window1;
    bool gameOver;
    sf::Event event;

    Character player;
    sf::Texture mapTexture;
    sf::Sprite map;

    Game();
    void initializer();
    void drawWindow();
    void eventListener();
    void gameLoop();

};

