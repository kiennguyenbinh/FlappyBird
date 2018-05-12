#pragma once
#include "AdListener.h"
#include <vector>

class EventManager :
	public AdListener
{
private:
	std::vector<AdListener*> m_AdListener;
public:
	EventManager();
	~EventManager();
	bool Init();
	bool Update();
	void Destroy();
	bool AddListenner();
	EventManager* getInstace();
};

