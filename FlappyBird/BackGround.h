#pragma once
#include "Texture.h"
class BackGround
{
private:
	Texture mBackGround[6];
	Texture mPipe[8];
	int speed = 1;
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

