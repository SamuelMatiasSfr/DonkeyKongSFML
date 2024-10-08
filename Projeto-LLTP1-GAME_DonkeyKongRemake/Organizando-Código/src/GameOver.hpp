#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include "Entidade.hpp"
#include "Jogo.hpp"
#include "Credito.hpp"

class GameOver {

private:
	sf::Texture texturaFundoGameOver;
	sf::Texture texturaBotaoPlay;
	sf::Texture texturaBotaoPlayHover;
	sf::Texture texturaBotaoCredito;
	sf::Texture texturaBotaoCreditoHover;

	sf::Music musicaGameOver;

	sf::Font fonteTituloRemake;
	sf::Text tituloRemake;

	sf::Sprite fundoGameOver;
	sf::VideoMode tamanhoJanela;
	sf::Event event;
	sf::Image icon;

	Mapa *mapaGameOver;
	Entidade *botaoPlay;
	Entidade *botaoCredito;

public:
	GameOver();
	~GameOver();

    void reiniciarJogo();
    void mostrarCreditos();

};

#endif /* GAMEOVER_HPP_ */
