#ifndef BARRIL_HPP_
#define BARRIL_HPP_

#include "Personagem.hpp"
#include "Escada.hpp"

#include <cstdlib>
#include <ctime>

class Barril : public Personagem {

protected:
	bool desceEscada;

public:
	Barril(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);
	Barril();
	~Barril();

	bool getDesceEscada();

	void respawAleatotio(sf::RenderWindow &window);

};

#endif /* BARRIL_HPP_ */
