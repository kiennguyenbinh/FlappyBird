#include "PlayerState.h"
#include "BackGround.h"

PlayerState::PlayerState()
{
}


PlayerState::~PlayerState()
{
}

bool PlayerState::Init() {
	StateBase::Init();

	if (!BackGround::getInstance()->Init())
		return false;

	return true;
}
bool PlayerState::Pause() {
	//process it
	BackGround::getInstance()->Pause();
	StateBase::Pause();
	return true;
}
bool PlayerState::Resume() {
	StateBase::Resume();
	BackGround::getInstance()->Resume();
	//process it
	return true;
}
bool PlayerState::Update() {
	BackGround::getInstance()->Update();
	return true;
}