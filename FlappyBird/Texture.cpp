#include "Texture.h"



Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::Init(Position _src, int _src_width, int _src_height, Position _des, int _des_width, int _des_height, double _angle, SDL_Point* _center, SDL_RendererFlip _flip) {
	srcRect.x = _src.x;
	srcRect.y = _src.y;
	srcRect.w = _src_width;
	srcRect.h = _src_height;

	desRect.x = _des.x;
	desRect.y = _des.y;
	desRect.w = _des_width;
	desRect.h = _des_height;

	angle = _angle;
	center = _center;
	flip = _flip;
	
	return true;
}

void Texture::Destroy() {
	SDL_DestroyTexture(gTexture);
	gTexture = nullptr;

	SDL_FreeSurface(gSurface);
	gSurface = nullptr;
}
bool Texture::loadTextTure(std::string path) {
	if (!path.empty()) {
		gSurface = IMG_Load(path.c_str());
		if (gSurface == nullptr) {
			SDL_Log("Texture :: Can't load texture Cause:: gSurface == null :: %s :: Path: %s", IMG_GetError(), path.c_str());
			return false;
		}
		SDL_SetColorKey(gSurface, SDL_TRUE,	SDL_MapRGB(gSurface->format, 0, 0, 0));
		gTexture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRender(), gSurface);
		if (gTexture == nullptr) {
			SDL_Log("Texture :: Can't load texture Cause:: gTexture == null :: %s :: Path: %s", IMG_GetError(), path.c_str());
			return false;
		}
		SDL_FreeSurface(gSurface);
		return true;

	}
	return false;
}
void Texture::setDPosition(Position _des) {
	desRect.x = _des.x;
	desRect.y = _des.y;
}

void Texture::Render() {
	if (SDL_RenderCopyEx(Engine::getInstance()->getRender(), gTexture, &srcRect, &desRect, angle, center, flip) != 0) {
		SDL_Log("Error Texture Render");
	}
}
