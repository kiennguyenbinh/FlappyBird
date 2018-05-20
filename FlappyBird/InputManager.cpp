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
	SDL_PumpEvents();
	SDL_Event event;
	while (SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_KEYDOWN, SDL_KEYUP))
	{
		//SDL_Log("event.key.keysym.scancode :: %d ", event.key.keysym.scancode);
		EventManager::getInstace()->PushEvent(new Event(event.key.keysym.scancode, event.type));
	}
	return true;
}
void InputManager::Destroy() {

}
