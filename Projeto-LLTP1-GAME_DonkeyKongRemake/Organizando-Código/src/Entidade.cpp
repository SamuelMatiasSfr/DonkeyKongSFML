#include "Entidade.hpp"

Entidade::Entidade(){
	posicaoX = 0;
	posicaoY = 0;
}

Entidade::Entidade(sf::Texture &textura, float posX, float posY, sf::IntRect retangulo, sf::Vector2f escala){
	posicaoX = posX;
	posicaoY = posY;
	this->textura = textura;
    corpo.setTexture(textura);
    corpo.setTextureRect(retangulo);
    corpo.setScale(escala);
    corpo.setPosition(posicaoX, posicaoY);
    corpo.setOrigin(corpo.getLocalBounds().width / 2, corpo.getLocalBounds().height / 2);
}

Entidade::~Entidade(){
    std::cerr << "Entidade excluida\n";
}

sf::Texture &Entidade::getTextura(){
    return textura;
}

sf::Sprite &Entidade::getSprite(){
    return corpo;
}

sf::Vector2f Entidade::getPosicao(){
    return sf::Vector2f(posicaoX, posicaoY);
}

void Entidade::setPosicao(float posX, float posY){
    posicaoX = posX;
    posicaoY = posY;
    corpo.setPosition(posX, posY);
}

void Entidade::setTexturaSprite(sf::Texture &textura, sf::IntRect &retangulo){
	this->textura = textura;
	corpo.setTexture(textura);
	corpo.setTextureRect(retangulo);
}

void Entidade::setTexturaSprite(sf::Texture &textura){
	this->textura = textura;
	corpo.setTexture(textura);
}
