#ifndef _MUSIC_H_
#define _MUSIC_H_
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>
class Music {
private:
	Mix_Music * music;

public:
	Music();
	Music(std::string);
	~Music();
	void Play(int times);
	void Stop(int msToStop);
	void Open(std::string);
	bool IsOpen();
};

#endif