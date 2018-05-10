#include "Engine.h"



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
		cs->pos.x,
		cs->pos.y,
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


}

bool Engine::Update() {

}

void Engine::Render() {

}

void Engine::Pause() {

}

void Engine::Resume() {

}
void Engine::Execute() {

}