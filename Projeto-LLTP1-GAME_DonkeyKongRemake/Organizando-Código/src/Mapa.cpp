#include "Mapa.hpp"
#include <iostream>

Mapa::Mapa()
: tamanhoJanela(sf::VideoMode(800, 600)), cordenadas(0.0f, 0.0f), window(tamanhoJanela, nomeMapa) {

}

Mapa::Mapa(sf::VideoMode tamJan){
	this->tamanhoJanela = tamJan;
	window.create(tamanhoJanela, nomeMapa);
}

Mapa::Mapa(sf::VideoMode tamJan, sf::Sprite fundo){
	this->tamanhoJanela = tamJan;
	this->fundoImagem = fundo;
	window.create(tamanhoJanela, nomeMapa);
}

Mapa::Mapa(sf::Texture texturaFundo, sf::RenderWindow &janela) {
	fundoImagem.setTexture(texturaFundo);
	tamanhoJanela = sf::VideoMode(janela.getSize().x, janela.getSize().y);
	window.create(tamanhoJanela, nomeMapa);
	window.setFramerateLimit(30);
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

void Mapa::setFundoImage(sf::Sprite &imagem) {
    this->fundoImagem = imagem;
}

void Mapa::setFundoImage(sf::Texture &fundo_textura) {
    fundoImagem.setTexture(fundo_textura);
}

void Mapa::setTamanhoJanela(float x, float y) {
    tamanhoJanela = sf::VideoMode(x, y);
}

void Mapa::setCordenadas(sf::Vector2f cord){
	this->cordenadas = cord;
}

void Mapa::setCordenadas(float x, float y){
	this->cordenadas = sf::Vector2f(x, y);
}
