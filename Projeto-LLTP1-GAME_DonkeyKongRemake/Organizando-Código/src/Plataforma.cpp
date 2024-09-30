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

void Plataforma::definePlataforma(bool plataformaRegressa, int inclina, int qtd, int posX, int posY) {

	this->grau_inclinacao = inclina;
	this->quantidade_plataformas = qtd;
	this->posicaoX = posX;
	this->posicaoY = posY;
	int aux = (plataformaRegressa) ? -1 : 1;

	for (int i = 0; i < quantidade_plataformas; ++i) {
		sf::Sprite plataformaAtual = corpo;  // Cria uma nova instância de sf::Sprite
		plataformaAtual.setPosition(posX + corpo.getGlobalBounds().width * aux * i, posY + grau_inclinacao * i);
		armazenaPlataforma.push_back(plataformaAtual);  // Armazena a nova plataforma no vetor
	}
}

void Plataforma::draw(sf::RenderWindow &window) {
	for (auto &estruturas : armazenaPlataforma ) {
		window.draw(estruturas);
	}
}

std::vector<sf::Sprite> &Plataforma::getSprites() {
	return armazenaPlataforma;
}

int Plataforma::getGrauInclinacao(){
	return grau_inclinacao;
}

