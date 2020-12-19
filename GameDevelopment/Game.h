#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "TileMap.h"
#include "Entity.h"
#include <list>

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

    std::list<Entity*> entities;

    sf::Texture libroTexture;
    sf::Texture discoTexture;

    std::vector<sf::FloatRect>vectorColisiones;

    Game();
    void initializer();
    void drawWindow();
    void eventListener();
    void gameLoop();

};

