//S� EXISTE 4 BARRIS POR VEZ, QUANDO UM CAI L� EMBAIXO, ELE VOLTA PARA CIMA
//QUANDO PASSA NA PRIMEIRA ESCADA MAIS PERTO DO KONG, GERA UM NOVO BARRIL

#pragma once

#include "Personagem.hpp"

namespace Entidade{

	namespace Personagem{

		namespace Barril{

			class Barril : public Personagem{
			private:
				bool noChao;
				float tempoPulo;
                const int duracaoPulo;
                int limiteInferior;


			public:
				Barril(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala, int velocidadeX, int velocidadeY):
					Personagem(textura, posicaoX, posicaoY, retangulo, escala, velocidadeX, velocidadeY),
					noChao(true), tempoPulo(0.0f), duracaoPulo(0.5f)
				{
					limiteInferior = posicaoY;
				}

				void setNoChao(bool chao){
					if(chao){
						noChao = true;
					}else{
						noChao = false;
					}
				}

				void sofrerGravidade(float gravidade, float deltaTempo) {
					if (!noChao) {
						velocidadeY += gravidade * deltaTempo;
						posicaoY += velocidadeY * deltaTempo;


						if (posicaoY >= limiteInferior) {
							posicaoY = limiteInferior;
							velocidadeY = 0;
							noChao = true;
						}
					}
				}


				void mover() override{
					posicaoX = posicaoX + velocidadeX;
					posicaoY = posicaoY + velocidadeY;

					if(posicaoX >= (800 - (corpo.getGlobalBounds().width/2))){
						velocidadeX = velocidadeX*(-1);
					}else if(posicaoX <=  (0 + (corpo.getGlobalBounds().width/2))){
						velocidadeX = velocidadeX*(-1);
					}

					corpo.setPosition(posicaoX, posicaoY);
				}
			};

		}

	}

}
