#include "IntroducaoGame.hpp"

IntroducaoGame::IntroducaoGame(){
	//carrega texturas
    if (!texturaFundoCarregamento.loadFromFile("imagens/fundoCarregamento.jpg")) {
        std::cerr << "Erro ao abrir a imagem de fundo\n";
    }
    fundoCarregamento.setTexture(texturaFundoCarregamento);

    if(!texturaBotaoPlay[0].loadFromFile("imagens/botaoJogar.png") ||
        !texturaBotaoPlay[1].loadFromFile("imagens/botaoJogarHover.png")){
        std::cerr << "Erro ao carregar texturas de botao Play\n";
    }

    if(!texturaBotaoCredito[0].loadFromFile("imagens/botaoCreditos.png") ||
        !texturaBotaoCredito[1].loadFromFile("imagens/botaoCreditosHover.png")){
        std::cerr << "Erro ao carregar texturas de botao Creditos\n";
    }


    //carrega imagem icone
    if(!icon.loadFromFile("imagens/donkeyKong-icon.png")){
		std::cerr << "Erro ao abrir a imagem do icone\n";
	}


    //carrega musica de tela inicial
    if(!musicaInicio.openFromFile("audios/comeco.flac")){
        std::cerr << "Erro ao carregar som de inicio\n";
    }


    //cria mapa de tela inicial
    mapaCarregamento = new Mapa(sf::VideoMode(texturaFundoCarregamento.getSize().x, texturaFundoCarregamento.getSize().y), fundoCarregamento);
    mapaCarregamento->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    //carrega fontes e titulos
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


    //cria botoes
    botaoPlay = Entidade(texturaBotaoPlay[0], 400, 400, sf::IntRect(0, 0, 300, 120), sf::Vector2f(1.0f, 1.0f));
    botaoCredito = Entidade(texturaBotaoCredito[0], 400, 550, sf::IntRect(0, 0, 300, 120), sf::Vector2f(1.0f, 1.0f));


    //loop principal
    while (mapaCarregamento->getWindow().isOpen()) {

    	//loop de eventos
        while (mapaCarregamento->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mapaCarregamento->getWindow().close();
            }
        }


        //atualiza mundo

        //pega a posicao do mouse e passa como coordenadas para o mapa
        sf::Vector2i mousePos = sf::Mouse::getPosition(mapaCarregamento->getWindow());
        mapaCarregamento->setCordenadas(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		//se o mouse passar por cima dos botoes aparecera o o botao hover, senao aparecera o botao normal
        if (botaoPlay.getSprite().getGlobalBounds().contains(mapaCarregamento->getCordenadas())) {
            botaoPlay.setTexturaSprite(texturaBotaoPlay[1]);
        } else {
            botaoPlay.setTexturaSprite(texturaBotaoPlay[0]);
        }
        if (botaoCredito.getSprite().getGlobalBounds().contains(mapaCarregamento->getCordenadas())) {
            botaoCredito.setTexturaSprite(texturaBotaoCredito[1]);
        } else {
            botaoCredito.setTexturaSprite(texturaBotaoCredito[0]);
        }

		//a classe Jogo ou Credito sera criada se houver click e se o mouse estiver em contato com os botoes
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (botaoPlay.getSprite().getGlobalBounds().contains(mapaCarregamento->getCordenadas())) {
                iniciarJogo();
            }
            else if (botaoCredito.getSprite().getGlobalBounds().contains(mapaCarregamento->getCordenadas())) {
                mostraCreditos();
            }
        }

        if(musicaInicio.getStatus() != sf::Sound::Playing){
        	musicaInicio.play();
        }


        //desenha mundo

        mapaCarregamento->getWindow().clear();

        mapaCarregamento->getWindow().draw(fundoCarregamento);
        mapaCarregamento->getWindow().draw(tituloDonkeyKong);
        mapaCarregamento->getWindow().draw(tituloRemake);
        mapaCarregamento->getWindow().draw(botaoPlay.getSprite());
        mapaCarregamento->getWindow().draw(botaoCredito.getSprite());

        mapaCarregamento->getWindow().display();
    }
}

IntroducaoGame::~IntroducaoGame() {
    std::cerr << "Tela de Introducao Destruida\n";
}

void IntroducaoGame::iniciarJogo(){
    if(musicaInicio.getStatus() == sf::Sound::Playing){
    	musicaInicio.stop();
    }
	delete mapaCarregamento;
	new Jogo();
}

void IntroducaoGame::mostraCreditos(){
	new Credito();
}
