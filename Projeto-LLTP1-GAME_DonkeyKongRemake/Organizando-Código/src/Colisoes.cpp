#include "Colisoes.hpp"

void Colisoes::colisaoBarrilPlataforma(Barril &barril, Plataforma &plataformas) {
	for (auto &plataforma : plataformas.getPlataformas()){
		if (barril.getSprite().getGlobalBounds().intersects(plataforma.getGlobalBounds())) {

			float plataformaPosY = plataforma.getGlobalBounds().top;
			float baseBarrilY = barril.getSprite().getGlobalBounds().top + barril.getSprite().getGlobalBounds().height;

			if ((barril.getVelocidade().y > 0) && (baseBarrilY >= plataformaPosY &&
					barril.getSprite().getGlobalBounds().top <= plataformaPosY + plataforma.getGlobalBounds().height/1000)) {

				barril.setVelocidade(barril.getVelocidade().x, 0);
				barril.setPosicao(barril.getSprite().getPosition().x,
						plataformaPosY - barril.getSprite().getGlobalBounds().height/3);

			}
		}
	}
}

bool Colisoes::colisaoMarioPlataforma(Mario &mario, Plataforma &plataformas){
    for (auto &plataforma : plataformas.getPlataformas()){
        if (mario.getSprite().getGlobalBounds().intersects(plataforma.getGlobalBounds())) {

            float plataformaY = plataforma.getGlobalBounds().top;
            float marioBase = mario.getSprite().getGlobalBounds().top + mario.getSprite().getGlobalBounds().height;

            if ((mario.getVelocidade().y > 0) && (marioBase >= plataformaY &&
                mario.getSprite().getGlobalBounds().top <= plataformaY + plataforma.getGlobalBounds().height / 1000) &&
                (!mario.getEmEscada() || !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {

            	mario.setVelocidade(mario.getVelocidade().x, 0);
                mario.setPosicao(mario.getSprite().getPosition().x,
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

bool Colisoes::colisaoEntrePersonagens(Personagem &mario, Personagem &barril) {
	sf::FloatRect marioBounds = mario.getSprite().getGlobalBounds();
	sf::FloatRect barrilBounds = barril.getSprite().getGlobalBounds();

	marioBounds.height -= 25;
	marioBounds.width -= 25;
	barrilBounds.height -= 25;
	barrilBounds.width -= 25;

	if(marioBounds.intersects(barrilBounds)) {
		colide = true;
	}else{
		colide = false;
	}
	return colide;
}

void Colisoes::colisaoBarrilMapa(Barril &barril, Mapa *mapa){
	if (barril.getSprite().getPosition().x + barril.getSprite().getGlobalBounds().width >= mapa->getTamanhoJanela().width) {
						barril.setVelocidade(-barril.getVelocidade().x, barril.getVelocidade().y);
						barril.setPosicao(barril.getPosicao().x - 30, barril.getPosicao().y);
	}

	if (barril.getSprite().getPosition().x <= 0) {
		barril.setVelocidade(-barril.getVelocidade().x, barril.getVelocidade().y);
	}

	if ((barril.getSprite().getPosition().y  + barril.getSprite().getGlobalBounds().height >= mapa->getWindow().getSize().y)
			&& barril.getSprite().getPosition().x <= 30) {
		barril.respawAleatotio(mapa->getWindow());
	}

	if (barril.getSprite().getPosition().x == 500) {
		barril.determinarMovimento();
	}
}


