#include "Plataforma.hpp"

Plataforma::Plataforma(){ //chama Entidade()
	grauInclinacao = 0;
	quantidadePlataformas = 0;
}

void Plataforma::carregaTextura(){

	if(!textura.loadFromFile("imagens/plataforma.png")){
		std::cerr << "Erro ao carregar textura da plataforma";
	}

	corpo.setTexture(textura);
	corpo.setScale(1.2, 1.2);
}

std::vector<sf::Sprite> &Plataforma::getSprites() {
	return armazenadorPlataformas;
}

int Plataforma::getGrauInclinacao(){
	return grauInclinacao;
}

void Plataforma::definePlataforma(bool plataformaRegressa, int inclinacao, int quant, float posX, float posY) {
	grauInclinacao = inclinacao;
	quantidadePlataformas = quant;
	posicaoX = posX;
	posicaoY = posY;
	int aux = (plataformaRegressa) ? -1 : 1;

	for (int i = 0; i < quantidadePlataformas; ++i) {
		sf::Sprite plataformaAtual = corpo;
		plataformaAtual.setPosition(posX + corpo.getGlobalBounds().width * aux * i, posY + grauInclinacao * i);
		armazenadorPlataformas.push_back(plataformaAtual);
	}
}

void Plataforma::draw(sf::RenderWindow &window) {
	for (auto &estrutura : armazenadorPlataformas ) {
		window.draw(estrutura);
	}
}

