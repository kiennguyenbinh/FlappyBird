#include "Engine.h"
#include "StateBase.h"
#include "EventManager.h"
#include "BackGround.h"

StateBase::StateBase()
{
}


StateBase::~StateBase()
{
}
bool StateBase::Init() {

	EventManager::getInstace()->AddListener(this);
	isAlive = true;
	return true;
}
bool StateBase::Update() {
	if (!isAlive || !isRunning) {
		return false;
	}
	return true;
}
bool StateBase::Pause() {
	isRunning = false;
	return true;
}
bool StateBase::Resume() {
	if (!isAlive)
		if (!Init())
			return false;
	isRunning = true;
	return true;
}

void StateBase::Destroy() {
	if (isRunning) //We need pause beforce Destroy state.
		Pause();
}

void StateBase::OnEvent(Event* _event) {
	switch(_event->data) {
	case SDL_SCANCODE_A:
		SDL_Log("StateBase::OnEvent :: Left");
		break;
	case SDL_SCANCODE_D:
		BackGround::getInstance()->increaseSpeed();
		SDL_Log("StateBase::OnEvent :: Right");
		break;
	case SDL_SCANCODE_W:
		SDL_Log("StateBase::OnEvent :: Up");
		break;
	case SDL_SCANCODE_S:
		SDL_Log("StateBase::OnEvent :: Down");
		break;
	}
}