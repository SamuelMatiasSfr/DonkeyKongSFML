#pragma once

#include "Entidade.hpp"

namespace Entidade{

	namespace Martelo{

		class Martelo : public Entidade{
		protected:

		public:
			Martelo(sf::Texture textura, int posicaoX, int posicaoY):
				Entidade(textura, posicaoX, posicaoY)
			{

			}

		};

	}

}
