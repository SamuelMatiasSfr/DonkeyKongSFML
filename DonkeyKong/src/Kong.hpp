#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Kong{

			class Kong : public Personagem{
			private:


			public:
				Kong(sf::Texture textura, int posicaoX, int posicaoY, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, velocidadeX, velocidadeY)
				{

				}

				void mover() override{

				}
			};

		}

	}

}
