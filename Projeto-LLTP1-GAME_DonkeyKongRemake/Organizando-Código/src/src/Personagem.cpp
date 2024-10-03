#include "Personagem.hpp"

Personagem::Personagem(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY)
: Entidade(textura,posX, posY, retangulo, escala), velocidadeX(velX), velocidadeY(velY) {
	podeAndar = true;
}

Personagem::Personagem() : velocidadeX(0), velocidadeY(0){
	podeAndar = true;
}

sf::Vector2f Personagem::getVelocidade(){
	sf::Vector2f velocidades;
	velocidades.x = velocidadeX;
	velocidades.y = velocidadeY;

	return velocidades;
}

void Personagem::mover(float velX, float velY){
	this->velocidadeX = velX;
	this->velocidadeY = velY;
	setPosition(getPosition().x + velocidadeX, getPosition().y + velocidadeY);
}

void Personagem::atualizaMovimento(){
	setPosition(getPosition().x + velocidadeX, getPosition().y + velocidadeY);
}

void Personagem::sofreGravidade(){
	velocidadeY += gravidade * deltaTime;
	setPosition(getPosition().x, getPosition().y + velocidadeY);
}

void Personagem::setVelocidade(float velX, float velY){
	this->velocidadeX = velX;
	this->velocidadeY = velY;
}

bool Personagem::getPodeAndar(){
	return podeAndar;
}


void Personagem::permiteMovimento(Mapa &map){
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

