/*
 * JogarDeNovo.hpp
 *
 *  Created on: 6 de out. de 2024
 *      Author: mathe
 */

#ifndef JOGARDENOVO_HPP_
#define JOGARDENOVO_HPP_
#include "Fase2.hpp"
#include "Mapa.hpp"


class JogarDeNovo {
private:
	Mapa *mapaPergunta;
	sf::Texture texturaFundoPergunta, texturaBotaoPlayAgain[2], texturaBotaoProximaFase[2];
	sf::Image icon;
	sf::Sprite fundoPergunta;
	sf::Text tituloRemake;
	int rgbX = 0, rgbY = 0, rgbZ = 0;
	sf::Font fonteTituloRemake;
	sf::Music musicaGanhou;
	sf::Event event;
	Entidade *botaoPlayAgain, *botaoProximaFase;



public:
	JogarDeNovo();
	~JogarDeNovo();

	void carregaTexturas();
	void criaMapa();
	void configuraTextos();

	void configuraMusica();
	void criaBotoes();

	void loopPrincipal();

	void fechaJanela();
	void tituloColorido();

	void identificaPosicaoMouse();
	void identificaClick();
	void identificaMouseHover();

	void desenhaMapa();

};

#endif /* JOGARDENOVO_HPP_ */
