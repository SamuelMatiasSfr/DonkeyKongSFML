#include "Colisoes.hpp"

bool Colisoes::colisaoPersonagemPlataforma(Personagem &personagem, Plataforma &plataformas) {
	for (auto &plataforma : plataformas.getSprites()) {
		if (personagem.getSprite().getGlobalBounds().intersects(plataforma.getGlobalBounds())) {

			float plataformaY = plataforma.getGlobalBounds().top;
			float personagemBase = personagem.getSprite().getGlobalBounds().top + personagem.getSprite().getGlobalBounds().height;

			if ((personagem.getVelocidade().y > 0) && (personagemBase >= plataformaY &&
					personagem.getSprite().getGlobalBounds().top <= plataformaY + plataforma.getGlobalBounds().height/1000)) {

				personagem.setVelocidade(personagem.getVelocidade().x, 0);
				personagem.setPosition(personagem.getSprite().getPosition().x,
						plataformaY - personagem.getSprite().getGlobalBounds().height/3);

				colide = true;
			}

		}else{
			colide = false;
		}
	}
	personagem.setVelocidade(personagem.getVelocidade().x, personagem.getVelocidade().y);

	return colide;
}

bool Colisoes::colisaoMarioPlataforma(Mario &mario, Plataforma &plataformas) {
    for (auto &plataforma : plataformas.getSprites()) {
        if (mario.getSprite().getGlobalBounds().intersects(plataforma.getGlobalBounds())) {

            float plataformaY = plataforma.getGlobalBounds().top;
            float marioBase = mario.getSprite().getGlobalBounds().top + mario.getSprite().getGlobalBounds().height;

            if ((mario.getVelocidade().y > 0) && (marioBase >= plataformaY &&
                mario.getSprite().getGlobalBounds().top <= plataformaY + plataforma.getGlobalBounds().height / 1000) &&
                (!mario.getEmEscada() || !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {

            	mario.setVelocidade(mario.getVelocidade().x, 0);
                mario.setPosition(mario.getSprite().getPosition().x,
                		plataformaY - mario.getSprite().getGlobalBounds().height/3);

                colide = true;
                break;
            }

        }else{
    			colide = false;
    		}
    }
    mario.setVelocidade(mario.getVelocidade().x, mario.getVelocidade().y);

    return colide;
}


bool Colisoes::colisaoPersonagemEscada(Personagem &personagem, Escada &escadas) {
		for (auto &escada : escadas.getDegraus()) {
		    if (personagem.getSprite().getGlobalBounds().intersects(escada.getGlobalBounds())) {
		        colide = true;
		        break;
		    }else{
    			colide = false;
    		}

		}
		return colide;
}

bool Colisoes::colisaoEntrePersonagens(Personagem &personagem1, Personagem &personagem2){
	if(personagem1.getSprite().getGlobalBounds().intersects(personagem2.getSprite().getGlobalBounds())){
		colide = true;
	}else{
		colide = false;
	}
	return colide;
}

void Colisoes::colisaoBarrilMapa(Barril &barril, Mapa *mapa){
	    sf::Vector2f posicaoBarril = barril.getSprite().getPosition();
	    sf::Vector2u tamanhoJanela = mapa->getWindow().getSize();

	    if (posicaoBarril.x + barril.getSprite().getGlobalBounds().width >= tamanhoJanela.x) {
	        barril.setVelocidade(-barril.getVelocidade().x, barril.getVelocidade().y);
	    }
	    if (posicaoBarril.x <= 0) {
	        barril.setVelocidade(-barril.getVelocidade().x, barril.getVelocidade().y);
	    }
	    if (posicaoBarril.y <= 0) {
	        barril.setVelocidade(barril.getVelocidade().x, -barril.getVelocidade().y);
	    }
	    if ((posicaoBarril.y + barril.getSprite().getGlobalBounds().height >= tamanhoJanela.y -
	    		(barril.getSprite().getGlobalBounds().height)) && posicaoBarril.x <= 30) {
	        barril.respawAleatotio(mapa->getWindow());
	    }

	    sf::Vector2f posicaoBarril2 = barril.getSprite().getPosition();

	    barril.setPosition(posicaoBarril2.x + barril.getVelocidade().x,
	                          posicaoBarril2.y + barril.getVelocidade().y);
}


