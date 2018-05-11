#pragma once
#include <string>
class StateBase
{
private:
	bool isAlive;
	bool isRunning;
public:
	StateBase();
	virtual ~StateBase();
	virtual bool Init() = 0;
	virtual bool Pause();
	virtual bool Resume();
	virtual bool Update();
	virtual void Render();
	virtual void Destroy();
	virtual std::string getNameState() = 0;

};

