#ifndef _GAME_H_
#define _GAME_H_
#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include <string>


class Game {
private:
	Game(std::string, int, int);
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* estado;

public:
	~Game();
	State& GetState();
	static Game& GetInstance();
	SDL_Renderer* GetRenderer();
	void Run();
};

#endif