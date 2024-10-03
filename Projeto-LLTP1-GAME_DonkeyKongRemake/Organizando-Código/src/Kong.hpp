#ifndef KONG_HPP_
#define KONG_HPP_

#include "Personagem.hpp"
#include "Mapa.hpp"

class Kong : public Personagem{

public:
	Kong(sf::Texture& textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);

};

#endif /* KONG_HPP_ */
