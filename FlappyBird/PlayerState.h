#pragma once
#include "StateBase.h"

class PlayerState :
	public StateBase
{
private:
	
	/*Texture* mPipe;
	Texture* mc = nullptr;*/

public:
	PlayerState();
	~PlayerState();
	bool Init();
	bool Pause();
	bool Resume();
	bool Update();
};

