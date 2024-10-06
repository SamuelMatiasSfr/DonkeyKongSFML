#ifndef MAPA_HPP_
#define MAPA_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>

class Mapa{

private:
	sf::VideoMode tamanhoJanela;
	sf::Sprite fundoImagem;
	sf::Vector2f cordenadas;
	sf::RenderWindow window;
	const sf::String nomeMapa = "Donkey Kong";

public:
	Mapa(sf::VideoMode tamJan, sf::Sprite fundo);
	~Mapa();

	sf::RenderWindow &getWindow();
	sf::Vector2f getCordenadas();
	sf::VideoMode getTamanhoJanela();

	void setFundoImage(sf::Texture &fundoTextura);
	void setTamanhoJanela(float x, float y);
	void setCordenadas(float x, float y);

};

#endif /* MAPA_HPP_ */
