//SÓ EXISTE 4 BARRIS POR VEZ, QUANDO UM CAI LÁ EMBAIXO, ELE VOLTA PARA CIMA
//QUANDO PASSA NA PRIMEIRA ESCADA MAIS PERTO DO KONG, GERA UM NOVO BARRIL

#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Barril{

			class Barril : public Personagem{
			private:


			public:
				Barril(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, retangulo, escala, velocidadeX, velocidadeY)
				{

				}

				void mover() override{
					posicaoX = posicaoX + velocidadeX;
					posicaoY = posicaoY + velocidadeY;

					if(posicaoX >= (800 - corpo.getGlobalBounds().width/2)){
						velocidadeY = velocidadeX*(-1);
					}else if(posicaoX <=  0){
						velocidadeX = velocidadeX*(-1);
					}

					if(posicaoY >= (600 - corpo.getGlobalBounds().width/2)){
						velocidadeY = velocidadeY*(-1);
					}else if(posicaoY <= 0){
						velocidadeY = velocidadeY*(-1);
					}

					corpo.setPosition(posicaoX, posicaoY);
				}
			};

		}

	}

}
