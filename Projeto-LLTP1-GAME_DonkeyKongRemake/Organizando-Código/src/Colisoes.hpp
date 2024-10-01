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
#include "Personagem.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"

class Colisoes {
public:

	  bool verificarColisao(Personagem &personagem, Plataforma &plataforma);
	  bool verificarColisao(Personagem &personagem1, Personagem &personagem2);
	  bool verificarColisao(Personagem &personagem, Escada &escada);


};

#endif /* COLISOES_HPP_ */
