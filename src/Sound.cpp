#include "Sound.h"

Sound::Sound(GameObject& associated) : Component(associated) {
	chunk = nullptr;
	
}
Sound::Sound(GameObject& associated, std::string file) : Component(associated) {
	chunk = nullptr;
	Open(file);
}
Sound::~Sound() {
	if (chunk != nullptr) {
		Stop();
	}
	Mix_FreeChunk(chunk);
}
void Sound::Play(int times) {
	channel = Mix_PlayChannel(-1, chunk, times - 1);
	if (channel == -1) {
		printf("Mix_PlayChannel: %s\n", Mix_GetError());
		exit(1);
	}
}
void Sound::Stop() {
	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
	}
}
void Sound::Open(std::string file) {
	chunk = Mix_LoadWAV(file.c_str());
	if (!chunk) {
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		exit(1);
	}
}
bool Sound::IsOpen() {
	return (chunk != nullptr);
}
void Sound::Update(float dt) {

}

void Sound::Render() {

}

bool Sound::Is(std::string type) {
	return type == "Sound";
}