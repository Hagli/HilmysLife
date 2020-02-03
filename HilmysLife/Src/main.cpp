#include "GameStateClass.h"

int main() {
	std::cout << "Welcome to the game" << std::endl << "Press any key to start " << std::endl;
	std::cin.get();
	
	//initiate game
	
	GameState life;
	life.game();

	std::cin.get();
}