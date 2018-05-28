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
		mBackGround[i].Init(Position(0, 0), SIZE_BACKGROUND_X, SIZE_BACKGROUND_Y, s_start, SIZE_BACKGROUND_X, SIZE_BACKGROUND_Y);
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
	return true;
}
bool BackGround::Pause() {
	return true;
}
bool BackGround::Resume() {
	return true;
}
bool BackGround::Update() {
	for (int i = 0; i < 6; i++) {
		Position tmp_DPosition = mBackGround[i].getDPosition();
		tmp_DPosition.x -= speed;
		if (tmp_DPosition.x <= (SIZE_BACKGROUND_X)*(-1)) {
			tmp_DPosition.x += SIZE_BACKGROUND_X * 5;
		}
		mBackGround[i].setDPosition(tmp_DPosition);
	}
	for (int i = 0; i < 8; i++) {
		Position tmp_DPosition = mPipe[i].getDPosition();
		tmp_DPosition.x -= speed;
		if (tmp_DPosition.x <= 0) {
			int last = (i == 0) ? 7 : (i - 1);
			Position tmp_last = mPipe[last].getDPosition();
			tmp_DPosition.x = tmp_last.x + SIZE_PIPE_X + rand() % 10 + 50;
			tmp_DPosition.y = 150 + rand() % 50;
		}
		SDL_Log(" Pipe i :: %d  - position :: (%d-%d)", i, tmp_DPosition.x, tmp_DPosition.y);
		mPipe[i].setDPosition(tmp_DPosition);
	}
	return true;
}

BackGround* BackGround::getInstance() {
	static BackGround* instance;
	if (instance)
		return instance;
	instance = new BackGround();
	return instance;
}