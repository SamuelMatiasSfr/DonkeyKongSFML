#include "Mario.hpp"

Mario::Mario(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY)
	: Personagem(textura,posX, posY, retangulo, escala, velX, velY){
		podeAndar = true;
		emEscada = false;
		noAr = false;
}

void Mario::permiteMovimento(Mapa &map){
	if(corpo.getPosition().x >= (map.getTamanhoJanela().width - 1) ){
		podeAndar = false;
		setPosition(corpo.getPosition().x - 2,corpo.getPosition().y );
	}else if(corpo.getPosition().x <= (1) ){
		podeAndar = false;
		setPosition(corpo.getPosition().x + 2,corpo.getPosition().y );
	}else if(corpo.getPosition().y >= (map.getTamanhoJanela().height -1) ){
		podeAndar = false;
		setPosition(corpo.getPosition().x, map.getTamanhoJanela().height - 20 );
	}else if(corpo.getPosition().y <= (1) ){
		podeAndar = false;
		setPosition(corpo.getPosition().x, corpo.getPosition().y + 2);
	}else{
		podeAndar = true;
	}
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
	}else if (!emEscada && noAr){
		sofreGravidade();
	}

}

void Mario::setNoAr(bool estaNoAr){
	this->noAr = estaNoAr;
}

void Mario::pular(){
	if(!noAr){
		velocidadeY = -2;
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
