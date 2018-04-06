#ifndef COMPONENT_H
#define COMPONENT_H
#include "SDL_include.h"
#include <string>
#include "GameObject.h"

class Component {
protected:
	GameObject& associated;

public:
	Component(GameObject& associated);
	virtual ~Component();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	bool virtual Is(std::string type) = 0;

};
#endif