#pragma once
class InputManager
{
public:
	InputManager();
	~InputManager();
	static InputManager* getInstance();
	bool Init();
	bool Update();
	void Destroy();
};

