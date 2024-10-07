#include "Jogo.hpp"

Jogo::Jogo() : barris(7), plataformas(7), escadas(11){
	carregarAudios();
	carregartexturas();

	gerarEscadas();
	gerarPlataformas();
	criarMapa();
	criarPersonagens();
	criarVidas();

	setTexturaFundo();

    loopPrincipal();
}

Jogo::~Jogo(){
	delete mapaJogo;
	delete mario;
	delete kong;
	delete pauline;
	delete escudo;

    std::cerr << "Jogo Fechado\n";
}

void Jogo::setTexturaFundo(){
	fundoJogo.setTexture(texturaFundoJogo);
}

void Jogo::carregarAudios(){
	//musica de fundo
	if (!musicaFundo.openFromFile("audios/audioFundo.flac")) {
	    std::cerr << "Erro ao carregar a musica de fundo\n";
	}
	musicaFundo.setVolume(50);

	//musica de vitoria do jogo
	if (!musicaGanhou.openFromFile("audios/ganhou.wav")) {
	    std::cerr << "Erro ao carregar a musica de vitória\n";
	}
	musicaGanhou.setVolume(100);

	//audio de morte do mario
	if (!bufferMorte.loadFromFile("audios/morte.wav")){
		std::cerr << "Erro ao carregar som de morte\n";
	}
	somMorte.setBuffer(bufferMorte);
	somMorte.setVolume(50);

	//audio de pegar item
	if (!bufferGet.loadFromFile("audios/itemget.wav")){
		std::cerr << "Erro ao carregar som de pegar item\n";
	}
	somGet.setBuffer(bufferGet);
	somGet.setVolume(50);

	//audio escudo
	if (!bufferEscudo.loadFromFile("audios/martelo.wav")){
		std::cerr << "Erro ao carregar som do escudo\n";
	}
	somEscudo.setBuffer(bufferEscudo);
	somEscudo.setVolume(100);
}

void Jogo::carregartexturas(){
	//texturas fundo e icon
	if (!texturaFundoJogo.loadFromFile("imagens/fundoJogo.png")){
		std::cerr << "Erro ao carregar textura do fundo\n";
	}
	if (!icon.loadFromFile("imagens/donkeyKong-icon.png")) {
		std::cerr << "Erro ao carregar textura do icone\n";
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

	if (!texturaEscudoEsquerda.loadFromFile("imagens/marteloEsquerda.png")){
		std::cerr << "Erro ao carregar textura do Mario com escudo\n";
	}

	if (!texturaEscudoDireita.loadFromFile("imagens/marteloDireita.png")){
		std::cerr << "Erro ao carregar textura do Mario com escudo\n";
	}

	//textura barril
	if (!texturaBarril.loadFromFile("imagens/barril.png")){
		std::cerr << "Erro ao carregar textura do barril\n";
	}

	//textura kong
	if (!texturaKong.loadFromFile("imagens/kong.png")){
		std::cerr << "Erro ao carregar textura do Kong\n";
	}

	//textura pauline com coracao
	if (!texturaPaulineCoracao.loadFromFile("imagens/paulineCoracao.png")){
		std::cerr << "Erro ao carregar textura da Pauline com coracao\n";
	}

	//textura escudo
	if (!texturaEscudo.loadFromFile("imagens/escudo.png")){
		std::cerr << "Erro ao carregar textura do escudo\n";
	}

	//textura coracao
	if (!texturaCoracao.loadFromFile("imagens/coracao.png")){
		std::cerr << "Erro ao carregar textura do coracao\n";
	}

	if (!texturaCoracaoApagado.loadFromFile("imagens/perdendovida.png")){
		std::cerr << "Erro ao carregar textura do coracao\n";
	}

}

void Jogo::gerarPlataformas(){
	for (size_t i = 0; i < plataformas.size(); ++i) {
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
	for (size_t i = 0; i < escadas.size(); ++i) {
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
	mario = new Mario(texturaMarioDireita, 300, 780 - plataformas[0].getSprite().getGlobalBounds().height);
	kong = new Kong(texturaKong, 100, 110 - 47);
	pauline = new Pauline(texturaPaulineDireita, 250, 120 - plataformas[0].getSprite().getGlobalBounds().height);
	escudo = new Entidade(texturaEscudo, 50, 530 - plataformas[0].getSprite().getGlobalBounds().height, sf::IntRect(0,0,5000,5000), sf::Vector2f(0.03f, 0.03f));

	for (size_t i = 0; i < barris.size(); ++i) {
		barris[i] = Barril(texturaBarril);
		barris[i].respawAleatotio(mapaJogo->getWindow());
		barris[i].determinarMovimento();
	}
}

void Jogo::criarVidas(){
	for(int i=0; i<3; i++){
		sf::Sprite coracao;
		coracao.setTexture(texturaCoracao);
		coracao.setScale(0.02f, 0.02f);
		coracao.setPosition(700+(coracao.getGlobalBounds().width/2*i), 0);
		coracoes.push_back(coracao);
	}
}

void Jogo::criarMapa(){
	mapaJogo = new Mapa(sf::VideoMode(texturaFundoJogo.getSize().x, texturaFundoJogo.getSize().y), fundoJogo);
	mapaJogo->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Jogo::desenharMapa(){
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

    for(int i=0; i<3; i++){
    	mapaJogo->getWindow().draw(coracoes.at(i));
    }

    mapaJogo->getWindow().draw(kong->getSprite());
    mapaJogo->getWindow().draw(mario->getSprite());
    mapaJogo->getWindow().draw(pauline->getSprite());
    mapaJogo->getWindow().draw(escudo->getSprite());
}

/*
 * quando esta chegando perto da pauline, os barris respawnam
 * na parte de cima do mapa para dificultar o jogo
 */
void Jogo::dificultarJogo(){
	if(clock.getElapsedTime().asSeconds() > 5.0f){
		if(mario->getPosicao(). y < (mapaJogo->getWindow().getSize().y/2)){
			for(int i=0; i < 4; i++){
				barris[i].respawAleatotio(mapaJogo->getWindow());
				clock.restart();
			}
		}
	}

}

void Jogo::morteBarril(Barril &barril){
	sf::sleep(sf::seconds(1));
	barril.respawAleatotio(mapaJogo->getWindow());
}

void Jogo::morteMario(){
	coracoes.at(mario->getVidas()-1).setTexture(texturaCoracaoApagado);
	mario->setVidas(mario->getVidas()-1);

	mario->setPegouEscudo(false);
	escudo->setPosicao(550, 300 + plataformas[0].getSprite().getGlobalBounds().height + 10);

	if(!testarMusica(musicaFundo)){
		musicaFundo.pause();
	}
	if(testarSom(somMorte)){
		somMorte.play();
		sf::sleep(sf::seconds(5));
	}
	musicaFundo.play();

	mario->setPosicao(20, mapaJogo->getTamanhoJanela().height - 25);
	respawnarBarris();
}

void Jogo::colidirBarrilMartelo(int auxiliar){
	if(auxiliar == 4 || auxiliar == 5){
		for (size_t i = 0; i < barris.size(); ++i){
			if(colisao.colisaoEntrePersonagens(*mario, barris.at(i))){
				morteBarril(barris.at(i));
			}
		}
	}
}

void Jogo::colidirMarioEscudo(){
	if (mario->getSprite().getGlobalBounds().intersects(escudo->getSprite().getGlobalBounds())) {
		if (testarSom(somGet)) {
			somGet.play();
		}

		mario->getSprite().setColor(sf::Color::Blue);
		mario->setPegouEscudo(true);
		escudo->setPosicao(-100, -100);

		clock.restart();
	}

	    if (mario->getPegouEscudo() && clock.getElapsedTime().asSeconds() >= 5) {
	        mario->getSprite().setColor(sf::Color::White);
	        mario->setPegouEscudo(false);
	    }
}

void Jogo::colidirComPlataformas(){
	//colisao mario e plataformas
    for (size_t i = 0; i < plataformas.size(); ++i) {
    	if (colisao.colisaoMarioPlataforma(*mario, plataformas[i])) {
            mario->setNoAr(false);
            mario->setVelocidade(0, 0);
    	}

    	//colisao barril e plataformas
    	for (size_t j = 0; j < barris.size(); ++j) {
    		colisao.colisaoBarrilPlataforma(barris[j], plataformas[i]);
		}

    }

}

void Jogo::colidirComEscadas(){
	//colisao mario e escadas
	for (size_t i = 0; i < escadas.size(); ++i) {
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
	//colisao mario e barril
	if(!mario->getPegouEscudo()){
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

}

void Jogo::movimentarPersonagens(){
	//movimento mario
	mario->permitirMovimento(*mapaJogo);
	mario->mover();
	mario->sofrerGravidade();

	pauline->mover();

	//movimento barril
	for (size_t i = 0; i < barris.size(); ++i) {
		colisao.colisaoBarrilMapa(barris[i], mapaJogo);
		barris[i].mover();
		barris[i].sofrerGravidade();
	}
}

void Jogo::animarMario(int *auxiliar){
	/*
	 * a variável auxiliar é atualizada toda hora durante loop principal,
	 * ela serve para determinar qual textura passar para o mario quando
	 * o usuário parar de apertar alguma tecla. Essas texturas correspondem a
	 * direcao que o mario vai parar (norte, leste, oeste).
	 */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		mario->setParaDireitaEsquerda(true, false);
		*auxiliar = 1;
		int x=0;
		x=(int)mario->getPosicao().x /35 % 3;
		x = x*16;
		sf::IntRect retangulo(x, 0, 16, 16);
		mario->setTexturaSprite(texturaMarioDireita, retangulo);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

		mario->setParaDireitaEsquerda(false, true);
		*auxiliar = 2;
		int x=0;
		x=(int)mario->getPosicao().x /35 % 3;
		x = x*16;
		sf::IntRect retangulo(x, 0, 16, 16);
		mario->setTexturaSprite(texturaMarioLeft, retangulo);

	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

		*auxiliar = 3;
		sf::IntRect retangulo(0, 0, 13, 16);
		mario->setTexturaSprite(texturaMarioSubindo, retangulo);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (mario->getPegouEscudo()) && (mario->getParaDireita())){

		*auxiliar = 4;
		sf::IntRect retangulo(0, 0, 25, 29);
		mario->setTexturaSprite(texturaEscudoDireita, retangulo);
		mario->setApertouX(true);
		if(testarSom(somEscudo)){
			somEscudo.play();
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (mario->getPegouEscudo()) && (mario->getParaEsquerda())){

		*auxiliar = 5;
		sf::IntRect retangulo(0, 0, 25, 29);
		mario->setTexturaSprite(texturaEscudoEsquerda, retangulo);
		mario->setApertouX(true);
		if(testarSom(somEscudo)){
			somEscudo.play();
		}

	}

	else{

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

void Jogo::respawnarBarris(){
	for (size_t i = 0; i < barris.size(); ++i){
		barris[i].respawAleatotio(mapaJogo->getWindow());
	}
}

//verifica se o som esta tocando ou nao
bool Jogo::testarSom(sf::Sound &som){
	if(som.getStatus() != sf::Sound::Playing){
		return true;
	}else return false;
}

//verifica se a musica esta tocando ou nao
bool Jogo::testarMusica(sf::Music &som){
	if(som.getStatus() != sf::Music::Playing){
		return true;
	}else return false;
}

void Jogo::fecharJanela(){
	while (mapaJogo->getWindow().pollEvent(evento)) {
		if (evento.type == sf::Event::Closed) {
			if(!testarMusica(musicaFundo)){
				musicaFundo.stop();
			}
			mapaJogo->getWindow().close();
			mapaJogo->~Mapa();
		}
	}
}

void Jogo::loopPrincipal(){
	//loop principal
	while (mapaJogo->getWindow().isOpen()) {

		//loop de eventos
		fecharJanela();

		//atualiza mundo
		if(!mario->getGanhou()){
			dificultarJogo();
			int auxiliar;
			animarMario(&auxiliar);
			movimentarPersonagens();

			colidirBarrilMartelo(auxiliar);
			colidirComPlataformas();
			colidirComEscadas();
			colidirPersonagens();
			colidirMarioEscudo();
			gameOver();

			if(testarMusica(musicaFundo)){
				musicaFundo.play();
			}
		}
		ganharJogo();


		//desenha mundo
		mapaJogo->getWindow().clear();
		desenharMapa();
		mapaJogo->getWindow().display();
	}
}

void Jogo::gameOver(){
	if(mario->getVidas() == 0){
		if(!testarMusica(musicaFundo)){
			musicaFundo.stop();
		}
		mapaJogo->~Mapa();
		GameOver gameOver;
	}
}

void Jogo::ganharJogo(){
	if(colisao.colisaoEntrePersonagens(*mario, *pauline)){
		for (size_t i = 0; i < barris.size(); ++i){
			barris[i].setVelocidade(0,0);
		}

		if(!testarMusica(musicaFundo)){
			musicaFundo.pause();
		}
		if(testarMusica(musicaGanhou)){
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
