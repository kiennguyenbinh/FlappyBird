#pragma once

struct Event
{
	int data;
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

