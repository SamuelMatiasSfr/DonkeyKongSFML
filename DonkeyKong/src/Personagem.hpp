#pragma once

#include "Entidade.hpp"

namespace Entidade{

	namespace Personagem{

		class Personagem : public Entidade{
		protected:
			int velocidadeX;
			int velocidadeY;

		public:
			int getVelocidadeX(){
				return velocidadeX;
			}

			int getVelocidadeY(){
				return velocidadeY;
			}

			Personagem(sf::Texture textura, int posicaoX, int posicaoY, int velocidadeX, int velocidadeY):
				Entidade(textura, posicaoX, posicaoY)
			{
				this->velocidadeX = velocidadeX;
				this->velocidadeY = velocidadeY;
			}

			virtual void mover() = 0;
		};

	}

}
