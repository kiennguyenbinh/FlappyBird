#include "TextureManager.h"
#include "Engine.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

bool TextureManager::Init() {
	if (Engine::getInstance()->getRender() == nullptr) {
		SDL_Log("TextureManager :: Error getRender");
		return false;
	}
	if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) {
		SDL_Log("TextureManager :: IMG Init failed :: Cause %s :: IMG :: %s", SDL_GetError(), IMG_GetError());
		return false;
	}
	return true;
}

bool TextureManager::Destroy() {
	return true;
}

bool TextureManager::Update() {
	return true;
}

void TextureManager::Render() {
	Engine::getInstance()->CleanBuffer();
	for each (Texture *it in m_stackTexture)
	{
		it->Render();
	}
	Engine::getInstance()->RefereshBuffer();
}
TextureManager* TextureManager::getInstance() {
	static TextureManager* instance;
	if( instance) 
		return instance;
	instance = new TextureManager();
	return instance;
}


