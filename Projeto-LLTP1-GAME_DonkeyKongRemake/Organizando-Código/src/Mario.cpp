#include "Mario.hpp"

Mario::Mario(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY)
	: Personagem(textura,posX, posY, retangulo, escala, velX, velY){
		podeAndar = true;
		emEscada = false;
		noAr = false;
}

void Mario::setEmEscada(bool estaNaEscada){
	this->emEscada = estaNaEscada;
}

void Mario::movimentoTeclas(){

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (podeAndar)) {
		velocidadeX = -5;
		posicaoX += velocidadeX;
		setPosition(posicaoX, posicaoY);
		animaEntidade();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (podeAndar)) {
		velocidadeX = 5;
		posicaoX += velocidadeX;
		setPosition(posicaoX, posicaoY);
		animaEntidade();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (emEscada)) {
		velocidadeY = -1;
		posicaoY += velocidadeY;
		setPosition(posicaoX, posicaoY);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (emEscada)) {
		velocidadeY = 1;
		posicaoY += velocidadeY;
		setPosition(posicaoX, posicaoY);
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (podeAndar) && (!noAr)){
		pular();
	}

}

void Mario::setNoAr(bool estaNoAr){
	this->noAr = estaNoAr;
}

void Mario::pular(){
	if(!noAr){
		velocidadeY = -4;
		posicaoY += velocidadeY;
		setPosition(posicaoX, posicaoY);
		noAr = true;
	}
}


bool Mario::getEmEscada(){
	return emEscada;
}

bool Mario::getNoAr(){
	return noAr;
}

void Mario::animaEntidade(){
	float switchTime = 0.5f;

	    if (clock.getElapsedTime().asSeconds() > switchTime) {
	        currentTextureIndex = (currentTextureIndex + 1) % textura.size();
	        corpo.setTexture(textura[currentTextureIndex]);
	        clock.restart();
	    }
}
