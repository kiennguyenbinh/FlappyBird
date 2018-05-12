#pragma once
class AdListener
{
public:
	AdListener();
	virtual ~AdListener();
	virtual bool Init();
	virtual void Destroy();
	virtual void OnEvent() = 0;
};

