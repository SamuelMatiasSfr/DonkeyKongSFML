#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Escada{
	int numero_degrau = 0;
	int positionX = 0;
	int positionY = 0;
	std::vector<sf::RectangleShape> degraus;

public:
	Escada(int numDegrau, int posX, int posY){

		this->numero_degrau = numDegrau;
		this->positionX = posX;
		this->positionY = posY;


		int incrementa_pixels = 20;
		for (int i = 0; i < numDegrau; ++i) {
			sf::RectangleShape plataforma;
			plataforma.setSize(sf::Vector2f(50, 10));
			plataforma.setFillColor(sf::Color::Magenta);
			plataforma.setPosition(posX, posY + incrementa_pixels * i);

			degraus.push_back(plataforma);
		}

	}

    void draw(sf::RenderWindow& window) {
        for (auto& degrau : degraus) {
            window.draw(degrau);
        }
    }

};


