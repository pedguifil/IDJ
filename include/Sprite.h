#ifndef _SPRITE_H_
#define _SPRITE_H_
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include <string>
class Sprite : public Component {
private:
	SDL_Texture * texture;
	int width;
	int height;
	SDL_Rect clipRect;

public:
	Sprite(GameObject &associated);
	Sprite(GameObject &associated,std::string);
	~Sprite();
	void Open(std::string);
	void SetClip(int, int, int, int);
	virtual void Update(float dt);
	virtual void Render();
	bool virtual Is(std::string type);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
};

#endif