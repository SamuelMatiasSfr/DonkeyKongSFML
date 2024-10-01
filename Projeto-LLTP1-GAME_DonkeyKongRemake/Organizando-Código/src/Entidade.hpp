#ifndef ENTIDADE_HPP_
#define ENTIDADE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Entidade {
protected:
    std::vector<sf::Texture> textura;
    sf::Sprite corpo;
    float posicaoX;
    float posicaoY;
    int currentTextureIndex;
    sf::Clock clock;

public:

    Entidade();
    Entidade(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala);

    std::vector<sf::Texture> &getTextura();
    sf::Sprite &getSprite();
    sf::Vector2f getPosition();

    void setPosition(float posX, float posY);
    void setSprite(sf::Texture texture[]);
    void setSprite(const std::vector<sf::Texture> &texture);
    void setSprite(sf::Texture &texture);
    void animaEntidade();

    ~Entidade();
};

#endif // ENTIDADE_HPP_
