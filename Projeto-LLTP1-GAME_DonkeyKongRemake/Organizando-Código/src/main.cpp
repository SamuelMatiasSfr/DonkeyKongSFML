#include <iostream>
#include <SFML/Graphics.hpp>

#include "IntroducaoGame.hpp"

using namespace std;

int main() {
	try {
		IntroducaoGame introducao;
	} catch (const std::bad_alloc &e) {
		std::cerr << "Erro de alocação de memória: " << e.what() << std::endl;
	}
    return 0;
}

