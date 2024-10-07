#include <iostream>
#include <SFML/Graphics.hpp>

#include "IntroducaoGame.hpp"
#include "JogarDeNovo.hpp"

using namespace std;

int main() {
	try {
		JogarDeNovo introducao;
	} catch (const std::bad_alloc &e) {
		std::cerr << "Erro de alocação de memória: " << e.what() << std::endl;
	}
    return 0;
}
