#include "Pauline.hpp"

Pauline::Pauline(sf::Texture &textura, float posX, float posY)
:Personagem(textura,posX, posY, sf::IntRect(0, 0, 15, 22), sf::Vector2f(2.0f, 2.5f), 2, 0), texturas(2){
	if(!texturas[0].loadFromFile("imagens/paulineDireita.png")){
		std::cerr << "erro ao carregar textura Pauline Direita\n";
	}
	if(!texturas[1].loadFromFile("imagens/paulineEsquerda.png")){
		std::cerr << "erro ao carregar pauline textura Pauline Esquerda\n";
	}

	//this->textura = texturas.at(0);
}

Pauline::~Pauline(){}

void Pauline::mover(){
	posicaoX = posicaoX + velocidadeX;
	posicaoY = posicaoY + 0;

	if(posicaoX >= 335){
		velocidadeX = velocidadeX*(-1);
		this->textura = texturas.at(1);
	}else if(posicaoX <= 220 ){
		velocidadeX = velocidadeX*(-1);
		this->textura = texturas.at(0);
	}

	corpo.setPosition(posicaoX, posicaoY);

	//animacao da Pauline
	int x=0;
	x=(int)posicaoX /35 % 2;
	x = x*15;

	sf::IntRect retangulo(x, 0, 15, 22);
	setTexturaSprite(textura, retangulo);
}
