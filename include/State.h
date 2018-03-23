#ifndef _STATE_H_
#define _STATE_H_
#include "Music.h"
#include "Sprite.h"
class State {
private:
	bool quitRequested;
	Music music;
	Sprite bg;
public:
	State();
	void Update(float);
	void Render();
	void LoadAssets();
	bool QuitRequested();
};

#endif