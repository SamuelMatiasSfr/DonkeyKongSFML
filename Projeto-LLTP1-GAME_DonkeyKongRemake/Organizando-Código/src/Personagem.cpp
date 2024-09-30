#include "Personagem.hpp"

Personagem::Personagem(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY)
: Entidade(textura,posX, posY, retangulo, escala), velocidadeX(velX), velocidadeY(velY) {}

Personagem::Personagem() : velocidadeX(0), velocidadeY(0){}

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
