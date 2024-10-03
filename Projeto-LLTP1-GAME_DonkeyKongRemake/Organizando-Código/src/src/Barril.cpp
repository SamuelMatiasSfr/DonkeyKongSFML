/*
 * Barril.cpp
 *
 *  Created on: 2 de out. de 2024
 *      Author: mathe
 */

#include "Barril.hpp"

Barril::Barril(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY) :
Personagem(textura,posX, posY, retangulo, escala, velX, velY){
	desceEscada = false;
}
Barril::Barril(){
	desceEscada = 0;
}
void Barril::respawAleatotio(sf::RenderWindow &window){
	int windowWidth = static_cast<int>(window.getSize().x);
	int windowHeight = static_cast<int>(window.getSize().y);

	int spriteWidth = static_cast<int>(getSprite().getGlobalBounds().width);
	int spriteHeight = static_cast<int>(getSprite().getGlobalBounds().height);

	float randomX = static_cast<float>(rand() % (windowWidth - spriteWidth));
	float randomY = static_cast<float>(rand() % (windowHeight - spriteHeight));

	setPosition(randomX, randomY);
}

bool Barril::getDesceEscada(){
	return desceEscada;
}

Barril::~Barril() {
	// TODO Auto-generated destructor stub
}

