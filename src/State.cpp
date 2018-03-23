#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"

State::State() {
	quitRequested = false;
	bg=Sprite();
	music=Music();
}
bool State::QuitRequested() {
	return quitRequested;
}
void State::LoadAssets() {
	bg.Open("assets/img/ocean.jpg");
	music.Open("assets/audio/stageState.ogg");
	music.Play(-1);
}
void State::Render() {
	bg.Render(0,0);
}
void State::Update(float) {
	if (SDL_QuitRequested()) {
		quitRequested = true;
	}
}