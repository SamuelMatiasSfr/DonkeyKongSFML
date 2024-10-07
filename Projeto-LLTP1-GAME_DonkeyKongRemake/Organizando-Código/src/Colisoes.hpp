#ifndef COLISOES_HPP_
#define COLISOES_HPP_

#include "Mario.hpp"
#include "Barril.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"

class Colisoes {

private:
	bool colide;

public:
	  void colisaoBarrilPlataforma(Barril &personagem, Plataforma &plataformas);
	  bool colisaoMarioPlataforma(Mario &mario, Plataforma &plataformas);
	  bool colisaoPersonagemEscada(Personagem &personagem, Escada &escada);
	  bool colisaoEntrePersonagens(Personagem &mario, Personagem &barril);
	  void colisaoBarrilMapa(Barril &barril, Mapa *mapa);

};

#endif /* COLISOES_HPP_ */
