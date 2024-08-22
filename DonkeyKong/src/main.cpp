#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Escada{
private:
	sf::RectangleShape corpo;
	int posicaoX;
	int posicaoY;

public:
	Escada(int posicaoX, int posicaoY){
		this->posicaoX = posicaoX;
		this->posicaoY = posicaoY;
		corpo.setSize(sf::Vector2f(50.f, 100.f));
		corpo.setOrigin(posicaoX, posicaoY);
	}

	sf::RectangleShape getCorpo(){
		return corpo;
	}

	int getPosicaoX(){
		return posicaoX;
	}

	int getPosicaoY(){
		return posicaoY;
	}
};



class Bola{
private:
	sf::Sprite sprite;
	sf::Texture textura;
	int posx;
	int posy;
	int vx;
	int vy;

public:
	sf::Sprite getSprite(){
		return this->sprite;
	}
	Bola();
	void mover(vector<Escada>escadas);
	int decidirMovimento();
	void moverNaEscada(vector<Escada>escadas);
	void moverAteFim();
};



Bola::Bola(){
	posx = 0;
	posy = 0;
	vx = 15;
	vy = 2;

	textura.loadFromFile("pokemon.png");
	sprite.setTexture(textura);
	sprite.setScale(sf::Vector2f(0.1f, 0.1f));
	sprite.setOrigin(posx, posy);
}

int Bola::decidirMovimento(){
	unsigned seed = time(0);
	srand(seed);
	return rand()%2;
}

void Bola::moverNaEscada(vector<Escada>escadas){

}

void Bola::moverAteFim(){

}

void Bola::mover(vector<Escada>escadas){

	if(decidirMovimento() == 0){
		moverNaEscada(escadas);
	}else{
		moverAteFim();
	}

	posx = posx + vx;
	posy = posy + vy;

	sprite.rotate(4.f);

	if(posx >= 1000 - 0.1f*2){
		vx = vx*(-1);
	}else if(posx <=  0){
		vx = vx*(-1);
	}

	if(posy >= 1000 - 0.1f*2){
		vy = vy*(-1);
	}else if(posy <= 0){
		vy = vy*(-1);
	}

	sprite.setPosition(posx, posy);
}

class Mario{
private:
	sf::Sprite sprite;
	sf::Texture textura;
	vector<sf::Texture>texturas;
	int posicaoX;
	int posicaoY;
	float velocidadeX;
	float velocidadeY;

public:
	sf::Sprite getSprite(){;
		return sprite;
	}
	Mario();
	void mover();
	void carregarTexturas();
	void mudarFrames();
};

void Mario::carregarTexturas(){
	sf::Texture textura0;
	sf::Texture textura1;
	sf::Texture textura2;

	if(!textura0.loadFromFile("imgs/mario/frame0.png")){
		 cerr<<"Ocorreu um erro ao abrir textura"<< endl;
	}else{
		texturas.push_back(textura0);
	}

	if(!textura1.loadFromFile("imgs/mario/frame1.png")){
			 cerr<<"Ocorreu um erro ao abrir textura"<< endl;
		}else{
			texturas.push_back(textura1);
		}

	if(!textura2.loadFromFile("imgs/mario/frame2.png")){
			 cerr<<"Ocorreu um erro ao abrir textura"<< endl;
		}else{
			texturas.push_back(textura2);
		}

}

Mario::Mario(){
	this->posicaoX = 0;
	this->posicaoY = 0;
	this->velocidadeX = 2.f;
	this->velocidadeY = 2.f;
	textura.loadFromFile("imgs/mario/frame0.png");
	carregarTexturas();
	sprite.setTexture(textura);
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setOrigin(posicaoX, posicaoY);
}

void Mario::mudarFrames(){
	for(const auto& textura : texturas){
			sprite.setTexture(textura);
		}
		sprite.setTexture(texturas[0]);
}

void Mario::mover(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		sprite.move(-velocidadeX, 0.f);
		mudarFrames();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		sprite.move(velocidadeX, 0.f);
		mudarFrames();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		sprite.move(0.f, -velocidadeY);
	}
}


int main(int argc, char **argv) {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Demo");
	sf::Event event;
	window.setFramerateLimit(30.f);

	Bola bola;
	Mario mario;

	vector<Escada>escadas;

	for(int i=1; i<10; i++){
		Escada escada(i+5*10, i+5*10);
		escadas.push_back(escada);
	}

	//loop do jogo
	while (window.isOpen()) {

		//loop de eventos
		//Variável para armazenar o evento a ser tratado.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//atualiza mundo
		bola.mover(escadas);
		mario.mover();

		//desenha mundo
		window.clear();

		for(int i=0; i<9; i++){
				window.draw(escadas.at(i).getCorpo());
			}

		window.draw(bola.getSprite());
		window.draw(mario.getSprite());

		window.display();
	}

	return 0;
}
