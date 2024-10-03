#include "Mario.hpp"

Mario::Mario(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY)
: Personagem(textura,posX, posY, retangulo, escala, velX, velY){
	podeAndar = true;
	emEscada = false;
	noAr = false;

	if (!bufferAndar.loadFromFile("audios/andar_.wav")) {
		std::cerr << "Erro ao carregar o arquivo de som!\n";
	}
	somAndar.setBuffer(bufferAndar);

	if (!bufferPular.loadFromFile("audios/pulo.wav")) {
		std::cerr << "Erro ao carregar o arquivo de som!\n";
	}
	somPular.setBuffer(bufferPular);
}

bool Mario::getEmEscada(){
	return emEscada;
}

void Mario::setEmEscada(bool estaNaEscada){
	this->emEscada = estaNaEscada;
}

bool Mario::getNoAr(){
	return noAr;
}

void Mario::setNoAr(bool estaNoAr){
	this->noAr = estaNoAr;
}

bool Mario::testarSom(sf::Sound som){
	if(som.getStatus() != sf::Sound::Playing){
		return true;
	}else return false;
}

void Mario::movimentoTeclas(){

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (podeAndar)) {
		velocidadeX = -5;
		posicaoX += velocidadeX;
		setPosition(posicaoX, posicaoY);
		animaEntidade();

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (podeAndar)) {
		velocidadeX = 5;
		posicaoX += velocidadeX;
		setPosition(posicaoX, posicaoY);
		animaEntidade();

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (emEscada)) {
		velocidadeY = -1;
		posicaoY += velocidadeY;
		setPosition(posicaoX, posicaoY);
		somAndar.play();

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (emEscada)) {
		velocidadeY = 1;
		posicaoY += velocidadeY;
		setPosition(posicaoX, posicaoY);
		somAndar.play();

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (podeAndar) && (!noAr)){
		pular();

		if(testarSom(somPular)){
			somPular.play();
		}
	}

}

void Mario::pular(){
	if(!noAr){
		velocidadeY = -4;
		posicaoY += velocidadeY;
		setPosition(posicaoX, posicaoY);
		noAr = true;
		sf::sleep(sf::seconds(1));
	}
}

void Mario::animaEntidade(){
	float switchTime = 0.5f;

	    if (clock.getElapsedTime().asSeconds() > switchTime) {
	        currentTextureIndex = (currentTextureIndex + 1) % textura.size();
	        corpo.setTexture(textura[currentTextureIndex]);
	        clock.restart();
	    }
}
