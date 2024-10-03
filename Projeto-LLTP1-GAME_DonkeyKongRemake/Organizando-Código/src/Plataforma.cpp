#include "Plataforma.hpp"

Plataforma::Plataforma(){
	sf::Texture auxTextura;
	if(!auxTextura.loadFromFile("imagens/plataforma.png")){
		std::cerr << "Erro ao carregar textura da plataforma";
	}

	textura.push_back(auxTextura);

	corpo.setTexture(textura.back());
	corpo.setScale(1.2, 1.2);
}

std::vector<sf::Sprite> &Plataforma::getSprites() {
	return armazenaPlataformas;
}

int Plataforma::getGrauInclinacao(){
	return grauInclinacao;
}

void Plataforma::definePlataforma(bool plataformaRegressa, int inclinacao, int quant, int posX, int posY) {

	this->grauInclinacao = inclinacao;
	this->quantidadePlataformas = quant;
	this->posicaoX = posX;
	this->posicaoY = posY;
	int aux = (plataformaRegressa) ? -1 : 1;

	for (int i = 0; i < quantidadePlataformas; ++i) {
		sf::Sprite plataformaAtual = corpo;
		plataformaAtual.setPosition(posX + corpo.getGlobalBounds().width * aux * i, posY + grauInclinacao * i);
		armazenaPlataformas.push_back(plataformaAtual);
	}
}

void Plataforma::draw(sf::RenderWindow &window) {
	for (auto &estrutura : armazenaPlataformas ) {
		window.draw(estrutura);
	}
}

