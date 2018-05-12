#pragma once
#include "AdListener.h"
#include <vector>
#include <deque>
class EventManager :
	public AdListener
{
private:
	std::vector<AdListener*> m_AdListener;
	std::deque<Event*> m_eventStack;
public:
	EventManager();
	~EventManager();
	bool Init();
	bool Update();
	void RaiseEvent(Event* _event);
	void Destroy();
	virtual void OnEvent(Event* _event) {};
	bool PushEvent(Event* _event) {
		if (_event == nullptr)
			return false;
		m_eventStack.push_back(_event);
		return true;
	}
	bool AddListener(AdListener*);
	static EventManager* getInstace();
};

