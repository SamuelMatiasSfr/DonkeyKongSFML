#ifndef PERSONAGEM_HPP_
#define PERSONAGEM_HPP_

#include "Entidade.hpp"

class Personagem : public Entidade{
protected:

	float velocidadeX;
	float velocidadeY;
	const float deltaTime = 0.5;
	const float gravidade = 0.03;

public:

	Personagem();
	Personagem(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);
	sf::Vector2f getVelocidade();
	void mover(float velX, float velY);
	void sofreGravidade();
	void atualizaMovimento();
	void setVelocidade(float velX, float velY);

};

#endif /* PERSONAGEM_HPP_ */
