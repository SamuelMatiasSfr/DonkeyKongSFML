#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Mario{

			class Mario : public Personagem{
			private:


			public:
				Mario(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, retangulo, escala, velocidadeX, velocidadeY)
				{


				}

				void sofrerGravidade(float gravidade, float tempo){
					velocidadeY += gravidade*tempo;
					posicaoY += velocidadeY;
				}

				void mover() override{
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
						posicaoX -= velocidadeX;
					}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
						posicaoX += velocidadeX;
					}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
						velocidadeY = 12;
						posicaoY -= velocidadeY;

					}

					sofrerGravidade(0.5f, 1.5f);
					corpo.setPosition(posicaoX, posicaoY);
				}
			};

		}

	}

}
