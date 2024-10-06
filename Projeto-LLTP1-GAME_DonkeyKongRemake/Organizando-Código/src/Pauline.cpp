#include "Pauline.hpp"

Pauline::Pauline(sf::Texture &textura, float posX, float posY)
:Personagem(textura,posX, posY, sf::IntRect(0, 0, 15, 22), sf::Vector2f(2.0f, 2.5f), 2, 0){

}

Pauline::~Pauline(){}

void Pauline::mover(){
	posicaoX = posicaoX + velocidadeX;
	posicaoY = posicaoY + 0;

	if(posicaoX >= 335){
		velocidadeX = velocidadeX*(-1);
	}else if(posicaoX <= 220 ){
		velocidadeX = velocidadeX*(-1);
	}
	if(!textura.loadFromFile("imagens/pauline.png")){
		std::cerr << "erro ao carregar pauline";
	}

	//anima��o da Pauline
	int x=0;

	x=(int)posicaoX /37 % 2;
	x = x*53;

	sf::IntRect retangulo(x, 0, 15, 22);
	setTexturaSprite(textura, retangulo);

	corpo.setPosition(posicaoX, posicaoY);
}
