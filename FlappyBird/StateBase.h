#pragma once
class StateBase
{
public:
	StateBase();
	virtual ~StateBase();
	virtual bool Init() = 0;
	virtual bool Update();
	virtual void Render();
	virtual void Destroy();

};

