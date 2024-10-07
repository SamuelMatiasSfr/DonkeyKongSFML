#ifndef JOGO_HPP_
#define JOGO_HPP_

#include "Colisoes.hpp" //Colisoes.hpp importa Mario.hpp, Barril.hpp, Plataforma.hpp e Escada.hpp
#include "Kong.hpp" //Kong.hpp importa Personagem.hpp e Personagem.hpp importa Mapa.hpp
#include "Pauline.hpp"
#include "GameOver.hpp"

class Jogo {

private:
	sf::Music musicaFundo, musicaGanhou;
	sf::SoundBuffer bufferMorte, bufferGet, bufferEscudo;
	sf::Sound somMorte, somGet, somEscudo;
	sf::Texture texturaFundoJogo, texturaMarioLeft, texturaMarioDireita, texturaMarioSubindo, texturaMarioParado, texturaEscudoEsquerda,
	texturaEscudoDireita, texturaBarril, texturaKong, texturaEscada, texturaPlataforma, texturaPaulineDireita,
	texturaPaulineCoracao, texturaEscudo, texturaCoracao, texturaCoracaoApagado;
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

	void colidirBarrilMartelo(int auxiliar);
	void colidirMarioEscudo();
	void colidirComPlataformas();
	void colidirComEscadas();
	void colidirPersonagens();

	void movimentarPersonagens();
	void animarMario(int *auxiliar);

	void respawnarBarris();

	bool testarSom(sf::Sound &som);
	bool testarMusica(sf::Music &som);

	void fecharJanela();
	void loopPrincipal();
	void gameOver();
	void ganharJogo();

};

#endif /* JOGO_HPP_ */
