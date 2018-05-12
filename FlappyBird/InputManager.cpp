#include "InputManager.h"
#include "Engine.h"
#include "EventManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

InputManager* InputManager::getInstance() {
	static InputManager* instance;
	if (instance)
		return instance;
	instance = new InputManager();
	return instance;
}
bool InputManager::Init() {
	return true;
}
bool InputManager::Update() {
	printf("InputManager::Update().\n");
	SDL_PumpEvents();
	SDL_Event event;
	while (SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
		{
			//do something
			break;
		}
		case SDL_MOUSEMOTION:
			//do something
			break;
		case SDL_MOUSEBUTTONDOWN:
			//do something
			break;
		case SDL_MOUSEBUTTONUP:
			//do something
			break;
		}
	}
	return true;
}
void InputManager::Destroy() {

}
