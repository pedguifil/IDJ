#include "Music.h"

Music::Music() {
	music = nullptr;
}

Music::Music(std::string arq) {
	Open(arq);
}
void Music::Play(int times ) {
	if (music != nullptr) {
		int g = Mix_FadeInMusic(music, times, 100);
		if (g != 0) {
			printf("Mix_PlayMusic: %s\n", Mix_GetError());
		}
	}
	else {
		printf("Erro no Mix_PlayMusic:  %s.\n", Mix_GetError());
		getchar();
		exit(1);
	}
}
void Music::Stop(int msToStop) {
	Mix_FadeOutMusic(msToStop);
}
void Music::Open(std::string arq) {
	music = Mix_LoadMUS(arq.c_str());
	if (music == nullptr) {
		printf("Erro no Mix_LoadMUS:  %s.\n", Mix_GetError());
		getchar();
		exit(1);
	}
}
bool Music::IsOpen() {
	return music != nullptr;
}
Music::~Music() {
	Stop(0);
	Mix_FreeMusic(music);
}