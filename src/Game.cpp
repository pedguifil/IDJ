#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Game.h"

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height) {

	if (instance != nullptr) {
		exit(1);
	}
	else {
		instance = this;
	}

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
		printf("Erro no SDL_Init:  %s.\n", SDL_GetError());
		getchar();
		exit(1);
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
		printf("Erro no IMG_Init:  %s.\n", IMG_GetError());
		getchar();
		exit(1);
	}
	if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
		printf("Erro no Mix_Init:  %s.\n", Mix_GetError());
		getchar();
		exit(1);
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)!=0) {
		printf("Erro no Mix_OpenAudio:  %s.\n", Mix_GetError());
		getchar();
		exit(1);
	}
	Mix_AllocateChannels(32);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr){
		printf("Erro ao criar a window:  %s.\n", SDL_GetError());
		getchar();
		exit(1);
	}
	if (renderer == nullptr) {
		printf("Erro ao criar o renderer:  %s.\n", SDL_GetError());
		getchar();
		exit(1);
	}

	estado = new State();
}

Game::~Game() {
	if (estado != nullptr) {
		delete estado;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

Game& Game::GetInstance() {
	if (instance != nullptr) {
		return *instance;
	}
	else {
		instance = new Game("Pedro Henrique Antunes Rocha - 12/0132401", 1024, 600);
		return *instance;
	}
}

State& Game::GetState() {
	return *estado;
}

SDL_Renderer* Game::GetRenderer() {
	return renderer;
}

void Game::Run() {
	estado->LoadAssets();
	while (!estado->QuitRequested()) {
		estado->Update(0);
		estado->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}