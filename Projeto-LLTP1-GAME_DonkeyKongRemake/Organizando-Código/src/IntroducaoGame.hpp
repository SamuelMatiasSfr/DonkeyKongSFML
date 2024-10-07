#ifndef INTRODUCAOGAME_HPP
#define INTRODUCAOGAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Mapa.hpp"
#include "Entidade.hpp"
#include "Credito.hpp"
#include "Fase1.hpp"

class IntroducaoGame {

    sf::Texture texturaFundoCarregamento;
    sf::Texture texturaBotaoPlay[2];
    sf::Texture texturaBotaoCredito[2];

    sf::Sprite fundoCarregamento;

    sf::SoundBuffer somInicioBuffer;
    sf::SoundBuffer somPlayBuffer;
    sf::Sound somInicio;
    sf::Sound somPlay;

    sf::Image icon;

    sf::Font fonteDonkeyKongTitulo;
    sf::Font fonteTituloRemake;
    sf::Text tituloDonkeyKong;
    sf::Text tituloRemake;

    Entidade botaoPlay;
    Entidade botaoCredito;

    Mapa *carregamento;
    sf::Event event;

public:
    IntroducaoGame();
    ~IntroducaoGame();
    void IniciarJogo();
    void mostraCreditos();

};
#endif // INTRODUCAOGAME_HPP
