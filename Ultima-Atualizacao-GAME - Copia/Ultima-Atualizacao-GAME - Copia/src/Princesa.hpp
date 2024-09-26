#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Princesa{

			class Princesa : public Personagem{
			private:


			public:
				Princesa(sf::Texture textura, int posicaoX, int posicaoY, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, velocidadeX, velocidadeY)
				{

				}

				void mover() override{

				}
			};

		}

	}

}
