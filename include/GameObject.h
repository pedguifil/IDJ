/* Com isso, tá dando erro de compilação, sem isso, o problema saiu
mas tirar isso de GameObject.h e Component.h dá ruinzão
Dependência circular? como faz isso?
não esquecer de descomentar o endif no final vvvvv
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Rect.h"
#include <memory>
#include <string>
#include <vector>

class Component;

class GameObject {

public:

	GameObject();
	~GameObject();
	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
	Component* GetComponent(std::string type);

	Rect box;

private:
	std::vector<std::unique_ptr<Component>> components;
	bool isDead;

};
#endif /* STATE_H */