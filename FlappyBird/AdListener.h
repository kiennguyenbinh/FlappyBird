#pragma once

enum EventState {
	EVT_NONE = 0,
	EVT_PRESS = 0x300,
	EVT_RELEASE = 0x301,
	EVT_HOLD
};

struct Event
{
	int data;
	int state;
	Event(int _data, int _state = EVT_NONE) { data = _data; state = _state; };
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

