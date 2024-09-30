#include "Mapa.hpp"
#include <iostream>

Mapa::Mapa(sf::VideoMode tamJan){
	this->tamanho_janela = tamJan;
	window.create(tamanho_janela, nome_mapa);
}

Mapa::Mapa(sf::VideoMode tamJan, sf::Sprite fundo){
	this->tamanho_janela = tamJan;
	this->fundo_imagem = fundo;
	window.create(tamanho_janela, nome_mapa);
}

Mapa::Mapa(sf::Texture texturaFundo, sf::RenderWindow &janela) {
	fundo_imagem.setTexture(texturaFundo);
	tamanho_janela = sf::VideoMode(janela.getSize().x, janela.getSize().y);
	window.create(tamanho_janela, nome_mapa);
}

Mapa::Mapa()
    : tamanho_janela(sf::VideoMode(800, 600)), cordenadas(0.0f, 0.0f), window(tamanho_janela, nome_mapa) {}

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
    return tamanho_janela;
}

void Mapa::setFundoImage(sf::Sprite &imagem) {
    this->fundo_imagem = imagem;
}

void Mapa::setFundoImage(sf::Texture &fundo_textura) {
    fundo_imagem.setTexture(fundo_textura);
}

void Mapa::setTamanhoJanela(float a, float b) {
    tamanho_janela = sf::VideoMode(a, b);
}

void Mapa::setCordenadas(sf::Vector2f cord){
	this->cordenadas = cord;
}

void Mapa::setCordenadas(float a, float b){
	this->cordenadas = sf::Vector2f(a, b);
}
