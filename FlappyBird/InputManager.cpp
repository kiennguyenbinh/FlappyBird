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
	//printf("InputManager::Update().\n");
	SDL_PumpEvents();
	SDL_Event event;
	while (SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
		case SDL_KEYUP:
		{ 
			SDL_Log("event.key.keysym.scancode :: %d ", event.key.keysym.scancode);
			EventManager::getInstace()->PushEvent(new Event(event.key.keysym.scancode));
			break;
		}
		case SDL_MOUSEMOTION:
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_QUIT:
			Engine::getInstance()->setEngineQuit(true);
			break;
		}
	}
	return true;
}
void InputManager::Destroy() {

}
