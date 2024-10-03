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
	  bool colisaoPersonagemPlataforma(Personagem &personagem, Plataforma &plataforma);
	  bool colisaoMarioPlataforma(Mario &mario, Plataforma &plataformas);
	  bool colisaoPersonagemEscada(Personagem &personagem, Escada &escada);
	  bool colisaoEntrePersonagens(Personagem &personagem1, Personagem &personagem2);
	  void colisaoBarrilMapa(Barril &barril, Mapa *mapa);

};

#endif /* COLISOES_HPP_ */
