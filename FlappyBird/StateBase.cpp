#include "StateBase.h"



StateBase::StateBase()
{
}


StateBase::~StateBase()
{
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
	isRunning = true;
	return true;
}

void StateBase::Destroy() {
	if (isRunning) //We need pause beforce Destroy state.
		Pause();
}