#include "Mario.hpp"
#include "Barril.hpp"
#include "Kong.hpp"
#include "Escada.hpp"
#include "Plataforma.hpp"

#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void verificaColisao(Entidade::Personagem::Mario::Mario& mario, const sf::Sprite& teto) {
    sf::FloatRect marioBounds = mario.getSprite().getGlobalBounds();
    sf::FloatRect tetoBounds = teto.getGlobalBounds();

    if (marioBounds.intersects(tetoBounds)) {
        // Verifique se a colisão é com a parte superior
        float marioCentroY = marioBounds.top + marioBounds.height / 2;
        float tetoCentroY = tetoBounds.top + tetoBounds.height / 2;

        if (marioCentroY < tetoCentroY) {
            
            mario.setNoChao(true); // Assume que o Mario está no chão após a colisão com o teto
            mario.setLimiteInferior(teto.getPosition().y - 20);
        }
    }
}


int main(int argc, char **argv) {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 800), "Donkey Kong");
	sf::Event event;
	window.setFramerateLimit(30);

    // Carregar texturas
    sf::Texture texturaMario;
    if (!texturaMario.loadFromFile("imgs/mario.png")) {
        std::cerr << "Erro ao carregar textura de 'imgs/mario.png'" << std::endl;
        return EXIT_FAILURE;
    }
    sf::IntRect retanguloMario(32, 35, 12, 16);
    Entidade::Personagem::Mario::Mario mario(texturaMario, 50, 760, retanguloMario, sf::Vector2f(3.6, 3), 5, 0);



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
    Entidade::Personagem::Kong::Kong kong(texturaKong, 41, 40, retanguloKong, sf::Vector2f(2, 2), 5, 0);

	/*sf::RectangleShape plataforma;
	plataforma.setSize(sf::Vector2f(800, 100));
	plataforma.setFillColor(sf::Color::Magenta);
	plataforma.setPosition(0, 500);*/

	Escada escadalateral[5];
	escadalateral[0].defineEscada(4, 400, 180);
	escadalateral[1].defineEscada(5, 200, 70);
	escadalateral[2].defineEscada(4, 340, 280);
	escadalateral[3].defineEscada(8, 500, 700);
	escadalateral[4].defineEscada(9, 250, 700);

	Plataforma teto[7];
	teto[0].definePlataforma( false, 0, 4, 0, 50);
	teto[1].definePlataforma( false, 0, 8, 0, 190);
	teto[2].definePlataforma( true, 2, 9, 800, 310);
	teto[3].definePlataforma( false, 2, 9, 0, 430);
	teto[4].definePlataforma( true, 1, 9, 800, 550);
	teto[5].definePlataforma( false, 1, 9, 0, 670);
	teto[6].definePlataforma( false, 0, 12, 0, 790);



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
		mario.mover();
		kong.mover();

		//desenha mundo
		window.clear();

		for (int i = 0; i < 7; ++i) {
			verificaColisao(mario, teto[i].getSprite());
		}




		//window.draw(plataforma);
		for (int i = 0; i < 5; ++i) {
			escadalateral[i].draw(window);
		}



		for (int i = 0; i < 7; ++i) {
			teto[i].draw(window);
		}

		window.draw(mario.getSprite());
		window.draw(barril.getSprite());
		window.draw(kong.getSprite());


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
