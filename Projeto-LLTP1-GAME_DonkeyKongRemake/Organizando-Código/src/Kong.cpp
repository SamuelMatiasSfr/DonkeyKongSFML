#include "Kong.hpp"

Kong::Kong(sf::Texture &textura, float posX, float posY)
:Personagem(textura,posX, posY, sf::IntRect(99, 0, 45, 32), sf::Vector2f(2.5f, 3.0f), 2, 0){
	if(!this->textura.loadFromFile("imagens/kong.png")){
		std::cerr << "Erro ao carregar a imagem do kong\n";
	}
}

Kong::~Kong(){}
