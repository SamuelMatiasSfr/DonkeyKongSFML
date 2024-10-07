#ifndef CREDITO_HPP_
#define CREDITO_HPP_

#include "Mapa.hpp"

class Credito {

private:
	sf::Text textosCreditos;
	sf::Font fonteCreditos;
	sf::Texture texturaBonecoMatheus, texturaBonecoSamuel, texturaBonecoIgor, texturaFundoCreditos;
	sf::Sprite bonecoMatheus, bonecoSamuel, bonecoIgor, fundoCreditos;
	sf::Image icon;
	sf::Event evento;
	Mapa *mapaCreditos;

public:
	Credito();
	~Credito();

};

#endif /* CREDITO_HPP_ */
