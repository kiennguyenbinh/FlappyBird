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
	/*Texture* test = new Texture();
	test->Init(Position(0, 0), 288, 512, Position(0, 0), 600, 400);
	test->loadTextTure("asset/sprites/background-day.png");
	AddTexture(test);*/
	return true;
}

bool TextureManager::Destroy() {
	while (!m_stackTexture.empty()) {
		m_stackTexture.back()->Destroy();
		m_stackTexture.pop_back();
	}
	IMG_Quit();
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
bool TextureManager::AddTexture(Texture* _texture) {
	if (_texture == nullptr) {
		SDL_Log("TextureManager :: AddTexture :: Cause :: %s", SDL_GetError());
		return false;
	}
	m_stackTexture.push_back(_texture);
	return true;
}
TextureManager* TextureManager::getInstance() {
	static TextureManager* instance;
	if( instance) 
		return instance;
	instance = new TextureManager();
	return instance;
}


