#include "Escada.hpp"

Escada::Escada(){ //chama Entidade()
	numeroDegraus = 0;
	carregaTextura();
}

void Escada::carregaTextura(){
	if(!textura.loadFromFile("imagens/escada.png")){
		std::cerr << "Erro ao carregar textura da escada";
	}
	corpo.setTexture(textura);
}

std::vector<sf::Sprite> Escada::getDegraus() {
	return degraus;
}

void Escada::defineEscada(int numDegraus, float posX, float posY){
	numeroDegraus = numDegraus;
	posicaoX = posX;
	posicaoY = posY;
	int incrementaPosicao = getSprite().getGlobalBounds().height;

	//cada escada � criado degrau por degrau
	for (int i = 0; i < numDegraus; ++i) {
		sf::Sprite degrauAtual = corpo; //degrauAtual recebe o sprite de degrau com a textura passada

	    //incrementa a posi��o em Y conforme a altura do sprite degrau, portanto a escada � criada de cima para baixo
		degrauAtual.setPosition(posX, posY + incrementaPosicao * i);
		degraus.push_back(degrauAtual);
	}
}

void Escada::draw(sf::RenderWindow &janela){
	for (auto &degrau : degraus) {
		janela.draw(degrau);
	}
}



