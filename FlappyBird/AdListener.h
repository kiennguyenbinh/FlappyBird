#pragma once

struct Event
{

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

