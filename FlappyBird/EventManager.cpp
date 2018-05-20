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
	for (std::deque<Event*>::iterator it = m_eventStack.begin(); it!= m_eventStack.end() && !m_eventStack.empty(); it++)
	{
		RaiseEvent(*it);
	}
	return true;
}
bool EventManager::PrePushEvent(Event* _event) {
	if (_event->state == EventState::EVT_RELEASE) {
		std::deque<Event*>::iterator it = std::find_if(m_eventStack.begin(), m_eventStack.end(), [=](const Event* m_event) -> bool {return ((_event->data == m_event->data) && (EventState::EVT_PRESS == m_event->state)); });
		m_eventStack.erase(it);
		return false;
	}
	return std::find_if(m_eventStack.begin(), m_eventStack.end(), [_event](const Event* m_event) -> bool {return ((_event->data == m_event->data) && (_event->state == m_event->state)); }) == m_eventStack.end();
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