#pragma once
#include "AdListener.h"
#include <vector>
#include <deque>
#include <algorithm>

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
	bool PrePushEvent(Event* _event);
	bool PushEvent(Event* _event) {
		if (_event == nullptr)
			return false;

		if (!PrePushEvent(_event))
			return false;
		
		m_eventStack.push_back(_event);
		return true;
	}
	bool AddListener(AdListener*);
	static EventManager* getInstace();
};

