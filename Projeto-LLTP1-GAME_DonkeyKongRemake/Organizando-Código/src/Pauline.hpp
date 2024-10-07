#ifndef PAULINE_HPP_
#define PAULINE_HPP_

#include "Personagem.hpp"

class Pauline : public Personagem{

private:
	std::vector<sf::Texture>texturas;

public:
	Pauline(sf::Texture &textura, float posX, float posY);
	~Pauline();

	void mover();

};

#endif /* PAULINE_HPP_ */
