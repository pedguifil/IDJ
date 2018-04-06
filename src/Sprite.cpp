#include "Game.h"
#include "Sprite.h"
#include "GameObject.h"

Sprite::Sprite(GameObject &associated) : Component(associated){
	texture = nullptr;
}

Sprite::Sprite(GameObject &associated,std::string arq) : Component(associated) {
	texture = nullptr;
	Open(arq);
}
Sprite::~Sprite() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
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
	associated.box.height = (float)height;
	associated.box.width = (float)width;
	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render() {
	SDL_Rect dstrect = SDL_Rect();
	dstrect.x = (int)associated.box.x;
	dstrect.y = (int)associated.box.y;
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
void Sprite::Update(float dt) {


}
bool Sprite::Is(std::string type) {

	return (type == "Sprite");

}