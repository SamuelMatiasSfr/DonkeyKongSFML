#ifndef MARIO_HPP_
#define MARIO_HPP_

#include <SFML/Audio.hpp>

#include "Personagem.hpp"
#include "Mapa.hpp"

class Mario : public Personagem{

private:
	bool ganhouJogo;
	int vidas;
	bool paraEsquerda;
	bool paraDireita;
	bool pegouEscudo;
	bool apertouX;
	bool emEscada;
	bool noAr;
	sf::SoundBuffer bufferAndar;
	sf::SoundBuffer bufferPular;
	sf::Sound somAndar;
	sf::Sound somPular;

public:
	Mario(sf::Texture &textura, float posX, float posY);
	~Mario();

	bool getGanhou();
	void setGanhou(bool ganhou);
	int getVidas();
	void setVidas(int vida);
	bool getApertouX();
	void setApertouX(bool apertou);
	bool getParaEsquerda();
	bool getParaDireita();
	void setParaDireitaEsquerda(bool direita, bool esquerda);
	bool getPegouEscudo();
	void setPegouEscudo(bool pegou);
	bool getEmEscada();
	void setEmEscada(bool estaNaEscada);
	bool getNoAr();
	void setNoAr(bool estaNoAr);

	bool testarSom(sf::Sound som);
	void mover(); //fun��o herdada de personagem.hpp e implementada em mario.cpp
	void pular();
	void permitirMovimento(Mapa &map);

};

#endif /* MARIO_HPP_ */
