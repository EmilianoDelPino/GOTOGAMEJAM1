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
        /// 
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

