#include "Engine.h"
#include "Define.h"
#include "Timer.h"
#include "TextureManager.h"
#include "StateManager.h"
#include "EventManager.h"
#include "InputManager.h"
#include "PlayerState.h"
Engine::Engine()
{
}


Engine::~Engine()
{
}

bool Engine::Init(WindowsSetting *cs) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("SDL Init Failed :: Cause %s", SDL_GetError());
		return false;
	}
	
	gWindows = SDL_CreateWindow(
		cs->title.c_str(),
		cs->pos->x,
		cs->pos->y,
		cs->width,
		cs->height,
		cs->flag
	);
	if (gWindows == nullptr) {
		SDL_Log("Windows created error :: Cause %s", SDL_GetError());
		return false;
	}
	gRender = SDL_CreateRenderer(
		gWindows, 
		cs->renderSetting->index, 
		cs->renderSetting->flag
	);
	if (gRender == nullptr) {
		SDL_Log("Render create error :: Cause %s", SDL_GetError());
		return false;
	}

	if (!TextureManager::getInstance()->Init()) {
		return false;
	}

	if (!StateManager::getInstace()->Init()) {
		return false;
	}

	if (!EventManager::getInstace()->Init()) {
		return false;
	}

	if (!InputManager::getInstance()->Init()) {
		return false;
	}

	isRunning = true;

	StateManager::getInstace()->PushState(new PlayerState());
	return true;
}

bool Engine::Destroy() {

	InputManager::getInstance()->Destroy();
	EventManager::getInstace()->Destroy();
	StateManager::getInstace()->Destroy();
	TextureManager::getInstance()->Destroy();

	SDL_DestroyRenderer(gRender);
	gRender = nullptr;

	SDL_DestroyWindow(gWindows);
	gWindows = nullptr;

	SDL_Quit();
	return true;
}
bool Engine::Update() {
	//printf("Engine::Update().\n");
	StateManager::getInstace()->Update();
	EventManager::getInstace()->Update();
	InputManager::getInstance()->Update();
	return true;
}

void Engine::Render() {
	CleanBuffer();
	TextureManager::getInstance()->Render();
	RefereshBuffer();
}

void Engine::Execute() {
	WindowsSetting *cs = new WindowsSetting();
	cs->pos = new Position(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
	cs->width = WINDOWS_WIDTH;
	cs->height = WINDOWS_HEIGH;
	cs->flag = SDL_WINDOW_SHOWN;
	cs->title = "Flappy Bird Game v1.0";
	cs->renderSetting = new RenderSetting();
	cs->renderSetting->flag = SDL_RENDERER_ACCELERATED;

	if (Init(cs)) {
		Timer fps;
		while (isRunning && !isQuit) {
			fps.start();
			Update();
			Render();
			if (fps.get_ticks() < 1000 / FPS)
			{
				SDL_Delay((1000 / FPS) - fps.get_ticks());
			}
		}
	}
	else
	{
		SDL_Log("Engine :: Init Error");
	}
}

Engine* Engine::getInstance() {
	static Engine* instance;
	if (instance != nullptr) {
		return instance;
	}
	instance = new Engine();
	return instance;
}