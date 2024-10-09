/*
 * Fase2.cpp
 *
 *  Created on: 6 de out. de 2024
 *      Author: mathe
 */

#include "Fase2.hpp"

Fase2::Fase2(){

	carregarAudios();
	carregartexturas();
	gerarEscadas();
	gerarPlataformas();
	criarMapa();
	criarPersonagens();
	setTexturaFundo();
	geraMoedinhas();
	criarVidas();

    loopPrincipal();
}

Fase2::~Fase2(){
	delete mapaJogo;
	delete mario;
	delete kong;
	delete pauline;
	delete martelo;

    std::cerr << "Jogo Fechado\n";
}

void Fase2::setTexturaFundo(){
	fundoJogo.setTexture(texturaFundoJogo);
}

void Fase2::carregarAudios(){

	if (!musicaFundo.openFromFile("audios/audioFundo.flac")) {
	    std::cerr << "Erro ao carregar a m�sica de fundo\n";
	}
	musicaFundo.setVolume(50);

	if (!musicaGanhou.openFromFile("audios/ganhou.wav")) {
	    std::cerr << "Erro ao carregar a m�sica de fundo\n";
	}
	musicaGanhou.setVolume(100);

	if (!bufferMorte.loadFromFile("audios/morte.wav")){
		std::cerr << "Erro ao carregar som de morte\n";
	}
	somMorte.setBuffer(bufferMorte);
	somMorte.setVolume(50);

	if (!bufferGet.loadFromFile("audios/itemget.wav")){
		std::cerr << "Erro ao carregar som de pegar item\n";
	}
	somGet.setBuffer(bufferGet);
	somGet.setVolume(50);

	if (!bufferMartelo.loadFromFile("audios/martelo.wav")){
		std::cerr << "Erro ao carregar som do Martelo\n";
	}
	somMartelo.setBuffer(bufferMartelo);
	somMartelo.setVolume(100);
}

void Fase2::carregartexturas(){
	//texturas fundo e icon
	if (!texturaFundoJogo.loadFromFile("imagens/fundoJogo.png")){
		std::cerr << "Erro ao carregar textura do fundo\n";
	}
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao carregar textura do �cone\n";
	}

	//textura escada
	if(!texturaEscada.loadFromFile("imagens/escada.png")){
		std::cerr << "Erro ao carregar textura da escada\n";
	}

	//textura plataforma
	if(!texturaPlataforma.loadFromFile("imagens/plataforma.png")){
		std::cerr << "Erro ao carregar textura da plataforma\n";
	}

	//texturas mario
	if (!texturaMarioDireita.loadFromFile("imagens/marioDireita.png")){
		std::cerr << "Erro ao carregar textura do Mario Direita\n";
	}

	if (!texturaMarioLeft.loadFromFile("imagens/marioEsquerda.png")){
		std::cerr << "Erro ao carregar textura do Mario Esquerda\n";
	}

	if (!texturaMarioSubindo.loadFromFile("imagens/marioSubindo.png")){
		std::cerr << "Erro ao carregar textura do Mario subindo\n";
	}

	if (!texturaMarioParado.loadFromFile("imagens/marioParado.png")){
		std::cerr << "Erro ao carregar textura do Mario parado\n";
	}

	if (!texturaMarteloEsquerda.loadFromFile("imagens/marteloEsquerda.png")){
		std::cerr << "Erro ao carregar textura do Mario com Martelo\n";
	}

	if (!texturaMarteloDireita.loadFromFile("imagens/marteloDireita.png")){
		std::cerr << "Erro ao carregar textura do Mario com Martelo\n";
	}

	//textura barril
	if (!texturaBarril.loadFromFile("imagens/barril.png")){
		std::cerr << "Erro ao carregar textura do barril\n";
	}

	//textura kong
	if (!texturaKong.loadFromFile("imagens/kong.png")){
		std::cerr << "Erro ao carregar textura do Kong\n";
	}

	if (!texturaPaulineCoracao.loadFromFile("imagens/paulineCoracao.png")){
		std::cerr << "Erro ao carregar textura da Pauline com coracao\n";
	}

	//textura Martelo
	if (!texturaMartelo.loadFromFile("imagens/Martelo.png")){
		std::cerr << "Erro ao carregar textura do Martelo\n";
	}

	//textura coracao
	if (!texturaCoracao.loadFromFile("imagens/coracao.png")){
		std::cerr << "Erro ao carregar textura do coracao\n";
	}

	if (!texturaCoracaoApagado.loadFromFile("imagens/perdendovida.png")){
		std::cerr << "Erro ao carregar textura do coracao\n";
	}

	if(!texturaCoin.loadFromFile("imagens/coin.png")){
		std::cerr << "Erro ao carregar texturas da moedinha\n";
	}

}

void Fase2::gerarPlataformas(){
	plataformas.resize(7);

	for (size_t i = 0; i < plataformas.size(); ++i) {
		plataformas[i].carregaTextura();
	}

	plataformas[0].definePlataforma( false, 0, 31, 0, 110);
	plataformas[1].definePlataforma( false, 0, 31, 0, 230);
	plataformas[2].definePlataforma( false, 0, 31, 0, 370);
	plataformas[3].definePlataforma( false, 0, 31, 0, 530);
	plataformas[5].definePlataforma( false, 0, 31, 0, 650);
	plataformas[6].definePlataforma( false, 0, 31, 0, 780);

}

void Fase2::geraMoedinhas(){
	coin.resize(4);

	for (size_t i = 0; i < coin.size(); ++i) {
		float j = i;
		coin[i].setPosicao(500, (100*i) + 200);
		if (i == coin.size() - 1){
			j = i - 0.2;
		}
		coin[i] = Entidade(texturaCoin, 500, (150*j) + 200, sf::IntRect( 0, 0, 758, 711), sf::Vector2f(0.05f, 0.05f) );
	}
}

void Fase2::gerarEscadas(){
	escadas.resize(11);

	for (size_t i = 0; i < escadas.size(); ++i) {
		escadas[i].carregaTextura();
	}

	escadas[0].defineEscada(13, 50, 230);
	escadas[1].defineEscada(11, 50, 110);
	escadas[2].defineEscada(12, 900, 110);
	escadas[3].defineEscada(9, 50, 670);
	escadas[4].defineEscada(12, 50, 375);
	escadas[5].defineEscada(10, 50, 530);
	escadas[6].defineEscada(12, 900, 385);
	escadas[7].defineEscada(12, 900, 385);
	escadas[8].defineEscada(10, 900, 650);
	escadas[9].defineEscada(12, 900, 230);
	escadas[10].defineEscada(12, 900, 530);

}

void Fase2::criarPersonagens(){

	mario = new Mario(texturaMarioDireita, 300, 780  -plataformas[0].getSprite().getGlobalBounds().height);
	kong = new Kong(texturaKong, 100, 110- 47);
	pauline = new Pauline(texturaPaulineDireita, 250, 120 - plataformas[0].getSprite().getGlobalBounds().height);
	martelo = new Entidade(texturaMartelo, 50, 530 - plataformas[0].getSprite().getGlobalBounds().height, sf::IntRect(0, 0, 9, 15), sf::Vector2f(3.0f, 3.5f));

	barris.resize(4);

	for (size_t i = 0; i < barris.size(); ++i) {
		float j = i;
		if (i == barris.size() - 1){
			j = i - 0.2;
		}
		barris[i] = Barril(texturaBarril);
		barris[i].setVelocidade(2.0*(barris.size() - j) + 3.0, 0);
		barris[i].setPosicao(30 , (150*j) + 200);
		barris[i].determinarMovimento();
	}
}

void Fase2::criarVidas(){
	for(int i = 0; i < 3; i++){
		sf::Sprite coracao;
		coracao.setTexture(texturaCoracao);
		coracao.setScale(0.02f, 0.02f);
		coracao.setPosition(700+(coracao.getGlobalBounds().width/2*i), 0);
		coracoes.push_back(coracao);
	}
}

void Fase2::criarMapa(){
	mapaJogo = new Mapa(sf::VideoMode(texturaFundoJogo.getSize().x, texturaFundoJogo.getSize().y), fundoJogo);
	mapaJogo->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Fase2::desenharMapa(){
    mapaJogo->getWindow().draw(fundoJogo);
    for (size_t i = 0; i < escadas.size(); ++i) {
    	escadas[i].draw(mapaJogo->getWindow());
    }
    for (size_t i = 0; i < plataformas.size(); ++i) {
    	plataformas[i].draw(mapaJogo->getWindow());
    }

    for (size_t i = 0; i < barris.size(); ++i){
    	mapaJogo->getWindow().draw(barris[i].getSprite());
    }

    for (size_t i = 0; i < coin.size(); ++i){
    	mapaJogo->getWindow().draw(coin[i].getSprite());
    }

    for(int i=0; i<3; i++){
    	mapaJogo->getWindow().draw(coracoes.at(i));
    }

    mapaJogo->getWindow().draw(kong->getSprite());
    mapaJogo->getWindow().draw(mario->getSprite());
    mapaJogo->getWindow().draw(pauline->getSprite());
    mapaJogo->getWindow().draw(martelo->getSprite());
}

void Fase2::morteBarril(Barril &barril){
	barril.setPosicao(0 -texturaFundoJogo.getSize().x, 0);
}

void Fase2::morteMario(){
	coracoes.at(mario->getVidas()-1).setTexture(texturaCoracaoApagado);
	mario->setVidas(mario->getVidas()-1);

	mario->setPegouMartelo(false);
	martelo->setPosicao(550, 300+plataformas[0].getSprite().getGlobalBounds().height+10);

	if(musicaFundo.getStatus() == sf::Music::Playing){
		musicaFundo.pause();
	}
	if(somMorte.getStatus() != sf::Sound::Playing){
		somMorte.play();
		sf::sleep(sf::seconds(5));
	}
	for (size_t i = 0; i < coin.size(); ++i) {
		float j = i;
		if(i == coin.size() - 1){
			j = i - 0.2;
		}
		coin[i].setPosicao(500, (150*j) + 200);
	}
	musicaFundo.play();

	mario->setPosicao(20, mapaJogo->getTamanhoJanela().height - 25);
	respawnarBarris();
}

void Fase2::colidirMarioMartelo(){
	if (mario->getSprite().getGlobalBounds().intersects(martelo->getSprite().getGlobalBounds())) {
	        if (somGet.getStatus() != sf::Sound::Playing) {
	            somGet.play();
	        }

	        mario->setPegouMartelo(true);
	        martelo->setPosicao(-100, -100);

	        clockMartelo.restart();
	    }

	    if (mario->getPegouMartelo() && clockMartelo.getElapsedTime().asSeconds() >= 8) {
	        mario->setPegouMartelo(false);
	    }
}

void Fase2::colidirMarioMoeda(){
	for (size_t i = 0; i < coin.size(); ++i){
		if(colisao.colisaoEntreEntidades(*mario, coin[i])){
			coin[i].setPosicao(-100, -100);
			mario->setPegaCoins(mario->getPegaCoins() + 1);
		}
	}

}

void Fase2::colidirComPlataformas(){
	//colis�o mario e plataformas
    for (size_t i = 0; i < plataformas.size(); ++i) {
    	if (colisao.colisaoMarioPlataforma(*mario, plataformas[i])) {
            mario->setNoAr(false);
            mario->setVelocidade(0, 0);
    	}

    	//colis�o barril e plataformas
    	for (size_t j = 0; j < barris.size(); ++j) {
    		colisao.colisaoBarrilPlataforma(barris[j], plataformas[i]);
		}

    }

}

void Fase2::colidirComEscadas(){
	//colis�o mario e escadas

	for (size_t i = 0; i < escadas.size(); ++i) {
		if (colisao.colisaoPersonagemEscada(*mario, escadas[i])) {
			mario->setEmEscada(true);
			break;
		}else {
			mario->setEmEscada(false);
		}
	}

}

void Fase2::colidirPersonagens(){
	//colis�o mario e barril
	for (size_t i = 0; i < barris.size(); ++i) {
		if(colisao.colisaoEntrePersonagens(*mario, barris[i])){
			if(mario->getApertouX()){
				morteBarril(barris[i]);
			}else{
				morteMario();
			}
		}
	}


}

void Fase2::movimentarPersonagens(){
	//movimento m�rio
	mario->permitirMovimento(*mapaJogo);
	mario->mover();
	mario->sofrerGravidade();

	kong->mover();

	pauline->mover();

	//movimento barril
	for (size_t i = 0; i < barris.size(); ++i) {
		colisao.colisaoBarrilMapa(barris[i], mapaJogo);
		barris[i].mover();
		barris[i].sofrerGravidade();
	}
}

void Fase2::respawnarBarris(){
	for (size_t i = 0; i < barris.size(); ++i) {
		float j = i;
		if (i == barris.size() - 1){
			j = i - 0.2;
		}
		barris[i] = Barril(texturaBarril);
		barris[i].setVelocidade(2.0*(barris.size() - j) + 3.0, 0);
		barris[i].setPosicao(30 , (150*j) + 200);
		barris[i].determinarMovimento();
	}
}

void Fase2::animarMario(int *auxiliar){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		mario->setParaDireitaEsquerda(true, false);
		*auxiliar = 1;
		int x=0;
		x=(int)mario->getPosicao().x /35 % 3;
		x = x*16;
		sf::IntRect retangulo(x, 0, 16, 16);
		mario->setTexturaSprite(texturaMarioDireita, retangulo);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		mario->setParaDireitaEsquerda(false, true);
		*auxiliar = 2;
		int x=0;
		x=(int)mario->getPosicao().x /35 % 3;
		x = x*16;
		sf::IntRect retangulo(x, 0, 16, 16);
		mario->setTexturaSprite(texturaMarioLeft, retangulo);
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		*auxiliar = 3;
		sf::IntRect retangulo(0, 0, 13, 16);
		mario->setTexturaSprite(texturaMarioSubindo, retangulo);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (mario->getPegouMartelo()) && (mario->getParaDireita())){
		*auxiliar = 4;
		sf::IntRect retangulo(0, 0, 25, 29);
		mario->setTexturaSprite(texturaMarteloDireita, retangulo);
		mario->setApertouX(true);
		if(somMartelo.getStatus() != sf::Sound::Playing){
			somMartelo.play();
		}
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (mario->getPegouMartelo()) && (mario->getParaEsquerda())){
		*auxiliar = 5;
		sf::IntRect retangulo(0, 0, 25, 29);
		mario->setTexturaSprite(texturaMarteloEsquerda, retangulo);
		mario->setApertouX(true);
		if(somMartelo.getStatus() != sf::Sound::Playing){
			somMartelo.play();
		}
	}else{
		if(*auxiliar == 1 || *auxiliar == 4){
			sf::IntRect retangulo(0, 0, 16, 16);
			mario->setTexturaSprite(texturaMarioDireita, retangulo);
		}else if(*auxiliar == 2 || *auxiliar == 5){
			sf::IntRect retangulo(0, 0, 16, 16);
			mario->setTexturaSprite(texturaMarioLeft, retangulo);
		}else if(*auxiliar == 3){
			sf::IntRect retangulo(0, 0, 16, 15);
			mario->setTexturaSprite(texturaMarioParado, retangulo);
		}
	}

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
		mario->setApertouX(false);
	}
}

void Fase2::animarPauline(){
	if(pauline->getVelocidade().x > 0){
		pauline->setTexturaSprite(texturaPaulineDireita);
	}else if(pauline->getVelocidade().x < 0){
		pauline->setTexturaSprite(texturaPaulineEsquerda);
	}
}

void Fase2::fecharJanela(){
	while (mapaJogo->getWindow().pollEvent(evento)) {
		if (evento.type == sf::Event::Closed) {
			mapaJogo->getWindow().close();
			//Fase2::~Fase2();
		}
	}
}

void Fase2::loopPrincipal(){
	while (mapaJogo->getWindow().isOpen()) {

		fecharJanela();

		if(!mario->getGanhou()){

			int auxiliar;
			animarMario(&auxiliar);
			movimentarPersonagens();

			colidirComPlataformas();
			colidirComEscadas();
			colidirPersonagens();
			colidirMarioMartelo();
			colidirMarioMoeda();
			gameOver();
		}
		ganharJogo();

		if(musicaFundo.getStatus() != sf::Music::Playing && !mario->getGanhou()){
			musicaFundo.play();
		}

		perguntaProximaFase();


		mapaJogo->getWindow().clear();
		desenharMapa();
		mapaJogo->getWindow().display();
	}
}

void Fase2::gameOver(){
	if(mario->getVidas() == 0){
		musicaFundo.pause();
		mapaJogo->getWindow().close();
		GameOver gameOver;
	}
}

void Fase2::ganharJogo(){
	if(colisao.colisaoEntrePersonagens(*mario, *pauline) && (mario->getPegaCoins() >= coin.size())){
		for (size_t i = 0; i < barris.size(); ++i){
			barris[i].setVelocidade(0,0);
		}

		if(musicaFundo.getStatus() == sf::Music::Playing){
			musicaFundo.pause();
		}
		if(musicaGanhou.getStatus() != sf::Music::Playing){
			musicaGanhou.play();
		}

		sf::sleep(sf::seconds(1));

		pauline->setVelocidade(0,0);
		sf::IntRect retanguloPauline(0, 0, 27, 22);
		pauline->setTexturaSprite(texturaPaulineCoracao, retanguloPauline);
		pauline->setPosicao(250, pauline->getPosicao().y);

		sf::IntRect retanguloMario(0, 0, 16, 16);
		mario->setTexturaSprite(texturaMarioLeft, retanguloMario);
		mario->setPosicao(pauline->getPosicao().x+50, pauline->getPosicao().y);
		mario->setGanhou(true);
		clockGanhou.restart();

	}
}

void Fase2::perguntaProximaFase(){//ao ganhar e tempo ser maior que 5 destroi a fase e volta jogador para a tela de introdução

	if(mario->getGanhou()){
		if(clockGanhou.getElapsedTime().asSeconds() >= 5){
			mapaJogo->getWindow().close();
			//Fase2::~Fase2();
			IntroducaoGame iniciaNovamente;
		}
	}
}
