#pragma once

#include "Mario.hpp"
#include "Barril.hpp"
#include "Kong.hpp"

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
	texturaMario.loadFromFile("imgs/mario.png");
	sf::IntRect retanguloMario(32, 35, 12, 16);
	Entidade::Personagem::Mario::Mario mario(texturaMario, 100, 200, retanguloMario, sf::Vector2f(5, 5), 5, 5);

	sf::Texture texturaBarril;
	texturaBarril.loadFromFile("imgs/barril.png");
	sf::IntRect retanguloBarril(25, 3, 12, 10);
	Entidade::Personagem::Barril::Barril barril(texturaBarril, 0, 0, retanguloBarril, sf::Vector2f(5, 5), 5, 5);

	sf::Texture texturaKong;
	texturaKong.loadFromFile("imgs/kong.png");
	sf::IntRect retanguloKong(99, 0, 40, 32);
	Entidade::Personagem::Kong::Kong kong(texturaKong, 0, 200, retanguloKong, sf::Vector2f(2, 2), 5, 0);

	sf::RectangleShape plataforma;
	plataforma.setSize(sf::Vector2f(800, 100));
	plataforma.setFillColor(sf::Color::Magenta);
	plataforma.setPosition(0, 500);

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
		kong.mover();

		//desenha mundo
		window.clear();

		window.draw(barril.getSprite());
		window.draw(mario.getSprite());
		window.draw(kong.getSprite());
		window.draw(plataforma);

		window.display();
	}

	return 0;
}
