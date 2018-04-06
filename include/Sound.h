#ifndef _SOUND_H_
#define _SOUND_H_
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include <string>
class Sound : public Component {
private:
	Mix_Chunk * chunk;
	int channel;

public:
	Sound(GameObject& associated);
	Sound(GameObject& associated, std::string file);
	~Sound();
	void Play(int times=1);
	void Stop();
	void Open(std::string file);
	bool IsOpen();
	void Update(float dt);
	void Render();
	bool Is(std::string type);
};

#endif