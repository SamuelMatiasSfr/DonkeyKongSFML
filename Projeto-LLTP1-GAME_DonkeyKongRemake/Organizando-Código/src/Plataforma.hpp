#ifndef PLATAFORMA_HPP_
#define PLATAFORMA_HPP_

#include "Entidade.hpp"

class Plataforma : public Entidade{
protected:

	std::vector<sf::Sprite> armazenaPlataforma;
	int grau_inclinacao = 0;
	int quantidade_plataformas = 0;

public:

	Plataforma();
	void definePlataforma(bool plataformaRegressa, int inclina, int qtd, int posX, int posY);
    void draw(sf::RenderWindow &window);
    std::vector<sf::Sprite> &getSprites();
    int getGrauInclinacao();

};



#endif /* PLATAFORMA_HPP_ */
