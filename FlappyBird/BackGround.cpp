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
	for (int i = 0; i < 6; i++) {
		mBackGround[i].Init(Position(0, 0), SIZE_BACKGROUND_X, SIZE_BACKGROUND_Y, s_start, SIZE_BACKGROUND_X, SIZE_BACKGROUND_Y);
		mBackGround[i].loadTextTure(i < 3 ? "asset/sprites/background-day.png" : "asset/sprites/background-night.png");
		TextureManager::getInstance()->AddTexture(&mBackGround[i]);
		s_start = Position(s_start.x + SIZE_BACKGROUND_X, s_start.y);
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
	return true;
}

BackGround* BackGround::getInstance() {
	static BackGround* instance;
	if (instance)
		return instance;
	instance = new BackGround();
	return instance;
}