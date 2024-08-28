#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Kong{

			class Kong : public Personagem{
			private:


			public:
				Kong(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, retangulo, escala, velocidadeX, velocidadeY)
				{

				}

				void mover() override{
					posicaoX = posicaoX + velocidadeX;

					if(posicaoX >= (300 - corpo.getGlobalBounds().width/2)){
						velocidadeX = velocidadeX*(-1);
					}else if(posicaoX <= 0){
						velocidadeX = velocidadeX*(-1);
					}

					corpo.setPosition(posicaoX, 0);
				}
			};

		}

	}

}
