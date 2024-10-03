#include "Jogo.hpp"

Jogo::Jogo() {
	carregarAudios();
	carregatexturas();
	setTexturas();
	geraEscadas();
	geraPlataformas();
	criaMapa();
	criaPersonagens();

    loopPrincipal();
}

Jogo::~Jogo() {
	delete mapaJogo;
	delete mario;
	delete[] barril;
	delete[] escada;
	delete[] plataforma;

    std::cerr << "Jogo Fechado" << std::endl;
}

void Jogo::setTexturas(){
	explosao.setTexture(texturaExplosao);
	fundoJogo.setTexture(texturaFundoJogo);
	texturaBarrilVector.push_back(texturaBarril);
	mario->setSprite(texturaMario);
}

void Jogo::carregarAudios(){
	if (!bufferMorte.loadFromFile("audios/morte.wav")) {
		std::cerr << "Erro ao carregar o arquivo de som!\n";
	}
	somMorte.setBuffer(bufferMorte);
}

void Jogo::carregatexturas(){
	//texturas fundo e icon
	if (!texturaFundoJogo.loadFromFile("imagens/fundoJogo.png")) {
		std::cerr << "Erro ao carregar textura do fundo" << std::endl;
	}
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao carregar Ã­cone" << std::endl;
	}

	//texturas mario
	for (int i = 0; i < 2; ++i) {
		if (!texturaMario.loadFromFile("imagens/mario-sprites.png", sf::IntRect(0, i * 60, 60, 60))) {
			std::cerr << "Erro ao carregar textura do Mario" << std::endl;
		}
		texturaMarioVector.push_back(texturaMario);
	}

	for (int i = 0; i < 2; ++i) {
		if (!texturaMarioDireita.loadFromFile("imagens/mario-spritesDireita.png", sf::IntRect(0, i * 60, 60, 60))) {
			std::cerr << "Erro ao carregar textura do Mario" << std::endl;
		}
		texturaMarioVectorDireita.push_back(texturaMarioDireita);
	}

	//textura barril
	if (!texturaBarril.loadFromFile("imagens/barril.png" )) {
		std::cerr << "Erro ao carregar Ã­cone" << std::endl;
	}

 /*
	if (!texturaKong.loadFromFile("imagens/kong.png" )) {
		std::cerr << "Erro ao carregar Ã­cone" << std::endl;
	}
	*/

	//textura pauline

	//textura explosão
	if(!texturaExplosao.loadFromFile("imagens/explosao.png")){
		std::cout << "Erro ao carregar textura explosÃ£o"<< std::endl;
	}
}

void Jogo::geraPlataformas(){
	plataforma = new Plataforma[7];

	plataforma[0].definePlataforma( false, 0, 14, 0, 110);
	plataforma[1].definePlataforma( false, 0, 22, 0, 230);
	plataforma[2].definePlataforma( true, 1, 19, 1000, 370);
	plataforma[3].definePlataforma( false, 0, 4, 0, 530);
	plataforma[4].definePlataforma( true, 1, 21, 1000, 520);
	plataforma[5].definePlataforma( false, 1, 21, 0, 650);
	plataforma[6].definePlataforma( false, 0, 42, 0, 780);
}

void Jogo::geraEscadas(){
    escada = new Escada[11];

	escada[0].defineEscada(13, 650, 230);
	escada[1].defineEscada(11, 200, 110);
	escada[2].defineEscada(8, 440, 230);
	escada[3].defineEscada(9, 500, 670);
	escada[4].defineEscada(12, 880, 375);
	escada[5].defineEscada(10, 20, 530);
	escada[6].defineEscada(7, 600, 385);
	escada[7].defineEscada(7, 500, 470);
	escada[8].defineEscada(10, 300, 660);
	escada[9].defineEscada(10, 360, 540);
	escada[10].defineEscada(10, 600, 540);
}

void Jogo::criaPersonagens(){
	mario = new Mario(texturaMarioVector.back(), 300, 300, sf::IntRect(0, 0, 60, 60), sf::Vector2f(1.0f, 1.0f), 0, 0);
	//kong = new Kong(texturaKongVector.back(), 50, 110, sf::IntRect(99, 0, 44, 32), sf::Vector2f(1.0f, 1.0f), 0, 0);
	barril = new Barril[4];

	for (int i = 0; i < 4; ++i) {
		barril[i] = Barril(texturaBarrilVector.back(), 200, 110, sf::IntRect(25, 3, 12, 10), sf::Vector2f(2.5f, 3.0f), -0.2, 0);
		barril[i].getSprite().setTexture(texturaBarril);
	}
}

void Jogo::criaMapa(){
	mapaJogo = new Mapa(sf::VideoMode(texturaFundoJogo.getSize().x, texturaFundoJogo.getSize().y), fundoJogo);
	mapaJogo->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Jogo::desenhaMapa(){
    mapaJogo->getWindow().draw(fundoJogo);
    for (int i = 0; i < 11; ++i) {
    	escada[i].draw(mapaJogo->getWindow());
    }
    for (int i = 0; i < 7; ++i) {
    	plataforma[i].draw(mapaJogo->getWindow());
    }

    for(int i=0; i<4; i++){
    	mapaJogo->getWindow().draw(barril[i].getSprite());
    }

    //mapaJogo->getWindow().draw(kong->getSprite());
    mapaJogo->getWindow().draw(mario->getSprite());

}

void Jogo::colideComPlataformas(){
	//colisão mario e plataformas
    for (int i = 0; i < 7; ++i) {
    	if (colisao.colisaoMarioPlataforma(*mario, plataforma[i])) {
            mario->setNoAr(false);
            mario->setVelocidade(0, 0);
    	}

    	//colisão barril e plataformas
    	for (int j = 0; j < 4; ++j) {
    		if (colisao.colisaoPersonagemPlataforma(barril[j], plataforma[i])) {
				if (barril[j].getSprite().getPosition().x + barril[j].getSprite().getGlobalBounds().width >= mapaJogo->getTamanhoJanela().width){
					barril[j].setVelocidade(-barril[j].getVelocidade().x, barril[j].getVelocidade().y);
				}

				if (barril[j].getSprite().getPosition().x <= 0) {
					barril[j].setVelocidade(-barril[j].getVelocidade().x, barril[j].getVelocidade().y);
				}
    		}

    		barril[j].setPosition(barril[j].getPosition().x + barril[j].getVelocidade().x ,
					barril[j].getPosition().y + barril[j].getVelocidade().y);
		}

    }

}

void Jogo::colideComEscadas(){
	//colisão mario e escadas
	for (int i = 0; i < 11; ++i) {
		if(i != 6 && i!= 7){
			if (colisao.colisaoPersonagemEscada(*mario, escada[i])) {
				mario->setEmEscada(true);
				break;
			}
		}
		else {
			mario->setEmEscada(false);
		}
	}
}

void Jogo::colidePersonagens(){
	//colisão mario e barril
	for (int i = 0; i < 4; ++i) {
		if(colisao.colisaoEntrePersonagens(*mario, barril[i])){
			if(somMorte.getStatus() != sf::Sound::Playing){
				somMorte.play();
				sf::sleep(sf::seconds(5));
			}
			mario->setPosition(20, mapaJogo->getTamanhoJanela().height - 25);
			barril[i].respawAleatotio(mapaJogo->getWindow());
			clock.restart();
		}
	}
}

void Jogo::movimentaPersonagens(){
	//movimento mário
	mario->permiteMovimento(*mapaJogo);
	mario->movimentoTeclas();
	mario->sofreGravidade();

	//kong->mover(0.1, 0);

	//movimento barril
	for (int i = 0; i < 4; ++i) {
		colisao.colisaoBarrilMapa(barril[i], mapaJogo);
		barril[i].permiteMovimento(*mapaJogo);
		barril[i].sofreGravidade();
		barril[i].animaEntidade();
	}
}

void Jogo::animaMario(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		mario->setSprite(texturaMarioVector);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		mario->setSprite(texturaMarioVectorDireita);
	}else{
		mario->setSprite(texturaMarioVector);
	}
}

void Jogo::fechaJanela(){
	while (mapaJogo->getWindow().pollEvent(evento)) {
		if (evento.type == sf::Event::Closed) {
			mapaJogo->getWindow().close();
		}
	}
}

void Jogo::loopPrincipal(){
	while (mapaJogo->getWindow().isOpen()) {

		fechaJanela();

		animaMario();
		movimentaPersonagens();

		colideComPlataformas();
		colideComEscadas();
		colidePersonagens();

		mapaJogo->getWindow().clear();
		desenhaMapa();
		mapaJogo->getWindow().display();
	}
}
