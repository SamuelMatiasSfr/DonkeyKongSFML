#include "GameOver.hpp"

GameOver::GameOver() {
	//cria e carrega fundo da tela game over
	if(!texturaFundoGameOver.loadFromFile("imagens/fundoCarregamento.jpg")){
		std::cerr << "Erro ao abrir a imagem de fundo\n";
	}
	fundoGameOver.setTexture(texturaFundoGameOver);


	//cria a janela
	tamanhoJanela = sf::VideoMode(texturaFundoGameOver.getSize().x, texturaFundoGameOver.getSize().y);


	//cria e carrega o icone
	if(!icon.loadFromFile("imagens/donkeyKong-icon.png")){
		std::cerr << "Erro ao abrir a textura de icone\n";
	}


	//cria mapa de game over
	mapaGameOver = new Mapa(tamanhoJanela, fundoGameOver);
	mapaGameOver->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	//carrega texturas dos botoes
	if(!texturaBotaoPlay.loadFromFile("imagens/botaoJogar.png")){
		std::cerr << "Erro ao abrir a textura do botao de jogar\n";
	}
	if (!texturaBotaoPlayHover.loadFromFile("imagens/botaoJogarHover.png")) {
		std::cerr << "Erro ao abrir a textura do botao jogar hover\n";
	}

	if(!texturaBotaoCredito.loadFromFile("imagens/botaoCreditos.png") ||
			!texturaBotaoCreditoHover.loadFromFile("imagens/botaoCreditosHover.png")){
		std::cerr << "Erro ao carregar texturas de botao Creditos\n";
	}


	//carrega fontes
	fonteTituloRemake.loadFromFile("fontes/fonte1.TTF");

	tituloRemake.setFont(fonteTituloRemake);
	tituloRemake.setString("GAME OVER");
	tituloRemake.setFillColor(sf::Color(111, 0, 0));
	tituloRemake.setCharacterSize(60);
	tituloRemake.setPosition(tamanhoJanela.width/5, 200);
	tituloRemake.setOutlineThickness(3);
	tituloRemake.setOutlineColor(sf::Color(162, 130, 0));


	//carrega musica de game over
	if (!musicaGameOver.openFromFile("audios/gameOver.flac")) {
		std::cerr << "Erro ao carregar o arquivo de som\n";
	}
	musicaGameOver.setVolume(50);


	//cria entidades botoes
	botaoPlay = new Entidade(texturaBotaoPlay, 400, 400, sf::IntRect (0, 0, 300, 120), sf::Vector2f (1.0f, 1.0f));
	botaoCredito = new Entidade(texturaBotaoCredito, 400, 550, sf::IntRect (0, 0, 300, 120), sf::Vector2f (1.0f, 1.0f));


	//loop principal
	while (mapaGameOver->getWindow().isOpen()) {

		//loop de eventos
		while (mapaGameOver->getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mapaGameOver->getWindow().close();
			}
		}


		//atualiza mundo

		//pega a posicao do mouse e passa como coordenadas para o mapa
		sf::Vector2i mousePos = sf::Mouse::getPosition(mapaGameOver->getWindow());
		mapaGameOver->setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		//se o mouse passar por cima dos botoes aparecera o o botao hover, senao aparecera o botao normal
		if (botaoPlay->getSprite().getGlobalBounds().contains(mapaGameOver->getCordenadas())) {
			botaoPlay->setTexturaSprite(texturaBotaoPlayHover);
		} else {
			botaoPlay->setTexturaSprite(texturaBotaoPlay);
		}
		if (botaoCredito->getSprite().getGlobalBounds().contains(mapaGameOver->getCordenadas())) {
			botaoCredito->setTexturaSprite(texturaBotaoCreditoHover);
		} else {
			botaoCredito->setTexturaSprite(texturaBotaoCredito);
		}

		//a classe Jogo ou Credito sera criada se houver click e se o mouse estiver em contato com os botoes
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(botaoPlay->getSprite().getGlobalBounds().contains(mapaGameOver->getCordenadas())){
				reiniciarJogo();

			}
			else if (botaoCredito->getSprite().getGlobalBounds().contains(mapaGameOver->getCordenadas())) {
				mostrarCreditos();
			}

		}

		if(musicaGameOver.getStatus() != sf::Sound::Playing){
			musicaGameOver.play();
		}


		//desenha mundo

		mapaGameOver->getWindow().clear();

		mapaGameOver->getWindow().draw(fundoGameOver);
		mapaGameOver->getWindow().draw(tituloRemake);
		mapaGameOver->getWindow().draw(botaoPlay->getSprite());
		mapaGameOver->getWindow().draw(botaoCredito->getSprite());

		mapaGameOver->getWindow().display();

	}
}

void GameOver::reiniciarJogo(){
    if(musicaGameOver.getStatus() == sf::Sound::Playing){
    	musicaGameOver.stop();
    }
	delete mapaGameOver;
	new Fase1();
}

GameOver::~GameOver(){
	std::cerr << "Tela de Game Over Destruida\n";
}

void GameOver::mostrarCreditos(){
	new Credito();
}

