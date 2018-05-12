#pragma once
#include "AdListener.h"
#include <string>
class StateBase 
	: public AdListener
{
private:
	bool isAlive;
	bool isRunning;
public:
	StateBase();
	virtual ~StateBase();
	virtual bool Init();
	virtual bool Pause();
	virtual bool Resume();
	virtual bool Update();
	void OnEvent(Event* _event);
	virtual void Destroy();
	virtual std::string getNameState() = 0;

};

