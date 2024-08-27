#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Mario{

			class Mario : public Personagem{
			private:


			public:
				Mario(sf::Texture textura, int posicaoX, int posicaoY, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, velocidadeX, velocidadeY)
				{

				}

				void mover() override{
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
						this->corpo.move(-velocidadeX, 0.f);
					}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
						this->corpo.move(velocidadeX, 0.f);
					}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){


						this->corpo.move(0.f, -velocidadeY);
					}
				}
			};

		}

	}

}
