#ifndef JOGO_HPP_
#define JOGO_HPP_

#include "Mapa.hpp"
#include "Mario.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"
#include "Colisoes.hpp"
#include "Barril.hpp"


class Jogo {
protected:
	sf::Texture texturaFundoJogo, texturaMario, texturaMarioDireita, texturaBarril, texturaExplosao;
	sf::Sprite fundoJogo, explosao;
	sf::Image icon;
	std::vector<sf::Texture> texturaMarioVector, texturaMarioVectorDireita, texturaBarrilVector;
	Colisoes colisao;
	sf::Clock clock;
	sf::Event evento;

	Mapa *mapaJogo;
	Mario *mario;
	Barril *barril;
	Escada *escada;
	Plataforma *plataforma;

public:
	Jogo();
	void carregatexturas();
	void geraEscadas();
	void geraPlataformas();
	void criaMapa();
	void setTexturas();
	void criaPersonagens();
	void desenhaMapa();
	void colideComPlataformas();
	void colideComEscadas();
	void colidePersonagens();
	void movimentaPersonagens();
	void fechaJanela();
	void animaMario();
	void loopPrincipal();
	~Jogo();
};

#endif /* JOGO_HPP_ */
