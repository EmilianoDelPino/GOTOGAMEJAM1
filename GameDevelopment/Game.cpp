#include "Game.h"
#include <iostream>
Game::Game()
{
    
}
void Game::initializer()
{
    font.loadFromFile("fonts/PressStart2P-Regular.ttf");

    inteligenciaText = new sf::Text();
    carismaText = new sf::Text();
    puntajeTotalText = new sf::Text();


    inteligenciaText->setCharacterSize(15);
    carismaText->setCharacterSize(15);
    puntajeTotalText->setCharacterSize(15);

    inteligenciaText->setFont(font);
    carismaText->setFont(font);
    puntajeTotalText->setFont(font);

    inteligenciaText->setFillColor(sf::Color(0, 255, 0));
    carismaText->setFillColor(sf::Color(0, 255, 0));
    puntajeTotalText->setFillColor(sf::Color(0, 255, 0));

    inteligenciaText->setString("inteligencia: ");
    carismaText->setString("carisma: ");
    puntajeTotalText->setString("puntaje total:");

    inteligenciaText->setPosition(0, 0);
    carismaText->setPosition(250, 0);
    puntajeTotalText->setPosition(430, 0);

    textoParaMostrar.push_back(inteligenciaText);
    textoParaMostrar.push_back(carismaText);
    textoParaMostrar.push_back(puntajeTotalText);

    /*inteligenciaText
    carismaText
    puntajeTotalText*/

    gameOver = false;
    
    player.setTexturaPlayer();
    player.setPlayer();
    player._sprite.setPosition(sf::Vector2f(100, 100));

    mapTexture.loadFromFile("images/map.png");
    map.setTexture(mapTexture);

    mapTilesTexture.loadFromFile("images/map2.png");
    mapTilesSprite.setTexture(mapTilesTexture);

    libroTexture.loadFromFile("images/libro.png");
    discoTexture.loadFromFile("images/disco.png");
    puertaTexture.loadFromFile("images/puerta.png");

    ///-------------------------------------
    ///discos
    ///-------------------------------------

    {
        Entity* coso = new Entity("disco",discoTexture,215,720-210);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("disco", discoTexture, 325, 105);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("disco", discoTexture, 200, 350);
        entities.push_back(coso);
    }

    ///-------------------------------------
    ///libros
    ///-------------------------------------

    {
        Entity* coso = new Entity("libro", libroTexture, 545, 60);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("libro", libroTexture, 290, 315);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("libro", libroTexture, 600, 267);
        entities.push_back(coso);
    }

    ///-------------------------------------
    ///libros
    ///-------------------------------------
    /*{
        Entity* coso = new Entity("puerta", puertaTexture, 118, 640);
        entities.push_back(coso);
    }*/

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

    //player._x = 30;
    //player._y = 720-150;
    
    gameLoop();
}

void Game::gameLoop() {
    
    while (window1.isOpen() && !gameOver)
    {
        inteligenciaText->setString("inteligencia: " + std::to_string(player.inteligencia));
        carismaText->setString("carisma: " + std::to_string(player.carisma));
        puntajeTotalText->setString("puntaje total:" + std::to_string(player.inteligencia+ player.carisma));

        frame += 0.3f;
        eventListener();
        ///----------------------------
        ///actualizar las cosas
        ///----------------------------
       /*sf::FloatRect colisiones;
       for (auto &col : vectorColisiones) {
            player._sprite.setOrigin(0, 0);
            colisiones=sf::FloatRect(sf::Vector2f(player._x+15, player._y + player._sprite.getGlobalBounds().height), sf::Vector2f(20
                //player._sprite.getGlobalBounds().width -20, 5));
            if (col.intersects(colisiones)) {
            //if (player._sprite.getGlobalBounds().intersects(col)) {
                std::cout << "Colision" << std::endl;
            }
        }*/


        if (entities.size() == 0)
        {
            Entity* coso = new Entity("puerta", puertaTexture, 118, 640);
            entities.push_back(coso);
        }


        for (auto entity : entities)
        {
            if (entity->_sprite.getGlobalBounds().intersects(player._sprite.getGlobalBounds()))
            {
                
                std::cout << "hola" << std::endl;
                if (entity->_name.compare("disco")==0)
                {
                    entity->_life = 0;
                    player.carisma+=10;
                }
                if (entity->_name.compare("libro")==0)
                {
                    entity->_life = 0;
                    player.inteligencia+=10;
                }
                if (entity->_name.compare("puerta")==0)
                {
                    if ( (player.carisma + player.inteligencia )< 80)
                    {
                        entity->_life = 0;
                        sf::Text* texto = new sf::Text();
                        texto->setFont(font);
                        texto->setString("Te faltan puntos");
                        texto->setFillColor(sf::Color(0, 255, 0));
                        texto->setPosition(0, 680);
                        textoParaMostrar.push_back(texto);

                        {
                            Entity* coso = new Entity("disco", discoTexture, 100, 100);
                            entities.push_back(coso);
                        }
                        {
                            Entity* coso = new Entity("libro", libroTexture, 325, 105);
                            entities.push_back(coso);
                        }
                    }/*pasar de nivel*/

                    
                    //pasar al siguiente mapa
                }

                if ((player.carisma + player.inteligencia) >= 80)
                {
                    for (auto i = textoParaMostrar.begin(); i != textoParaMostrar.end();)
                    {
                        sf::Text* e = *i;
                        
                        if (std::string(e->getString()).compare("Te faltan puntos") == 0)
                        {
                            delete e;
                            i = textoParaMostrar.erase(i);
                        }else
                            i++;
                        
                    }
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window1);
        std::cout <<"x: "<< localPosition.x << std::endl;
        std::cout <<"y: "<< localPosition.y << std::endl;
    }

    //Player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && CanItMove(movement_type::UP, &player))
    {
        player.movePlayer(frame, movement_type::UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && CanItMove(movement_type::DOWN, &player))
    {
        player.movePlayer(frame, movement_type::DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && CanItMove(movement_type::RIGHT, &player))
    {
        player.movePlayer(frame, movement_type::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && CanItMove(movement_type::LEFT, &player))
    {
        player.movePlayer(frame, movement_type::LEFT);
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

    for (auto texto : textoParaMostrar)
    {
        window1.draw(*texto);
    }
    
    /*window1.draw(*inteligenciaText);
    window1.draw(*carismaText);
    window1.draw(*puntajeTotalText);*/



    window1.display();
}

bool Game::CanItMove(movement_type type, Character* player)
{
    sf::FloatRect futurePlayerRect = player->_sprite.getGlobalBounds();
    //Changing dimensions
    //height
    futurePlayerRect.height /= 4;
    futurePlayerRect.top += (futurePlayerRect.height * 3);
    //width
    futurePlayerRect.width /= 3;
    futurePlayerRect.left += futurePlayerRect.width;

    //Prepparing position
    switch (type)
    {
    case movement_type::UP:
        futurePlayerRect.top -= player->velocidad;
        break;
    case movement_type::DOWN:
        futurePlayerRect.top += player->velocidad;
        break;
    case movement_type::LEFT:
        futurePlayerRect.left -= player->velocidad;
        break;
    case movement_type::RIGHT:
        futurePlayerRect.left += player->velocidad;
        break;
    }

    //Check collision
    for (auto &x : vectorColisiones)
        if (futurePlayerRect.intersects(x))
            //collision found
            return false;
    //No collision found
    return true;

}