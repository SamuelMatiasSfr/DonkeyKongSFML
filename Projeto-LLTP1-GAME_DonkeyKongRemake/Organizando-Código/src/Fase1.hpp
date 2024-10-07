#ifndef FASE1_HPP_
#define FASE1_HPP_

#include "Mapa.hpp"
#include "Colisoes.hpp"
#include "Mario.hpp"
#include "Barril.hpp"
#include "Kong.hpp"
#include "Pauline.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"
#include "GameOver.hpp"
#include "JogarDeNovo.hpp"

class Fase1 {

private:
	sf::Music musicaFundo, musicaGanhou;
	sf::SoundBuffer bufferMorte, bufferGet, bufferMartelo;
	sf::Sound somMorte, somGet, somMartelo;
	sf::Texture texturaFundoJogo, texturaMarioLeft, texturaMarioDireita, texturaMarioSubindo, texturaMarioParado, texturaMarteloEsquerda,
	texturaMarteloDireita, texturaBarril, texturaKong, texturaEscada, texturaPlataforma, texturaPaulineDireita,
	texturaPaulineEsquerda, texturaPaulineCoracao, texturaMartelo, texturaCoracao, texturaCoracaoApagado;
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

	Entidade *martelo;

	sf::Clock clockDificuldade, clockMartelo, clockGanhou;

public:
	Fase1();
	~Fase1();

	void setTexturaFundo();

	void carregarAudios();
	void carregartexturas();
	void gerarPlataformas();
	void gerarEscadas();

	void criarPersonagens();
	void criarVidas();
	void criarMapa();

	void desenharMapa();
	void dificultarJogo();

	void morteBarril(Barril &barril);
	void morteMario();

	void colidirMarioMartelo();
	void colidirComPlataformas();
	void colidirComEscadas();
	void colidirPersonagens();

	void movimentarPersonagens();

	void respawnarBarris();
	void animarMario(int *auxiliar);

	void animarPauline();
	void fecharJanela();
	void loopPrincipal();
	void gameOver();
	void ganharJogo();

	void perguntaProximaFase();

};

#endif /* FASE1_HPP_ */
