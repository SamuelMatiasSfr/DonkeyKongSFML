#ifndef PAULINE_HPP_
#define PAULINE_HPP_

#include "Personagem.hpp"

class Pauline : public Personagem{

public:
	Pauline(sf::Texture &textura, float posX, float posY);
	~Pauline();

	void mover() override; //função herdada de personagem.hpp e implementada em pauline.cpp

};

#endif /* PAULINE_HPP_ */
