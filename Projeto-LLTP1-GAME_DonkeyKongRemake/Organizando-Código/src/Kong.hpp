#ifndef KONG_HPP_
#define KONG_HPP_

#include "Personagem.hpp"

class Kong : public Personagem{

public:
	Kong(sf::Texture &textura, float posX, float posY);
	~Kong();

	void mover() override; //função herdada de personagem.hpp e implementada em kong.cpp

};

#endif /* KONG_HPP_ */
