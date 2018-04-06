#include "Sound.h"
#include "Face.h"
#include "Sprite.h"
#include "GameObject.h"

Face::Face(GameObject &associated) : Component(associated) {
	hitpoints = 30;
}

void Face::Damage(int damage) {
	hitpoints -= damage;
	if (hitpoints <= 0) {
		Sprite* sprite = (Sprite*)associated.GetComponent("Sprite");
		if (sprite != nullptr) {
			Sound* sound = (Sound *)associated.GetComponent("Sound");
			if (sound != nullptr) {
				sound->Play();
				associated.RemoveComponent(sprite);
			}
			else {
				associated.RequestDelete();
			}
		}
	}
}

void Face::Update(float dt) {}

void Face::Render() {}

bool Face::Is(std::string type) {
	return type == "Face";
}