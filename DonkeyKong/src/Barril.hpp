#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Barril{

			class Barril : public Personagem{
			private:


			public:
				Barril(sf::Texture textura, int posicaoX, int posicaoY, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, velocidadeX, velocidadeY)
				{

				}

				void mover() override{
					posicaoX = posicaoX + velocidadeX;
					posicaoY = posicaoY + velocidadeY;

					corpo.rotate(4.f);

					if(posicaoX >= 1000 - 0.1f*2){
						velocidadeY = velocidadeX*(-1);
					}else if(posicaoX <=  0){
						velocidadeX = velocidadeX*(-1);
					}

					if(posicaoY >= 600 - 0.1f*2){
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
