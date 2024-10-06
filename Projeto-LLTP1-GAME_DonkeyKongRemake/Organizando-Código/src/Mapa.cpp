#include "Mapa.hpp"
#include <iostream>

Mapa::Mapa(sf::VideoMode tamJan, sf::Sprite fundo){
	tamanhoJanela = tamJan;
	fundoImagem = fundo;
	window.create(tamanhoJanela, nomeMapa);
	window.setFramerateLimit(50);
}

Mapa::~Mapa() {
    std::cout << "Mapa Destruido\n";
}

sf::RenderWindow &Mapa::getWindow() {
    return window;
}

sf::Vector2f Mapa::getCordenadas() {
    return cordenadas;
}

sf::VideoMode Mapa::getTamanhoJanela() {
    return tamanhoJanela;
}

void Mapa::setFundoImage(sf::Texture &fundoTextura) {
    fundoImagem.setTexture(fundoTextura);
}

void Mapa::setTamanhoJanela(float x, float y) {
    tamanhoJanela = sf::VideoMode(x, y);
}

void Mapa::setCordenadas(float x, float y){
	cordenadas = sf::Vector2f(x, y);
}
