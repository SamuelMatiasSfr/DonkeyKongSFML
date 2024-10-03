#ifndef PLATAFORMA_HPP_
#define PLATAFORMA_HPP_

#include "Entidade.hpp"

class Plataforma : public Entidade{

protected:
	std::vector<sf::Sprite> armazenaPlataformas;
	int grauInclinacao = 0;
	int quantidadePlataformas = 0;

public:
	Plataforma();

	std::vector<sf::Sprite> &getSprites();
	int getGrauInclinacao();

	void definePlataforma(bool plataformaRegressa, int inclinacao, int quant, int posX, int posY);
    void draw(sf::RenderWindow &window);

};



#endif /* PLATAFORMA_HPP_ */
