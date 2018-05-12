#include "StateBase.h"
#include "EventManager.h"


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
	//process Event Here
}