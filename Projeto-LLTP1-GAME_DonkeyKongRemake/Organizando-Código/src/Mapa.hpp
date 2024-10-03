#ifndef MAPA_HPP_
#define MAPA_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>

class Mapa{

protected:
	sf::VideoMode tamanhoJanela;
	sf::Sprite fundoImagem;
	sf::Vector2f cordenadas;
	sf::RenderWindow window;
	const sf::String nomeMapa = "Donkey Kong";

public:
	Mapa();
	Mapa(sf::VideoMode tamJan);
	Mapa(sf::VideoMode tamJan, sf::Sprite fundo);
	Mapa(sf::Texture texturaFundo, sf::RenderWindow &janela);
	~Mapa();

	sf::RenderWindow &getWindow();
	sf::Vector2f getCordenadas();
	sf::VideoMode getTamanhoJanela();

	void setFundoImage(sf::Sprite &fundo_imagem);
	void setFundoImage(sf::Texture &fundo_textura);
	void setTamanhoJanela(float a, float b);
	void setCordenadas(sf::Vector2f cord);
	void setCordenadas(float a, float b);
};

#endif /* MAPA_HPP_ */
