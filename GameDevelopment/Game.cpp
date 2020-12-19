#include "Game.h"
#include <iostream>
Game::Game()
{
    
}
void Game::initializer()
{
    gameOver = false;
    
    player.setTexturaPlayer();
    player.setPlayer();

    mapTexture.loadFromFile("images/map.png");
    map.setTexture(mapTexture);

    window1.create(sf::VideoMode(1280, 720), "The Game");
    window1.setFramerateLimit(60);

    int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    int i = 0;
    for (auto x : level) {
        if (level[i] != 0) {
            level[i] -= 1;
            vectorColisiones.push_back(sf::FloatRect(i % 20 * 16, i / 20 * 16, 16, 16));
        }
        i++;
    }

    if (!mapTiles.load("tileset.png", sf::Vector2u(16, 16), level, 16, 8)) {
        std::cout << "Error en la carga de ID de tiles en el mapTiles.load" << std::endl;
    }

    gameLoop();
}

void Game::gameLoop() {
    
    while (window1.isOpen() && !gameOver)
    {
        frame += 0.3f;
        eventListener();
        ///----------------------------
        ///actualizar las cosas
        ///----------------------------

        for (auto col : vectorColisiones) {
            if (player._sprite.getGlobalBounds().intersects(col)) {
                std::cout << "Colision" << std::endl;
            }
        }


        player.movePlayer(frame);
        drawWindow();

    }
}

void Game::eventListener()
{

    while (window1.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window1.close();
    }
}

void Game::drawWindow() {
    window1.clear();

    //window1.draw(algo);   EJEMPLO

    window1.draw(map);
    //window1.draw(player);
    player.draw(window1);

    window1.display();
}

