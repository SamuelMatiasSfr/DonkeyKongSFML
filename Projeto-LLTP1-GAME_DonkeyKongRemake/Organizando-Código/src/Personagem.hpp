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

public:
	Personagem();
	Personagem(sf::Texture textura, int posX, int posY, sf::IntRect retangulo, sf::Vector2f escala, float velX, float velY);

	sf::Vector2f getVelocidade();
	bool getPodeAndar();
	void setVelocidade(float velX, float velY);

	void mover(float velX, float velY);
	void atualizaMovimento();
	void sofreGravidade();
	void permiteMovimento(Mapa &map);

};

#endif /* PERSONAGEM_HPP_ */
