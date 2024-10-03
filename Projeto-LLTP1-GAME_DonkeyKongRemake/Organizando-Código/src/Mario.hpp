#ifndef MARIO_HPP_
#define MARIO_HPP_
#include "Personagem.hpp"
#include "Mapa.hpp"

class Mario : public Personagem{
protected:

	bool emEscada;
	bool noAr;

public:
	Mario(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);
	void setEmEscada(bool estaNaEscada);
	void setNoAr(bool estaNoAr);
	void pular();
	void movimentoTeclas();
	bool getNoAr();
	bool getEmEscada();
	void animaEntidade();

};

#endif /* MARIO_HPP_ */
