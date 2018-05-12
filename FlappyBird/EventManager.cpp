#include "EventManager.h"
#include "Engine.h"


EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

bool EventManager::Init() {
	return true;
}

bool EventManager::Update() {
	while (!m_eventStack.empty()) {
		RaiseEvent(m_eventStack.front());
		m_eventStack.pop_front();
	}
	return true;
}
void EventManager::Destroy() {

}
void EventManager::RaiseEvent(Event* _event) {
	for each (AdListener* it in m_AdListener)
	{
		it->OnEvent(_event);
	}
}
bool EventManager::AddListener(AdListener* _listenter) {
	if (_listenter == nullptr)
		return false;
	m_AdListener.push_back(_listenter);
	return true;
}
EventManager* EventManager::getInstace() {
	static EventManager* instance;
	if (instance)
		return instance;
	instance = new EventManager();
	return instance;
}