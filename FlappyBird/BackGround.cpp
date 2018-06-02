#include "BackGround.h"
#include "TextureManager.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}
bool BackGround::Init() {
	Position s_start(0, 0);
	for (int i = 0; i < COUNT_BACKGROUND; i++) {
		mBackGround[i].Init(Position(0, 0), SIZE_BACKGROUND_X, SIZE_BACKGROUND_Y, s_start, SIZE_BACKGROUND_X, SIZE_BACKGROUND_Y - 50);
		mBackGround[i].loadTextTure(i < (COUNT_BACKGROUND / 2) ? "asset/sprites/background-day.png" : "asset/sprites/background-night.png");
		TextureManager::getInstance()->AddTexture(&mBackGround[i]);
		s_start = Position(s_start.x + SIZE_BACKGROUND_X, s_start.y);
	}

	s_start = Position(SIZE_BACKGROUND_X, 300);
	for (int i = 0; i < COUNT_PIPE; i++) {
		mPipe[i].Init(Position(0, 0), SIZE_PIPE_X, SIZE_PIPE_Y, s_start, SIZE_PIPE_X, SIZE_PIPE_Y);
		mPipe[i].loadTextTure(i < (COUNT_PIPE /2) ? "asset/sprites/pipe-green.png" : "asset/sprites/pipe-red.png");
		TextureManager::getInstance()->AddTexture(&mPipe[i]);
		s_start = Position(s_start.x + SIZE_PIPE_X + rand() % 10 + 50,  150 + rand() % 50);
	}

	s_start = Position(SIZE_BACKGROUND_X, 300);
	mc.Init(Position(0, 0), SIZE_MC_X, SIZE_MC_Y, s_start, SIZE_MC_X, SIZE_MC_Y, 3);
	mc.loadTextTure("asset/sprites/sprite.png");
	TextureManager::getInstance()->AddTexture(&mc);
	
	s_start = Position(0, 350);
	for (int i = 0; i < COUNT_GROUND; i++) {
		mGround[i].Init(Position(0, 0), SIZE_GROUND_X, SIZE_GROUND_Y, s_start, SIZE_GROUND_X, SIZE_GROUND_Y);
		mGround[i].loadTextTure("asset/sprites/base.png");
		TextureManager::getInstance()->AddTexture(&mGround[i]);
		s_start = Position(s_start.x + SIZE_GROUND_X, 350);
	}
	return true;
}
bool BackGround::Pause() {
	return true;
}
bool BackGround::Resume() {
	return true;
}
bool BackGround::Update() {
	for (int i = 0; i < COUNT_BACKGROUND; i++) {
		Position tmp_DPosition = mBackGround[i].getDPosition();
		tmp_DPosition.x -= speed;
		if (tmp_DPosition.x <= (SIZE_BACKGROUND_X)*(-1)) {
			tmp_DPosition.x += SIZE_BACKGROUND_X * (COUNT_BACKGROUND - 1);
		}
		mBackGround[i].setDPosition(tmp_DPosition);
	}
	for (int i = 0; i < COUNT_PIPE; i++) {
		Position tmp_DPosition = mPipe[i].getDPosition();
		tmp_DPosition.x -= speed;
		if (tmp_DPosition.x <= 0) {
			int last = (i == 0) ? (COUNT_PIPE - 1) : (i - 1);
			Position tmp_last = mPipe[last].getDPosition();
			tmp_DPosition.x = tmp_last.x + SIZE_PIPE_X + rand() % 10 + 50;
			tmp_DPosition.y = 150 + rand() % 50;
		}
		mPipe[i].setDPosition(tmp_DPosition);
	}
	mc.playAnimation(50);
	return true;
}

BackGround* BackGround::getInstance() {
	static BackGround* instance;
	if (instance)
		return instance;
	instance = new BackGround();
	return instance;
}