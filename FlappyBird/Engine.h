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
	Position pos;
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
public:
	Engine();
	virtual ~Engine();
	bool Init(WindowsSetting *cs);
	bool Update();
	void Render();
	void Pause();
	void Resume();
	void Execute();
};

