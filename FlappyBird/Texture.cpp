#include "Texture.h"



Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::Init(Position _src, int _src_width, int _src_height, Position _des, int _des_width, int _des_height, bool isFrame = false) {
	srcRect.x = _src.x;
	srcRect.y = _src.y;
	srcRect.w = _src_width;
	srcRect.h = _src_height;

	desRect.x = _des.x;
	desRect.y = _des.y;
	desRect.w = _des_width;
	desRect.h = _des_height;
	isFrame = isFrame;
}
bool Texture::loadTextTure(std::string path) {
	if (!path.empty()) {
		gSurface = IMG_Load(path.c_str());
		if (gSurface == nullptr) {
			SDL_Log("Texture :: Can't load texture :: %s :: Path: %s", IMG_GetError(), path.c_str());
			return false;
		}
		SDL_SetColorKey(gSurface, SDL_TRUE,	SDL_MapRGB(gSurface->format, 0, 0, 0));
		gTexture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRender(), gSurface);
		if (gTexture == nullptr) {
			SDL_Log("Texture :: Can't load texture :: %s :: Path: %s", IMG_GetError(), path.c_str());
			return false;
		}
		SDL_FreeSurface(gSurface);
		return true;

	}
	return false;
}
void Texture::Render() {
	SDL_RenderCopy(Engine::getInstance()->getRender(),gTexture, &srcRect, &desRect);
}
