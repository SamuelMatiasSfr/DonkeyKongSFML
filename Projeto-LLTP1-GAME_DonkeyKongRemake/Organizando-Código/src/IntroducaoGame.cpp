#include "IntroducaoGame.hpp"

IntroducaoGame::IntroducaoGame() {

	sf::Texture texturaFundoTelaInicial;
	if (!texturaFundoTelaInicial.loadFromFile("imagens/fundoCarregamento.jpg")) {
		std::cerr << "Erro ao abrir a imagem de fundo\n";
	}

	sf::Sprite fundoTelaInicial;
	fundoTelaInicial.setTexture(texturaFundoTelaInicial);

	sf::VideoMode tamjanela(texturaFundoTelaInicial.getSize().x, texturaFundoTelaInicial.getSize().y);
	sf::Event event;
	sf::Image icon;
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao abrir a textura de ícone\n";
	}

	Mapa mapaTelaInicial(tamjanela, fundoTelaInicial);
	mapaTelaInicial.getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	sf::Texture texturaBotaoPlay[2];
	if (!texturaBotaoPlay[0].loadFromFile("imagens/botaoJogar.png")) {
		std::cerr << "Erro ao abrir a textura do botao de jogar\n";
	}
	if (!texturaBotaoPlay[1].loadFromFile("imagens/botaoJogarHover.png")) {
		std::cerr << "Erro ao abrir a textura do botao jogar hover\n";
	}

	sf::Texture texturaBotaoCredito[2];
	if (!texturaBotaoCredito[0].loadFromFile("imagens/botaoCreditos.png")) {
		std::cerr << "Erro ao abrir a textura do botao de créditos\n";
	}
	if (!texturaBotaoCredito[1].loadFromFile("imagens/botaoCreditosHover.png")) {
		std::cerr << "Erro ao abrir a textura do botaoo de créditos hover\n";
	}

	sf::Font fonteDonkeyKongTitulo, fonteTituloRemake;
	fonteDonkeyKongTitulo.loadFromFile("fontes/Jumpman.ttf");
	fonteTituloRemake.loadFromFile("fontes/fonte1.TTF");
	sf::Text tituloDonkeyKong, tituloRemake;
	tituloRemake.setFont(fonteTituloRemake);
	tituloDonkeyKong.setFont(fonteDonkeyKongTitulo);
	tituloDonkeyKong.setString("Donkey Kong");
	tituloRemake.setString("REMAKE");
	tituloDonkeyKong.setFillColor(sf::Color::Red);
	tituloRemake.setFillColor(sf::Color(111, 0, 0));
	tituloDonkeyKong.setCharacterSize(130);
	tituloDonkeyKong.setStyle(sf::Text::Bold);
	tituloDonkeyKong.setOutlineColor(sf::Color(236, 236, 0));
	tituloDonkeyKong.setOutlineThickness(5);
	tituloRemake.setCharacterSize(60);
	tituloDonkeyKong.setPosition(60, 50);
	tituloRemake.setPosition(230, 200);

	sf::Music musicaComeco;
	if (!musicaComeco.openFromFile("audios/comeco.flac")) {
		std::cerr << "Erro ao carregar o arquivo de som\n";
	}
	musicaComeco.setVolume(50);

	sf::IntRect retangulo(0, 0, 300, 120);
	sf::Vector2f escala(1.0f, 1.0f);
	Entidade botaoPlay(texturaBotaoPlay[0], 400, 400, retangulo, escala);
	Entidade botaoCredito(texturaBotaoCredito[0], 400, 550, retangulo, escala);

	// Loop principal
	while (mapaTelaInicial.getWindow().isOpen()) {
		while (mapaTelaInicial.getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mapaTelaInicial.getWindow().close();
			}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(mapaTelaInicial.getWindow());
		mapaTelaInicial.setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (botaoPlay.getSprite().getGlobalBounds().contains(mapaTelaInicial.getCordenadas())) {
			botaoPlay.setTexturaSprite(texturaBotaoPlay[1]);
		} else {
			botaoPlay.setTexturaSprite(texturaBotaoPlay[0]);
		}
		if (botaoCredito.getSprite().getGlobalBounds().contains(mapaTelaInicial.getCordenadas())) {
			botaoCredito.setTexturaSprite(texturaBotaoCredito[1]);
		} else {
			botaoCredito.setTexturaSprite(texturaBotaoCredito[0]);
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(botaoPlay.getSprite().getGlobalBounds().contains(mapaTelaInicial.getCordenadas())){
				mapaTelaInicial.~Mapa();
				if(musicaComeco.getStatus() == sf::Sound::Playing){
					musicaComeco.pause();
				}
				Jogo jogo;
			}
		}

		mapaTelaInicial.getWindow().clear();

		if(musicaComeco.getStatus() != sf::Sound::Playing){
			musicaComeco.play();
		}

		mapaTelaInicial.getWindow().draw(fundoTelaInicial);
		mapaTelaInicial.getWindow().draw(tituloDonkeyKong);
		mapaTelaInicial.getWindow().draw(tituloRemake);
		mapaTelaInicial.getWindow().draw(botaoPlay.getSprite());
		mapaTelaInicial.getWindow().draw(botaoCredito.getSprite());

		mapaTelaInicial.getWindow().display();

	}
}

IntroducaoGame::~IntroducaoGame() {
	std::cerr << "Tela de Introducao Destruida\n";
}

