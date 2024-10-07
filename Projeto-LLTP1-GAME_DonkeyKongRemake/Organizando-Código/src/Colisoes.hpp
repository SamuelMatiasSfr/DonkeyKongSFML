#ifndef COLISOES_HPP_
#define COLISOES_HPP_

#include <SFML/Graphics.hpp>
#include <vector>

#include "Mario.hpp"
#include "Barril.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"

class Colisoes {

private:
	bool colide;

public:
	  void colisaoBarrilPlataforma(Barril &personagem, Plataforma &plataforma);
	  bool colisaoMarioPlataforma(Mario &mario, Plataforma &plataformas);
	  bool colisaoPersonagemEscada(Personagem &personagem, Escada &escada);
	  bool colisaoEntrePersonagens(Personagem &mario, Entidade &barril);
	  void colisaoBarrilMapa(Barril &barril, Mapa *mapa);

};

#endif /* COLISOES_HPP_ */
