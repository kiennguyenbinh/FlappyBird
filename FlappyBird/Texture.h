#pragma once
#include "Engine.h"

class Texture
{
private:
	SDL_Surface* gSurface;
	SDL_Texture* gTexture;
	SDL_Rect srcRect;
	SDL_Rect desRect;
	double angle;
	SDL_Point* center;
	SDL_RendererFlip flip;
public:
	Texture();
	~Texture();
	bool Init(Position _src, int _src_width, int _src_height, Position _des, int _des_width, int _des_height, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Destroy();
	void Render();
	bool loadTextTure(std::string path);
	void setDPosition(Position des);
	Position getDPosition() { return Position(desRect.x, desRect.y); };
};

