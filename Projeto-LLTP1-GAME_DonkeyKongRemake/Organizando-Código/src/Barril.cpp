#include "Barril.hpp"

Barril::Barril(sf::Texture &textura)
:Personagem(textura, 20 , 20, sf::IntRect(0, 0, 12, 10), sf::Vector2f(2.5f, 3.0f), 4, 0) {

}

Barril::Barril(){}

Barril::~Barril(){}

void Barril::respawAleatotio(sf::RenderWindow &window){
	int windowLargura = static_cast<int>(window.getSize().x);
	int windowAltura = static_cast<int>(window.getSize().y/3);

	int spriteLargura = static_cast<int>(getSprite().getGlobalBounds().width);
	int spriteAltura = static_cast<int>(getSprite().getGlobalBounds().height);

	float randomX = static_cast<float>(rand() % (windowLargura - spriteLargura));
	float randomY = static_cast<float>(rand() % (windowAltura - spriteAltura));

	setPosicao(randomX, randomY);
}

void Barril::determinarMovimento(){
	int random = rand() % 2;

	if(random == 0){
		velocidadeX = -velocidadeX;
	}
}

//rotaciona o barril, de forma que o barril parece estar girando
void Barril::animarBarril() {
    float tempoRotacao = 0.5f;

    if (clock.getElapsedTime().asSeconds() > tempoRotacao) {
        corpo.rotate(45);
        clock.restart();
    }
}

void Barril::mover(){
	animarBarril();
	posicaoX = posicaoX + velocidadeX;
	posicaoY = posicaoY + velocidadeY;
	corpo.setPosition(posicaoX, posicaoY);
}


