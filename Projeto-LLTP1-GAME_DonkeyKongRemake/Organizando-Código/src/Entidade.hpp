#ifndef ENTIDADE_HPP_
#define ENTIDADE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Entidade {

protected:
    sf::Texture textura;
    sf::Sprite corpo;
    float posicaoX;
    float posicaoY;

public:
    Entidade();
    Entidade(sf::Texture &textura, float posX, float posY, sf::IntRect retangulo, sf::Vector2f escala);
    ~Entidade();

    sf::Texture &getTextura();
    sf::Sprite &getSprite();
    sf::Vector2f getPosicao();

    void setPosicao(float posX, float posY);
    void setTexturaSprite(sf::Texture &textura, sf::IntRect &retangulo);
    void setTexturaSprite(sf::Texture &textura);

};

#endif // ENTIDADE_HPP_
