#pragma once
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	bool Init();
	bool Update();
	void Render();
	bool Destroy();
	static TextureManager* getInstance();
};

