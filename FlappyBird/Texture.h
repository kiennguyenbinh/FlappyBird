#pragma once
#include "Engine.h"

class Texture
{
private:
	SDL_Surface* gSurface;
	SDL_Texture* gTexture;
	SDL_Rect srcRect;
	SDL_Rect desRect;
	bool isFrame;
public:
	Texture();
	~Texture();
	bool Init(Position _src, int _src_width, int _src_height,  Position _des, int _des_width, int _des_height, bool isFrame = false);
	void Destroy();
	void Render();
	bool loadTextTure(std::string path);
	void setDPosition(Position des);
	Position getDPosition() { return Position(desRect.x, desRect.y); };
};

