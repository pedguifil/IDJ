#include "Game.h"

int main(int argc, char* argv[]) {
	printf("Teste \n");
	Game game = Game::GetInstance();
	game.Run();
	return 0;
}