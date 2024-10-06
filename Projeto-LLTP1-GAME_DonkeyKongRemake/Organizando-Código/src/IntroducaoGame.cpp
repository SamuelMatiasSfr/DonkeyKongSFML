#include "IntroducaoGame.hpp"


void IntroducaoGame::IniciarJogo(){
	delete carregamento;
	new Jogo();
}

void IntroducaoGame::mostraCreditos(){
	new Credito();
}

IntroducaoGame::IntroducaoGame(){

    if (!texturaFundoCarregamento.loadFromFile("imagens/fundoCarregamento.jpg")) {
        std::cerr << "Erro ao abrir a imagem de fundo." << std::endl;
    }
    fundoCarregamento.setTexture(texturaFundoCarregamento);

    if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
        std::cerr << "Erro ao abrir o ícone." << std::endl;
    }

    if (!texturaBotaoPlay[0].loadFromFile("imagens/botaoJogar.png") ||
        !texturaBotaoPlay[1].loadFromFile("imagens/botaoJogarHover.png")) {
        std::cerr << "Erro ao carregar texturas de botão Play." << std::endl;
    }

    if (!texturaBotaoCredito[0].loadFromFile("imagens/botaoCreditos.png") ||
        !texturaBotaoCredito[1].loadFromFile("imagens/botaoCreditosHover.png")) {
        std::cerr << "Erro ao carregar texturas de botão Créditos." << std::endl;
    }

    if (!somInicioBuffer.loadFromFile("audios/telaInicio.wav")) {
        std::cerr << "Erro ao carregar som de início." << std::endl;
    }

    carregamento = new Mapa(sf::VideoMode(texturaFundoCarregamento.getSize().x, texturaFundoCarregamento.getSize().y), fundoCarregamento);
    carregamento->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    somInicio.setBuffer(somInicioBuffer);
    somInicio.setLoop(true);
    somInicio.play();

    fonteDonkeyKongTitulo.loadFromFile("fontes/Jumpman.ttf");
    fonteTituloRemake.loadFromFile("fontes/fonte1.TTF");
    tituloDonkeyKong.setFont(fonteDonkeyKongTitulo);
    tituloRemake.setFont(fonteTituloRemake);
    tituloDonkeyKong.setString("Donkey Kong");
    tituloRemake.setString("REMAKE");

    tituloDonkeyKong.setFillColor(sf::Color::Red);
    tituloDonkeyKong.setCharacterSize(130);
    tituloDonkeyKong.setPosition(60, 50);
    tituloDonkeyKong.setOutlineColor(sf::Color(236, 236, 0));
    tituloDonkeyKong.setOutlineThickness(5);
    tituloRemake.setFillColor(sf::Color(111, 0, 0));
    tituloRemake.setCharacterSize(60);
    tituloRemake.setPosition(230, 200);

    sf::IntRect rect(0, 0, 300, 120);
    sf::Vector2f escala(1.0f, 1.0f);
    botaoPlay = Entidade(texturaBotaoPlay[0], 400, 400, rect, escala);
    botaoCredito = Entidade(texturaBotaoCredito[0], 400, 550, rect, escala);

    while (carregamento->getWindow().isOpen()) {
        while (carregamento->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                carregamento->getWindow().close();
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(carregamento->getWindow());
        carregamento->setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        if (botaoPlay.getSprite().getGlobalBounds().contains(carregamento->getCordenadas())) {
            botaoPlay.setTexturaSprite(texturaBotaoPlay[1]);
        } else {
            botaoPlay.setTexturaSprite(texturaBotaoPlay[0]);
        }
        if (botaoCredito.getSprite().getGlobalBounds().contains(carregamento->getCordenadas())) {
            botaoCredito.setTexturaSprite(texturaBotaoCredito[1]);
        } else {
            botaoCredito.setTexturaSprite(texturaBotaoCredito[0]);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (botaoPlay.getSprite().getGlobalBounds().contains(carregamento->getCordenadas())) {
                IniciarJogo();
            }
            else if (botaoCredito.getSprite().getGlobalBounds().contains(carregamento->getCordenadas())) {
                mostraCreditos();
            }
        }

        carregamento->getWindow().clear();
        carregamento->getWindow().draw(fundoCarregamento);
        carregamento->getWindow().draw(tituloDonkeyKong);
        carregamento->getWindow().draw(tituloRemake);
        carregamento->getWindow().draw(botaoPlay.getSprite());
        carregamento->getWindow().draw(botaoCredito.getSprite());
        carregamento->getWindow().display();
    }
}

IntroducaoGame::~IntroducaoGame() {

	somInicio.stop();
	somPlay.stop();
    std::cerr << "Tela de Introdução Destruída";

}
