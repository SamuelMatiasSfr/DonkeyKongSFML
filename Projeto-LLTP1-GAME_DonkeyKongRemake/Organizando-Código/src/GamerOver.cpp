#include "GameOver.hpp"

GameOver::GameOver() {
	sf::Texture texturaFundoGameOver;
	if (!texturaFundoGameOver.loadFromFile("imagens/fundoCarregamento.jpg")) {
		std::cerr << "Erro ao abrir a imagem de fundo\n";
	}

	sf::Sprite fundoGameOver;
	fundoGameOver.setTexture(texturaFundoGameOver);

	sf::VideoMode tamjanela(texturaFundoGameOver.getSize().x, texturaFundoGameOver.getSize().y);
	sf::Event event;

	sf::Image icon;
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao abrir a textura de �cone\n";
	}

	Mapa mapaGameOver(tamjanela, fundoGameOver);
	mapaGameOver.getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	sf::Texture texturaBotaoPlay[2];
	if (!texturaBotaoPlay[0].loadFromFile("imagens/botaoJogar.png")) {
		std::cerr << "Erro ao abrir a textura do botao de jogar\n";
	}
	if (!texturaBotaoPlay[1].loadFromFile("imagens/botaoJogarHover.png")) {
		std::cerr << "Erro ao abrir a textura do botao jogar hover\n";
	}

	sf::Texture texturaBotaoCredito[2];
	if (!texturaBotaoCredito[0].loadFromFile("imagens/botaoCreditos.png") ||
			!texturaBotaoCredito[1].loadFromFile("imagens/botaoCreditosHover.png")) {
		std::cerr << "Erro ao carregar texturas de botão Créditos." << std::endl;
	}



	sf::Font fonteTituloRemake;
	fonteTituloRemake.loadFromFile("fontes/fonte1.TTF");

	sf::Text tituloRemake;
	tituloRemake.setFont(fonteTituloRemake);
	tituloRemake.setString("GAME OVER");
	tituloRemake.setFillColor(sf::Color(111, 0, 0));
	tituloRemake.setCharacterSize(60);
	tituloRemake.setPosition(tamjanela.width/5, 200);
	tituloRemake.setOutlineThickness(3);
	tituloRemake.setOutlineColor(sf::Color(162, 130, 0));

	sf::Music musicaGameOver;
	if (!musicaGameOver.openFromFile("audios/gameOver.flac")) {
		std::cerr << "Erro ao carregar o arquivo de som\n";
	}
	musicaGameOver.setVolume(50);

	sf::IntRect retangulo(0, 0, 300, 120);
	sf::Vector2f escala(1.0f, 1.0f);
	Entidade botaoPlay(texturaBotaoPlay[0], 400, 400, retangulo, escala);
	Entidade botaoCredito(texturaBotaoCredito[0], 400, 550, retangulo, escala);

	// Loop principal
	while (mapaGameOver.getWindow().isOpen()) {
		while (mapaGameOver.getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mapaGameOver.getWindow().close();
			}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(mapaGameOver.getWindow());
		mapaGameOver.setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (botaoPlay.getSprite().getGlobalBounds().contains(mapaGameOver.getCordenadas())) {
			botaoPlay.setTexturaSprite(texturaBotaoPlay[1]);
		} else {
			botaoPlay.setTexturaSprite(texturaBotaoPlay[0]);
		}
		if (botaoCredito.getSprite().getGlobalBounds().contains(mapaGameOver.getCordenadas())) {
			botaoCredito.setTexturaSprite(texturaBotaoCredito[1]);
		} else {
			botaoCredito.setTexturaSprite(texturaBotaoCredito[0]);
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(botaoPlay.getSprite().getGlobalBounds().contains(mapaGameOver.getCordenadas())){
				mapaGameOver.~Mapa();
				if(musicaGameOver.getStatus() == sf::Sound::Playing){
					musicaGameOver.pause();
				}
				Jogo jogo;
			}
			else if (botaoCredito.getSprite().getGlobalBounds().contains(mapaGameOver.getCordenadas())) {
				Credito mostraCreditos;
			}

		}

		mapaGameOver.getWindow().clear();

		if(musicaGameOver.getStatus() != sf::Sound::Playing){
			musicaGameOver.play();
		}

		mapaGameOver.getWindow().draw(fundoGameOver);
		mapaGameOver.getWindow().draw(tituloRemake);
		mapaGameOver.getWindow().draw(botaoPlay.getSprite());
		mapaGameOver.getWindow().draw(botaoCredito.getSprite());

		mapaGameOver.getWindow().display();

	}
}

GameOver::~GameOver(){
	std::cerr << "Tela de Game Over Destruida\n";
}

