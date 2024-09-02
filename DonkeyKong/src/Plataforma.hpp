#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Plataforma{
	sf::Texture texturaPlataforma;
	sf::Sprite estrutura;
	std::vector<sf::Sprite> armazenaPlataforma;
	int grau_inclinacao = 0;
	int quantidade_plataformas = 0;
	int positionX = 0;
	int positionY = 0;

public:

	Plataforma(){
		if(!texturaPlataforma.loadFromFile("imgs/plataforma.png")){
			std::cerr << "Erro ao carregar textura da plataforma";
		}
		estrutura.setTexture(texturaPlataforma);
	}

	void definePlataforma(bool plataformaRegressa, int inclina, int qtd, int posX, int posY){

		this->grau_inclinacao = inclina;
		this->quantidade_plataformas = qtd;
		this->positionX = posX;
		this->positionY = posY;
		int aux = 0;

		if(plataformaRegressa == true){
			aux = -1;
		}else{
			aux = 1;
		}


		for (int i = 0; i < qtd; ++i) {
			estrutura.setPosition(posX + 78 * aux * i , posY + grau_inclinacao * i);
			armazenaPlataforma.push_back(estrutura);
		}

	}

    void draw(sf::RenderWindow& window) {
        for (auto& estruturas : armazenaPlataforma ) {
            window.draw(estruturas);
        }
    }

    void free(){
        armazenaPlataforma.clear();
        armazenaPlataforma.shrink_to_fit();
    }

};
