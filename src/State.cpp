#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include "Face.h"
#include "Sound.h"
#include <math.h>
State::State() {
	GameObject* go = new GameObject();
	go->AddComponent(new Sprite(*go, "assets/img/ocean.jpg"));
	objectArray.emplace_back(go);
	quitRequested = false;
	music = Music();
	LoadAssets();
}
State::~State() {
	objectArray.clear();
}
bool State::QuitRequested() {
	return quitRequested;
}
void State::LoadAssets() {
	music.Open("assets/audio/stageState.ogg");
	music.Play(-1);
}
void State::Render() {
	for (unsigned int i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Render();
	}
}
void State::Update(float dt) {
	if (SDL_QuitRequested()) {
		quitRequested = true;
	}
	Input();
	for (int i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Update(dt);
	}

	for (int i = 0; i < objectArray.size(); i++) {
		if (objectArray[i]->IsDead()) {
			objectArray.erase(objectArray.begin() + i);
		}
	}
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contr�rio
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para termina��o
		if (event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de tr�s pra frente pra sempre clicar no objeto mais de cima
			for (int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro � algo que devemos evitar ao m�ximo.
				// O prop�sito do unique_ptr � manter apenas uma c�pia daquele ponteiro,
				// ao usar get(), violamos esse princ�pio e estamos menos seguros.
				// Esse c�digo, assim como a classe Face, � provis�rio. Futuramente, para
				// chamar fun��es de GameObjects, use objectArray[i]->fun��o() direto.

				if (go->box.Contains({ (float)mouseX, (float)mouseY })) {
					Face* face = (Face*)go->GetComponent("Face");
					if (nullptr != face) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (s� queremos acertar um)
						break;
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}
			// Se n�o, crie um objeto
			else {
				Vec2 objPos = Vec2(200,0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}
void State::AddObject(int mouseX, int mouseY) {
	GameObject *go_enemy = new GameObject();
	Sprite *sprite = new Sprite(*go_enemy, "assets/img/penguinface.png");

	go_enemy->box.x = mouseX - go_enemy->box.width / 2;
	go_enemy->box.y = mouseY - go_enemy->box.height / 2;

	go_enemy->AddComponent(sprite);

	go_enemy->AddComponent(new Sound(*go_enemy, "assets/audio/boom.wav"));
	go_enemy->AddComponent(new Face(*go_enemy));

	objectArray.emplace_back(go_enemy);

}