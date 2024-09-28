#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Plataforma{
	sf::Texture texturaPlataforma;
	sf::Sprite estrutura;
	std::vector<sf::Sprite> armazenaPlataforma;
	int grau_inclinacao;
	int quantidade_plataformas;
	int positionX;
	int positionY;

public:

	Plataforma(){
		if(!texturaPlataforma.loadFromFile("imgs/plataforma.png")){
			std::cerr << "Erro ao carregar textura da plataforma";
		}
		estrutura.setTexture(texturaPlataforma);
	}

	void definePlataforma(bool plataformaRegressa, int inclina, int qtd, int posX, int posY) {
	    this->grau_inclinacao = inclina;
	    this->quantidade_plataformas = qtd;
	    this->positionX = posX;
	    this->positionY = posY;
	    int aux = (plataformaRegressa) ? -1 : 1;

	    for (int i = 0; i < qtd; ++i) {
	        sf::Sprite plataformaAtual = estrutura;  // Cria uma nova instância de sf::Sprite
	        plataformaAtual.setPosition(posX + 78 * aux * i, posY + grau_inclinacao * i);
	        armazenaPlataforma.push_back(plataformaAtual);  // Armazena a nova plataforma no vetor
	    }
	}

	int getPosY(){
		return positionY;
	}

    void draw(sf::RenderWindow &window) {
        for (auto &estruturas : armazenaPlataforma ) {
            window.draw(estruturas);
        }
    }

    void free(){
    	armazenaPlataforma.clear();
    	armazenaPlataforma.shrink_to_fit();
    }

    sf::Sprite getSprite(){
    	return estrutura;
    }

    std::vector<sf::Sprite> getSprites() {
        return armazenaPlataforma;
    }
};
