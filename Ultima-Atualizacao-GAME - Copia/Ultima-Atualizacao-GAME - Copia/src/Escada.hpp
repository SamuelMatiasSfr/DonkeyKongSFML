#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Escada{
public:
	int numero_degrau = 0;
	int positionX = 0;
	int positionY = 0;
	std::vector<sf::RectangleShape> degraus;

public:
	void defineEscada(int numDegrau, int posX, int posY) {
	    this->numero_degrau = numDegrau;
	    this->positionX = posX;
	    this->positionY = posY;
	    int incrementa_pixels = 15;

	    for (int i = 0; i < numDegrau; ++i) {
	        sf::RectangleShape degrauAtual;  // Cria uma nova instância de sf::RectangleShape
	        degrauAtual.setSize(sf::Vector2f(40, 5));
	        degrauAtual.setFillColor(sf::Color(102, 35, 130));
	        degrauAtual.setPosition(posX, posY + incrementa_pixels * i);

	        degraus.push_back(degrauAtual);  // Armazena o novo degrau no vetor
	    }
	}


    void draw(sf::RenderWindow& window) {
        for (auto& degrau : degraus) {
            window.draw(degrau);
        }
    }

    void free(){
        degraus.clear();
        degraus.shrink_to_fit();
    }

    std::vector<sf::RectangleShape> getDegraus() {
        return degraus;
    }

};
