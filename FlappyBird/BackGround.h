#pragma once
#include "Texture.h"

#define COUNT_BACKGROUND 12
#define COUNT_PIPE 8
class BackGround
{
private:
	Texture mBackGround[COUNT_BACKGROUND];
	Texture mPipe[COUNT_PIPE];
	Texture mc;
	int speed = 1;
	const int SIZE_MC_X = 34;
	const int SIZE_MC_Y = 24;
	const int SIZE_PIPE_X = 52;
	const int SIZE_PIPE_Y = 320;
	const int SIZE_BACKGROUND_X = 288;
	const int SIZE_BACKGROUND_Y = 512;
public:
	BackGround();
	~BackGround();
	bool Init();
	bool Pause();
	bool Resume();
	bool Update();
	void increaseSpeed() { speed++; };
	static BackGround* getInstance();
};

