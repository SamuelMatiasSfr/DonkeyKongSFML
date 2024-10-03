#ifndef MARIO_HPP_
#define MARIO_HPP_

#include <SFML/Audio.hpp>

#include "Personagem.hpp"
#include "Mapa.hpp"

class Mario : public Personagem{

protected:
	bool emEscada;
	bool noAr;
	sf::SoundBuffer bufferAndar;
	sf::SoundBuffer bufferPular;
	sf::Sound somAndar;
	sf::Sound somPular;

public:
	Mario(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);

	bool getEmEscada();
	void setEmEscada(bool estaNaEscada);
	bool getNoAr();
	void setNoAr(bool estaNoAr);

	bool testarSom(sf::Sound som);
	void movimentoTeclas();
	void pular();
	void animaEntidade();

};

#endif /* MARIO_HPP_ */
