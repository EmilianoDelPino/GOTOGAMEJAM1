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

    mapTilesTexture.loadFromFile("images/map2.png");
    mapTilesSprite.setTexture(mapTilesTexture);

    libroTexture.loadFromFile("images/libro.png");
    discoTexture.loadFromFile("images/disco.png");

    {
        Entity* disco = new Entity("disco",discoTexture,400,350);
        entities.push_back(disco);
    }
    {
        Entity* disco = new Entity("disco", discoTexture, 300, 350);
        entities.push_back(disco);
    }
    {
        Entity* disco = new Entity("disco", discoTexture, 200, 350);
        entities.push_back(disco);
    }
    {
        Entity* disco = new Entity("disco", discoTexture, 300, 150);
        entities.push_back(disco);
    }
    {
        Entity* disco = new Entity("disco", discoTexture, 300, 267);
        entities.push_back(disco);
    }

    window1.create(sf::VideoMode(720, 720), "The Game");
    window1.setFramerateLimit(60);

    int level[] =
    {
        311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 311, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311
    };

    int i = 0;
    for (auto x : level) {
        if (level[i] != 0) {
            level[i] -= 1;
            //sf::RectangleShape shape;
            //shape.setFillColor(sf::Color::Blue);
            //shape.setSize(sf::Vector2f(36.f, 36.f));
            //shape.setPosition(i % 20 * 36, i / 20 * 36);

            vectorColisiones.push_back(sf::FloatRect(i % 20 * 36, i / 20 * 36, 36, 36));
        }
        i++;
    }

    if (!mapTiles.load("images/tileset.png", sf::Vector2u(36, 36), level, 20, 20)) {
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
        sf::FloatRect cosita;
        for (auto &col : vectorColisiones) {
            player._sprite.setOrigin(0, 0);
            cosita=sf::FloatRect(sf::Vector2f(player._x+15, player._y + player._sprite.getGlobalBounds().height), sf::Vector2f(20/*player._sprite.getGlobalBounds().width -20 */, 5));
            if (col.intersects(cosita)) {
            //if (player._sprite.getGlobalBounds().intersects(col)) {
                std::cout << "Colision" << std::endl;
            }
        }


        for (auto entity : entities)
        {
            if (entity->_sprite.getGlobalBounds().intersects(player._sprite.getGlobalBounds()))
            {
                entity->_life = 0;
                std::cout << "hola" << std::endl;
                if (entity->_name.compare("disco"))
                {
                    player.carisma++;
                }
                if (entity->_name.compare("libro"))
                {
                    player.inteligencia++;
                }

            }
           
        }

        for (auto i = entities.begin(); i != entities.end();)
        {
            Entity* e = *i;
            if (e->_life == 0)
            {
                delete e;
                i = entities.erase(i);
            }
            else
            {
                i++;
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

    window1.draw(mapTilesSprite);
   // window1.draw(mapTiles);

    player.draw(window1);
    for (auto entity : entities)
    {
        entity->draw(window1);
    }

    window1.display();
}

