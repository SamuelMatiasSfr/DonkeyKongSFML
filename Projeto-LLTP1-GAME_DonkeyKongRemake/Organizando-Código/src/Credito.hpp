/*
 * Credito.hpp
 *
 *  Created on: 3 de out. de 2024
 *      Author: mathe
 */

#ifndef CREDITO_HPP_
#define CREDITO_HPP_

#include "Mapa.hpp"

class Credito {

protected:

	sf::Text textosCarregamentos;
	sf::Font fonteCreditos;
	sf::Texture texturaBonecoMatheus, texturaBonecoSamuel, texturaBonecoIgor, texturaFundoCreditos;
	sf::Sprite bonecoMatheus, bonecoSamuel, bonecoIgor, fundoCreditos;
	sf::Image icon;
	sf::Event evento;
	Mapa *mapaCreditos;

public:
	Credito();
	~Credito();

	void carregaTexturaseTextos();

	void aplicaTexturas();

	void configuraBonecos();

	void configuraTextos();

	void configuraMapa();

	void loopPrincipal();

	void desenharMapa();

	void fechaJanela();
};

#endif /* CREDITO_HPP_ */
