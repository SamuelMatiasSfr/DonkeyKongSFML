#ifndef BARRIL_HPP_
#define BARRIL_HPP_

#include <cstdlib> //para usar a funcao rand()
#include <ctime> //para usar a funcao rand()

#include "Personagem.hpp"

class Barril : public Personagem {

private:
    sf::Clock clock;

public:
	Barril(sf::Texture &textura);
	Barril();
	~Barril();

	void respawAleatotio(sf::RenderWindow &window);
	void determinarMovimento();
	void animarBarril();
	void mover();

};

#endif /* BARRIL_HPP_ */
