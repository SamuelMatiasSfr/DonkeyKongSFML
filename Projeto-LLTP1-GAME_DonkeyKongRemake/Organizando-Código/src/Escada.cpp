#include "Escada.hpp"

Escada::Escada(){
	sf::Texture auxTextura;
	if(!auxTextura.loadFromFile("imagens/escada.png")){
		std::cerr << "Erro ao carregar textura da escada";
	}
	textura.push_back(auxTextura);
	corpo.setTexture(textura.back());
}

void Escada::defineEscada(int numDegraus, float posX, float posY){
	this->numeroDegrau = numDegraus;
	this->posicaoX = posX;
	this->posicaoY = posY;
	int incrementa_pixels = getSprite().getGlobalBounds().height;

	for (int i = 0; i < numDegraus; ++i) {
		sf::Sprite degrauAtual = corpo;
		degrauAtual.setPosition(posX, posY + incrementa_pixels * i);
		degraus.push_back(degrauAtual);
	}
}

void Escada::draw(sf::RenderWindow &janela){
	for (auto &degrau : degraus) {
		janela.draw(degrau);
	}
}

std::vector<sf::Sprite> Escada::getDegraus() {
		return degraus;
}


