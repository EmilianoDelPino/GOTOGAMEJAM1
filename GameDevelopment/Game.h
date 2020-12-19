#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "TileMap.h"

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
    TileMap mapTiles;

    Game();
    void initializer();
    void drawWindow();
    void eventListener();
    void gameLoop();

};

