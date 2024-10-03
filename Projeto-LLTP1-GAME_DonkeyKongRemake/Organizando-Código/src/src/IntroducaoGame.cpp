
#include "IntroducaoGame.hpp"

IntroducaoGame::IntroducaoGame() {
	sf::Texture texturaFundoCarregamento;
	if (!texturaFundoCarregamento.loadFromFile("imagens/fundoCarregamento.jpg")) {
		std::cerr << "Erro ao abrir a imagem de fundo." << std::endl;
	}

	sf::Sprite fundoCarregamento;
	fundoCarregamento.setTexture(texturaFundoCarregamento);

	sf::VideoMode tamjanela(texturaFundoCarregamento.getSize().x, texturaFundoCarregamento.getSize().y);
	sf::Event event;
	sf::Image icon;
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao abrir a textura do botão jogar." << std::endl;
	}

	Mapa carregamento(tamjanela, fundoCarregamento);
	carregamento.getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	sf::Texture texturaBotaoPlay[2];
	if (!texturaBotaoPlay[0].loadFromFile("imagens/botaoJogar.png")) {
		std::cerr << "Erro ao abrir a textura do botão jogar." << std::endl;
	}
	if (!texturaBotaoPlay[1].loadFromFile("imagens/botaoJogarHover.png")) {
		std::cerr << "Erro ao abrir a textura do botão jogar hover." << std::endl;
	}

	sf::Texture texturaBotaoCredito[2];

	if (!texturaBotaoCredito[0].loadFromFile("imagens/botaoCreditos.png")) {
		std::cerr << "Erro ao abrir a textura do botão jogar." << std::endl;
	}
	if (!texturaBotaoCredito[1].loadFromFile("imagens/botaoCreditosHover.png")) {
		std::cerr << "Erro ao abrir a textura do botão jogar hover." << std::endl;
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

	sf::IntRect rect(0, 0, 300, 120);
	sf::Vector2f escala(1.0f, 1.0f);
	Entidade botaoPlay(texturaBotaoPlay[0], 400, 400, rect, escala);
	Entidade botaoCredito(texturaBotaoCredito[0], 400, 550, rect, escala);

	// Loop principal
	// Loop principal
	while (carregamento.getWindow().isOpen()) {
		while (carregamento.getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				carregamento.getWindow().close();
			}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(carregamento.getWindow());
		carregamento.setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (botaoPlay.getSprite().getGlobalBounds().contains(carregamento.getCordenadas())) {
			botaoPlay.setSprite(texturaBotaoPlay[1]);
		} else {
			botaoPlay.setSprite(texturaBotaoPlay[0]);
		}
		if (botaoCredito.getSprite().getGlobalBounds().contains(carregamento.getCordenadas())) {
			botaoCredito.setSprite(texturaBotaoCredito[1]);
		} else {
			botaoCredito.setSprite(texturaBotaoCredito[0]);
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(botaoPlay.getSprite().getGlobalBounds().contains(carregamento.getCordenadas())){
				carregamento.~Mapa();
				Jogo jogo;
			}
		}


		carregamento.getWindow().clear();
		carregamento.getWindow().draw(fundoCarregamento);
		carregamento.getWindow().draw(tituloDonkeyKong);
		carregamento.getWindow().draw(tituloRemake);
		carregamento.getWindow().draw(botaoPlay.getSprite());
		carregamento.getWindow().draw(botaoCredito.getSprite());
		carregamento.getWindow().display();
	}



}

IntroducaoGame::~IntroducaoGame() {
	std::cerr << "Tela de Introdução Destruida";
}

