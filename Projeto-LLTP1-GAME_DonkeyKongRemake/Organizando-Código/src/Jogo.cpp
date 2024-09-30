#include "Jogo.hpp"

Jogo::Jogo() {

    sf::Texture texturaFundoJogo;
    if (!texturaFundoJogo.loadFromFile("imagens/fundoJogo.png")) {
        std::cerr << "Erro ao carregar textura do fundo" << std::endl;
    }
    sf::Sprite fundoJogo;
    fundoJogo.setTexture(texturaFundoJogo);
    sf::Image icon;
    if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
        std::cerr << "Erro ao carregar ícone" << std::endl;
    }

    Mapa mapaJogo(sf::VideoMode(texturaFundoJogo.getSize().x, texturaFundoJogo.getSize().y), fundoJogo);
    mapaJogo.getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    std::vector<sf::Texture> texturaMarioVector;
    for (int i = 0; i < 2; ++i) {
        sf::Texture texturaMario;
        if (!texturaMario.loadFromFile("imagens/mario-sprites.png", sf::IntRect(0, i * 60, 60, 60))) {
            std::cerr << "Erro ao carregar textura do Mario" << std::endl;
        }
        texturaMarioVector.push_back(texturaMario);
    }

    std::vector<sf::Texture> texturaMarioVectorDireita;
    for (int i = 0; i < 2; ++i) {
    	sf::Texture texturaMarioDireita;
    	if (!texturaMarioDireita.loadFromFile("imagens/mario-spritesDireita.png", sf::IntRect(0, i * 60, 60, 60))) {
    		std::cerr << "Erro ao carregar textura do Mario" << std::endl;
    	}
    	texturaMarioVectorDireita.push_back(texturaMarioDireita);
    }


    Mario mario(texturaMarioVector.back(), 300, 300, sf::IntRect(0, 0, 60, 60), sf::Vector2f(1.0f, 1.0f), 0, 0);


    Escada escada[9];
	escada[0].defineEscada(7, 550, 210);
	escada[1].defineEscada(9, 200, 70);
	escada[2].defineEscada(8, 340, 210);
	escada[3].defineEscada(8, 500, 700);
	escada[4].defineEscada(9, 250, 700);
	escada[5].defineEscada(7, 350, 580);
	escada[6].defineEscada(7, 200, 460);
	escada[7].defineEscada(7, 500, 470);
	escada[8].defineEscada(6, 300, 340);

	Plataforma plataforma[7];
	plataforma[0].definePlataforma( false, 0, 14, 0, 110);
	plataforma[1].definePlataforma( false, 0, 18, 0, 230);
	plataforma[2].definePlataforma( true, 2, 19, 1000, 310);
	plataforma[3].definePlataforma( false, 2, 19, 0, 430);
	plataforma[4].definePlataforma( true, 1, 19, 1000, 550);
	plataforma[5].definePlataforma( false, 1, 19, 0, 670);
	plataforma[6].definePlataforma( false, 0, 42, 0, 780);

	Colisoes colisao;



    sf::Event evento;
    while (mapaJogo.getWindow().isOpen()) {
    	while (mapaJogo.getWindow().pollEvent(evento)) {
    		if (evento.type == sf::Event::Closed) {
    			mapaJogo.getWindow().close();
    		}
    	}



    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    		mario.setSprite(texturaMarioVector);
    	}
    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    		mario.setSprite(texturaMarioVectorDireita);
    	}else{
    		mario.setSprite(texturaMarioVector);
    	}
    	mario.permiteMovimento(mapaJogo);
        mario.movimentoTeclas();


        for (int i = 0; i < 7; ++i) {
        	if (colisao.verificarColisao(mario, plataforma[i])) {
                mario.setNoAr(false);
        		break;
        	} else {
        	}
        }


        // Verificar colisão com escadas
        for (int i = 0; i < 9; ++i) {
        	if (colisao.verificarColisao(mario.getSprite(), escada[i])) {
                mario.setEmEscada(true);
        		break;
        	} else {
        		mario.setEmEscada(false);
        	}
        }


        if (mario.getNoAr() && !mario.getEmEscada()) {
            mario.sofreGravidade();
        }

        mapaJogo.getWindow().clear();

        mapaJogo.getWindow().draw(fundoJogo);
        for (int i = 0; i < 9; ++i) {
			escada[i].draw(mapaJogo.getWindow());
		}
        for (int i = 0; i < 7; ++i) {
        	plataforma[i].draw(mapaJogo.getWindow());
        }
        mapaJogo.getWindow().draw(mario.getSprite());

        if (mario.getNoAr() || !mario.getEmEscada()) {
            mario.sofreGravidade();
        }

        mapaJogo.getWindow().display();
    }
}

Jogo::~Jogo() {
    std::cerr << "Jogo Fechado" << std::endl;
}

