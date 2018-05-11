#pragma once
#include "StateBase.h"
#include <vector>
class StateManager
{
private:
	std::vector<StateBase*> m_stateStack;

public:
	StateManager();
	~StateManager();
	bool Init();
	bool Update();
	bool Destroy();
	bool PushState(StateBase* _state);
	bool PopState();
	bool SwitchState(StateBase* _state);
	StateBase* getCurrentState() { return m_stateStack.empty() ? nullptr : m_stateStack.back(); };
	/*bool IsStateRunning(std::string _state_name);
	bool IsStatePause(std::string _state_name);*/
	static StateManager* getInstace();
};

