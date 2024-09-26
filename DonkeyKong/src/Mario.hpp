#pragma once

#include "Personagem.hpp"

namespace Entidade {

    namespace Personagem {

        namespace Mario {

            class Mario : public Personagem {
            private:
                bool podeMovimentarDireita;
                bool podeMovimentarLeft;
                bool sobeEscada;
                bool noChao;
                float tempoPulo;
                const int duracaoPulo;
                int limiteInferior = 770;

            public:


                Mario(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala, int velocidadeX, int velocidadeY)
                    : Personagem(textura, posicaoX, posicaoY, retangulo, escala, velocidadeX, velocidadeY),
                       noChao(true), tempoPulo(0.0f), duracaoPulo(0.5f)
                {
                	podeMovimentarDireita = true;
                	podeMovimentarLeft = true;
                }


                void permitirMovimento(){
                	if(posicaoX <= 0+corpo.getGlobalBounds().width/2){
                		podeMovimentarDireita = true;
                		podeMovimentarLeft = false;
                	}else if(posicaoX >= 800-corpo.getGlobalBounds().width/2){
                		podeMovimentarDireita = false;
                		podeMovimentarLeft = true;
                	}else{
                		podeMovimentarDireita = true;
                		podeMovimentarLeft = true;
                	}
                }

                void setNoChao(bool chao){
                	if(true){
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

                void pular() {
                    if (noChao) {
                    	this->velocidadeY = -7.5f;

                        noChao = false;
                    }
                }

                void mover(){

                	permitirMovimento();

                	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (podeMovimentarLeft)) {
                		velocidadeX = -5;
                		posicaoX += velocidadeX;
                	}
                	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (podeMovimentarDireita)) {
                		velocidadeX = 5;
                        posicaoX += velocidadeX;
                	}
                	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (sobeEscada)) {
                		velocidadeY = 5;
                		posicaoY -= velocidadeY;
                	}
                	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                		velocidadeY = 5;
                		posicaoY += velocidadeY;
                	}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        pular();
                    }

                    // aplica a gravidade

                    sofrerGravidade(0.5f, 1.5f);

                    corpo.setPosition(posicaoX, posicaoY);
                }

                void setVelocidade(int x, int y){
                	posicaoX += x;
                	posicaoY += y;

                	corpo.setPosition(posicaoX, posicaoY);
                }

                void setLimiteInferior(float novoLim){
                	limiteInferior = novoLim;
                }

            };

        }

    }

}
