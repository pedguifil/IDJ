#ifndef _SPRITE_H_
#define _SPRITE_H_
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>
class Sprite {
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;

public:
	Sprite();
	Sprite(std::string);
	~Sprite();
	void Open(std::string);
	void SetClip(int, int, int, int);
	void Render(int, int);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
};

#endif