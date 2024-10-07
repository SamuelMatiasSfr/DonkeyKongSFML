#ifndef ESCADA_HPP_
#define ESCADA_HPP_

#include "Entidade.hpp"

class Escada : public Entidade{

private:
	int numeroDegraus;
	std::vector<sf::Sprite> degraus;

public:
	Escada();

	std::vector<sf::Sprite> &getDegraus();

	void defineEscada(int numDegrau, float posX, float posY);
	void draw(sf::RenderWindow &janela);

};

#endif /* ESCADA_HPP_ */
