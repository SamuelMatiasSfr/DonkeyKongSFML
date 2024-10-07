#include "Credito.hpp"

Credito::Credito() {
	//carrega texturas e sprites
	if(!texturaFundoCreditos.loadFromFile("imagens/fundoCreditos.png")){
		 std::cerr << "Erro ao carregar a textura de fundo Creditos\n";
	}

	if(!texturaBonecoMatheus.loadFromFile("imagens/matheus.png")){
		 std::cerr << "Erro ao abrir a textura de Matheus\n";
	}

	if(!texturaBonecoIgor.loadFromFile("imagens/igor.png")){
		 std::cerr << "Erro ao abrir a textura de Igor\n";
	}

	if(!texturaBonecoSamuel.loadFromFile("imagens/samuel.png")){
		 std::cerr << "Erro ao abrir a textura de Samuel\n";
	}

	fundoCreditos.setTexture(texturaFundoCreditos);
	bonecoMatheus.setTexture(texturaBonecoMatheus);
	bonecoIgor.setTexture(texturaBonecoIgor);
	bonecoSamuel.setTexture(texturaBonecoSamuel);

	bonecoMatheus.setPosition(100, 100);
	bonecoIgor.setPosition(250, 110);
	bonecoSamuel.setPosition(400, 110);

	bonecoMatheus.setScale(0.19, 0.19);
	bonecoIgor.setScale(0.2, 0.2);
	bonecoSamuel.setScale(0.2, 0.2);


	//carrega fonte e imagem do icone
	fonteCreditos.loadFromFile("fontes/fonte1.ttf");
	icon.loadFromFile("imagens/donkeyKong-icon.png");

	textosCreditos.setFont(fonteCreditos);
	textosCreditos.setFillColor(sf::Color::Magenta);
	textosCreditos.setString("Devs:\n\t Matheus  Igor   Samuel");
	textosCreditos.setScale(0.8, 0.8);
	textosCreditos.setPosition(0, 40);
	textosCreditos.setOutlineThickness(3);
	textosCreditos.setOutlineColor(sf::Color::Blue);


	//cria mapa creditos
	sf::VideoMode tamJam(texturaFundoCreditos.getSize().x, texturaFundoCreditos.getSize().y);

	mapaCreditos = new Mapa(tamJam, fundoCreditos);
	mapaCreditos->getWindow().setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	//loop principal
	while(mapaCreditos->getWindow().isOpen()){

		//loop de eventos
		while (mapaCreditos->getWindow().pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				mapaCreditos->getWindow().close();
			}
		}

		//desenha na tela
		mapaCreditos->getWindow().clear();

		mapaCreditos->getWindow().draw(fundoCreditos);
		mapaCreditos->getWindow().draw(textosCreditos);
		mapaCreditos->getWindow().draw(bonecoMatheus);
		mapaCreditos->getWindow().draw(bonecoIgor);
		mapaCreditos->getWindow().draw(bonecoSamuel);

		mapaCreditos->getWindow().display();
	}

}

Credito::~Credito() {
	delete mapaCreditos;
}

