#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
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

    sf::Texture mapTilesTexture2;
    sf::Sprite mapTilesSprite2;

    TileMap mapTiles;
    TileMap mapTiles2;

    std::list<Entity*> entities;

    sf::Texture libroTexture;
    sf::Texture discoTexture;
    sf::Texture puertaTexture;

    std::vector<sf::FloatRect>vectorColisiones;
    std::vector<sf::FloatRect>vectorColisiones2;

    bool level1 = true;

    sf::SoundBuffer buffer;
    sf::Sound winSound;

    Game();
    void initializer();
    void drawWindow();
    void eventListener();
    void gameLoop();
    bool CanItMove(movement_type type, Character* player);
    void cargarEntidadeslvl1();
    void cargarEntidadeslvl2();
    void gameOverScreen();
    void menuPregunta(bool);

};

