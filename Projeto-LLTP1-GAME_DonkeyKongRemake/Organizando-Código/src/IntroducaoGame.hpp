#ifndef INTRODUCAOGAME_HPP
#define INTRODUCAOGAME_HPP

#include "Entidade.hpp"
#include "Fase1.hpp"
#include "Credito.hpp"

class IntroducaoGame {

private:
    sf::Texture texturaFundoCarregamento;
    sf::Texture texturaBotaoPlay[2];
    sf::Texture texturaBotaoCredito[2];

    sf::Sprite fundoCarregamento;

    sf::Music musicaInicio;

    sf::Image icon;

    sf::Font fonteDonkeyKongTitulo;
    sf::Font fonteTituloRemake;
    sf::Text tituloDonkeyKong;
    sf::Text tituloRemake;

    Entidade botaoPlay;
    Entidade botaoCredito;

    Mapa *mapaCarregamento;
    sf::Event event;

public:
    IntroducaoGame();
    ~IntroducaoGame();

    void carregaTexturasImagens();
    void criaMapa();
    void configuraTextos();
    void criaBotoes();
    void loopPrincipal();
    void identificaPosicaoMouse();

    void fechaJanela();
    void identificaMouseHover();
    void identificaClick();
    void tocaMusica();
    void desenhaMapa();

    void iniciarJogo();
    void mostraCreditos();

};

#endif // INTRODUCAOGAME_HPP
