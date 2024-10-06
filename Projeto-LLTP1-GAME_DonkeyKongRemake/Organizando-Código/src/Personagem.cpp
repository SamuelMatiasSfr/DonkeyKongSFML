#include "Personagem.hpp"

Personagem::Personagem(){
	velocidadeX = 0;
	velocidadeY = 0;
	podeAndar = true;
}

Personagem::Personagem(sf::Texture &textura, float posX, float posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY)
:Entidade(textura,posX, posY, retangulo, escala){
	velocidadeX = velX;
	velocidadeY = velY;
	podeAndar = true;
}

sf::Vector2f Personagem::getVelocidade(){
	sf::Vector2f velocidades;
	velocidades.x = velocidadeX;
	velocidades.y = velocidadeY;

	return velocidades;
}

bool Personagem::getPodeAndar(){
	return podeAndar;
}

void Personagem::setVelocidade(float velX, float velY){
	velocidadeX = velX;
	velocidadeY = velY;
}

void Personagem::sofrerGravidade(){
	velocidadeY += gravidade * deltaTime;
	setPosicao(getPosicao().x, getPosicao().y + velocidadeY);
}


