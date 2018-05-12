#pragma once

#include <string>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

struct Position {
	int x;
	int y;
	Position(int _x, int _y) { x = _x; y = _y; };
};

struct RenderSetting {
	int index = -1;
	Uint32 flag;
};
struct WindowsSetting {
	Position *pos;
	int width;
	int height;
	Uint32 flag;
	std::string title;
	RenderSetting* renderSetting;
};
class Engine
{
private:
	SDL_Window *gWindows;
	SDL_Renderer *gRender;
	bool isRunning = false;
	bool isQuit = false;
public:
	Engine();
	virtual ~Engine();
	bool Init(WindowsSetting *cs);
	bool Update();
	void Render();
	bool Destroy();
	void Execute();
	void CleanBuffer() { SDL_RenderClear(gRender); };
	void RefereshBuffer() { SDL_RenderPresent(gRender); };
	static Engine* getInstance();
	bool getEngineStatus() { return isRunning; };
	bool getEngineQuit() { return isQuit; };
	void setEngineQuit(bool quit) { isQuit = quit; };
	SDL_Window* getWindows() { return gWindows; };
	SDL_Renderer* getRender() { return gRender; };
};

