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

            float plataformaY = plataforma.getGlobalBounds().top;
            float novaPosicaoY = plataformaY + plataforma.getGlobalBounds().height;

            if (personagem.getSprite().getGlobalBounds().top <= novaPosicaoY) {
                personagem.getSprite().setPosition(personagem.getSprite().getPosition().x, novaPosicaoY - personagem.getSprite().getGlobalBounds().height);
                personagem.setVelocidade(0, 0);
                return true;
            }
        }
    }
    return false;
}

bool Colisoes::verificarColisao(sf::Sprite &sprite1, Escada &escadas) {
		for (auto &escada : escadas.getDegraus()) {
		    if (sprite1.getGlobalBounds().intersects(escada.getGlobalBounds())) {
		        return true;
		    }

		}
		return false;
}
