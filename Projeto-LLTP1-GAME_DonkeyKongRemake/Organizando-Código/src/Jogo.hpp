#ifndef JOGO_HPP_
#define JOGO_HPP_

#include "Mapa.hpp"
#include "Colisoes.hpp"
#include "Mario.hpp"
#include "Barril.hpp"
#include "Kong.hpp"
#include "Pauline.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"
#include "GameOver.hpp"

class Jogo {

private:
	sf::Music musicaFundo, musicaGanhou;
	sf::SoundBuffer bufferMorte, bufferGet, bufferEscudo;
	sf::Sound somMorte, somGet, somEscudo;
	sf::Texture texturaFundoJogo, texturaMarioLeft, texturaMarioDireita, texturaMarioSubindo, texturaMarioParado, texturaEscudoEsquerda,
	texturaEscudoDireita, texturaBarril, texturaKong, texturaEscada, texturaPlataforma, texturaPaulineDireita,
	texturaPaulineEsquerda, texturaPaulineCoracao, texturaEscudo, texturaCoracao, texturaCoracaoApagado;
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

	Entidade *escudo;

	sf::Clock clock;

public:
	Jogo();
	~Jogo();

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

	void colidirMarioEscudo();
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

};

#endif /* JOGO_HPP_ */
