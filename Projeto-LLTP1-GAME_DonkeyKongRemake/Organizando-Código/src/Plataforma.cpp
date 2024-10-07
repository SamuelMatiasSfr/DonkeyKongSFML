#include "Plataforma.hpp"

Plataforma::Plataforma(){ //chama Entidade()
	grauInclinacao = 0;
	quantidadePlataformas = 0;
}

std::vector<sf::Sprite> &Plataforma::getPlataformas(){
	return armazenadorPlataformas;
}

int Plataforma::getGrauInclinacao(){
	return grauInclinacao;
}

void Plataforma::definePlataforma(bool plataformaRegressa, int inclinacao, int quant, float posX, float posY){
	grauInclinacao = inclinacao;
	quantidadePlataformas = quant;
	posicaoX = posX;
	posicaoY = posY;

	/*
	 * Variavel auxiliar para controlar a direção em que as plataformas serão geradas.
	 * Se "plataformaRegressa" for verdadeiro, o valor sera -1, senao, sera 1.
	 */
	int aux = (plataformaRegressa) ? -1 : 1;

	for(int i = 0; i < quantidadePlataformas; ++i){
		sf::Sprite novaPataforma = corpo;
		novaPataforma.setPosition(posX + corpo.getGlobalBounds().width * aux * i, posY + grauInclinacao * i);
		armazenadorPlataformas.push_back(novaPataforma);
	}
}

void Plataforma::draw(sf::RenderWindow &window){
	for (auto &estrutura : armazenadorPlataformas ){
		window.draw(estrutura);
	}
}

