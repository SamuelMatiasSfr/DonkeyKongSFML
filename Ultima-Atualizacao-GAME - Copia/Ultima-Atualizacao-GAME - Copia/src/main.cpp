#include "Mario.hpp"
#include "Barril.hpp"
#include "Kong.hpp"
#include "Escada.hpp"
#include "Plataforma.hpp"

#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

float calcularCentro(sf::RectangleShape sprite) {
	float centro = sprite.getPosition().x + (sprite.getGlobalBounds().width/2);
	return centro;
}

void colisaoMarioTeto(Entidade::Personagem::Mario::Mario &mario, Plataforma &teto){
    std::vector<sf::Sprite> plataformas = teto.getSprites();

    sf::Sprite spriteMario = mario.getSprite();

    int posTetoY = 0;

    int ajusteY = mario.getPosicaoY();

    for (auto &plataforma : plataformas) {
    	posTetoY = plataforma.getPosition().y - plataforma.getGlobalBounds().height;
        if (spriteMario.getGlobalBounds().intersects(plataforma.getGlobalBounds())){
            ajusteY = posTetoY;
            break;
        }
    }

    if(!(mario.getApertouDown()) && !(mario.getApertouUp())){
    	mario.setPosicaoY(ajusteY);
    	mario.setLimiteInferior(ajusteY);
    }

}

void colisaoMarioEscada(Entidade::Personagem::Mario::Mario &mario, Escada escada){
	bool podeSubir = mario.getPodeSubir();
	bool podeDescer = mario.getPodeDescer();

	sf::Sprite spriteMario = mario.getSprite();

	vector<sf::RectangleShape> degraus = escada.getDegraus();

	int quantDegraus = degraus.size();
	for(int i=0; i<quantDegraus; i++){
		if (spriteMario.getGlobalBounds().intersects(degraus.at(i).getGlobalBounds())){
			podeSubir = true;
			podeDescer = true;

			if((i == quantDegraus-1)&& (mario.getPosicaoY() > degraus.at(i).getPosition().y)){
				podeSubir = true;
				podeDescer = false;
			}else if((i == 0) && (mario.getPosicaoY() < degraus.at(i).getPosition().y)){
				podeSubir = false;
				podeDescer = true;
			}
		}
	}

	mario.setPodeSubir(podeSubir);
	mario.setPodeDescer(podeDescer);
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
    sf::IntRect retanguloMario(32, 35, 11, 14);
    Entidade::Personagem::Mario::Mario mario(texturaMario, 50, 770, retanguloMario, sf::Vector2f(3.6, 3), 5, 0);



    sf::Texture texturaBarril;
    if (!texturaBarril.loadFromFile("imgs/barril.png")) {
        std::cerr << "Erro ao carregar textura de 'imgs/barril.png'" << std::endl;
        return EXIT_FAILURE;
    }
    sf::IntRect retanguloBarril(25, 3, 12, 10);
    Entidade::Personagem::Barril::Barril barril(texturaBarril, 100, 190, retanguloBarril, sf::Vector2f(5, 5), 5, 0);

    vector<Entidade::Personagem::Barril::Barril> barris;
    barris.push_back(barril);

    sf::Texture texturaKong;
    if (!texturaKong.loadFromFile("imgs/kong.png")) {
        std::cerr << "Erro ao carregar textura de 'imgs/kong.png'" << std::endl;
        return EXIT_FAILURE;
    }
    sf::IntRect retanguloKong(99, 0, 40, 32);
    Entidade::Personagem::Kong::Kong kong(texturaKong, 41, 40, retanguloKong, sf::Vector2f(2, 2), 5, 0);

	Escada escadalateral[9];
	escadalateral[0].defineEscada(9, 200, 70);
	escadalateral[1].defineEscada(7, 340, 210);
	escadalateral[2].defineEscada(7, 550, 210);
	escadalateral[3].defineEscada(7, 300, 340);
	escadalateral[4].defineEscada(7, 200, 460);
	escadalateral[5].defineEscada(6, 500, 470);
	escadalateral[6].defineEscada(6, 350, 580);
	escadalateral[7].defineEscada(6, 250, 700);
	escadalateral[8].defineEscada(6, 500, 700);

	Plataforma teto[7];
	teto[0].definePlataforma( false, 0, 4, 0, 50);
	teto[1].definePlataforma( false, 0, 8, 0, 190);
	teto[2].definePlataforma( true, 2, 9, 800, 310);
	teto[3].definePlataforma( false, 2, 9, 0, 430);
	teto[4].definePlataforma( true, 1, 9, 800, 550);
	teto[5].definePlataforma( false, 1, 9, 0, 670);
	teto[6].definePlataforma( false, 0, 12, 0, 790);

	sf::Sprite spriteTeto = teto[0].getSprite();
	bool colidiuComPlataforma = false;
	float limiteInferiorGlobal = 770;


	mario.setLimiteInferior(limiteInferiorGlobal);


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

		/*
		for (int i = 0; i < 7; ++i) {
		    std::vector<sf::Sprite> plataformas = teto[i].getSprites();
		    for (auto &plataforma : plataformas) {
		        colisaoMarioTeto(mario, plataforma);
		    }
		}*/

		for(int i=0; i<9; i++){
			colisaoMarioEscada(mario, escadalateral[i]);
		}

		for (int i = 0; i < 7; ++i) {
							colisaoMarioTeto(mario, teto[i]);
						}


		if (!colidiuComPlataforma) {
		    mario.setLimiteInferior(limiteInferiorGlobal);
		}


		//window.draw(plataforma);
		for (int i = 0; i < 9; ++i) {
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

    for (int i = 0; i < 9; ++i) {
        escadalateral[i].free();
    }

    for (int i = 0; i < 7; ++i) {
        teto[i].free();
    }


	return 0;
}
