#ifndef _STATE_H_
#define _STATE_H_
#include "Music.h"
#include "Sprite.h"
#include <vector>
#include <memory>
class State {
private:
	void Input();
	void AddObject(int mouseX, int mouseY);
	bool quitRequested;
	Music music;
	std::vector<std::unique_ptr<GameObject>> objectArray;
public:
	State();
	~State();
	void Update(float);
	void Render();
	void LoadAssets();
	bool QuitRequested();
};

#endif