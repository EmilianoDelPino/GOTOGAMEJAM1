#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "TileMap.h"
#include "Entity.h"
#include <list>

class Game
{
public:
    sf::Font font;

    sf::Text *inteligenciaText;
    sf::Text *carismaText;
    sf::Text *puntajeTotalText;
    std::list<sf::Text*> textoParaMostrar;
    
    float frame = 0.f;

    sf::RenderWindow window1;
    bool gameOver;
    sf::Event event;

    Character player;
    sf::Texture mapTexture;
    sf::Sprite map;
    
    sf::Texture mapTilesTexture;
    sf::Sprite mapTilesSprite;
    TileMap mapTiles;

    std::list<Entity*> entities;

    

    sf::Texture libroTexture;
    sf::Texture discoTexture;
    sf::Texture puertaTexture;

    std::vector<sf::FloatRect>vectorColisiones;

    Game();
    void initializer();
    void drawWindow();
    void eventListener();
    void gameLoop();
    bool CanItMove(movement_type type, Character* player);
};

