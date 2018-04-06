#ifndef _FACE_H_
#define _FACE_H_
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include <string>
class Face : public Component {
private:
	int hitpoints;

public:
	Face(GameObject& associated);
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
};

#endif