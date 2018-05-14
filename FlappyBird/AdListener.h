#pragma once

enum EventState {
	EVT_NONE = 0,
	EVT_PRESS,
	EVT_RELEASE,
	EVT_HOLD
};

struct Event
{
	int data;
	int state;
	Event(int _data) { data = _data; };
};

class AdListener
{
public:
	AdListener();
	virtual ~AdListener();
	virtual bool Init();
	virtual void Destroy();
	virtual void OnEvent(Event* _event) = 0;
};

