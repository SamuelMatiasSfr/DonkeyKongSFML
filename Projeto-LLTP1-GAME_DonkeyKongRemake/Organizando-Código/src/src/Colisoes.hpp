/*
 * Colisoes.hpp
 *
 *  Created on: 28 de set. de 2024
 *      Author: mathe
 */

#ifndef COLISOES_HPP_
#define COLISOES_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Mario.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"
#include "Barril.hpp"

class Colisoes {
protected:
	bool colide;
public:

	  bool verificarColisao(Personagem &personagem, Plataforma &plataforma);
	  bool verificarColisao(Mario &mario, Plataforma &plataformas);
	  bool verificarColisao(Personagem &personagem1, Personagem &personagem2);
	  bool verificarColisao(Personagem &personagem, Escada &escada);
	  void verificarColisao(Barril &barril, Mapa *mapa);


};

#endif /* COLISOES_HPP_ */
