/*
 * JogarDeNovo.hpp
 *
 *  Created on: 6 de out. de 2024
 *      Author: mathe
 */

#ifndef JOGARDENOVO_HPP_
#define JOGARDENOVO_HPP_
#include "Fase2.hpp"
#include "Mapa.hpp"


class JogarDeNovo {
	Mapa *mapaPergunta;
	sf::Texture texturaFundoPergunta, texturaBotaoPlayAgain[2], texturaBotaoProximaFase[2];
	sf::Image icon;
	sf::Sprite fundoPergunta;
	sf::Event event;
	Entidade *botaoPlayAgain, *botaoProximaFase;
public:
	JogarDeNovo();
	~JogarDeNovo();
};

#endif /* JOGARDENOVO_HPP_ */
