#ifndef ESCADA_HPP_
#define ESCADA_HPP_

#include "Entidade.hpp"

class Escada : public Entidade{

protected:
	int numeroDegrau = 0;
	std::vector<sf::Sprite> degraus;

public:
	Escada();

	void defineEscada(int numDegrau, float posX, float posY);
	void draw(sf::RenderWindow &janela);
	std::vector<sf::Sprite> getDegraus();

};


#endif /* ESCADA_HPP_ */
