/*
 * JogarDeNovo.cpp
 *
 *  Created on: 6 de out. de 2024
 *      Author: mathe
 */

#include "JogarDeNovo.hpp"

JogarDeNovo::JogarDeNovo() {

	if (!texturaFundoPergunta.loadFromFile("imagens/fundoCarregamento2.jpg")) {
		std::cerr << "Erro ao abrir a imagem de fundo\n";
	}

	fundoPergunta.setTexture(texturaFundoPergunta);
	sf::VideoMode tamjanela(texturaFundoPergunta.getSize().x, texturaFundoPergunta.getSize().y);

	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao abrir a textura de �cone\n";
	}

	mapaPergunta = new Mapa(tamjanela, fundoPergunta);

	mapaPergunta->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	if (!texturaBotaoPlayAgain[0].loadFromFile("imagens/botaoJogarDeNovo.png")) {
		std::cerr << "Erro ao abrir a textura do botao de jogar\n";
	}
	if (!texturaBotaoPlayAgain[1].loadFromFile("imagens/botaoJogarDeNovoHover.png")) {
		std::cerr << "Erro ao abrir a textura do botao jogar hover\n";
	}

	if (!texturaBotaoProximaFase[0].loadFromFile("imagens/botaoProximaFase.png") ||
			!texturaBotaoProximaFase[1].loadFromFile("imagens/botaoProximaFaseHover.png")) {
		std::cerr << "Erro ao carregar texturas de botão Créditos." << std::endl;
	}



	sf::Font fonteTituloRemake;
	fonteTituloRemake.loadFromFile("fontes/fonte1.TTF");

	sf::Text tituloRemake;
	tituloRemake.setFont(fonteTituloRemake);
	tituloRemake.setString("\t PARABENS\nVoce passou de fase!");
	tituloRemake.setCharacterSize(45);
	tituloRemake.setPosition(25, 50);
	tituloRemake.setOutlineThickness(3);
	tituloRemake.setOutlineColor(sf::Color(0, 0, 0));

	sf::Music musicaGanhou;
	if (!musicaGanhou.openFromFile("audios/ganhou.wav")) {
		std::cerr << "Erro ao carregar o arquivo de som\n";
	}
	musicaGanhou.setVolume(50);
	musicaGanhou.setLoop(true);
	musicaGanhou.play();

	sf::IntRect retangulo(0, 0, 1000, 400);
	sf::Vector2f escala(0.27f, 0.27f);
	botaoPlayAgain = new Entidade(texturaBotaoPlayAgain[0], texturaFundoPergunta.getSize().x/2, 250, retangulo, escala);
	botaoProximaFase = new Entidade(texturaBotaoProximaFase[0], texturaFundoPergunta.getSize().x/2, 350, retangulo, escala);

	int x = 0;
	int y = 0;
	int z = 0;

	// Loop principal
	while (mapaPergunta->getWindow().isOpen()) {
		while (mapaPergunta->getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mapaPergunta->getWindow().close();
			}
		}
		x++; y += 2; z+= 3;
		tituloRemake.setFillColor(sf::Color((x % 255), (y % 255), (z % 255) ));

		sf::Vector2i mousePos = sf::Mouse::getPosition(mapaPergunta->getWindow());
		mapaPergunta->setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (botaoPlayAgain->getSprite().getGlobalBounds().contains(mapaPergunta->getCordenadas())) {
			botaoPlayAgain->setTexturaSprite(texturaBotaoPlayAgain[1]);
		} else {
			botaoPlayAgain->setTexturaSprite(texturaBotaoPlayAgain[0]);
		}
		if (botaoProximaFase->getSprite().getGlobalBounds().contains(mapaPergunta->getCordenadas())) {
			botaoProximaFase->setTexturaSprite(texturaBotaoProximaFase[1]);
		} else {
			botaoProximaFase->setTexturaSprite(texturaBotaoProximaFase[0]);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		    if (botaoPlayAgain->getSprite().getGlobalBounds().contains(mapaPergunta->getCordenadas())) {
		        if (musicaGanhou.getStatus() == sf::Sound::Playing) {
		            musicaGanhou.pause();
		        }
		        mapaPergunta->getWindow().close();
		        Fase1 fase1;
		    } else if (botaoProximaFase->getSprite().getGlobalBounds().contains(mapaPergunta->getCordenadas())) {
		    	mapaPergunta->getWindow().close();
		        Fase2 fase2;
		    }
		}

		mapaPergunta->getWindow().clear();

		mapaPergunta->getWindow().draw(fundoPergunta);
		mapaPergunta->getWindow().draw(tituloRemake);
		mapaPergunta->getWindow().draw(botaoPlayAgain->getSprite());
		mapaPergunta->getWindow().draw(botaoProximaFase->getSprite());

		mapaPergunta->getWindow().display();

	}
	JogarDeNovo::~JogarDeNovo();
}

JogarDeNovo::~JogarDeNovo() {
	// TODO Auto-generated destructor stub
}

