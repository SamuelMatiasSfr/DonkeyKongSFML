#ifndef PLATAFORMA_HPP_
#define PLATAFORMA_HPP_

#include "Entidade.hpp"

class Plataforma : public Entidade{

private:
	std::vector<sf::Sprite> armazenadorPlataformas;
	int grauInclinacao;
	int quantidadePlataformas;

public:
	Plataforma();

	std::vector<sf::Sprite> &getSprites();
	int getGrauInclinacao();

	void definePlataforma(bool plataformaRegressa, int inclinacao, int quant, float posX, float posY);
    void draw(sf::RenderWindow &window);

};



#endif /* PLATAFORMA_HPP_ */
