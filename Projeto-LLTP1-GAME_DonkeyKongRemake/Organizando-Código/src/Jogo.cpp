#include "Jogo.hpp"

Jogo::Jogo(){
	carregarAudios();
	carregartexturas();
	gerarEscadas();
	gerarPlataformas();
	criarMapa();
	criarPersonagens();
	setTexturaFundo();
	criarVidas();

    loopPrincipal();
}

Jogo::~Jogo(){
	delete mapaJogo;
	delete mario;
	delete kong;
	delete pauline;
	delete martelo;
	delete[] barris;
	delete[] escadas;
	delete[] plataformas;

    std::cerr << "Jogo Fechado\n";
}

void Jogo::setTexturaFundo(){
	fundoJogo.setTexture(texturaFundoJogo);
}

void Jogo::carregarAudios(){
	if (!musicaFundo.openFromFile("audios/audioFundo.flac")) {
	    std::cerr << "Erro ao carregar a música de fundo\n";
	}
	musicaFundo.setVolume(50);

	if (!musicaGanhou.openFromFile("audios/ganhou.wav")) {
	    std::cerr << "Erro ao carregar a música de fundo\n";
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
		std::cerr << "Erro ao carregar som do martelo\n";
	}
	somMartelo.setBuffer(bufferMartelo);
	somMartelo.setVolume(100);
}

void Jogo::carregartexturas(){
	//texturas fundo e icon
	if (!texturaFundoJogo.loadFromFile("imagens/fundoJogo.png")){
		std::cerr << "Erro ao carregar textura do fundo\n";
	}
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao carregar textura do ícone\n";
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
		std::cerr << "Erro ao carregar textura do Mario com martelo\n";
	}

	if (!texturaMarteloDireita.loadFromFile("imagens/marteloDireita.png")){
		std::cerr << "Erro ao carregar textura do Mario com martelo\n";
	}

	//textura barril
	if (!texturaBarril.loadFromFile("imagens/barril.png")){
		std::cerr << "Erro ao carregar textura do barril\n";
	}

	//textura kong
	if (!texturaKong.loadFromFile("imagens/kong.png")){
		std::cerr << "Erro ao carregar textura do Kong\n";
	}

	//texturas pauline
	if (!texturaPaulineDireita.loadFromFile("imagens/paulineDireita.png")){
		std::cerr << "Erro ao carregar textura da Pauline Direita\n";
	}

	if (!texturaPaulineEsquerda.loadFromFile("imagens/paulineEsquerda.png")){
		std::cerr << "Erro ao carregar textura da Pauline Esquerda\n";
	}

	if (!texturaPaulineCoracao.loadFromFile("imagens/paulineCoracao.png")){
		std::cerr << "Erro ao carregar textura da Pauline com coracao\n";
	}

	//textura martelo
	if (!texturaMartelo.loadFromFile("imagens/martelo.png")){
		std::cerr << "Erro ao carregar textura do martelo\n";
	}

	//textura coracao
	if (!texturaCoracao.loadFromFile("imagens/coracao.png")){
		std::cerr << "Erro ao carregar textura do coracao\n";
	}

}

void Jogo::gerarPlataformas(){
	plataformas = new Plataforma[7];

	for(int i=0; i<7; i++){
		plataformas[i].setTexturaSprite(texturaPlataforma);
	}

	plataformas[0].definePlataforma( false, 0, 14, 0, 110);
	plataformas[1].definePlataforma( false, 0, 22, 0, 230);
	plataformas[2].definePlataforma( true, 1, 19, 1000, 370);
	plataformas[3].definePlataforma( false, 0, 4, 0, 530);
	plataformas[4].definePlataforma( true, 1, 21, 1000, 520);
	plataformas[5].definePlataforma( false, 1, 21, 0, 650);
	plataformas[6].definePlataforma( false, 0, 42, 0, 780);
}

void Jogo::gerarEscadas(){
    escadas = new Escada[11];
	for(int i=0; i<11; i++){
		escadas[i].setTexturaSprite(texturaEscada);
	}

	escadas[0].defineEscada(13, 650, 230);
	escadas[1].defineEscada(11, 200, 110);
	escadas[2].defineEscada(8, 440, 230);
	escadas[3].defineEscada(9, 500, 670);
	escadas[4].defineEscada(12, 880, 375);
	escadas[5].defineEscada(10, 20, 530);
	escadas[6].defineEscada(7, 600, 385);
	escadas[7].defineEscada(7, 500, 470);
	escadas[8].defineEscada(10, 300, 660);
	escadas[9].defineEscada(10, 360, 540);
	escadas[10].defineEscada(10, 600, 540);
}

void Jogo::criarPersonagens(){
	mario = new Mario(texturaMarioDireita, 300, 780-plataformas[0].getSprite().getGlobalBounds().height);
	kong = new Kong(texturaKong, 100, 120-plataformas[0].getSprite().getGlobalBounds().height*2);
	pauline = new Pauline(texturaPaulineDireita, 250, 120-plataformas[0].getSprite().getGlobalBounds().height);
	martelo = new Entidade(texturaMartelo, 150, 120+plataformas[0].getSprite().getGlobalBounds().height, sf::IntRect(0,0,9,15), sf::Vector2f(3.0f, 3.0f));
	barris = new Barril[7];

	for (int i = 0; i < 7; ++i) {
		int windowLargura = static_cast<int>(mapaJogo->getWindow().getSize().x);
		int windowAltura = static_cast<int>(mapaJogo->getWindow().getSize().y/3);

		int spriteLargura = static_cast<int>(barris[i].getSprite().getGlobalBounds().width);
		int spriteAltura = static_cast<int>(barris[i].getSprite().getGlobalBounds().height);

		float posX = static_cast<float>(rand() % (windowLargura - spriteLargura));
		float posY = static_cast<float>(rand() % (windowAltura - spriteAltura));

		barris[i] = Barril(texturaBarril, posX, posY);
		barris[i].getSprite().setTexture(texturaBarril);
		barris[i].determinarMovimento();
	}
}

void Jogo::criarVidas(){
	for(int i=0; i<3; i++){
		sf::Sprite coracao;
		coracao.setTexture(texturaCoracao);
		coracao.setScale(4.0f, 4.0f);
		coracao.setPosition(800+(coracao.getGlobalBounds().width/2*i), 100);
		coracoes.push_back(coracao);
	}
}

void Jogo::criarMapa(){
	mapaJogo = new Mapa(sf::VideoMode(texturaFundoJogo.getSize().x, texturaFundoJogo.getSize().y), fundoJogo);
	mapaJogo->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Jogo::desenharMapa(){
    mapaJogo->getWindow().draw(fundoJogo);
    for (int i = 0; i < 11; ++i) {
    	escadas[i].draw(mapaJogo->getWindow());
    }
    for (int i = 0; i < 7; ++i) {
    	plataformas[i].draw(mapaJogo->getWindow());
    }

    for(int i=0; i<7; i++){
    	mapaJogo->getWindow().draw(barris[i].getSprite());
    }

    for(int i=0; i<3; i++){
    	mapaJogo->getWindow().draw(coracoes.at(i));
    }

    mapaJogo->getWindow().draw(kong->getSprite());
    mapaJogo->getWindow().draw(mario->getSprite());
    mapaJogo->getWindow().draw(pauline->getSprite());
    mapaJogo->getWindow().draw(martelo->getSprite());
}

void Jogo::dificultarJogo(){
	if(mario->getPosicao(). y < (mapaJogo->getWindow().getSize().y/2)){
		for(int i=0; i<3; i++){
			barris[i].respawAleatotio(mapaJogo->getWindow());
		}
	}
}

void Jogo::morteBarril(Barril &barril){
	sf::sleep(sf::seconds(1));
	barril.respawAleatotio(mapaJogo->getWindow());
}

void Jogo::morteMario(){
	coracoes.at(mario->getVidas()-1).setPosition(-200, -200);
	mario->setVidas(mario->getVidas()-1);

	mario->setPegouMartelo(false);
	martelo->setPosicao(150, 120+plataformas[0].getSprite().getGlobalBounds().height+10);

	if(musicaFundo.getStatus() == sf::Music::Playing){
		musicaFundo.pause();
	}
	if(somMorte.getStatus() != sf::Sound::Playing){
		somMorte.play();
		sf::sleep(sf::seconds(5));
	}
	musicaFundo.play();

	mario->setPosicao(20, mapaJogo->getTamanhoJanela().height - 25);
	respawnarBarris();
}

void Jogo::colidirMarioMartelo(){
	if(mario->getSprite().getGlobalBounds().intersects(martelo->getSprite().getGlobalBounds())){
		if(somGet.getStatus() != sf::Sound::Playing){
			somGet.play();
			sf::sleep(sf::seconds(1));
		}
		mario->setPegouMartelo(true);
		martelo->setPosicao(-100, -100);
	}
}

void Jogo::colidirComPlataformas(){
	//colisão mario e plataformas
    for (int i = 0; i < 7; ++i) {
    	if (colisao.colisaoMarioPlataforma(*mario, plataformas[i])) {
            mario->setNoAr(false);
            mario->setVelocidade(0, 0);
    	}

    	//colisão barril e plataformas
    	for (int j = 0; j < 7; ++j) {
    		colisao.colisaoBarrilPlataforma(barris[j], plataformas[i]);
		}

    }

}

void Jogo::colidirComEscadas(){
	//colisão mario e escadas
	for (int i = 0; i < 11; ++i) {
		if(i != 6 && i!= 7){
			if (colisao.colisaoPersonagemEscada(*mario, escadas[i])) {
				mario->setEmEscada(true);
				break;
			}
		}
		else {
			mario->setEmEscada(false);
		}
	}
}

void Jogo::colidirPersonagens(){
	//colisão mario e barril
	for (int i = 0; i < 7; ++i) {
		if(colisao.colisaoEntrePersonagens(*mario, barris[i])){
			if(mario->getApertouX()){
				morteBarril(barris[i]);
			}else{
				morteMario();
			}
		}
	}
}

void Jogo::movimentarPersonagens(){
	//movimento mário
	mario->permitirMovimento(*mapaJogo);
	mario->mover();
	mario->sofrerGravidade();

	kong->mover();

	pauline->mover();

	//movimento barril
	for (int i = 0; i < 7; ++i) {
		colisao.colisaoBarrilMapa(barris[i], mapaJogo);
		barris[i].mover();
		barris[i].sofrerGravidade();
	}
}

void Jogo::respawnarBarris(){
	for(int i=0; i<7; i++){
		barris[i].respawAleatotio(mapaJogo->getWindow());
	}
}

void Jogo::animarMario(int *auxiliar){
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

void Jogo::animarPauline(){
	if(pauline->getVelocidade().x > 0){
		pauline->setTexturaSprite(texturaPaulineDireita);
	}else if(pauline->getVelocidade().x < 0){
		pauline->setTexturaSprite(texturaPaulineEsquerda);
	}
}

void Jogo::fecharJanela(){
	while (mapaJogo->getWindow().pollEvent(evento)) {
		if (evento.type == sf::Event::Closed) {
			mapaJogo->getWindow().close();
		}
	}
}

void Jogo::loopPrincipal(){
	while (mapaJogo->getWindow().isOpen()) {

		fecharJanela();

		if(!mario->getGanhou()){
			dificultarJogo();
			int auxiliar;
			animarMario(&auxiliar);
			movimentarPersonagens();

			colidirComPlataformas();
			colidirComEscadas();
			colidirPersonagens();
			colidirMarioMartelo();
			gameOver();
		}
		ganharJogo();

		if(musicaFundo.getStatus() != sf::Music::Playing && !mario->getGanhou()){
			musicaFundo.play();
		}

		mapaJogo->getWindow().clear();
		desenharMapa();
		mapaJogo->getWindow().display();
	}
}

void Jogo::gameOver(){
	if(mario->getVidas() == 0){
		musicaFundo.pause();
		mapaJogo->~Mapa();
		GameOver gameOver;
	}
}

void Jogo::ganharJogo(){
	if(colisao.colisaoEntrePersonagens(*mario, *pauline)){
		for(int i=0; i<7; i++){
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
	}
}
