#pragma once

#include "Mario.hpp"
#include "Barril.hpp"

#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Demo");
	sf::Event event;
	window.setFramerateLimit(30.f);

	sf::Texture texturaMario;
	texturaMario.loadFromFile("imgs/mario/frame0.png");
	Entidade::Personagem::Mario::Mario mario(texturaMario, 100, 500, 5, 5);

	sf::Texture texturaBarril;
	texturaBarril.loadFromFile("imgs/pokemon.png");
	Entidade::Personagem::Barril::Barril barril(texturaBarril, 0, 0, 5, 5);

	//loop do jogo
	while (window.isOpen()) {

		//loop de eventos
		//Variável para armazenar o evento a ser tratado.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//atualiza mundo
		barril.mover();
		mario.mover();

		//desenha mundo
		window.clear();

		window.draw(barril.getSprite());
		window.draw(mario.getSprite());

		window.display();
	}

	return 0;
}
