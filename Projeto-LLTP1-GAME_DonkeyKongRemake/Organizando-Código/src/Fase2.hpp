/*
 * Fase2.hpp
 *
 *  Created on: 6 de out. de 2024
 *      Author: mathe
 */

#ifndef FASE2_HPP_
#define FASE2_HPP_

#include "Fase1.hpp"
#include "IntroducaoGame.hpp"

class Fase2 {

	sf::Music musicaFundo, musicaGanhou;
	sf::SoundBuffer bufferMorte, bufferGet, bufferMartelo;
	sf::Sound somMorte, somGet, somMartelo;
	sf::Texture texturaFundoJogo, texturaMarioLeft, texturaMarioDireita, texturaMarioSubindo, texturaMarioParado, texturaMarteloEsquerda,
	texturaMarteloDireita, texturaBarril, texturaKong, texturaEscada, texturaPlataforma, texturaPaulineDireita,
	texturaPaulineEsquerda, texturaPaulineCoracao, texturaMartelo, texturaCoracao, texturaCoracaoApagado, texturaCoin;
	sf::Sprite fundoJogo;
	std::vector<sf::Sprite>coracoes;
	sf::Image icon;
	Colisoes colisao;
	sf::Event evento;

	Mapa *mapaJogo;
	Mario *mario;
	Kong *kong;
	Pauline *pauline;

	std::vector<Barril> barris;
	std::vector<Escada> escadas;
	std::vector<Plataforma> plataformas;
	std::vector<Entidade> coin;

	Entidade *martelo;

	sf::Clock clockDificuldade, clockMartelo, clockGanhou;

public:
	Fase2();
	~Fase2();

	void setTexturaFundo();

	void carregarAudios();
	void carregartexturas();
	void gerarPlataformas();
	void gerarEscadas();

	void criarPersonagens();
	void criarVidas();
	void criarMapa();

	void desenharMapa();

	void morteBarril(Barril &barril);
	void morteMario();

	void colidirMarioMartelo();
	void colidirComPlataformas();
	void colidirComEscadas();
	void colidirPersonagens();
	void colidirMarioMoeda();

	void movimentarPersonagens();

	void respawnarBarris();
	void animarMario(int *auxiliar);

	void animarPauline();
	void fecharJanela();
	void loopPrincipal();
	void gameOver();
	void ganharJogo();

	void geraMoedinhas();



	void perguntaProximaFase();

};

#endif /* FASE2_HPP_ */
