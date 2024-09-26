#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

namespace Entidade{

	class Entidade{
	protected:
		sf::Sprite corpo;
		sf::Texture textura;
		int posicaoX;
		int posicaoY;

	public:
		sf::Sprite getSprite(){
			return corpo;
		}

		sf::Texture getTextura(){
			return textura;
		}

		int getPosicaoX(){
			return posicaoX;
		}

		int getPosicaoY(){
			return posicaoY;
		}

		void setPosicaoY(int posY){
			this->posicaoY = posY;
		}

		Entidade(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala){
			this->textura = textura;
			this->posicaoX = posicaoX;
			this->posicaoY = posicaoY;
			/*
			 * preciso saber se carrego a textura aqui dentro e recebo o caminho
			 * ou se recebo textura carregada
			 */
			corpo.setTexture(this->textura);
			corpo.setTextureRect(retangulo);
			corpo.setScale(escala.x, escala.y);
			corpo.setPosition(posicaoX, posicaoY);
			corpo.setOrigin(corpo.getLocalBounds().width / 2.,
						corpo.getLocalBounds().height / 2.);
		}
	};

}
