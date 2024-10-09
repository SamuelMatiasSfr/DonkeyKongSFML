#include "Mario.hpp"

Mario::Mario(sf::Texture &textura, float posX, float posY)
:Personagem(textura,posX, posY, sf::IntRect(0, 0, 16, 16), sf::Vector2f(3.0f, 3.5f), 0, 0){
	vidas = 3;
	ganhouJogo = false;
	apertouX = false;
	pegouMartelo = false;
	paraEsquerda = false;
	paraDireita = true;
	podeAndar = true;
	emEscada = false;
	noAr = false;

	//carrega os sons de andar e pular do m�rio
	if (!bufferAndar.loadFromFile("audios/andar_.wav")) {
		std::cerr << "Erro ao carregar o arquivo de som!\n";
	}
	somAndar.setBuffer(bufferAndar);
	somAndar.setVolume(15);

	if (!bufferPular.loadFromFile("audios/pulo.wav")) {
		std::cerr << "Erro ao carregar o arquivo de som!\n";
	}
	somPular.setBuffer(bufferPular);
	somPular.setVolume(50);
}

Mario::~Mario(){}

bool Mario::getGanhou(){
	return ganhouJogo;
}

void Mario::setGanhou(bool ganhou){
	ganhouJogo = ganhou;
}

int Mario::getVidas(){
	return vidas;
}

void Mario::setVidas(int vida){
	vidas = vida;
}

bool Mario::getApertouX(){
	return apertouX;
}

void Mario::setApertouX(bool apertou){
	apertouX = apertou;
}

bool Mario::getParaDireita(){
	return paraDireita;
}

bool Mario::getParaEsquerda(){
	return paraEsquerda;
}

void Mario::setParaDireitaEsquerda(bool direita, bool esquerda){
	paraDireita = direita;
	paraEsquerda = esquerda;
}

bool Mario::getPegouMartelo(){
	return pegouMartelo;
}

void Mario::setPegouMartelo(bool pegou){
	pegouMartelo = pegou;
}

bool Mario::getEmEscada(){
	return emEscada;
}

void Mario::setEmEscada(bool estaNaEscada){
	emEscada = estaNaEscada;
}

bool Mario::getNoAr(){
	return noAr;
}

void Mario::setNoAr(bool estaNoAr){
	noAr = estaNoAr;
}

//verifica se o som est� tocando ou n�o
bool Mario::testarSom(sf::Sound &som){
	if(som.getStatus() != sf::Sound::Playing){
		return true;
	}else return false;
}

void Mario::mover(){
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (podeAndar)) {
		velocidadeX = -5;
		posicaoX += velocidadeX;
		setPosicao(posicaoX, posicaoY);

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (podeAndar)) {
		velocidadeX = 5;
		posicaoX += velocidadeX;
		setPosicao(posicaoX, posicaoY);

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (emEscada)) {
		velocidadeY = -1;
		posicaoY += velocidadeY;
		setPosicao(posicaoX, posicaoY);

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (emEscada)) {
		velocidadeY = 1;
		posicaoY += velocidadeY;
		setPosicao(posicaoX, posicaoY);

		if(testarSom(somAndar)){
			somAndar.play();
		}
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (podeAndar) && (!noAr)){
		pular();

		if(testarSom(somPular)){
			somPular.play();
		}
	}

}

void Mario::pular(){
	if(!noAr){
		velocidadeY = -4;
		posicaoY += velocidadeY;
		setPosicao(posicaoX, posicaoY);
		noAr = true;
	}
}

//verifica os limites do mapa, para o m�rio n�o sair da tela
void Mario::permitirMovimento(Mapa &map){
	if(corpo.getPosition().x >= (map.getTamanhoJanela().width - 1) ){
		podeAndar = false;
		setPosicao(corpo.getPosition().x - 2,corpo.getPosition().y );
	}else if(corpo.getPosition().x <= (1) ){
		podeAndar = false;
		setPosicao(corpo.getPosition().x + 2,corpo.getPosition().y );
	}else if(corpo.getPosition().y >= (map.getTamanhoJanela().height -1) ){
		podeAndar = false;
		setPosicao(corpo.getPosition().x, map.getTamanhoJanela().height - 20 );
	}else if(corpo.getPosition().y <= (1) ){
		podeAndar = false;
		setPosicao(corpo.getPosition().x, corpo.getPosition().y + 2);
	}else{
		podeAndar = true;
	}
}
size_t Mario::getPegaCoins(){
	return pegaCoins;
}
void Mario::setPegaCoins(int coinsColetadas){
	pegaCoins = coinsColetadas;
}
