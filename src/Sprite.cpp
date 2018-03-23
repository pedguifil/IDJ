#include "Game.h"
#include "Sprite.h"
Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(std::string arq) {
	texture = nullptr;
}
Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}
void Sprite::Open(std::string arq) {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), arq.c_str());
	if (texture == nullptr) {
		printf("Erro no IMG_LoadTexture:  %s.\n", SDL_GetError());
		getchar();
		exit(1);
	}
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(int x, int y) {
	SDL_Rect dstrect = SDL_Rect();
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = clipRect.w;
	dstrect.h = clipRect.h;
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}
int Sprite::GetWidth() {
	return width;
}
int Sprite::GetHeight() {
	return height;
}
bool Sprite::IsOpen() {

	return (texture != nullptr);
}