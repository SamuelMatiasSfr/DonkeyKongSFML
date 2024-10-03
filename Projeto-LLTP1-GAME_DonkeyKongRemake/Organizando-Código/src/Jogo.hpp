#ifndef JOGO_HPP_
#define JOGO_HPP_

#include "Mapa.hpp"
#include "Mario.hpp"
#include "Plataforma.hpp"
#include "Escada.hpp"
#include "Colisoes.hpp"
#include "Barril.hpp"
#include "Kong.hpp"


class Jogo {

protected:
	sf::SoundBuffer bufferMorte;
	sf::Sound somMorte;
	sf::Texture texturaFundoJogo, texturaMario, texturaMarioDireita, texturaBarril, texturaKong, texturaExplosao;
	sf::Sprite fundoJogo, explosao;
	sf::Image icon;
	std::vector<sf::Texture> texturaMarioVector, texturaMarioVectorDireita, texturaBarrilVector, texturaKongVector;
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
	~Jogo();

	void setTexturas();

	void carregarAudios();
	void carregatexturas();
	void geraPlataformas();
	void geraEscadas();
	void criaPersonagens();
	void criaMapa();
	void desenhaMapa();
	void colideComPlataformas();
	void colideComEscadas();
	void colidePersonagens();
	void movimentaPersonagens();
	void animaMario();
	void fechaJanela();
	void loopPrincipal();

};

#endif /* JOGO_HPP_ */
