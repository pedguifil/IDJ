#ifndef _RECT_H_
#define _RECT_H_
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>
#include "Vec2.h"
class Rect {

public:
	Rect();
	Rect(float x, float y, float w, float h);
	bool Contains(Vec2 v);
	float x;
	float y;
	float width;
	float height;
};

#endif