/*
 * Colisoes.cpp
 *
 *  Created on: 28 de set. de 2024
 *      Author: mathe
 */

#include "Colisoes.hpp"

bool Colisoes::verificarColisao(Personagem &personagem, Plataforma &plataformas) {
    for (auto &plataforma : plataformas.getSprites()) {
        if (personagem.getSprite().getGlobalBounds().intersects(plataforma.getGlobalBounds())) {

            float plataformaY = plataforma.getGlobalBounds().top;
            float personagemBase = personagem.getSprite().getGlobalBounds().top + personagem.getSprite().getGlobalBounds().height;

            if ((personagem.getVelocidade().y > 0) && (personagemBase >= plataformaY &&
            		personagem.getSprite().getGlobalBounds().top <= plataformaY + plataforma.getGlobalBounds().height/1000)) {

            	personagem.setVelocidade(personagem.getVelocidade().x, 0);
                personagem.setPosition(personagem.getSprite().getPosition().x,
                		plataformaY - personagem.getSprite().getGlobalBounds().height/3);

                return true;
            }
        }
    }
    personagem.setVelocidade(personagem.getVelocidade().x, personagem.getVelocidade().y);
    return false;
}


bool Colisoes::verificarColisao(Personagem &personagem, Escada &escadas) {
		for (auto &escada : escadas.getDegraus()) {
		    if (personagem.getSprite().getGlobalBounds().intersects(escada.getGlobalBounds())) {
		        return true;
		    }

		}
		return false;
}

bool Colisoes::verificarColisao(Personagem &personagem1, Personagem &personagem2){
	if(personagem1.getSprite().getGlobalBounds().intersects(personagem2.getSprite().getGlobalBounds())){
		return true;
	}
	return false;
}


