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


    Escada escada[11];
	escada[0].defineEscada(13, 650, 230);
	escada[1].defineEscada(11, 200, 110);
	escada[2].defineEscada(8, 440, 230);
	escada[3].defineEscada(9, 500, 670);
	escada[4].defineEscada(12, 880, 385);
	escada[5].defineEscada(10, 20, 530);
	escada[6].defineEscada(7, 600, 385);
	escada[7].defineEscada(7, 500, 470);
	escada[8].defineEscada(10, 300, 660);
	escada[9].defineEscada(10, 360, 540);
	escada[10].defineEscada(10, 600, 540);

	Plataforma plataforma[7];
	plataforma[0].definePlataforma( false, 0, 14, 0, 110);
	plataforma[1].definePlataforma( false, 0, 22, 0, 230);
	plataforma[2].definePlataforma( true, 1, 19, 1000, 370);
	plataforma[3].definePlataforma( false, 0, 4, 0, 530);
	plataforma[4].definePlataforma( true, 1, 21, 1000, 520);
	plataforma[5].definePlataforma( false, 1, 21, 0, 650);
	plataforma[6].definePlataforma( false, 0, 42, 0, 780);

	Colisoes colisao;

	sf::Texture texturaBarril[2];
	if (!texturaBarril[0].loadFromFile("imagens/barril.png", sf::IntRect(25, 3, 11, 10))) {
		std::cerr << "Erro ao carregar ícone" << std::endl;
	}
	if (!texturaBarril[1].loadFromFile("imagens/barril.png", sf::IntRect(25, 21, 12, 13) )) {
		std::cerr << "Erro ao carregar ícone" << std::endl;
	}

	std::vector<sf::Texture> texturaBarrilVector;
	texturaBarrilVector.push_back(texturaBarril[0]);
	texturaBarrilVector.push_back(texturaBarril[1]);

	Personagem barril(texturaBarrilVector.back(), 200, 200, sf::IntRect(0, 0, 12, 13), sf::Vector2f(2.0f, 2.0f), -2, 0);
	barril.getSprite().setTexture(*texturaBarril);

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
    	mario.sofreGravidade();

    	barril.permiteMovimento(mapaJogo);
    	barril.sofreGravidade();



        for (int i = 0; i < 7; ++i) {
        	if (colisao.verificarColisao(mario, plataforma[i])) {
                mario.setNoAr(false);
                mario.setVelocidade(0, 0);
        	}
        	if (colisao.verificarColisao(barril, plataforma[i])) {

        	    if (barril.getSprite().getPosition().x + barril.getSprite().getGlobalBounds().width >= mapaJogo.getTamanhoJanela().width) {
        	        barril.setVelocidade(-0.5, 0);
        	    }

        	    if (barril.getSprite().getPosition().x <= 0) {
        	        barril.setVelocidade(0.5, 0);
        	    }
        	}

        	barril.setPosition(
        	    barril.getPosition().x + barril.getVelocidade().x,
        	    barril.getPosition().y + barril.getVelocidade().y
        	);
        }

        for (int i = 0; i < 11; ++i) {
        	if (colisao.verificarColisao(mario, escada[i])) {
                mario.setEmEscada(true);
                break;
        	} else {
        		mario.setEmEscada(false);
        	}
        }
        if(colisao.verificarColisao(mario, barril)){
        	mario.setPosition(20, mapaJogo.getTamanhoJanela().height - 25);
        	barril.setPosition(20, 10);
        }


        mapaJogo.getWindow().clear();

        mapaJogo.getWindow().draw(fundoJogo);
        for (int i = 0; i < 11; ++i) {
			escada[i].draw(mapaJogo.getWindow());
		}
        for (int i = 0; i < 7; ++i) {
        	plataforma[i].draw(mapaJogo.getWindow());
        }
        mapaJogo.getWindow().draw(mario.getSprite());

        mapaJogo.getWindow().draw(barril.getSprite());

        mapaJogo.getWindow().display();
    }
}

Jogo::~Jogo() {
    std::cerr << "Jogo Fechado" << std::endl;
}

