#pragma once

#include "Personagem.hpp"

namespace Entidade {

    namespace Personagem {

        namespace Mario {

            class Mario : public Personagem {
            private:
                float velocidadeY;
                bool noChao;
                float tempoPulo;
                const float duracaoPulo;
                int limiteInferior = 760;

            public:
                Mario(sf::Texture textura, int posicaoX, int posicaoY, sf::IntRect retangulo, sf::Vector2f escala, int velocidadeX, int velocidadeY)
                    : Personagem(textura, posicaoX, posicaoY, retangulo, escala, velocidadeX, velocidadeY),
                      velocidadeY(0.0f), noChao(true), tempoPulo(0.0f), duracaoPulo(0.5f)
                {

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
                        velocidadeY = -8.0f; // Ajuste a força do pulo se necessário
                        noChao = false;
                    }
                }

                void mover(){


                	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                		velocidadeX = -5;
                		posicaoX += velocidadeX;
                	}
                	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                		velocidadeX = 5;
                        posicaoX += velocidadeX;
                	}
                	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
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

                    // Aplicar a gravidade
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
