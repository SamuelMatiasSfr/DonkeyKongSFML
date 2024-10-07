#include "GameOver.hpp"

GameOver::GameOver() {
	//cria e carrega fundo da tela game over
	sf::Texture texturaFundoGameOver;
	if(!texturaFundoGameOver.loadFromFile("imagens/fundoCarregamento.jpg")){
		std::cerr << "Erro ao abrir a imagem de fundo\n";
	}

	sf::Sprite fundoGameOver;
	fundoGameOver.setTexture(texturaFundoGameOver);


	//cria a janela
	sf::VideoMode tamjanela(texturaFundoGameOver.getSize().x, texturaFundoGameOver.getSize().y);
	sf::Event event;


	//cria e carrega o icone
	sf::Image icon;
	if(!icon.loadFromFile("imagens/donkeyKong-icon.png")){
		std::cerr << "Erro ao abrir a textura de icone\n";
	}


	//cria mapa de game over
	Mapa mapaGameOver(tamjanela, fundoGameOver);
	mapaGameOver.getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	//carrega texturas dos botoes
	sf::Texture texturaBotaoPlay[2];
	if(!texturaBotaoPlay[0].loadFromFile("imagens/botaoJogar.png")){
		std::cerr << "Erro ao abrir a textura do botao de jogar\n";
	}
	if (!texturaBotaoPlay[1].loadFromFile("imagens/botaoJogarHover.png")) {
		std::cerr << "Erro ao abrir a textura do botao jogar hover\n";
	}

	sf::Texture texturaBotaoCredito[2];
	if(!texturaBotaoCredito[0].loadFromFile("imagens/botaoCreditos.png") ||
			!texturaBotaoCredito[1].loadFromFile("imagens/botaoCreditosHover.png")){
		std::cerr << "Erro ao carregar texturas de botao Creditos\n";
	}


	//carrega fontes
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


	//carrega musica de game over
	sf::Music musicaGameOver;
	if (!musicaGameOver.openFromFile("audios/gameOver.flac")) {
		std::cerr << "Erro ao carregar o arquivo de som\n";
	}
	musicaGameOver.setVolume(50);


	//cria entidades botoes
	Entidade botaoPlay(texturaBotaoPlay[0], 400, 400, sf::IntRect (0, 0, 300, 120), sf::Vector2f (1.0f, 1.0f));
	Entidade botaoCredito(texturaBotaoCredito[0], 400, 550, sf::IntRect (0, 0, 300, 120), sf::Vector2f (1.0f, 1.0f));


	//loop principal
	while (mapaGameOver.getWindow().isOpen()) {

		//loop de eventos
		while (mapaGameOver.getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mapaGameOver.getWindow().close();
			}
		}


		//atualiza mundo

		//pega a posicao do mouse e passa como coordenadas para o mapa
		sf::Vector2i mousePos = sf::Mouse::getPosition(mapaGameOver.getWindow());
		mapaGameOver.setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		//se o mouse passar por cima dos botoes aparecera o o botao hover, senao aparecera o botao normal
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

		//a classe Jogo ou Credito sera criada se houver click e se o mouse estiver em contato com os botoes
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

		if(musicaGameOver.getStatus() != sf::Sound::Playing){
			musicaGameOver.play();
		}


		//desenha mundo

		mapaGameOver.getWindow().clear();

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

