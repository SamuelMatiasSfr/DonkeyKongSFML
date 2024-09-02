#include "Mario.hpp"
#include "Barril.hpp"
#include "Kong.hpp"
#include "Escada.hpp"
#include "Plataforma.hpp"

#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Donkey Kong");
	sf::Event event;
	window.setFramerateLimit(30);

    // Carregar texturas
    sf::Texture texturaMario;
    if (!texturaMario.loadFromFile("imgs/mario.png")) {
        std::cerr << "Erro ao carregar textura de 'imgs/mario.png'" << std::endl;
        return EXIT_FAILURE;
    }
    sf::IntRect retanguloMario(32, 35, 12, 16);
    Entidade::Personagem::Mario::Mario mario(texturaMario, 50, 550, retanguloMario, sf::Vector2f(5, 5), 5, 0);

    sf::Texture texturaBarril;
    if (!texturaBarril.loadFromFile("imgs/barril.png")) {
        std::cerr << "Erro ao carregar textura de 'imgs/barril.png'" << std::endl;
        return EXIT_FAILURE;
    }
    sf::IntRect retanguloBarril(25, 3, 12, 10);
    Entidade::Personagem::Barril::Barril barril(texturaBarril, 0, 0, retanguloBarril, sf::Vector2f(5, 5), 5, 5);

    sf::Texture texturaKong;
    if (!texturaKong.loadFromFile("imgs/kong.png")) {
        std::cerr << "Erro ao carregar textura de 'imgs/kong.png'" << std::endl;
        return EXIT_FAILURE;
    }
    sf::IntRect retanguloKong(99, 0, 40, 32);
    Entidade::Personagem::Kong::Kong kong(texturaKong, 0, 200, retanguloKong, sf::Vector2f(2, 2), 5, 0);

	/*sf::RectangleShape plataforma;
	plataforma.setSize(sf::Vector2f(800, 100));
	plataforma.setFillColor(sf::Color::Magenta);
	plataforma.setPosition(0, 500);*/

	Escada escadalateral[5];
	escadalateral[0].defineEscada(4, 400, 180);
	escadalateral[1].defineEscada(5, 200, 70);
	escadalateral[2].defineEscada(4, 340, 280);
	escadalateral[3].defineEscada(6, 500, 480);
	escadalateral[4].defineEscada(6, 250, 480);

	Plataforma teto[7];
	teto[0].definePlataforma( false, 0, 4, 0, 40);
	teto[1].definePlataforma( true, 2, 10, 800, 150);
	teto[2].definePlataforma( false, 2, 8, 0, 250);
	teto[3].definePlataforma( true, 1, 10, 800, 350);
	teto[4].definePlataforma( false, 1, 8, 0, 450);
	teto[5].definePlataforma( false, 0, 11, 0, 590);



	//loop do jogo
	while (window.isOpen()) {

		//loop de eventos
		//Vari�vel para armazenar o evento a ser tratado.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//atualiza mundo
		barril.mover();
		//mario.mover();
		kong.mover();

		//desenha mundo
		window.clear();

		window.draw(barril.getSprite());
		window.draw(mario.getSprite());
		window.draw(kong.getSprite());
		//window.draw(plataforma);
		for (int i = 0; i < 5; ++i) {
			escadalateral[i].draw(window);
		}

		for (int i = 0; i < 7; ++i) {
			teto[i].draw(window);
		}

		window.display();
	}

    for (int i = 0; i < 5; ++i) {
        escadalateral[i].free();
    }

    for (int i = 0; i < 7; ++i) {
        teto[i].free();
    }


	return 0;
}
