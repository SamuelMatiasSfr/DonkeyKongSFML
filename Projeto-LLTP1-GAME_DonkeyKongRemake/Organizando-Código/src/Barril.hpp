#ifndef BARRIL_HPP_
#define BARRIL_HPP_

#include <cstdlib>
#include <ctime>

#include "Personagem.hpp"

class Barril : public Personagem {

public:
	Barril(sf::Texture &textura);
	Barril();
	~Barril();

	void respawAleatotio(sf::RenderWindow &window);
	void determinarMovimento();
	void mover();
	void animarBarril();

};

#endif /* BARRIL_HPP_ */
