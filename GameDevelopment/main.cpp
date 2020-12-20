#include "Game.h"
#include "SFML/Audio.hpp"

int main()
{
	srand((unsigned)time(NULL));
	sf::Music theme;
	theme.openFromFile("music/theme.wav");
	theme.setLoop(true);
	theme.setVolume(50.f);
	theme.play();
	Game hola;
	hola.initializer();

}