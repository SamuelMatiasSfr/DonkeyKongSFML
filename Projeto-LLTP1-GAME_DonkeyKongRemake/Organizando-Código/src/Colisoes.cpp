/*
 * Colisoes.cpp
 *
 *  Created on: 28 de set. de 2024
 *      Author: mathe
 */

#include "Colisoes.hpp"
#include <cmath>

bool Colisoes::verificarColisao(Personagem &personagem, Plataforma &plataformas) {
    for (auto &plataforma : plataformas.getSprites()) {
        if (personagem.getSprite().getGlobalBounds().intersects(plataforma.getGlobalBounds())) {

            float plataformaX = plataforma.getGlobalBounds().left;
            float plataformaY = plataforma.getGlobalBounds().top;
            float inclinacaoRad = plataformas.getGrauInclinacao() * (M_PI / 180.0f);
            float deslocamentoX = personagem.getSprite().getGlobalBounds().left - plataformaX;
            float novaPosicaoY = plataformaY + (tan(inclinacaoRad) * deslocamentoX);

            if (personagem.getSprite().getGlobalBounds().top + personagem.getSprite().getGlobalBounds().height <= novaPosicaoY) {
                personagem.getSprite().setPosition(personagem.getSprite().getPosition().x, novaPosicaoY - personagem.getSprite().getGlobalBounds().height);
                personagem.setVelocidade(0, 0);  // Reseta a velocidade vertical
                return true; // Retorna verdadeiro para indicar que houve uma colisão
            }
        }
    }
    return false;
}

bool Colisoes::verificarColisao(sf::Sprite &sprite1, Escada &escadas) {
	bool aux;
		for (auto &escada : escadas.getDegraus()) {
		    if (sprite1.getGlobalBounds().intersects(escada.getGlobalBounds())) {
		        aux = true;
		    }
		    else{
		    	aux = false;
		    }
		}
		return aux;
}
