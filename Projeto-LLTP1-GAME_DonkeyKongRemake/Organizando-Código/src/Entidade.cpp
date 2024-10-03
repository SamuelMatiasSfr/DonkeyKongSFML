#include "Entidade.hpp"

Entidade::Entidade() : posicaoX(0), posicaoY(0), currentTextureIndex(0) {}

Entidade::Entidade(sf::Texture texture, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala)
    : posicaoX(posX), posicaoY(posY), currentTextureIndex(0) {
    this->textura.push_back(texture);
    corpo.setTexture(textura[0]);
    corpo.setTextureRect(retangulo);
    corpo.setScale(escala);
    corpo.setPosition(posicaoX, posicaoY);
    corpo.setOrigin(corpo.getLocalBounds().width / 2, corpo.getLocalBounds().height / 2);
}

Entidade::~Entidade() {
    std::cerr << "Entidade excluida!" << std::endl;
}

std::vector<sf::Texture> &Entidade::getTextura() {
    return textura;
}

sf::Sprite &Entidade::getSprite() {
    return corpo;
}

sf::Vector2f Entidade::getPosition() {
    return sf::Vector2f(posicaoX, posicaoY);
}

void Entidade::setPosition(float posX, float posY) {
    this->posicaoX = posX;
    this->posicaoY = posY;
    corpo.setPosition(posX, posY);
}

void Entidade::setSprite(sf::Texture texture[]) {
    for (int i = 0; i < 5; ++i) {
        textura.push_back(texture[i]);
    }
}

void Entidade::setSprite(const std::vector<sf::Texture> &texture) {
    this->textura = texture;
    corpo.setTexture(textura.back());
}

void Entidade::setSprite(sf::Texture &texture){
	corpo.setTexture(texture);
}

void Entidade::animaEntidade() {
    float switchTime = 0.5f;

    if (clock.getElapsedTime().asSeconds() > switchTime) {
        corpo.rotate(45);
        clock.restart();
    }
}
