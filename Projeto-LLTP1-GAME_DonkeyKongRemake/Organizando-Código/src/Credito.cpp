/*
 * Credito.cpp
 *
 *  Created on: 3 de out. de 2024
 *      Author: mathe
 */

#include "Credito.hpp"

Credito::Credito() {

	texturaFundoCreditos.loadFromFile("imagens/fundoCreditos.png");
	texturaBonecoMatheus.loadFromFile("imagens/matheus.png");
	texturaBonecoIgor.loadFromFile("imagens/igor.png");
	texturaBonecoSamuel.loadFromFile("imagens/samuel.png");
	fonteCreditos.loadFromFile("fontes/fonte1.ttf");
	icon.loadFromFile("imagens/donkeyKong-icon.png");

	fundoCreditos.setTexture(texturaFundoCreditos);
	bonecoMatheus.setTexture(texturaBonecoMatheus);
	bonecoIgor.setTexture(texturaBonecoIgor);
	bonecoSamuel.setTexture(texturaBonecoSamuel);

	bonecoMatheus.setPosition(100, 100);
	bonecoIgor.setPosition(250, 110);
	bonecoSamuel.setPosition(400, 110);

	bonecoMatheus.setScale(0.19, 0.19);
	bonecoIgor.setScale(0.2, 0.2);
	bonecoSamuel.setScale(0.2, 0.2);

	textosCarregamentos.setFont(fonteCreditos);
	textosCarregamentos.setFillColor(sf::Color::Magenta);
	textosCarregamentos.setString("Devs:\n\t Matheus  Igor   Samuel");
	textosCarregamentos.setScale(0.8, 0.8);
	textosCarregamentos.setPosition(0, 40);
	textosCarregamentos.setOutlineThickness(3);
	textosCarregamentos.setOutlineColor(sf::Color::Blue);


	sf::VideoMode tamJam(texturaFundoCreditos.getSize().x, texturaFundoCreditos.getSize().y);

	mapaCreditos = new Mapa(tamJam, fundoCreditos);
	mapaCreditos->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	while(mapaCreditos->getWindow().isOpen()){

		while (mapaCreditos->getWindow().pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				mapaCreditos->getWindow().close();
			}
		}


		mapaCreditos->getWindow().clear();

		mapaCreditos->getWindow().draw(fundoCreditos);
		mapaCreditos->getWindow().draw(textosCarregamentos);
		mapaCreditos->getWindow().draw(bonecoMatheus);
		mapaCreditos->getWindow().draw(bonecoIgor);
		mapaCreditos->getWindow().draw(bonecoSamuel);

		mapaCreditos->getWindow().display();
	}

}

Credito::~Credito() {
	delete mapaCreditos;
}

