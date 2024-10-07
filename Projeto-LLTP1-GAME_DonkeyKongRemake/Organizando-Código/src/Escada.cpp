#include "Escada.hpp"

Escada::Escada() : degraus(0){ //chama Entidade()
	numeroDegraus = 0;
}

std::vector<sf::Sprite> &Escada::getDegraus(){
	return degraus;
}

void Escada::defineEscada(int numDegraus, float posX, float posY){
	numeroDegraus = numDegraus;
	posicaoX = posX;
	posicaoY = posY;
	float incrementaPosicao = getSprite().getGlobalBounds().height;

	//cada escada criada degrau por degrau
	for (int i = 0; i < numDegraus; ++i) {
		sf::Sprite novoDegrau = corpo; //degrauAtual recebe o sprite de degrau com a textura passada

	    /*
	     * incrementa a posicao em Y conforme a altura do sprite degrau, portanto a escada eh criada de cima para baixo,
	     * levando em consideracao o eixo x e y da SFML.
	     */
		novoDegrau.setPosition(posX, posY + incrementaPosicao * i);
		degraus.push_back(novoDegrau);
	}
}

void Escada::draw(sf::RenderWindow &janela){
	for (auto &degrau : degraus) {
		janela.draw(degrau);
	}
}



