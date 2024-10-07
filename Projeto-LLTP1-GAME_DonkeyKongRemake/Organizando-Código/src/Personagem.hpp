#ifndef PERSONAGEM_HPP_
#define PERSONAGEM_HPP_

#include "Entidade.hpp"
#include "Mapa.hpp"

class Personagem : public Entidade{

protected:
	float velocidadeX;
	float velocidadeY;
	float deltaTime = 0.5 ;
	float gravidade = 0.3;
	bool podeAndar;
    sf::Clock clock;

public:
	Personagem();
	Personagem(sf::Texture &textura, float posX, float posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);

	sf::Vector2f getVelocidade();
	bool getPodeAndar();
	void setVelocidade(float velX, float velY);

	void mover(); //fun��o implementada nas classes filhas
	void sofrerGravidade();

};

#endif /* PERSONAGEM_HPP_ */
