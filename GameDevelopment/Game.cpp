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

    mapTilesTexture2.loadFromFile("images/map3.png");
    mapTilesSprite2.setTexture(mapTilesTexture2);

    libroTexture.loadFromFile("images/libro.png");
    discoTexture.loadFromFile("images/disco.png");
    puertaTexture.loadFromFile("images/puerta.png");

    ///-------------------------------------
    ///discos
    ///-------------------------------------

    cargarEntidadeslvl1();

    ///-------------------------------------
    ///libros
    ///-------------------------------------
    /*{
        Entity* coso = new Entity("puerta", puertaTexture, 118, 640);
        entities.push_back(coso);
    }*/

    window1.create(sf::VideoMode(720, 720), "The Game");
    window1.setFramerateLimit(60);

    //Mapa1

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
    //Mapa 2
    int level2[] =
    {
        311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 311, 311, 311, 0, 0, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 0, 0, 0, 0, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311
    };
    int i2 = 0;
    for (auto x2 : level2) {
        if (level2[i2] != 0) {
            level2[i2] -= 1;
            //sf::RectangleShape shape2;
            //shape2.setFillColor(sf::Color::Blue);
            //shape2.setSize(sf::Vector2f(36.f, 36.f));
            //shape2.setPosition(i2 % 20 * 36, i2 / 20 * 36);

            vectorColisiones2.push_back(sf::FloatRect(i2 % 20 * 36, i2 / 20 * 36, 36, 36));
        }
        i2++;
    }
    if (!mapTiles2.load("images/tileset.png", sf::Vector2u(36, 36), level2, 20, 20)) {
        std::cout << "Error en la carga de ID de tiles en el mapTiles.load" << std::endl;
    }
    //player._x = 30;
    //player._y = 720-150;

    if (!buffer.loadFromFile("music/win.wav")) {
        std::cout << "Error sound load" << std::endl;
    }
    winSound.setBuffer(buffer);

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


        if (entities.size() == 0 && level1)
        {
            Entity* coso = new Entity("puertalvl1", puertaTexture, 118, 640);
            entities.push_back(coso);
        }
        if (entities.size() == 0 && !level1)
        {
            Entity* coso = new Entity("puertalvl2", puertaTexture, 118, 640);
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
                    menuPregunta(true);
                    //player.carisma+=10;
                }
                if (entity->_name.compare("libro")==0)
                {
                    entity->_life = 0;
                    menuPregunta(false);
                    //player.inteligencia+=10;
                }
                if (entity->_name.compare("puertalvl1")==0)
                {
                    entity->_life = 0;
                    if ( (player.carisma + player.inteligencia )< 80)
                    {
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
                    else {
                        level1 = false;

                        /*for (auto i = entities.begin(); i != entities.end();)
                        {
                            Entity* e = *i;
                            delete e;
                            i = entities.erase(i);
                        }*/
                        cargarEntidadeslvl2();
                    }
                    
                    //pasar al siguiente mapa
                }

                if (entity->_name.compare("puertalvl2") == 0)
                {
                    entity->_life = 0;
                    if ((player.carisma + player.inteligencia) >= 160)
                    {
                        gameOver = true;
                        gameOverScreen();

                        for (auto i = entities.begin(); i != entities.end();)
                        {
                            Entity* e = *i;
                            delete e;
                            i = entities.erase(i);
                        }
                        break;
                    }
                    else
                    {
                        {
                            Entity* coso = new Entity("disco", discoTexture, 570, 605);
                            entities.push_back(coso);
                        }
                        {
                            Entity* coso = new Entity("libro", libroTexture, 545, 60);
                            entities.push_back(coso);
                        }
                    }
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        level1 = level1 ? false : true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        for (auto i = entities.begin(); i != entities.end();)
        {
            Entity* e = *i;
            delete e;
            i = entities.erase(i);
        }
        cargarEntidadeslvl1();
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        for (auto i = entities.begin(); i != entities.end();)
        {
            Entity* e = *i;
            delete e;
            i = entities.erase(i);
        }
        cargarEntidadeslvl2();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        gameOver = true;
        gameOverScreen();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        menuPregunta(true);        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        menuPregunta(false);
    }
}

void Game::drawWindow() {
    window1.clear();

    if(level1){
    // Mapa 1
    window1.draw(mapTilesSprite);
    //window1.draw(mapTiles);
    }
    else{
    // Mapa 2
    window1.draw(mapTilesSprite2);
    //window1.draw(mapTiles2);
    }
    //
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
    if(level1){
    //Check collision for level 1
    for (auto &x : vectorColisiones)
        if (futurePlayerRect.intersects(x))
            //collision found
            return false;
    //No collision found
    return true;
    }
    //--------
    else{
    //Check collision for level 2
    for (auto& x2 : vectorColisiones2)
        if (futurePlayerRect.intersects(x2))
            //collision found
            return false;
    //No collision found
    return true;
    }
}

void Game::cargarEntidadeslvl1()
{
    {
        Entity* coso = new Entity("disco", discoTexture, 215, 720 - 210);
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
}


void Game::cargarEntidadeslvl2()
{
    {
        Entity* coso = new Entity("disco", discoTexture, 215 - 50 + 10, 720 - 210);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("disco", discoTexture, 365, 105);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("disco", discoTexture, 190, 360);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("disco", discoTexture, 570, 605);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("libro", libroTexture, 545, 60);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("libro", libroTexture, 360, 245);
        entities.push_back(coso);
    }
    {
        Entity* coso = new Entity("libro", libroTexture, 620, 245);
        entities.push_back(coso);
    }
}


void Game::gameOverScreen()
{
    sf::Text title;
    sf::Text score;
    sf::Text otroTexto;
    sf::Text textoDeRelleno;
    title.setFont(font);
    score.setFont(font);
    textoDeRelleno.setFont(font);
    otroTexto.setFont(font);
    title.setFillColor(sf::Color(255, 255, 255));
    score.setFillColor(sf::Color(255, 255, 255));
    otroTexto.setFillColor(sf::Color(255, 255, 255));
    textoDeRelleno.setFillColor(sf::Color(255, 255, 255));

    winSound.play();

    title.setString("Juego Terminado");
    score.setString("Puntos: " + std::to_string(player.carisma + player.inteligencia));
    std::string algo("Bien! Felicidades, haz logrado\nincluir muchos conocimientos\na lo largo de esta aventura que\nte permitieron avanzar y\ndesarrollarte como persona, si\nbien fue dificil, no te rendiste\ny superaste tus adversidades.\nEstamos orgullosos de vos\nAtte: Elfos.exe developers");
    textoDeRelleno.setString(algo);
    textoDeRelleno.setCharacterSize(20);
    textoDeRelleno.setOrigin(textoDeRelleno.getGlobalBounds().width / 2, textoDeRelleno.getGlobalBounds().height / 2);
    textoDeRelleno.setPosition(720 / 2, 720 / 2);

    otroTexto.setString("Presione ENTER para salir");
    otroTexto.setCharacterSize(20);
    otroTexto.setOrigin(otroTexto.getGlobalBounds().width / 2, otroTexto.getGlobalBounds().height / 2);
    otroTexto.setPosition(720 / 2, 720- otroTexto.getGlobalBounds().height * 2);
    

    title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
    title.setPosition(720 / 2, 50);

    score.setOrigin(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 2);
    score.setPosition(720 / 2, 100);

    bool exit = false;
    while (window1.isOpen() && !exit)
    {
        sf::Event event1;
        while (window1.pollEvent(event1))
        {
            if (event1.type == sf::Event::Closed)
                window1.close();
            if (event1.type == sf::Event::MouseMoved)
            {
                /*if (backButton.checkMouseColition(window1))
                {
                    backButton.updateSelection(true);
                }
                else
                {
                    backButton.updateSelection(false);
                }*/
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                exit = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                exit = true;
            }
            /*if (backButton.isClicked(window1))
            {
                exit = true;
            }*/
        }

        //backButton.update();

        window1.clear();
       // backButton.draw(window1);
        window1.draw(title);
        window1.draw(score);
        window1.draw(otroTexto);
        window1.draw(textoDeRelleno);
        window1.display();
    }

}



void Game::menuPregunta(bool disco)
{
    sf::Text title;
    sf::Text pregunta;
    sf::Text respuesta1;
    sf::Text respuesta2;    
    sf::Text textoDeAbajo;
    title.setFont(font);
    pregunta.setFont(font);
    pregunta.setFont(font);
    respuesta1.setFont(font);   
    respuesta2.setFont(font);
    textoDeAbajo.setFont(font);
    title.setFillColor(sf::Color(255, 255, 255));
    pregunta.setFillColor(sf::Color(255, 255, 255));
    respuesta1.setFillColor(sf::Color(255, 255, 255));
    pregunta.setFillColor(sf::Color(255, 255, 255));
    respuesta2.setFillColor(sf::Color(255, 255, 255));
    textoDeAbajo.setFillColor(sf::Color(255, 255, 255));
    int correcta = 0;
    int answer = rand() % 10;


    std::vector<std::string> preguntas(10);
    if (disco)
    {
        preguntas = 
        { 
            "¿Cual fue la primera grabación de\nRock and Roll?",
            "Una de estas obras NO es de Mozart.\n¿Cual de ellas?" ,
            "¿Cual de los siguientes cantantes\npronunció la frase 'Prefiero que me\nodien por lo que soy a que me\nadmiren por lo que nunca sere'?",
            "¿Cuándo nacio el rap?",
            "¿Cual de estas canciones no es del\ngrupo inmortal Queen?",
            "¿En qué año Beyonce lanzó su primer\ndisco como solista?",
            "¿Quién compuso\n'Las cuatro estaciones'?",
            "Livin la vida loca, es\nprobablemente la canción insignia de\nRicky Martin.\n¿Recuerdas en que año salio ? ",
            "El baile 'La Macarena', sacudio al\nmundo desde 1996. ¿Recuerdas quien\ncantaba esta canción ?.",
            "Shakira es recordada por sus\ninteligentes y divertidas\nfrases, ¿recuerdas a qué\ncanción pertenece su lírica\n'Si me cambias, por esa\nbruja pedazo de cuero, no\nvuelvas nunca mas ?' "
        };
        switch (answer) {
        case 0:

            respuesta1.setString("1) Una cancion de Elvis Presley");
            respuesta2.setString("2) Una cancion de Chuck Berry");//correcta
            correcta = 2;
            break;
        case 1:
            respuesta1.setString("1) La flauta magica");
            respuesta2.setString("2) Madama Butterfly");//correcta
            correcta = 2;
            break;
        case 2:
            respuesta1.setString("1) Kurt Cobain");//correcta
            respuesta2.setString("2) Jim Morrison");
            correcta = 1;
            break;
        case 3:
            respuesta1.setString("1) Finales de los 50/ principios de los 60");
            respuesta2.setString("2) Finales de los 60/ principios de los 70");//correcta
            correcta = 2;
            break;
        case 4:
            respuesta1.setString("1) Where are we now?");//correcta
            respuesta2.setString("2) Tie your mother down");
            correcta = 1;
            break;
        case 5:
            respuesta1.setString("1) 2002");
            respuesta2.setString("2) 2003");//correcta
            correcta = 2;
            break;
        case 6:
            respuesta1.setString("1) Mozart");
            respuesta2.setString("2) Vivaldi");//correcta
            correcta = 2;
            break;
        case 7:
            respuesta1.setString("1) 1998");
            respuesta2.setString("2) 1999");//correcta
            correcta = 2;
            break;
        case 8:
            respuesta1.setString("1) Los del Rio");//correcta
            respuesta2.setString("2) Los del Lago");
            correcta = 1;
            break;
        case 9:
            respuesta1.setString("1) Te aviso, te anuncio");
            respuesta2.setString("2) Si te vas");//correcta
            correcta = 2;
            break;
        }


    }
    else
    {
        preguntas =
        {
            "¿Quién fue el primer Presidente\nde Estados Unidos?",
            "Nombre de la famosa batalla\ndonde Napoleon Bonaparte\nfue derrotado." ,
            "A traves de que rio africano\nse alzo el antiguo Egipto??",
            "El vomitorium era una\nsala especial presente en las\nfiestas romanas donde los\ncomensales podian ir y vomitar\npara dejar espacio en el\nestomago para mas comida.",
            "A que filosofo griego se\natribuye la famosa obra\n'La Republica'?",
            "¿En que año se disolvió\nla Unión Soviética ? ",
            "¿Que civilización prehispánica\nadoro al dios Kukulkan?",
            "El mundo lo conoce como Leonardo\nda Vinci.\n¿Que significa 'da Vinci?'",
            "Julio Cesar nacio en el\naño 100 a.C.en el seno de\nuna familia patricia.\n¿Cual era su nombre de pila?",
            "De que pais eran originarios los Samurais",
        };
        switch (answer) {
        case 0:

            respuesta1.setString("1) George Washington");
            respuesta2.setString("2) Abraham Lincoln");//correcta
            correcta = 1;
            break;
        case 1:
            respuesta1.setString("1) La batalla de Waterloo");
            respuesta2.setString("2) La batalla de Stalingrado");//correcta
            correcta = 1;
            break;
        case 2:
            respuesta1.setString("1) Tigris");//correcta
            respuesta2.setString("2) Nilo");
            correcta = 2;
            break;
        case 3:
            respuesta1.setString("1) Verdadero");
            respuesta2.setString("2) Falso");//correcta
            correcta = 2;
            break;
        case 4:
            respuesta1.setString("1) Platon");//correcta
            respuesta2.setString("2) Aristoteles");
            correcta = 1;
            break;
        case 5:
            respuesta1.setString("1) 1990");
            respuesta2.setString("2) 1991");//correcta
            correcta = 2;
            break;
        case 6:
            respuesta1.setString("1) Incas");
            respuesta2.setString("2) Mayas");//correcta
            correcta = 2;
            break;
        case 7:
            respuesta1.setString("1) Su apellido");
            respuesta2.setString("2) Su lugar de procedencia");//correcta
            correcta = 2;
            break;
        case 8:
            respuesta1.setString("1) Cayo");//correcta
            respuesta2.setString("2) Julio");
            correcta = 1;
            break;
        case 9:
            respuesta1.setString("1) China");
            respuesta2.setString("2) Japon");//correcta
            correcta = 2;
            break;
        }
    }
   
    
    
    

    title.setString("TRIVIA");
    //pregunta.setString("Puntos: " + std::to_string(player.carisma + player.inteligencia));
    std::string algo(preguntas[answer]);
    pregunta.setString(algo);
    pregunta.setCharacterSize(20);
    pregunta.setOrigin(pregunta.getGlobalBounds().width / 2, pregunta.getGlobalBounds().height / 2);
    pregunta.setPosition(720 / 2, 720 / 3);

    
    respuesta1.setCharacterSize(20);
    respuesta1.setOrigin(respuesta1.getGlobalBounds().width / 2, respuesta1.getGlobalBounds().height / 2);
    respuesta1.setPosition(720 / 2, 720/2);

    respuesta2.setCharacterSize(20);
    respuesta2.setOrigin(respuesta2.getGlobalBounds().width / 2, respuesta2.getGlobalBounds().height / 2);
    respuesta2.setPosition(720 / 2, (720 / 2)+ respuesta2.getGlobalBounds().height * 4);


    textoDeAbajo.setCharacterSize(20);
    textoDeAbajo.setString("Presione 1 para elegir la opcion 1\nPresione 2 para elegir la opcion 2");
    textoDeAbajo.setOrigin(textoDeAbajo.getGlobalBounds().width / 2, textoDeAbajo.getGlobalBounds().height / 2);
    textoDeAbajo.setPosition(720 / 2, 720 - textoDeAbajo.getGlobalBounds().height * 2);


    title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
    title.setPosition(720 / 2, 50);

    /*pregunta.setOrigin(pregunta.getGlobalBounds().width / 2, pregunta.getGlobalBounds().height / 2);
    pregunta.setPosition(720 / 2, 100);*/

    bool exit = false;
    while (window1.isOpen() && !exit)
    {
        sf::Event event1;
        while (window1.pollEvent(event1))
        {
            if (event1.type == sf::Event::Closed)
                window1.close();
            if (event1.type == sf::Event::MouseMoved)
            {
                /*if (backButton.checkMouseColition(window1))
                {
                    backButton.updateSelection(true);
                }
                else
                {
                    backButton.updateSelection(false);
                }*/
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                exit = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                exit = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
            {
                if (correcta == 1)
                {
                    if (disco)
                    {
                        player.carisma += 10;
                    }
                    else
                    {
                        player.inteligencia += 10;
                    }
                }
                ///algo
                exit = true;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
            {
                if (correcta == 2)
                {
                    if (disco)
                    {
                        player.carisma += 10;
                    }
                    else
                    {
                        player.inteligencia += 10;
                    }
                }
                
                exit = true;
            }

            /*if (backButton.isClicked(window1))
            {
                exit = true;
            }*/
        }
        //backButton.update();

        window1.clear();
        // backButton.draw(window1);
        window1.draw(title);
        window1.draw(pregunta);
        window1.draw(respuesta1);
        window1.draw(respuesta2);
        window1.draw(pregunta);
        window1.draw(textoDeAbajo);
        window1.display();
    }
}