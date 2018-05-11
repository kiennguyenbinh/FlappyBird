#include "StateManager.h"



StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}
bool StateManager::Init() {
	return true;
}
bool StateManager::Update() {
	if (getCurrentState() == nullptr) {
		return false;
	}
	getCurrentState()->Update();
	return true;
}
void StateManager::Render() {
	if (getCurrentState() != nullptr) {
		getCurrentState()->Render();
	}
}
bool StateManager::Destroy() {
	//we need pop all state beforce Destroy StateManager
	while (!m_stateStack.empty()) {
		PopState();
	}

	return true;
}
bool StateManager::PushState(StateBase* _state) {
	if (_state == nullptr) {
		return false;
	}
	getCurrentState()->Pause();
	m_stateStack.push_back(_state);
	getCurrentState()->Resume();
	return true;
}
bool StateManager::PopState() {
	if (m_stateStack.empty()) {
		return false;
	}
	getCurrentState()->Pause();
	getCurrentState()->Destroy();
	m_stateStack.pop_back();

	if (m_stateStack.size() > 0) {
		getCurrentState()->Resume();
	}
	return true;
}
bool StateManager::SwitchState(StateBase* _state) {
	if ((_state == nullptr) && (getCurrentState() == nullptr)) {
		return false;
	}
	if (PopState())
		if (PushState(_state))
			return true;
	return false;

	
}
StateManager* StateManager::getInstace() {
	static StateManager* instance = nullptr;
	if (instance)
		return instance;
	instance = new StateManager();
	return instance;
}